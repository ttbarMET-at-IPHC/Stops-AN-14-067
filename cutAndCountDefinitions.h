
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

std::pair<double,double> Pred_cutAndCount_T2tt_offShellLoose(){return std::pair<double,double>(48.1101,8.3111);}
std::pair<double,double> Pred_cutAndCount_T2tt_offShellTight(){return std::pair<double,double>(16.7876,3.5236);}
std::pair<double,double> Pred_cutAndCount_T2tt_lowDeltaM(){return std::pair<double,double>(358.625,80.7227);}
std::pair<double,double> Pred_cutAndCount_T2tt_mediumDeltaM(){return std::pair<double,double>(16.0243,6.0595);}
std::pair<double,double> Pred_cutAndCount_T2tt_highDeltaM(){return std::pair<double,double>(2.5033,0.9448);}
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
std::pair<double,double> Pred_BDT_T2tt_1(){return std::pair<double,double>(38.4453,8.7745);}
std::pair<double,double> Pred_BDT_T2tt_2(){return std::pair<double,double>(38.331,8.1962);}
std::pair<double,double> Pred_BDT_T2tt_5_loose(){return std::pair<double,double>(16.0994,4.537);}
std::pair<double,double> Pred_BDT_T2tt_5_tight(){return std::pair<double,double>(4.9319,2.0099);}
std::pair<double,double> Pred_BDT_T2bw075_1(){return std::pair<double,double>(10.616,3.7794);}
std::pair<double,double> Pred_BDT_T2bw075_2(){return std::pair<double,double>(23.2888,6.7232);}
std::pair<double,double> Pred_BDT_T2bw075_3(){return std::pair<double,double>(5.9687,2.6584);}
std::pair<double,double> Pred_BDT_T2bw075_5(){return std::pair<double,double>(15.2831,4.32);}
std::pair<double,double> Pred_BDT_T2bw050_1_loose(){return std::pair<double,double>(14.7944,3.7032);}
std::pair<double,double> Pred_BDT_T2bw050_1_tight(){return std::pair<double,double>(81.6085,14.5565);}
std::pair<double,double> Pred_BDT_T2bw050_3(){return std::pair<double,double>(8.3554,2.4705);}
std::pair<double,double> Pred_BDT_T2bw050_4(){return std::pair<double,double>(1.4885,1.2307);}
std::pair<double,double> Pred_BDT_T2bw050_5(){return std::pair<double,double>(4.6252,1.7233);}
std::pair<double,double> Pred_BDT_T2bw050_6(){return std::pair<double,double>(3.2662,1.3211);}
std::pair<double,double> Pred_BDT_T2bw025_1(){return std::pair<double,double>(38.2686,5.8624);}
std::pair<double,double> Pred_BDT_T2bw025_3(){return std::pair<double,double>(3.0298,1.3844);}
std::pair<double,double> Pred_BDT_T2bw025_4(){return std::pair<double,double>(5.0316,1.571);}
std::pair<double,double> Pred_BDT_T2bw025_6(){return std::pair<double,double>(5.7326,1.6911);}
