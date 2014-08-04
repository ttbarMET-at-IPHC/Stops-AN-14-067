/*
pair<double,double> backgroundPrediction_BDT_T2bw025_1                   (double BDTcutOffset = 0.0) { return pair<double,double>(129.5715,   26.3946  ); }
pair<double,double> backgroundPrediction_BDT_T2bw025_3_highDM            (double BDTcutOffset = 0.0) { return pair<double,double>(3.1555,     1.6466   ); }
pair<double,double> backgroundPrediction_BDT_T2bw025_3_lowDM             (double BDTcutOffset = 0.0) { return pair<double,double>(88.4375,    24.3092  ); }
pair<double,double> backgroundPrediction_BDT_T2bw025_4                   (double BDTcutOffset = 0.0) { return pair<double,double>(19.9847,    6.2634   ); }
pair<double,double> backgroundPrediction_BDT_T2bw025_6                   (double BDTcutOffset = 0.0) { return pair<double,double>(5.8498,     2.5183   ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_1_highDM            (double BDTcutOffset = 0.0) { return pair<double,double>(22.5160,    7.6761   ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_1_lowDM             (double BDTcutOffset = 0.0) { return pair<double,double>(91.2816,    26.7520  ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_3                   (double BDTcutOffset = 0.0) { return pair<double,double>(7.0636,     2.4887   ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_4                   (double BDTcutOffset = 0.0) { return pair<double,double>(0.7824,     0.3205   ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_5                   (double BDTcutOffset = 0.0) { return pair<double,double>(3.3373,     1.5419   ); }
pair<double,double> backgroundPrediction_BDT_T2bw050_6                   (double BDTcutOffset = 0.0) { return pair<double,double>(2.7323,     1.3394   ); }
pair<double,double> backgroundPrediction_BDT_T2tt_1                      (double BDTcutOffset = 0.0) { return pair<double,double>(101.0314,   29.4811  ); }
pair<double,double> backgroundPrediction_BDT_T2tt_2_highDM               (double BDTcutOffset = 0.0) { return pair<double,double>(16.0594,    5.0642   ); }
pair<double,double> backgroundPrediction_BDT_T2tt_2_lowDM                (double BDTcutOffset = 0.0) { return pair<double,double>(37.1207,    11.3233  ); }
pair<double,double> backgroundPrediction_BDT_T2tt_5_highDM               (double BDTcutOffset = 0.0) { return pair<double,double>(1.9454,     1.2176   ); }
pair<double,double> backgroundPrediction_BDT_T2tt_5_lowDM                (double BDTcutOffset = 0.0) { return pair<double,double>(2.3211,     1.3199   ); }
pair<double,double> backgroundPrediction_BDT_T2tt_5_mediumDM             (double BDTcutOffset = 0.0) { return pair<double,double>(3.6069,     2.0745   ); }
*/

pair<double,double> backgroundPrediction_BDT_T2bw025_1 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(1977.2456, 530.9258); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(876.8497, 211.8462); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(356.7234, 77.6266); } 
    if (BDTcutOffset == 0.0) { return pair<double,double>(129.5715, 26.3946); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(41.6493, 9.2321); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(13.9251, 3.8811); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(4.2083, 1.6940); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw025_3_lowDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(1343.9038, 375.5248); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(632.1891, 170.2068); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(256.9275, 66.8787); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(88.4375, 24.3092); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(28.6173, 8.0101); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(13.6138, 4.1820); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(3.1555, 1.6466); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw025_3_highDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(88.4375, 24.3092); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(28.6173, 8.0101); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(13.6138, 4.1820); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(3.1555, 1.6466); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(0.7127, 0.5427); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.2939, 0.2977); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.0166, 0.0163); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw025_4 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(965.7327, 336.7641); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(340.6452, 115.3445); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(97.5235, 30.3386); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(19.9847, 6.2634); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(4.9724, 1.9534); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(1.0875, 0.6634); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.3224, 0.3250); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw025_6 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(381.4061, 100.9967); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(122.1663, 30.4489); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(34.0219, 8.9863); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(5.8498, 2.5183); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(1.8374, 1.1951); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(2.1569, 2.4791); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.0052, 0.0058); }
    return pair<double,double>(-1.0,-1.0);
}



pair<double,double> backgroundPrediction_BDT_T2bw050_1_highDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(462.6539, 135.6267); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(166.7844, 48.7078); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(56.6031, 16.6445); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(22.5160, 7.6761); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(8.2416, 3.0677); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(4.6761, 2.1992); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(1.4140, 0.8858); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw050_1_lowDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(1831.1659, 555.2623); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(727.9721, 213.4308); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(283.2525, 82.1887); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(91.2816, 26.7520); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(37.1426, 11.5262); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(14.0526, 5.0428); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(6.0615, 2.4909); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw050_3 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(141.9949, 40.1270); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(60.8767, 17.7723); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(23.8821, 8.0204); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(7.0636, 2.4887); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(2.3890, 1.2983); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.2164, 0.1220); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.0957, 0.0620); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw050_4 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(123.1786, 32.9287); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(38.8240, 9.7451); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(9.1320, 3.1589); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(0.7824, 0.3205); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(0.3217, 0.1990); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.1465, 0.1900); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.0001, 0.0001); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw050_5 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(193.2236, 66.1133); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(64.3383, 20.9893); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(18.2323, 5.1464); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(3.3373, 1.5419); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(0.6466, 0.3705); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.2864, 0.2054); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.1418, 0.2676); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2bw050_6 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(227.3193, 68.5296); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(69.6256, 19.1175); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(20.7395, 5.9252); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(2.7323, 1.3394); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(0.4971, 0.3279); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.2226, 0.3330); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.0117, 0.0102); }
     return pair<double,double>(-1.0,-1.0);
}


