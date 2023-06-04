#include <mic.h>
#include <ArduinoBLE.h>
#include <SD.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* clock=*/ PIN_WIRE_SCL, /* data=*/ PIN_WIRE_SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

#include "svm2.h"
Eloquent::ML::Port::SVM classifier;

// BLE vars
#define SERVICE_UUID            "0f9aa5ef-bde7-4147-9f4f-3fb30983c38E"                       
#define CHARACTERISTIC_UUID_1   "0f9aa5ef-bde7-4247-9f4f-3fb30983c38E"
#define CHARACTERISTIC_UUID_2   "0f9aa5ef-bde7-4347-9f4f-3fb30983c38E"
#define CHARACTERISTIC_UUID_3   "0f9aa5ef-bde7-4447-9f4f-3fb30983c38E"
#define CHARACTERISTIC_UUID_4   "0f9aa5ef-bde7-4547-9f4f-3fb30983c38E"


BLEService features(SERVICE_UUID); 

BLEStringCharacteristic timestamp(CHARACTERISTIC_UUID_1, BLENotify, 20);
BLEStringCharacteristic rpiCommands(CHARACTERISTIC_UUID_2, BLEWrite, 20);
BLEStringCharacteristic exectime(CHARACTERISTIC_UUID_3, BLENotify, 20);
BLEStringCharacteristic counters(CHARACTERISTIC_UUID_4, BLENotify, 20);


#define DEBUG 0              // Enable pin pulse during ISR  
#define SAMPLES 12800


mic_config_t mic_config{
  .channel_cnt = 1,
  .sampling_rate = 16000,
  .buf_size = 12800,
  .debug_pin = LED_BUILTIN                

};

File txtfile;

NRF52840_ADC_Class Mic(&mic_config);


int16_t recording_buf[SAMPLES];
volatile uint8_t recording = 0;
volatile static bool record_ready = false;

float feature_svm[7];


static void audio_rec_callback(uint16_t *buf, uint32_t buf_len);
void AT(int16_t *recording_buf);
void rpiCommandsWritten(BLEDevice central, BLECharacteristic characteristic);
void blePeripheralDisconnectHandler(BLEDevice central);
void blePeripheralConnectHandler(BLEDevice central);
//AT DESCRIPTOR VARS
int16_t maxima =0 ; 
uint    max_index = 0;
uint    start_attack = 0;
uint    end_attack   = 0;
float    avg_abs     = 0; 
long    sum_abs     = 0;
uint    AT_val          = 0;

uint    interval    = SAMPLES/20;
volatile static bool empty = false;
uint    zero_cross  =0;
long     STE         = 0;
uint    LoLAS       =0;
uint    LoHAS       = 0;
float     slope       = 0;
float     LAT         =0;
float   threshold     =0;
long    exec_time     =0;
int    counter       =0;

uint step_counter   =0;
uint clap_counter   =0;
uint knock_counter   =0;
uint noise_counter   =0;


void setup() {

  Serial.begin(57600);
  while (!Serial) {delay(10);}
  u8x8.begin();
  u8x8.setFlipMode(1);
  Mic.set_callback(audio_rec_callback);

  if (!Mic.begin()) {
    Serial.println("init_fail");
    while (1);
  }

  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }
  if (!SD.begin()) {
    Serial.println("sd card not initialized");
    while (1);
  }
  
  BLE.setLocalName("seeed");
  
  BLE.setAdvertisedService(features);

  // add the characteristic to the servicekok
  features.addCharacteristic(timestamp);
  features.addCharacteristic(exectime);
  features.addCharacteristic(rpiCommands);
  features.addCharacteristic(counters);
  // add service
  BLE.addService(features);

  // assign event handlers for connected, disconnected to peripheral
  BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  // assign event handlers for characteristic
  rpiCommands.setEventHandler(BLEWritten, rpiCommandsWritten);
  // set an initial value for the characteristic
  rpiCommands.setValue("Hello darkness my old friend");

  // start advertising
  BLE.advertise();

  Serial.println(("Bluetooth device active, waiting for connections..."));
  Serial.println(BLE.address());
  Serial.println("init_ok");
  
}

