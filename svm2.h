#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[153] = { 0 };
                        float decisions[6] = { 0 };
                        int votes[4] = { 0 };
                        kernels[0] = compute_kernel(x,   1.361727836018  , 222654.3181046196  , 900.0  , 7397.0 );
                        kernels[1] = compute_kernel(x,   2.123851640967  , 8188.969432859492  , 805.0  , 6706.0 );
                        kernels[2] = compute_kernel(x,   1.50514997832  , 56756.927490234375  , 1122.0  , 7509.0 );
                        kernels[3] = compute_kernel(x,   1.462397997899  , 172296.8918372845  , 1006.0  , 7191.0 );
                        kernels[4] = compute_kernel(x,   1.531478917042  , 490324.5634191177  , 1021.0  , 6178.0 );
                        kernels[5] = compute_kernel(x,   1.462397997899  , 121135.3549299569  , 1021.0  , 6510.0 );
                        kernels[6] = compute_kernel(x,   2.484299839347  , 3354.507796490778  , 878.0  , 6282.0 );
                        kernels[7] = compute_kernel(x,   1.653212513775  , 173887.890625  , 1163.0  , 8114.0 );
                        kernels[8] = compute_kernel(x,   2.245512667814  , 13433.45780806108  , 939.0  , 7114.0 );
                        kernels[9] = compute_kernel(x,   2.537819095073  , 1782.826299252718  , 813.0  , 5868.0 );
                        kernels[10] = compute_kernel(x,   1.681241237376  , 487259.6435546875  , 828.0  , 11742.0 );
                        kernels[11] = compute_kernel(x,   2.466867620354  , 70282.28322312287  , 795.0  , 12388.0 );
                        kernels[12] = compute_kernel(x,   1.690196080029  , 263629.2649872449  , 683.0  , 11694.0 );
                        kernels[13] = compute_kernel(x,   1.672097857936  , 314351.99883643625  , 739.0  , 11686.0 );
                        kernels[14] = compute_kernel(x,   2.651278013998  , 34998.03815569197  , 778.0  , 12371.0 );
                        kernels[15] = compute_kernel(x,   1.681241237376  , 342299.2757161458  , 758.0  , 11645.0 );
                        kernels[16] = compute_kernel(x,   1.672097857936  , 378983.9178856383  , 807.0  , 11606.0 );
                        kernels[17] = compute_kernel(x,   2.403120521176  , 89823.47764328064  , 845.0  , 12389.0 );
                        kernels[18] = compute_kernel(x,   2.064457989227  , 164049.63631465516  , 764.0  , 11704.0 );
                        kernels[19] = compute_kernel(x,   1.770852011642  , 257535.3879766949  , 766.0  , 11746.0 );
                        kernels[20] = compute_kernel(x,   1.690196080029  , 363639.42920918367  , 761.0  , 11661.0 );
                        kernels[21] = compute_kernel(x,   1.672097857936  , 446724.3600398936  , 741.0  , 11786.0 );
                        kernels[22] = compute_kernel(x,   2.338456493605  , 72861.7133744266  , 595.0  , 12490.0 );
                        kernels[23] = compute_kernel(x,   1.672097857936  , 478198.4291888298  , 858.0  , 11666.0 );
                        kernels[24] = compute_kernel(x,   2.509202522331  , 76695.5725135449  , 882.0  , 12354.0 );
                        kernels[25] = compute_kernel(x,   1.623249290398  , 571545.7124255953  , 730.0  , 12405.0 );
                        kernels[26] = compute_kernel(x,   1.672097857936  , 521200.0083111702  , 697.0  , 11874.0 );
                        kernels[27] = compute_kernel(x,   1.681241237376  , 141538.1062825521  , 891.0  , 7560.0 );
                        kernels[28] = compute_kernel(x,   2.326335860929  , 110092.16538915096  , 870.0  , 12381.0 );
                        kernels[29] = compute_kernel(x,   1.662757831682  , 131668.24473505435  , 1022.0  , 6611.0 );
                        kernels[30] = compute_kernel(x,   1.672097857936  , 431958.7350398936  , 749.0  , 11697.0 );
                        kernels[31] = compute_kernel(x,   1.690196080029  , 320777.94164540817  , 904.0  , 11386.0 );
                        kernels[32] = compute_kernel(x,   1.681241237376  , 47526.631673177086  , 767.0  , 6583.0 );
                        kernels[33] = compute_kernel(x,   1.672097857936  , 523531.4162234042  , 854.0  , 11688.0 );
                        kernels[34] = compute_kernel(x,   2.399673721481  , 56213.155191733065  , 702.0  , 12421.0 );
                        kernels[35] = compute_kernel(x,   1.954242509439  , 263309.13628472225  , 870.0  , 12318.0 );
                        kernels[36] = compute_kernel(x,   1.681241237376  , 423847.37141927076  , 815.0  , 11676.0 );
                        kernels[37] = compute_kernel(x,   2.61066016309  , 47043.38522518383  , 712.0  , 12404.0 );
                        kernels[38] = compute_kernel(x,   1.690196080029  , 403395.0494260204  , 764.0  , 11737.0 );
                        kernels[39] = compute_kernel(x,   1.959041392321  , 221606.3701923077  , 623.0  , 12449.0 );
                        kernels[40] = compute_kernel(x,   2.611723308007  , 57982.60333893643  , 765.0  , 12374.0 );
                        kernels[41] = compute_kernel(x,   1.785329835011  , 51301.3415727459  , 891.0  , 6503.0 );
                        kernels[42] = compute_kernel(x,   1.681241237376  , 99324.62565104169  , 959.0  , 6403.0 );
                        kernels[43] = compute_kernel(x,   1.681241237376  , 321753.7027994792  , 804.0  , 11726.0 );
                        kernels[44] = compute_kernel(x,   2.397940008672  , 102366.3984375  , 724.0  , 12433.0 );
                        kernels[45] = compute_kernel(x,   1.838849090737  , 33873.697916666664  , 865.0  , 6120.0 );
                        kernels[46] = compute_kernel(x,   2.356025857193  , 77488.80609856828  , 714.0  , 12409.0 );
                        kernels[47] = compute_kernel(x,   1.672097857936  , 89074.69664228724  , 892.0  , 6877.0 );
                        kernels[48] = compute_kernel(x,   2.338456493605  , 75131.30733944956  , 745.0  , 12370.0 );
                        kernels[49] = compute_kernel(x,   1.662757831682  , 117992.66516644023  , 886.0  , 6939.0 );
                        kernels[50] = compute_kernel(x,   1.681241237376  , 48047.53112792969  , 836.0  , 6313.0 );
                        kernels[51] = compute_kernel(x,   1.681241237376  , 79051.31530761719  , 849.0  , 6478.0 );
                        kernels[52] = compute_kernel(x,   2.225309281726  , 103483.49144345238  , 696.0  , 12454.0 );
                        kernels[53] = compute_kernel(x,   1.643452676486  , 307874.73366477276  , 636.0  , 12428.0 );
                        kernels[54] = compute_kernel(x,   1.681241237376  , 64570.38370768229  , 736.0  , 7330.0 );
                        kernels[55] = compute_kernel(x,   1.690196080029  , 42107.18271683674  , 603.0  , 7291.0 );
                        kernels[56] = compute_kernel(x,   1.690196080029  , 377553.8504464286  , 560.0  , 12038.0 );
                        kernels[57] = compute_kernel(x,   1.672097857936  , 424964.5113031915  , 732.0  , 11762.0 );
                        kernels[58] = compute_kernel(x,   1.732393759823  , 252183.4309895833  , 669.0  , 11724.0 );
                        kernels[59] = compute_kernel(x,   1.681241237376  , 319724.5076497396  , 701.0  , 11816.0 );
                        kernels[60] = compute_kernel(x,   1.690196080029  , 297794.2243303573  , 729.0  , 11668.0 );
                        kernels[61] = compute_kernel(x,   1.672097857936  , 71625.7635887633  , 769.0  , 6730.0 );
                        kernels[62] = compute_kernel(x,   2.164352855784  , 122582.59310787672  , 867.0  , 12308.0 );
                        kernels[63] = compute_kernel(x,   1.681241237376  , 436402.9947916667  , 873.0  , 11499.0 );
                        kernels[64] = compute_kernel(x,   2.518513939878  , 88614.14535984848  , 676.0  , 12471.0 );
                        kernels[65] = compute_kernel(x,   2.465382851448  , 70756.68209546233  , 723.0  , 12427.0 );
                        kernels[66] = compute_kernel(x,   2.143014800254  , 12864.879580710432  , 792.0  , 11564.0 );
                        kernels[67] = compute_kernel(x,   2.033423755487  , 81296.95638020834  , 921.0  , 11710.0 );
                        kernels[68] = compute_kernel(x,   1.301029995664  , 152968.6767578125  , 1114.0  , 11635.0 );
                        kernels[69] = compute_kernel(x,   1.690196080029  , 47475.18235809949  , 858.0  , 11822.0 );
                        kernels[70] = compute_kernel(x,   2.41995574849  , 8050.411790042775  , 919.0  , 11445.0 );
                        kernels[71] = compute_kernel(x,   1.716003343635  , 46524.91173377404  , 728.0  , 11630.0 );
                        kernels[72] = compute_kernel(x,   1.361727836018  , 106795.64368206522  , 658.0  , 11663.0 );
                        kernels[73] = compute_kernel(x,   2.173186268412  , 22217.47522546141  , 738.0  , 11698.0 );
                        kernels[74] = compute_kernel(x,   1.54406804435  , 90125.28599330357  , 468.0  , 12038.0 );
                        kernels[75] = compute_kernel(x,   1.653212513775  , 63252.17013888889  , 581.0  , 11867.0 );
                        kernels[76] = compute_kernel(x,   1.995635194598  , 27720.555160984848  , 589.0  , 11814.0 );
                        kernels[77] = compute_kernel(x,   1.623249290398  , 81771.88546316964  , 764.0  , 11652.0 );
                        kernels[78] = compute_kernel(x,   1.662757831682  , 57637.47240149457  , 789.0  , 11462.0 );
                        kernels[79] = compute_kernel(x,   1.939519252619  , 46017.11229346264  , 637.0  , 12011.0 );
                        kernels[80] = compute_kernel(x,   2.136720567156  , 14717.12477189781  , 1049.0  , 11023.0 );
                        kernels[81] = compute_kernel(x,   1.462397997899  , 129050.2340382543  , 769.0  , 11618.0 );
                        kernels[82] = compute_kernel(x,   2.232996110392  , 14879.009046052632  , 798.0  , 11807.0 );
                        kernels[83] = compute_kernel(x,   1.812913356643  , 58607.155198317305  , 855.0  , 11666.0 );
                        kernels[84] = compute_kernel(x,   1.949390006645  , 33015.26564694523  , 619.0  , 11930.0 );
                        kernels[85] = compute_kernel(x,   1.724275869601  , 493588.5170990566  , 492.0  , 12279.0 );
                        kernels[86] = compute_kernel(x,   2.411619705963  , 13641.200339147286  , 904.0  , 11841.0 );
                        kernels[87] = compute_kernel(x,   2.292256071356  , 12231.084084024234  , 725.0  , 11636.0 );
                        kernels[88] = compute_kernel(x,   2.238046103129  , 14816.838082550576  , 732.0  , 11744.0 );
                        kernels[89] = compute_kernel(x,   1.838849090737  , 208348.0100769928  , 665.0  , 11960.0 );
                        kernels[90] = compute_kernel(x,   1.079181246048  , 572718.994140625  , 1022.0  , 9711.0 );
                        kernels[91] = compute_kernel(x,   1.949390006645  , 152010.4130091292  , 765.0  , 11939.0 );
                        kernels[92] = compute_kernel(x,   2.037426497941  , 101028.49949827982  , 674.0  , 12003.0 );
                        kernels[93] = compute_kernel(x,   2.348304863048  , 27284.089913817264  , 707.0  , 11963.0 );
                        kernels[94] = compute_kernel(x,   1.698970004336  , 178865.2734375  , 877.0  , 11993.0 );
                        kernels[95] = compute_kernel(x,   1.819543935542  , 201604.66974431815  , 728.0  , 12106.0 );
                        kernels[96] = compute_kernel(x,   1.690196080029  , 230606.0467155612  , 679.0  , 12231.0 );
                        kernels[97] = compute_kernel(x,   1.799340549454  , 73434.74082341269  , 680.0  , 11942.0 );
                        kernels[98] = compute_kernel(x,   1.869231719731  , 99141.11987964528  , 637.0  , 12085.0 );
                        kernels[99] = compute_kernel(x,   1.845098040014  , 151449.37220982142  , 697.0  , 12070.0 );
                        kernels[100] = compute_kernel(x,   1.845098040014  , 310204.2410714286  , 677.0  , 12165.0 );
                        kernels[101] = compute_kernel(x,   1.361727836018  , 628585.3430706521  , 817.0  , 11942.0 );
                        kernels[102] = compute_kernel(x,   1.806179973984  , 308875.54931640625  , 638.0  , 12105.0 );
                        kernels[103] = compute_kernel(x,   1.763427993563  , 140151.0220231681  , 802.0  , 11877.0 );
                        kernels[104] = compute_kernel(x,   2.423245873937  , 20377.990492334902  , 697.0  , 11950.0 );
                        kernels[105] = compute_kernel(x,   1.875061263392  , 333844.21875  , 848.0  , 11997.0 );
                        kernels[106] = compute_kernel(x,   1.832508912706  , 177633.96139705885  , 710.0  , 11973.0 );
                        kernels[107] = compute_kernel(x,   1.50514997832  , 200826.3702392578  , 771.0  , 11885.0 );
                        kernels[108] = compute_kernel(x,   2.724275869601  , 6008.895010318396  , 745.0  , 11908.0 );
                        kernels[109] = compute_kernel(x,   2.086359830675  , 55813.62464779713  , 701.0  , 12069.0 );
                        kernels[110] = compute_kernel(x,   1.857332496431  , 151476.6845703125  , 698.0  , 12052.0 );
                        kernels[111] = compute_kernel(x,   2.365487984891  , 31453.040813577587  , 732.0  , 12060.0 );
                        kernels[112] = compute_kernel(x,   1.875061263392  , 107925.4296875  , 357.0  , 12394.0 );
                        kernels[113] = compute_kernel(x,   1.672097857936  , 247712.1633976064  , 1044.0  , 9807.0 );
                        kernels[114] = compute_kernel(x,   1.518513939878  , 121188.45436789774  , 770.0  , 11873.0 );
                        kernels[115] = compute_kernel(x,   1.778151250384  , 180820.10091145837  , 621.0  , 12114.0 );
                        kernels[116] = compute_kernel(x,   2.43775056282  , 15411.385863366788  , 985.0  , 12052.0 );
                        kernels[117] = compute_kernel(x,   1.819543935542  , 171505.53385416666  , 810.0  , 11988.0 );
                        kernels[118] = compute_kernel(x,   2.176091259056  , 26118.45703125  , 697.0  , 12003.0 );
                        kernels[119] = compute_kernel(x,   1.949390006645  , 178916.54231039327  , 759.0  , 11946.0 );
                        kernels[120] = compute_kernel(x,   1.724275869601  , 189821.9892393868  , 730.0  , 12078.0 );
                        kernels[121] = compute_kernel(x,   1.806179973984  , 156028.6102294922  , 726.0  , 11959.0 );
                        kernels[122] = compute_kernel(x,   1.812913356643  , 228813.23617788465  , 663.0  , 11934.0 );
                        kernels[123] = compute_kernel(x,   1.770852011642  , 309699.4504766949  , 800.0  , 11946.0 );
                        kernels[124] = compute_kernel(x,   1.826074802701  , 203793.62465018657  , 783.0  , 9896.0 );
                        kernels[125] = compute_kernel(x,   2.292256071356  , 17619.902941645407  , 795.0  , 11897.0 );
                        kernels[126] = compute_kernel(x,   1.832508912706  , 217513.21231617648  , 719.0  , 12101.0 );
                        kernels[127] = compute_kernel(x,   1.278753600953  , 410509.3544407895  , 1147.0  , 8961.0 );
                        kernels[128] = compute_kernel(x,   1.903089986992  , 161431.55517578125  , 755.0  , 10088.0 );
                        kernels[129] = compute_kernel(x,   1.778151250384  , 107378.90625  , 662.0  , 12058.0 );
                        kernels[130] = compute_kernel(x,   1.623249290398  , 187183.22172619047  , 897.0  , 9668.0 );
                        kernels[131] = compute_kernel(x,   2.225309281726  , 35473.99030412947  , 705.0  , 11987.0 );
                        kernels[132] = compute_kernel(x,   1.89209460269  , 101499.8560196314  , 665.0  , 12047.0 );
                        kernels[133] = compute_kernel(x,   1.342422680822  , 92595.23703835226  , 706.0  , 9811.0 );
                        kernels[134] = compute_kernel(x,   1.880813592281  , 251811.72902960525  , 776.0  , 11926.0 );
                        kernels[135] = compute_kernel(x,   1.819543935542  , 129086.69211647728  , 772.0  , 11911.0 );
                        kernels[136] = compute_kernel(x,   1.89209460269  , 129107.68479567308  , 779.0  , 11991.0 );
                        kernels[137] = compute_kernel(x,   1.851258348719  , 146130.48800616196  , 760.0  , 12040.0 );
                        kernels[138] = compute_kernel(x,   1.949390006645  , 76907.01259655898  , 804.0  , 11970.0 );
                        kernels[139] = compute_kernel(x,   1.812913356643  , 228312.0042067308  , 768.0  , 11993.0 );
                        kernels[140] = compute_kernel(x,   1.681241237376  , 162391.91691080728  , 836.0  , 11905.0 );
                        kernels[141] = compute_kernel(x,   2.060697840354  , 74580.32438858696  , 781.0  , 11818.0 );
                        kernels[142] = compute_kernel(x,   2.348304863048  , 17422.370944857063  , 763.0  , 11914.0 );
                        kernels[143] = compute_kernel(x,   1.770852011642  , 27877.72278866525  , 964.0  , 8631.0 );
                        kernels[144] = compute_kernel(x,   1.875061263392  , 10489.938151041666  , 786.0  , 9297.0 );
                        kernels[145] = compute_kernel(x,   2.255272505103  , 57968.16948784722  , 721.0  , 12087.0 );
                        kernels[146] = compute_kernel(x,   1.380211241712  , 356345.947265625  , 627.0  , 12049.0 );
                        kernels[147] = compute_kernel(x,   1.792391689498  , 205887.3802923387  , 819.0  , 12026.0 );
                        kernels[148] = compute_kernel(x,   1.832508912706  , 349997.55859375  , 721.0  , 11922.0 );
                        kernels[149] = compute_kernel(x,   1.869231719731  , 154095.54476351355  , 573.0  , 12093.0 );
                        kernels[150] = compute_kernel(x,   1.63346845558  , 62390.51144622093  , 1023.0  , 8994.0 );
                        kernels[151] = compute_kernel(x,   1.47712125472  , 462547.85156249994  , 1025.0  , 9621.0 );
                        kernels[152] = compute_kernel(x,   2.450249108319  , 16087.918328900709  , 750.0  , 11889.0 );
                        decisions[0] = 6614.119599223011
                        + kernels[0]
                        + kernels[1]
                        + kernels[2] * 0.274665989486
                        + kernels[3] * 0.150247533655
                        + kernels[4] * 0.428187397139
                        + kernels[5]
                        + kernels[6]
                        + kernels[8]
                        + kernels[9]
                        - kernels[27]
                        - kernels[29]
                        - kernels[41]
                        - kernels[42]
                        + kernels[45] * -0.774041297427
                        - kernels[47]
                        + kernels[50] * -0.079059622805
                        - kernels[51]
                        ;
                        decisions[1] = 5.49199987923
                        + kernels[7] * 1.79228e-07
                        + kernels[80] * -1.19658e-07
                        + kernels[85] * -5.957e-08
                        ;
                        decisions[2] = 24.244013525865
                        + kernels[7] * 4.665108e-06
                        + kernels[127] * -1.780174e-06
                        + kernels[143] * -2.884934e-06
                        ;
                        decisions[3] = 1456.294204662853
                        + kernels[10] * 0.600801767108
                        + kernels[14]
                        + kernels[25] * 0.45582859707
                        + kernels[34]
                        + kernels[37]
                        + kernels[40]
                        + kernels[46]
                        + kernels[55] * 0.911183671152
                        + kernels[59] * 0.756023724316
                        + kernels[62]
                        - kernels[67]
                        - kernels[68]
                        - kernels[72]
                        + kernels[74] * -0.698255861984
                        - kernels[75]
                        - kernels[77]
                        - kernels[78]
                        + kernels[80] * -0.02558189765
                        - kernels[81]
                        - kernels[85]
                        ;
                        decisions[4] = 57005.08679833382
                        + kernels[11]
                        + kernels[12]
                        + kernels[13]
                        + kernels[14]
                        + kernels[15]
                        + kernels[16]
                        + kernels[17]
                        + kernels[18]
                        + kernels[19]
                        + kernels[20] * 0.883459254341
                        + kernels[21]
                        + kernels[22]
                        + kernels[23] * 0.269626973407
                        + kernels[24]
                        + kernels[26]
                        + kernels[28]
                        + kernels[30]
                        + kernels[31]
                        + kernels[32] * 0.3453409164
                        + kernels[33]
                        + kernels[34]
                        + kernels[35]
                        + kernels[36]
                        + kernels[37]
                        + kernels[38]
                        + kernels[39]
                        + kernels[40]
                        + kernels[43]
                        + kernels[44]
                        + kernels[46]
                        + kernels[47] * 0.497652756163
                        + kernels[48]
                        + kernels[49]
                        + kernels[52]
                        + kernels[53]
                        + kernels[54]
                        + kernels[56]
                        + kernels[57]
                        + kernels[58]
                        + kernels[60]
                        + kernels[61]
                        + kernels[62]
                        + kernels[63]
                        + kernels[64]
                        + kernels[65]
                        - kernels[89]
                        - kernels[90]
                        - kernels[91]
                        - kernels[92]
                        - kernels[94]
                        - kernels[95]
                        - kernels[96]
                        - kernels[100]
                        - kernels[101]
                        - kernels[102]
                        - kernels[103]
                        - kernels[105]
                        - kernels[106]
                        - kernels[107]
                        - kernels[110]
                        - kernels[112]
                        - kernels[113]
                        + kernels[114] * -0.996079900327
                        - kernels[115]
                        - kernels[117]
                        - kernels[119]
                        - kernels[120]
                        - kernels[121]
                        - kernels[122]
                        - kernels[123]
                        - kernels[124]
                        - kernels[126]
                        - kernels[127]
                        - kernels[128]
                        - kernels[129]
                        - kernels[130]
                        - kernels[132]
                        - kernels[133]
                        - kernels[134]
                        - kernels[136]
                        - kernels[137]
                        - kernels[139]
                        - kernels[140]
                        - kernels[146]
                        - kernels[147]
                        - kernels[148]
                        - kernels[149]
                        - kernels[151]
                        ;
                        decisions[5] = -788.244695651944
                        + kernels[66]
                        + kernels[67]
                        + kernels[69]
                        + kernels[70]
                        + kernels[71]
                        + kernels[72]
                        + kernels[73]
                        + kernels[74]
                        + kernels[75]
                        + kernels[76]
                        + kernels[77]
                        + kernels[78]
                        + kernels[79]
                        + kernels[80]
                        + kernels[81]
                        + kernels[82]
                        + kernels[83]
                        + kernels[84]
                        + kernels[85]
                        + kernels[86]
                        + kernels[87]
                        + kernels[88] * 0.270457457405
                        - kernels[93]
                        + kernels[94] * -0.72429172165
                        - kernels[97]
                        - kernels[98]
                        - kernels[99]
                        - kernels[100]
                        - kernels[104]
                        - kernels[108]
                        - kernels[109]
                        - kernels[111]
                        + kernels[112] * -0.304890874548
                        + kernels[116] * -0.24127486117
                        - kernels[118]
                        - kernels[125]
                        - kernels[131]
                        - kernels[135]
                        - kernels[138]
                        - kernels[141]
                        - kernels[142]
                        - kernels[144]
                        - kernels[145]
                        - kernels[150]
                        - kernels[152]
                        ;
                        votes[decisions[0] > 0 ? 0 : 1] += 1;
                        votes[decisions[1] > 0 ? 0 : 2] += 1;
                        votes[decisions[2] > 0 ? 0 : 3] += 1;
                        votes[decisions[3] > 0 ? 1 : 2] += 1;
                        votes[decisions[4] > 0 ? 1 : 3] += 1;
                        votes[decisions[5] > 0 ? 2 : 3] += 1;
                        int val = votes[0];
                        int idx = 0;

                        for (int i = 1; i < 4; i++) {
                            if (votes[i] > val) {
                                val = votes[i];
                                idx = i;
                            }
                        }

                        return idx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "clap";
                            case 1:
                            return "knock";
                            case 2:
                            return "noise";
                            case 3:
                            return "step";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: linear
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 4);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 4; i++) {
                            kernel += x[i] * va_arg(w, double);
                        }

                        return kernel;
                    }
                };
            }
        }
    }