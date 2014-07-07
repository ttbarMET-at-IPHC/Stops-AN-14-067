//prediction total yield for the different SR
//first value = yield
//second vlaue = uncertainty

pair<double,double> Pred_cutAndCount_T2tt_offShellLoose()         { return pair<double,double>(48.1101,8.3111 ); }
pair<double,double> Pred_cutAndCount_T2tt_offShellTight()         { return pair<double,double>(16.7876,3.5236 ); }
pair<double,double> Pred_cutAndCount_T2tt_lowDeltaM()             { return pair<double,double>(358.625,80.7227); }
pair<double,double> Pred_cutAndCount_T2tt_mediumDeltaM()          { return pair<double,double>(16.0243,6.0595 ); }
pair<double,double> Pred_cutAndCount_T2tt_highDeltaM()            { return pair<double,double>(2.5033 ,0.9448 ); }
pair<double,double> Pred_cutAndCount_T2bw025_veryOffShell_loose() { return pair<double,double>(25.617 ,4.6451 ); }
pair<double,double> Pred_cutAndCount_T2bw025_offShell_loose()     { return pair<double,double>(16.1526,3.098  ); }
pair<double,double> Pred_cutAndCount_T2bw025_lowDeltaM_tight()    { return pair<double,double>(14.0656,2.5857 ); }
pair<double,double> Pred_cutAndCount_T2bw025_highDeltaM()         { return pair<double,double>(3.1555 ,1.0451 ); }
pair<double,double> Pred_cutAndCount_T2bw050_offShell_loose()     { return pair<double,double>(25.617 ,4.6451 ); }
pair<double,double> Pred_cutAndCount_T2bw050_lowMass()            { return pair<double,double>(47.084 ,7.8155 ); }
pair<double,double> Pred_cutAndCount_T2bw050_mediumDeltaM_loose() { return pair<double,double>(9.9766 ,2.3078 ); }
pair<double,double> Pred_cutAndCount_T2bw050_highDeltaM()         { return pair<double,double>(2.4413 ,0.8501 ); }
pair<double,double> Pred_cutAndCount_T2bw075_lowDeltaM_tight()    { return pair<double,double>(7.5097 ,1.8561 ); }
pair<double,double> Pred_cutAndCount_T2bw075_mediumDeltaM()       { return pair<double,double>(35.7962,8.3931 ); }
pair<double,double> Pred_cutAndCount_T2bw075_highDeltaM()         { return pair<double,double>(3.3587 ,0.9881 ); }
pair<double,double> Pred_BDT_T2tt_1()                             { return pair<double,double>(38.4453,8.7745 ); }
pair<double,double> Pred_BDT_T2tt_2()                             { return pair<double,double>(38.331 ,8.1962 ); }
pair<double,double> Pred_BDT_T2tt_5_loose()                       { return pair<double,double>(16.0994,4.537  ); }
pair<double,double> Pred_BDT_T2tt_5_tight()                       { return pair<double,double>(4.9319 ,2.0099 ); }
pair<double,double> Pred_BDT_T2bw075_1()                          { return pair<double,double>(10.616 ,3.7794 ); }
pair<double,double> Pred_BDT_T2bw075_2()                          { return pair<double,double>(23.2888,6.7232 ); }
pair<double,double> Pred_BDT_T2bw075_3()                          { return pair<double,double>(5.9687 ,2.6584 ); }
pair<double,double> Pred_BDT_T2bw075_5()                          { return pair<double,double>(15.2831,4.32   ); }
pair<double,double> Pred_BDT_T2bw050_1_loose()                    { return pair<double,double>(81.6085,14.5565); }
pair<double,double> Pred_BDT_T2bw050_1_tight()                    { return pair<double,double>(14.7944,3.7032 ); }
pair<double,double> Pred_BDT_T2bw050_3()                          { return pair<double,double>(8.3554 ,2.4705 ); }
pair<double,double> Pred_BDT_T2bw050_4()                          { return pair<double,double>(1.4885 ,1.2307 ); }
pair<double,double> Pred_BDT_T2bw050_5()                          { return pair<double,double>(4.6252 ,1.7233 ); }
pair<double,double> Pred_BDT_T2bw050_6()                          { return pair<double,double>(3.2662 ,1.3211 ); }
pair<double,double> Pred_BDT_T2bw025_1()                          { return pair<double,double>(38.2686,5.8624 ); }
pair<double,double> Pred_BDT_T2bw025_3()                          { return pair<double,double>(3.0298 ,1.3844 ); }
pair<double,double> Pred_BDT_T2bw025_4()                          { return pair<double,double>(5.0316 ,1.571  ); }
pair<double,double> Pred_BDT_T2bw025_6()                          { return pair<double,double>(5.7326 ,1.6911 ); }