void loop() { 
  delay(1000);
  unsigned long start1 = micros();
  counter +=1;
  
  
  uint resp =1;
  
  
  if (!recording && record_ready){
  resp = 0;
  }  
  
  BLE.poll();
  
  if (resp == 1 && !recording) {

    recording = 1;
    record_ready = false;  
    //Serial.println("Initiated recording");
  }

  if (!recording && record_ready)
  {
    
  
  AT(recording_buf);
  
  
  if (DEBUG==1){ 
  Serial.println("");
  Serial.println("#################");
  Serial.print("Finding AT features took  ");
  Serial.print (exec_time);
  Serial.println("  µs");
  
  Serial.print("MAXIMA    ");
  Serial.println(maxima);
  Serial.print("CALCULATED START OF ATTACK IS AT      ");
  Serial.print(start_attack);
  Serial.println("  SAMPLE" );
  Serial.print("CALCULATED END OF ATTACK IS AT      ");
  Serial.print(max_index);
  Serial.println("  SAMPLE" );
  
  Serial.print("CALCULATED ATTACK TIME IS     ");
  Serial.print(AT_val);
  Serial.println("  samples" );
  Serial.print("ZCR IS  ");
  Serial.print(zero_cross);
  Serial.println("  number of times");
  Serial.print("STE   ");
  Serial.println(STE/SAMPLES);
  Serial.print("LoLAS is equal   ");
  Serial.println(LoLAS);
  Serial.print("LoHAS is equal   ");
  Serial.println(LoHAS);
  Serial.print("Slope of attack:  ");
  Serial.println(slope);
  Serial.print("LAT   ");
  Serial.println(LAT);
   }
  if (!empty){
  feature_svm[0] = AT_val;
  feature_svm[1] = LAT; 
  feature_svm[2] = slope;
  feature_svm[3] = STE/SAMPLES; 
  feature_svm[4] = zero_cross;
  feature_svm[5] = LoLAS;
  feature_svm[6] = LoHAS;  

  unsigned long start3 = micros();
  String y_pred = String(classifier.predictLabel(feature_svm));
  unsigned long end3 = micros();

  if (DEBUG ==1){
  Serial.print("Classification took  ");
  Serial.print((end3-start3));
  Serial.println("    µs");  
  Serial.print("Predicted class:   ");
  Serial.println(y_pred);
  }
  
  /*
  txtfile = SD.open((String(counter) + ".txt"), FILE_WRITE);
  txtfile.print("label  ");
  txtfile.print(y_pred);
  txtfile.print("; ");
  txtfile.print("exec_time  "); 
  txtfile.print(exec_time); 
  txtfile.print("; ");
  txtfile.print("timestamp  "); 
  txtfile.print(millis());
  txtfile.close();
  end3 = micros();
  
  Serial.print("Writing to file took  ");
  Serial.print((end3-start3));
  Serial.println("    µs");  
  
  start1 = micros();
  u8x8.setFont(u8x8_font_courB18_2x3_r);
  u8x8.setCursor(0, 0);
  u8x8.println(y_pred);*/
  //Serial.println(y_pred);
  if (y_pred== "step"){
    step_counter++;
  }
  if (y_pred== "clap"){
    clap_counter++;
  }
  if (y_pred== "knock"){
    knock_counter++;
  }
  if (y_pred== "noise"){
    noise_counter++;
  }
  }
  else{
  Serial.println("empty");    
  }/*
  end1 = micros();
  Serial.print("Printing on screen took ");
  Serial.print((end1-start1));
  Serial.println("    µs"); 
*/
  
    maxima = 0;
    start_attack = 0; 
    end_attack = 0; 
    max_index = 0; 
    sum_abs = 0;
    avg_abs = 0;
    AT_val          = 0;
    slope       = 0;
    zero_cross = 0;
    STE = 0; 
    LoHAS = 0; 
    LoLAS = 0;
    slope = 0;
    LAT = 0;
    record_ready = false; 

  }
  unsigned long end1 = micros();
  Serial.println("Execution time");
  Serial.println(end1-start1);
}


