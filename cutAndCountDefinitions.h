
// LM 150 to cross check with number from Alex. G

bool crossCheck_LM150(bool applyMTCut)
{
    // Apply MET and MT cuts
    if (myEvent.MET < 150) return false;
    if ((applyMTCut) && (myEvent.MT < 120)) return false;

    // Chi2 and deltaPhi cuts
    if (myEvent.deltaPhiMETJets < 0.8) return false;
    if (myEvent.hadronicChi2 > 5) return false;

    return true;
}

// Preselection definition
bool preselection(bool applyMTCut)
{
    if (applyMTCut) return goesInPreselectionMTtail();
    else            return goesInPreselection();
}

// ISR jet definition

bool findISRJet()
{
    if (myEvent.nJets < 5) return false;

    bool foundISRJet = false;
    for (unsigned int i = 0 ; i < myEvent.jets.size() ; i++)
    {
        // Check jet is high-pt
        if ((myEvent.jets)[i].Pt() < 200) continue;

        // Check jet isn't b-tagged
        if (sampleType == "data") { if ((myEvent.jets_CSV_raw)[i]      > 0.679) continue; }
        else                      { if ((myEvent.jets_CSV_reshaped)[i] > 0.679) continue; }

        foundISRJet = true;
    }

    return foundISRJet;
}

// ###########################
// #  _____ ____  _   _      #
// #  |_   _|___ \| |_| |_   #
// #    | |   __) | __| __|  #
// #    | |  / __/| |_| |_   #
// #    |_| |_____|\__|\__|  #
// #                         #
// ###########################

bool cutAndCount_T2tt(float cutMET, float cutMEToverSqrtHT, float cutMT, float cutMT2W, float cutDeltaPhi, float cutHadronicChi2, bool enableISRJetRequirement)
{
    if (myEvent.METoverSqrtHT   < cutMEToverSqrtHT) return false;
    if (myEvent.MT              < cutMT)            return false;
    if (myEvent.MT2W            < cutMT2W)          return false;
    if (myEvent.MET             < cutMET)           return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)      return false;
    if (myEvent.hadronicChi2    > cutHadronicChi2)  return false;
    if ((enableISRJetRequirement) && (!findISRJet()))       return false;

    return true;
}

                                                                            // MET METsig   MT             MT2W dPhi Chi2    ISRjet
bool cutAndCount_T2tt_offShellLoose(bool applyMTCut) { return cutAndCount_T2tt( 200, -1, 120 * applyMTCut, -1,  -1,  999999, true ); }
bool cutAndCount_T2tt_offShellTight(bool applyMTCut) { return cutAndCount_T2tt( -1,  10, 140 * applyMTCut, -1,  -1,  999999, true ); }
bool cutAndCount_T2tt_lowDeltaM    (bool applyMTCut) { return cutAndCount_T2tt( 130, -1, 130 * applyMTCut, -1,  0.8, 5,      false); }
bool cutAndCount_T2tt_mediumDeltaM (bool applyMTCut) { return cutAndCount_T2tt( -1,  10, 140 * applyMTCut, 180, 0.8, 3,      false); }
bool cutAndCount_T2tt_highDeltaM   (bool applyMTCut) { return cutAndCount_T2tt( -1,  15, 190 * applyMTCut, 240, -1,  999999, false); }

// #################################
// #  _____ ____  _                #
// #  |_   _|___ \| |____      __  #
// #    | |   __) | '_ \ \ /\ / /  #
// #    | |  / __/| |_) \ V  V /   #
// #    |_| |_____|_.__/ \_/\_/    #
// #                               #
// #################################

bool cutAndCount_T2bw(float cutMET, float cutMETsig, float cutMT, float cutMT2W, float cutBPt, float cutDeltaPhi, bool enableISRJetRequirement)
{
    if (myEvent.MET             < cutMET)               return false;
    if (myEvent.METoverSqrtHT   < cutMETsig)            return false;
    if (myEvent.MT              < cutMT)                return false;
    if (myEvent.MT2W            < cutMT2W)              return false;
    if (myEvent.leadingBPt      < cutBPt)               return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)          return false;
    if ((enableISRJetRequirement) && (!findISRJet()))   return false;

    return true;
}

                                                                                    // MET METsig   MT                MT2W BPt dPhi ISRjet
bool cutAndCount_T2bw025_veryOffShell_loose(bool applyMTCut) { return cutAndCount_T2bw(-1,   9,    120 * applyMTCut, -1,  -1,  0.2, true ); }
bool cutAndCount_T2bw025_offShell_loose(bool applyMTCut)     { return cutAndCount_T2bw(-1,   7,    120 * applyMTCut, 200, 150, 0.8, false); }
bool cutAndCount_T2bw025_lowDeltaM_tight(bool applyMTCut)    { return cutAndCount_T2bw(-1,   6,    120 * applyMTCut, 200, 180, 0.8, false); }
bool cutAndCount_T2bw025_highDeltaM(bool applyMTCut)         { return cutAndCount_T2bw(-1,  10,    140 * applyMTCut, 200, 180, 0.8, false); }

                                                                                    // MET METsig   MT                MT2W BPt dPhi ISRjet
