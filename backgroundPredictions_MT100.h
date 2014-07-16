//prediction total yield for the different SR
//first value = yield
//second vlaue = uncertainty



pair<double,double> Pred_BDT_T2bw025_1(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 8595.60 , 486.27);
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 5976.89 , 352.57);
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 3439.61 , 203.30);
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 1795.03 , 114.61);
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 826.10 , 58.99 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 325.27 , 28.53 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 125.88 , 13.73 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 38.27 , 5.86);
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 13.03 , 3.00);
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 4.13 , 1.30);
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 1.59 , 0.96);
    if (BDTcutOffset == 0.20)
return std::pair<double,double>( 2.04 , 2.26);

    else return pair<double,double>( -999 , -999 );

}

pair<double,double> Pred_BDT_T2bw025_3(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 2467.92 , 155.00);
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 1247.15 , 89.91 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 567.47 , 42.59  );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 212.57 , 17.85 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 69.43 , 7.88  );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 23.61 , 4.09 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 10.56 , 2.80);
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 3.03 , 1.38 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.64 , 1.11);
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.31 , 0.28);
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.08 , 0.11);
    if (BDTcutOffset == 0.20)
return std::pair<double,double>( 0.85 , 1.03);

    else return pair<double,double>( -999 , -999 );
}

pair<double,double> Pred_BDT_T2bw025_4(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 6081.30 , 311.52);
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 3881.95 , 205.27);
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 2055.85 , 130.29);
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 866.10 , 61.32 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 299.48 , 23.10 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 82.02 , 9.23 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 18.28 , 3.51);
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 5.03 , 1.57 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.58 , 0.81);
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.50 , 0.44);
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.25 , 0.45);
    if (BDTcutOffset == 0.20)
return std::pair<double,double>( 1.07 , 0.85);

    else return pair<double,double>( -999 , -999 );
}

pair<double,double> Pred_BDT_T2bw025_6(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 4675.58 , 243.63);
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 3029.99 , 164.91);
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1631.71 , 95.94 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 783.86 , 51.25 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 319.42 , 24.67 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 93.05 , 9.58 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 24.84 , 4.30);
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 5.73 , 1.69 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 2.37 , 1.38);
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.98 , 1.74);
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.01 , 0.01);
    if (BDTcutOffset == 0.20)
return std::pair<double,double>( 0.28 , 0.28);

    else return pair<double,double>( -999 , -999 );
}



pair<double,double> Pred_BDT_T2bw050_1_loose(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 7780.75 , 479.03 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 4880.24 , 361.57 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 2514.84 , 215.02 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 1029.76 , 78.19 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 400.73 , 37.75 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 137.26 , 19.83 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 45.95 , 9.56 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 14.79 , 3.70 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 6.30 , 2.78 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 2.41 , 1.59 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 1.67 , 1.60 	 );

    else return pair<double,double>( -999 , -999 );
}



pair<double,double> Pred_BDT_T2bw050_1_tight(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 10335.55 , 523.14 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 9048.50 , 519.21 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 6310.34 , 450.55 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 3579.82 , 271.33 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 1616.96 , 129.74 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 651.66 , 54.14 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 240.31 , 28.62 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 81.61 , 14.56 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 26.80 , 6.63 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 10.35 , 3.41 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 3.81 , 2.05 	 );

    else return pair<double,double>( -999 , -999 );
}


pair<double,double> Pred_BDT_T2bw050_3(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 2945.15 , 181.24 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 1484.88 , 105.76 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 722.18 , 56.69 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 285.49 , 24.11 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 112.41 , 11.98 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 49.74 , 7.33 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 25.25 , 5.62 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 8.36 , 2.47 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 3.10 , 1.37 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 1.38 , 0.88 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.08 , 0.06 	 );

    else return pair<double,double>( -999 , -999 );
}