pair<double,double> Pred_BDT_T2tt_1(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
        return pair<double,double>( 4126.59 , 313.31);
    if (BDTcutOffset == -0.30)
        return pair<double,double>( 2369.72 , 186.71);
    if (BDTcutOffset == -0.20)
        return pair<double,double>( 1212.70, 103.46);
    if (BDTcutOffset == -0.20)
        return pair<double,double>( 625.98 , 59.25 );
    if (BDTcutOffset == -0.15)
        return pair<double,double>( 323.00 , 37.03 );
    if (BDTcutOffset == -0.10)
        return pair<double,double>( 175.48 , 22.84 );
    if (BDTcutOffset == -0.05)
        return pair<double,double>( 92.27 , 15.98);
    if (BDTcutOffset == 0.0)
        return pair<double,double>( 38.45 , 8.77 );
    if (BDTcutOffset == 0.05)
        return pair<double,double>( 17.58 , 5.34 );
    if (BDTcutOffset == 0.10)
        return pair<double,double>( 6.58 , 2.55 );
    if (BDTcutOffset == 0.15)
        return pair<double,double>( 3.08 , 2.44 );
    if (BDTcutOffset == 0.20)
        return pair<double,double>( 2.04 , 2.26 );

    else return pair<double,double>( -999 , -999 );

}





pair<double,double> Pred_BDT_T2tt_2(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
        return pair<double,double>( 3404.90 , 206.66 );
    if (BDTcutOffset == -0.30)
        return pair<double,double>( 2194.66 , 141.72 );
    if (BDTcutOffset == -0.25)
        return pair<double,double>( 1313.13, 97.99 );
    if (BDTcutOffset == -0.20)
        return pair<double,double>( 731.10 , 68.03 );
    if (BDTcutOffset == -0.15)
        return pair<double,double>( 378.11 , 45.59 );
    if (BDTcutOffset == -0.10)
        return pair<double,double>( 187.38 , 26.54 );
    if (BDTcutOffset == -0.05)
        return pair<double,double>( 91.42 , 15.18 );
    if (BDTcutOffset == 0.0)
        return pair<double,double>( 38.33 , 8.20	);
    if (BDTcutOffset == 0.05)
        return pair<double,double>( 17.92 , 4.80 );
    if (BDTcutOffset == 0.10)
        return pair<double,double>( 5.09 , 2.33 );
    if (BDTcutOffset == 0.15)
        return pair<double,double>( 1.09 , 1.02 );
    if (BDTcutOffset == 0.20)
        return pair<double,double>( 0.85 , 1.03 );

    else return pair<double,double>( -999 , -999 );

}

pair<double,double> Pred_BDT_T2tt_5_loose(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
        return pair<double,double>( 3251.22 , 195.41 );
    if (BDTcutOffset == -0.30)
        return pair<double,double>( 1690.08 , 131.73 );
    if (BDTcutOffset == -0.25)
        return pair<double,double>( 862.10 , 80.31 );
    if (BDTcutOffset == -0.20)
        return pair<double,double>( 360.92 , 40.14	);
    if (BDTcutOffset == -0.15)
        return pair<double,double>( 155.06 , 20.22	);
    if (BDTcutOffset == -0.10)
        return pair<double,double>( 75.13 , 11.62 );
    if (BDTcutOffset == -0.05)
        return pair<double,double>( 36.65 , 8.06 );
    if (BDTcutOffset == 0.0)
        return pair<double,double>( 16.10 , 4.54 );
    if (BDTcutOffset == 0.05)
        return pair<double,double>( 7.80 , 2.99 );
    if (BDTcutOffset == 0.10)
        return pair<double,double>( 3.05 , 1.48 );
    if (BDTcutOffset == 0.15)
        return pair<double,double>( 1.29 , 0.85 );
    if (BDTcutOffset == 0.20)
        return pair<double,double>( 1.07 , 0.85 );

    else return pair<double,double>( -999 , -999 );

}

pair<double,double> Pred_BDT_T2tt_5_tight(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
        return pair<double,double>( 1224.10 , 105.92 );
    if (BDTcutOffset == -0.30)
        return pair<double,double>( 565.05 , 59.93 );
    if (BDTcutOffset == -0.25)
        return pair<double,double>( 235.51 , 28.50 );
    if (BDTcutOffset == -0.20)
        return pair<double,double>( 110.93 , 15.11	);
    if (BDTcutOffset == -0.15)
        return pair<double,double>( 55.27 , 10.46 );
    if (BDTcutOffset == -0.10)
        return pair<double,double>( 24.79 , 6.36 );
    if (BDTcutOffset == -0.05)
        return pair<double,double>( 13.56 , 4.18 );
    if (BDTcutOffset == 0.0)
        return pair<double,double>( 4.93 , 2.01 );
    if (BDTcutOffset == 0.05)
        return pair<double,double>( 2.27 , 1.27 );
    if (BDTcutOffset == 0.10)
        return pair<double,double>( 1.41 , 1.04 );
    if (BDTcutOffset == 0.15)
        return pair<double,double>( 0.99 , 0.83 );
    if (BDTcutOffset == 0.20)
        return pair<double,double>( 0.28 , 0.28 );

    else return pair<double,double>( -999 , -999 );
}