static void audio_rec_callback(uint16_t *buf, uint32_t buf_len) {

  static uint32_t idx = 0;

  if (recording) {
    for (uint32_t i = 0; i < buf_len; i++) {
      
      recording_buf[idx++] = buf[i]*20;

          
      if (idx >= SAMPLES){ 
      idx = 0;
      recording = 0;
      record_ready = true;
      break;
     } 
    }
  }
}
void AT(int16_t *recording_buf)
{
  //Serial.println("CALCULATING TIME FEATURES");
  for (uint i=0; i<SAMPLES; i++){
    //Serial.println(recording_buf[i]);
    STE += pow(recording_buf[i],2);
    
    //CALCULATING ZERO CROSSING NUMBER 
    if ((recording_buf[i-1]<=0)&&(recording_buf[i]>0)){
      zero_cross +=1;
    }
    if ((recording_buf[i-1]>=0)&&(recording_buf[i]<0)){
      zero_cross +=1;
    }


    //    LOOKING FOR MAX VALUE 
    if (recording_buf[i] > maxima){
      maxima = recording_buf[i];     
      max_index = i;
      //threshold = maxima*0.05;
      }

    if (abs(recording_buf[i])> 80){
        
      LoHAS +=1; 

    }
    else{
      LoLAS +=1;       
    }
  }
 
  
  if (STE > 70000000){
    empty = false;
    //        ATTACK TIME IMPLEMENTATION     
    if (max_index>interval){
      for (uint k =(max_index-interval); k<=(max_index); k+=10){
        for (uint i = (k-5); i<(k+5); i++){
        
        sum_abs += abs(recording_buf[i]);  
        }
        avg_abs = (sum_abs/10);
        sum_abs = 0;

        if (avg_abs < 0.15*maxima){
          start_attack = k; 
            }
        avg_abs = 0;
        
      }
     }
    else{
      for (uint k =0; k<=(max_index); k+=10){
        for (uint i = (k-5); i<(k+5); i++){
        
        sum_abs += abs(recording_buf[i]);  
        }
        avg_abs = (sum_abs/10);
        sum_abs = 0;

        if (avg_abs < (0.15*maxima)){
          start_attack = k; 
            }
        avg_abs = 0;
      }
     }
     slope = (((maxima - recording_buf[start_attack])*1000)/(max_index-start_attack));
     AT_val= (max_index - start_attack);
     LAT = log10(AT_val);
     
  }
  else{
  empty = true;
  }
}
void blePeripheralConnectHandler(BLEDevice central) {
  // central connected event handler
  Serial.print("Connected event, central: ");
  Serial.println(central.address());
}

void blePeripheralDisconnectHandler(BLEDevice central) {
  // central disconnected event handler
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
}

void rpiCommandsWritten(BLEDevice central, BLECharacteristic characteristic) {
  // central wrote new value to characteristic, update LED
  Serial.print("Characteristic event, written: ");

  Serial.println("len=" + 
                  String(rpiCommands.valueLength()));
  Serial.println(rpiCommands.value()); 
  
  if (rpiCommands.value() == "get") {
    
    Serial.println("got command from pi");
    String response = String(step_counter);
    response += ";"; 
    response += String(clap_counter); 
    response += ";"; 
    response += String(knock_counter); 
    response += ";"; 
    response += String(noise_counter);
    Serial.println(response);
    counters.setValue(response);
    step_counter = 0;
    knock_counter =0;
    noise_counter= 0;
    clap_counter =0;
    delay(1500);
  }
}
