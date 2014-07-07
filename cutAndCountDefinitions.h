#ifndef _cutAndCountDefinitions_h
#define _cutAndCountDefinitions_h

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

// Preselection signal region (ie : basically no cut compared to other "standard" SR's)
bool preselection(bool applyMTCut)
{
    if ((applyMTCut) && (myEvent.MT < 100)) return false;

    return true;
}


// ISR jet definition

float leadingNonBPt()
{
    float leadingPt = -1;
    for (unsigned int j = 0 ; j < myEvent.jets.size()  ; j++)
    {
        // Ignore b-tagged jets
        float CSV;
        if (sampleType == "data") CSV = (myEvent.jets_CSV_raw)[j];
        else                      CSV = (myEvent.jets_CSV_reshaped)[j];

        if (CSV > 0.679) continue;

        // Keep Pt max
        if (leadingPt < (myEvent.jets)[j].Pt())
            leadingPt = (myEvent.jets)[j].Pt();
    }
    return leadingPt;
}

bool findISRJet()
{
    if (myEvent.nJets < 5) return false;
    if (leadingNonBPt() < 200) return false;
    return true;
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
    if (cutMT2W >0 && myEvent.MT2W>99990)        return false;
    if (myEvent.MET             < cutMET)           return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)      return false;
    if (myEvent.hadronicChi2    > cutHadronicChi2)  return false;
 
    if (enableISRJetRequirement)
    {
        #ifdef ISR_JET_ALREADY_COMPUTED
            if (!myEvent.ISRJet)   return false;
        #else
            if (!findISRJet())     return false;
        #endif
    }

    return true;
}

                                                                            // MET METsig   MT             MT2W dPhi Chi2    ISRjet
bool cutAndCount_T2tt_offShellLoose(bool applyMTCut) { return cutAndCount_T2tt( 200, -1, 120 * applyMTCut, -1,  -1,  999999, true ); }
bool cutAndCount_T2tt_offShellTight(bool applyMTCut) { return cutAndCount_T2tt( -1,  10, 140 * applyMTCut, -1,  -1,  999999, true ); }
bool cutAndCount_T2tt_lowDeltaM    (bool applyMTCut) { return cutAndCount_T2tt( 130, -1, 130 * applyMTCut, -1,  0.8, 5,      false); }
bool cutAndCount_T2tt_mediumDeltaM (bool applyMTCut) { return cutAndCount_T2tt( -1,  10, 140 * applyMTCut, 180, 0.8, 3,      false); }
bool cutAndCount_T2tt_highDeltaM   (bool applyMTCut) { return cutAndCount_T2tt( -1,  15, 190 * applyMTCut, 240, -1,  999999, false); }

bool cut_nocut(bool applyMTCut) { return cutAndCount_T2tt( -1, -1, 100 * applyMTCut, -1,  -1,  999999, false ); }

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
    if (cutMT2W >0 && myEvent.MT2W>99990)        return false;
    if (myEvent.leadingBPt      < cutBPt)               return false;
    if (myEvent.deltaPhiMETJets < cutDeltaPhi)          return false;
    if (enableISRJetRequirement)
    {
        #ifdef ISR_JET_ALREADY_COMPUTED
            if (!myEvent.ISRJet)   return false;
        #else
            if (!findISRJet())     return false;
        #endif
    }

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

#endif