bool cutAndCount_T2bw050_offShell_loose(bool applyMTCut)     { return cutAndCount_T2bw(-1,   9,   120 * applyMTCut, -1,  -1, 0.2, true ); }
bool cutAndCount_T2bw050_lowMass(bool applyMTCut)            { return cutAndCount_T2bw(-1,   6,   120 * applyMTCut, 200,100, 0.8, false); }
bool cutAndCount_T2bw050_mediumDeltaM_loose(bool applyMTCut) { return cutAndCount_T2bw(-1,   7,   150 * applyMTCut, 200,150, 0.8, false); }
bool cutAndCount_T2bw050_highDeltaM(bool applyMTCut)         { return cutAndCount_T2bw(-1,  10,   160 * applyMTCut, 200,180, 0.8, false); }

                                                                                    // MET METsig   MT                MT2W BPt dPhi ISRjet
bool cutAndCount_T2bw075_lowDeltaM_tight(bool applyMTCut)    { return cutAndCount_T2bw(-1,  12,    120 * applyMTCut, -1,  -1, 0.8, true);  }
bool cutAndCount_T2bw075_mediumDeltaM(bool applyMTCut)       { return cutAndCount_T2bw(-1,  10,    140 * applyMTCut, 180, -1, 0.8, false); }
bool cutAndCount_T2bw075_highDeltaM(bool applyMTCut)         { return cutAndCount_T2bw(320, -1,    160 * applyMTCut, 200, -1, 0.8, false); }





// prediction total yield for the different SR (from Eric)
// first value = yield
// second vlaue = uncertainty


std::pair<double,double> Pred_cutAndCount_T2bw025_veryOffShell_loose(){return std::pair<double,double>(25.617,4.6451);}
std::pair<double,double> Pred_cutAndCount_T2bw025_offShell_loose(){return std::pair<double,double>(16.1526,3.098);}
std::pair<double,double> Pred_cutAndCount_T2bw025_lowDeltaM_tight(){return std::pair<double,double>(14.0656,2.5857);}
std::pair<double,double> Pred_cutAndCount_T2bw025_highDeltaM(){return std::pair<double,double>(3.1555,1.0451);}
std::pair<double,double> Pred_cutAndCount_T2bw050_offShell_loose(){return std::pair<double,double>(25.617,4.6451);}
std::pair<double,double> Pred_cutAndCount_T2bw050_lowMass(){return std::pair<double,double>(47.084,7.8155);}
std::pair<double,double> Pred_cutAndCount_T2bw050_mediumDeltaM_loose(){return std::pair<double,double>(9.9766,2.3078);}
std::pair<double,double> Pred_cutAndCount_T2bw050_highDeltaM(){return std::pair<double,double>(2.4413,0.8501);}
std::pair<double,double> Pred_cutAndCount_T2bw075_lowDeltaM_tight(){return std::pair<double,double>(7.5097,1.8561);}
std::pair<double,double> Pred_cutAndCount_T2bw075_mediumDeltaM(){return std::pair<double,double>(35.7962,8.3931);}
std::pair<double,double> Pred_cutAndCount_T2bw075_highDeltaM(){return std::pair<double,double>(3.3587,0.9881);}



std::pair<double,double> Pred_BDT_T2tt_1(double BDTcutOffset){ 


   if (BDTcutOffset == -0.35)
      return std::pair<double,double>( 4126.59 , 313.31);  
   if (BDTcutOffset == -0.30) 
      return std::pair<double,double>( 2369.72 , 186.71);
   if (BDTcutOffset == -0.20) 
       return std::pair<double,double>(  1212.70, 103.46);
   if (BDTcutOffset == -0.20) 
      return std::pair<double,double>( 625.98 , 59.25 );
   if (BDTcutOffset == -0.15) 
      return std::pair<double,double>( 323.00 , 37.03 );
   if (BDTcutOffset == -0.10) 
      return std::pair<double,double>( 175.48 , 22.84 );
   if (BDTcutOffset == -0.05) 
      return std::pair<double,double>( 92.27 , 15.98);
   if (BDTcutOffset == 0.0) 
      return std::pair<double,double>( 38.45 , 8.77 );
   if (BDTcutOffset == 0.05) 
      return std::pair<double,double>( 17.58 , 5.34 );
   if (BDTcutOffset == 0.10) 
      return std::pair<double,double>( 6.58 , 2.55  );
   if (BDTcutOffset == 0.15) 
      return std::pair<double,double>( 3.08 , 2.44  );
   if (BDTcutOffset == 0.20) 
      return std::pair<double,double>( 2.04 , 2.26  );

   else return std::pair<double,double>( -999 , -999  );

}