pair<double,double> backgroundPrediction_BDT_T2tt_1 (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(687.9462, 200.0806); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(364.4019, 105.6631); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(190.8940, 55.5246); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(101.0314, 29.4811); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(46.4145, 14.6925); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(19.0522, 6.4119); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(9.2589, 3.5445); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2tt_2_highDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(197.5235, 55.7071); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(86.6212, 25.1847); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(37.1207, 11.3233); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(16.0594, 5.0642); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(4.1323, 1.7630); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(0.5650, 0.2808); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.3693, 0.3739); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2tt_2_lowDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(387.3758, 109.6903); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(197.5235, 55.7071); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(86.6212, 25.1847); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(37.1207, 11.3233); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(16.0594, 5.0642); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(4.1323, 1.7630); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.5650, 0.2808); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2tt_5_highDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(22.7557, 10.8570); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(11.8821, 5.5866); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(3.6069, 2.0745); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(1.9454, 1.2176); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(1.6889, 1.3680); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(1.4761, 1.3727); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(0.2938, 0.2771); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2tt_5_lowDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(32.5760, 15.3694); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(14.7107, 7.1694); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(5.7045, 3.0317); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(2.3211, 1.3199); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(1.3084, 1.0084); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(1.2942, 1.1604); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(1.2924, 1.2865); }
     return pair<double,double>(-1.0,-1.0);
}
pair<double,double> backgroundPrediction_BDT_T2tt_5_mediumDM (double BDTcutOffset = 0.0)
{
    if (BDTcutOffset == -0.15) { return pair<double,double>(53.7201, 24.7644); }
    if (BDTcutOffset == -0.10) { return pair<double,double>(22.7557, 10.8570); }
    if (BDTcutOffset == -0.05) { return pair<double,double>(11.8821, 5.5866); }
    if (BDTcutOffset == 0.0) { return pair<double,double>(3.6069, 2.0745); }
    if (BDTcutOffset == 0.05) { return pair<double,double>(1.9454, 1.2176); }
    if (BDTcutOffset == 0.10) { return pair<double,double>(1.6889, 1.3680); }
    if (BDTcutOffset == 0.15) { return pair<double,double>(1.4761, 1.3727); }
     return pair<double,double>(-1.0,-1.0);
}


pair<double,double> backgroundPrediction_BDT_T2bw075_1                   (double BDTcutOffset = 0.0) { return pair<double,double>(13.2689,    4.0458   ); }
pair<double,double> backgroundPrediction_BDT_T2bw075_2                   (double BDTcutOffset = 0.0) { return pair<double,double>(23.1362,    8.1749   ); }
pair<double,double> backgroundPrediction_BDT_T2bw075_3                   (double BDTcutOffset = 0.0) { return pair<double,double>(5.2028,     2.0296   ); }
pair<double,double> backgroundPrediction_BDT_T2bw075_5_highDM            (double BDTcutOffset = 0.0) { return pair<double,double>(0.3632,     0.2140   ); }
pair<double,double> backgroundPrediction_BDT_T2bw075_5_lowDM             (double BDTcutOffset = 0.0) { return pair<double,double>(2.2578,     1.1356   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw025_highMasses  () { return pair<double,double>(1.8211,     0.9338   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw025_lowMasses   () { return pair<double,double>(12.0031,    4.2772   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw025_offShell    () { return pair<double,double>(24.1765,    7.3290   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw050_highDeltaM  () { return pair<double,double>(2.5166,     1.1039   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw050_lowMasses   () { return pair<double,double>(97.0783,    14.3624  ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw050_mediumDeltaM() { return pair<double,double>(31.0122,    8.6789   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw050_offShell    () { return pair<double,double>(24.1765,    7.3290   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw075_highDeltaM  () { return pair<double,double>(5.1450,     2.0179   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw075_lowDeltaM   () { return pair<double,double>(5.2540,     2.2087   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2bw075_mediumDeltaM() { return pair<double,double>(34.0299,    6.9528   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2tt_highDeltaM     () { return pair<double,double>(3.4188,     1.4003   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2tt_lowDeltaM      () { return pair<double,double>(178.8980,   21.3484  ); }
pair<double,double> backgroundPrediction_cutAndCount_T2tt_mediumDeltaM   () { return pair<double,double>(10.6587,    2.5934   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2tt_offShellLoose  () { return pair<double,double>(38.5279,    8.3234   ); }
pair<double,double> backgroundPrediction_cutAndCount_T2tt_offShellTight  () { return pair<double,double>(11.3975,    4.3959   ); }
pair<double,double> backgroundPrediction_preselection                    () { return pair<double,double>(9940.2217,  1664.9653); }