pair<double,double> Pred_BDT_T2bw050_4(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 4339.88 , 225.48 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 2373.56 , 150.16 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1037.04 , 76.26 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 360.65 , 29.14 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 101.91 , 11.51 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 33.29 , 5.59 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 11.15 , 2.79 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 1.49 , 1.23 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.77 , 1.21 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 17.68 , 30.79 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.00 , 0.00 	 );

    else return pair<double,double>( -999 , -999 );
}


pair<double,double> Pred_BDT_T2bw050_5(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 3878.54 , 205.49 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 2263.26 , 136.50 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1124.48 , 77.16 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 475.18 , 36.55 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 171.81 , 15.82 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 51.22 , 7.39 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 18.48 , 4.03 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 4.63 , 1.72 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.56 , 1.07 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 1.91 , 1.74 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( 0.51 , 1.21 	 );

    else return pair<double,double>( -999 , -999 );
}


pair<double,double> Pred_BDT_T2bw050_6(double BDTcutOffset){
    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 3878.48 , 202.56 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 2411.54 , 138.52 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1299.73 , 82.13 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 588.22 , 39.93 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 185.55 , 16.51 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 54.56 , 7.07 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 18.35 , 3.82 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 3.27 , 1.32 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.43 , 1.03 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.06 , 0.53 	 );
    if (BDTcutOffset == 0.15)
return std::pair<double,double>( -0.24 , 0.66 	 );

    else return pair<double,double>( -999 , -999 );
}





pair<double,double> Pred_BDT_T2bw075_1(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 8232.52 , 392.83 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 5903.85 , 291.90 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 3477.20 , 191.77 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 1574.64 , 109.47 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 577.33 , 51.21 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 199.71 , 26.01 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 49.33 , 11.67 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 10.62 , 3.78 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 2.64 , 1.38 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.48 , 0.43 	 );

    else return pair<double,double>( -999 , -999 );

}


pair<double,double> Pred_BDT_T2bw075_2(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 4267.02 , 232.19 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 2585.41 , 167.46 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1467.38 , 133.00 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 754.87 , 85.21 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 338.41 , 47.15 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 157.12 , 28.06 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 58.24 , 12.09 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 23.29 , 6.72 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 10.29 , 3.79 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 4.21 , 1.86 	 );

    else return pair<double,double>( -999 , -999 );

}


pair<double,double> Pred_BDT_T2bw075_3(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 1417.22 , 115.03 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 753.93 , 75.81 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 377.67 , 45.96 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 183.80 , 25.28 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 85.52 , 14.34 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 35.34 , 7.84 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 15.20 , 5.08 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 5.97 , 2.66 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 1.24 , 0.87 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.20 , 0.12 	 );

    else return pair<double,double>( -999 , -999 );

}


pair<double,double> Pred_BDT_T2bw075_5(double BDTcutOffset){

    if (BDTcutOffset == -0.35)
return std::pair<double,double>( 5910.79 , 286.41 	 );
    if (BDTcutOffset == -0.30)
return std::pair<double,double>( 3605.77 , 202.22 	 );
    if (BDTcutOffset == -0.25)
return std::pair<double,double>( 1789.55 , 135.22 	 );
    if (BDTcutOffset == -0.20)
return std::pair<double,double>( 777.29 , 75.05 	 );
    if (BDTcutOffset == -0.15)
return std::pair<double,double>( 330.70 , 34.45 	 );
    if (BDTcutOffset == -0.10)
return std::pair<double,double>( 127.21 , 16.11 	 );
    if (BDTcutOffset == -0.05)
return std::pair<double,double>( 44.41 , 7.91 	 );
    if (BDTcutOffset == 0.0)
return std::pair<double,double>( 15.28 , 4.32 	 );
    if (BDTcutOffset == 0.05)
return std::pair<double,double>( 3.09 , 1.30 	 );
    if (BDTcutOffset == 0.10)
return std::pair<double,double>( 0.66 , 0.58 	 );

    else return pair<double,double>( -999 , -999 );

}






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
        return pair<double,double>( 110.93 , 15.11);
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