std::pair<double,double> Pred_BDT_T2tt_2(double BDTcutOffset){

   if (BDTcutOffset == -0.35)
       return std::pair<double,double>( 3404.90 , 206.66 );
   if (BDTcutOffset == -0.30)
       return std::pair<double,double>( 2194.66 , 141.72 );
   if (BDTcutOffset == -0.25)
       return std::pair<double,double>( 1313.13, 97.99 );
   if (BDTcutOffset == -0.20)
	return std::pair<double,double>( 731.10 , 68.03 );
   if (BDTcutOffset == -0.15)
	return std::pair<double,double>( 378.11 , 45.59 );
   if (BDTcutOffset == -0.10)
	return std::pair<double,double>( 187.38 , 26.54 );
   if (BDTcutOffset == -0.05)
	return std::pair<double,double>( 91.42 , 15.18  );
   if (BDTcutOffset == 0.0)
	return std::pair<double,double>( 38.33 , 8.20	);
   if (BDTcutOffset == 0.05)
	return std::pair<double,double>( 17.92 , 4.80 	);
   if (BDTcutOffset == 0.10)
	return std::pair<double,double>( 5.09 , 2.33 	);
   if (BDTcutOffset == 0.15)
	return std::pair<double,double>( 1.09 , 1.02 	);
   if (BDTcutOffset == 0.20)
	return std::pair<double,double>( 0.85 , 1.03 	);

   else return std::pair<double,double>( -999 , -999  );

}






std::pair<double,double> Pred_BDT_T2tt_5_loose(double BDTcutOffset){

   if (BDTcutOffset == -0.35)
       return std::pair<double,double>( 3251.22 , 195.41 );
   if (BDTcutOffset == -0.30)
       return std::pair<double,double>( 1690.08 , 131.73 );
   if (BDTcutOffset == -0.25)
       return std::pair<double,double>( 862.10 , 80.31   );
   if (BDTcutOffset == -0.20)
	return std::pair<double,double>( 360.92 , 40.14	 );
   if (BDTcutOffset == -0.15)
	return std::pair<double,double>( 155.06 , 20.22	 );
   if (BDTcutOffset == -0.10)
	return std::pair<double,double>( 75.13 , 11.62 	 );
   if (BDTcutOffset == -0.05)
	return std::pair<double,double>( 36.65 , 8.06 	 );
   if (BDTcutOffset == 0.0)
	return std::pair<double,double>( 16.10 , 4.54 	 );
   if (BDTcutOffset == 0.05)
	return std::pair<double,double>( 7.80 , 2.99 	 );
   if (BDTcutOffset == 0.10)
	return std::pair<double,double>( 3.05 , 1.48 	 );
   if (BDTcutOffset == 0.15)
	return std::pair<double,double>( 1.29 , 0.85 	 );
   if (BDTcutOffset == 0.20)
	return std::pair<double,double>( 1.07 , 0.85 	 );

   else return std::pair<double,double>( -999 , -999  );

}




std::pair<double,double> Pred_BDT_T2tt_5_tight(double BDTcutOffset){

   if (BDTcutOffset == -0.35)
       return std::pair<double,double>( 1224.10 , 105.92 );
   if (BDTcutOffset == -0.30)
       return std::pair<double,double>( 565.05 , 59.93   );
   if (BDTcutOffset == -0.25)
       return std::pair<double,double>( 235.51 , 28.50   );
   if (BDTcutOffset == -0.20)
	return std::pair<double,double>( 110.93 , 15.11	 );
   if (BDTcutOffset == -0.15)
	return std::pair<double,double>( 55.27 , 10.46 	 );
   if (BDTcutOffset == -0.10)
	return std::pair<double,double>( 24.79 , 6.36 	 );
   if (BDTcutOffset == -0.05)
	return std::pair<double,double>( 13.56 , 4.18 	 );
   if (BDTcutOffset == 0.0)
	return std::pair<double,double>( 4.93 , 2.01 	 );
   if (BDTcutOffset == 0.05)
	return std::pair<double,double>( 2.27 , 1.27 	 );
   if (BDTcutOffset == 0.10)
	return std::pair<double,double>( 1.41 , 1.04 	 );
   if (BDTcutOffset == 0.15)
	return std::pair<double,double>( 0.99 , 0.83 	 );
   if (BDTcutOffset == 0.20)
	return std::pair<double,double>( 0.28 , 0.28 	 );

   else return std::pair<double,double>( -999 , -999  );

}
