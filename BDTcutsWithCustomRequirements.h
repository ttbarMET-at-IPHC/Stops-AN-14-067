#ifndef _BDTCUTSWITHCUSTOMREQUIREMENT_H
#define _BDTCUTSWITHCUSTOMREQUIREMENT_H

// Loading the loosened BDT cuts used for the CR 4/5 modeling checks
// customRequirement correspond to the requirement choosen

void loadBDTCutsWithCustomRequirement(string customRequirement)
{
    map<string,float> customBDTCuts;

    if (customRequirement == "30evts_in_CR4_2jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    = 0.275;
        customBDTCuts["T2tt_2"]    = 0.355;
        customBDTCuts["T2tt_5"]    = 0.205;
        customBDTCuts["T2bw075_1"] = 0.205;
        customBDTCuts["T2bw075_2"] = 0.265;
        customBDTCuts["T2bw075_3"] = 0.265;
        customBDTCuts["T2bw075_5"] = 0.135;
        customBDTCuts["T2bw050_1"] = 0.195;
        customBDTCuts["T2bw050_3"] = 0.205;
        customBDTCuts["T2bw050_4"] = 0.135;
        customBDTCuts["T2bw050_5"] = 0.125;
        customBDTCuts["T2bw050_6"] = 0.095;
        customBDTCuts["T2bw025_1"] = 0.185;
        customBDTCuts["T2bw025_3"] = 0.145;
        customBDTCuts["T2bw025_4"] = 0.105;
        customBDTCuts["T2bw025_6"] = 0.075;
    }
    if (customRequirement == "30evts_in_CR4_3jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    = 0.255;
        customBDTCuts["T2tt_2"]    = 0.325;
        customBDTCuts["T2tt_5"]    = 0.165;
        customBDTCuts["T2bw075_1"] = 0.175;
        customBDTCuts["T2bw075_2"] = 0.235;
        customBDTCuts["T2bw075_3"] = 0.225;
        customBDTCuts["T2bw075_5"] = 0.125;
        customBDTCuts["T2bw050_1"] = 0.165;
        customBDTCuts["T2bw050_3"] = 0.175;
        customBDTCuts["T2bw050_4"] = 0.125;
        customBDTCuts["T2bw050_5"] = 0.105;
        customBDTCuts["T2bw050_6"] = 0.085;
        customBDTCuts["T2bw025_1"] = 0.155;
        customBDTCuts["T2bw025_3"] = 0.125;
        customBDTCuts["T2bw025_4"] = 0.095;
        customBDTCuts["T2bw025_6"] = 0.075;
    }
    if (customRequirement == "30evts_in_CR4_4jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    = 0.215;
        customBDTCuts["T2tt_2"]    = 0.265;
        customBDTCuts["T2tt_5"]    = 0.115;
        customBDTCuts["T2bw075_1"] = 0.145;
        customBDTCuts["T2bw075_2"] = 0.195;
        customBDTCuts["T2bw075_3"] = 0.175;
        customBDTCuts["T2bw075_5"] = 0.095;
        customBDTCuts["T2bw050_1"] = 0.135;
        customBDTCuts["T2bw050_3"] = 0.135;
        customBDTCuts["T2bw050_4"] = 0.085;
        customBDTCuts["T2bw050_5"] = 0.075;
        customBDTCuts["T2bw050_6"] = 0.055;
        customBDTCuts["T2bw025_1"] = 0.115;
        customBDTCuts["T2bw025_3"] = 0.095;
        customBDTCuts["T2bw025_4"] = 0.065;
        customBDTCuts["T2bw025_6"] = 0.045;
    }
    if (customRequirement == "50evts_in_CR4_4jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    =  0.175;
        customBDTCuts["T2tt_2"]    =  0.225;
        customBDTCuts["T2tt_5"]    =  0.085;
        customBDTCuts["T2bw075_1"] =  0.115;
        customBDTCuts["T2bw075_2"] =  0.155;
        customBDTCuts["T2bw075_3"] =  0.145;
        customBDTCuts["T2bw075_5"] =  0.065;
        customBDTCuts["T2bw050_1"] =  0.105;
        customBDTCuts["T2bw050_3"] =  0.105;
        customBDTCuts["T2bw050_4"] =  0.065;
        customBDTCuts["T2bw050_5"] =  0.045;
        customBDTCuts["T2bw050_6"] =  0.025;
        customBDTCuts["T2bw025_1"] =  0.085;
        customBDTCuts["T2bw025_3"] =  0.065;
        customBDTCuts["T2bw025_4"] =  0.045;
        customBDTCuts["T2bw025_6"] =  0.025;
    }
    if (customRequirement == "100evts_in_CR4_4jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    =  0.125;
        customBDTCuts["T2tt_2"]    =  0.175;
        customBDTCuts["T2tt_5"]    =  0.035;
        customBDTCuts["T2bw075_1"] =  0.085;
        customBDTCuts["T2bw075_2"] =  0.115;
        customBDTCuts["T2bw075_3"] =  0.085;
        customBDTCuts["T2bw075_5"] =  0.025;
        customBDTCuts["T2bw050_1"] =  0.075;
        customBDTCuts["T2bw050_3"] =  0.065;
        customBDTCuts["T2bw050_4"] =  0.025;
        customBDTCuts["T2bw050_5"] =  0.005;
        customBDTCuts["T2bw050_6"] = -0.005;
        customBDTCuts["T2bw025_1"] =  0.055;
        customBDTCuts["T2bw025_3"] =  0.025;
        customBDTCuts["T2bw025_4"] =  0.005;
        customBDTCuts["T2bw025_6"] = -0.015;
    }
    if (customRequirement == "150evts_in_CR4_4jets_MTTail")
    {
        customBDTCuts["T2tt_1"]    =  0.085;
        customBDTCuts["T2tt_2"]    =  0.135;
        customBDTCuts["T2tt_5"]    =  0.015;
        customBDTCuts["T2bw075_1"] =  0.055;
        customBDTCuts["T2bw075_2"] =  0.085;
        customBDTCuts["T2bw075_3"] =  0.055;
        customBDTCuts["T2bw075_5"] = -0.005;
        customBDTCuts["T2bw050_1"] =  0.055;
        customBDTCuts["T2bw050_3"] =  0.035;
        customBDTCuts["T2bw050_4"] =  0.005;
        customBDTCuts["T2bw050_5"] = -0.015;
        customBDTCuts["T2bw050_6"] = -0.025;
        customBDTCuts["T2bw025_1"] =  0.025;
        customBDTCuts["T2bw025_3"] =  0.005;
        customBDTCuts["T2bw025_4"] = -0.015;
        customBDTCuts["T2bw025_6"] = -0.045;
    }

    if (customRequirement == "25percentEfficiency")
    {
        customBDTCuts["T2tt_1"]    = -0.005;
        customBDTCuts["T2tt_2"]    =  0.015;
        customBDTCuts["T2tt_5"]    = -0.065;
        customBDTCuts["T2bw075_1"] = -0.015;
        customBDTCuts["T2bw075_2"] = -0.035;
        customBDTCuts["T2bw075_3"] = -0.035;
        customBDTCuts["T2bw075_5"] = -0.045;
        customBDTCuts["T2bw050_1"] = -0.005;
        customBDTCuts["T2bw050_3"] =  0.035;
        customBDTCuts["T2bw050_4"] =  0.015;
        customBDTCuts["T2bw050_5"] = -0.005;
        customBDTCuts["T2bw050_6"] = -0.015;
        customBDTCuts["T2bw025_1"] =  0.01;
        customBDTCuts["T2bw025_3"] =  0.045;
        customBDTCuts["T2bw025_4"] =  0.015;
        customBDTCuts["T2bw025_6"] = -0.015;
    }

    // Only take the custom cuts if it's looser than the standard cut
    BDTSignalRegionMap["T2tt_1_lowLSP"    ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_1_lowLSP"    ].BDTOutputCut, customBDTCuts["T2tt_1"   ] );
    BDTSignalRegionMap["T2tt_1_mediumLSP" ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_1_mediumLSP" ].BDTOutputCut, customBDTCuts["T2tt_1"   ] );
    BDTSignalRegionMap["T2tt_1_highLSP"   ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_1_highLSP"   ].BDTOutputCut, customBDTCuts["T2tt_1"   ] );
    BDTSignalRegionMap["T2tt_2"           ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_2"           ].BDTOutputCut, customBDTCuts["T2tt_2"   ] );
    BDTSignalRegionMap["T2tt_5_lowDM"     ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_5_lowDM"     ].BDTOutputCut, customBDTCuts["T2tt_5"   ] );
    BDTSignalRegionMap["T2tt_5_highDM"    ].BDTOutputCut = min( BDTSignalRegionMap["T2tt_5_highDM"    ].BDTOutputCut, customBDTCuts["T2tt_5"   ] );

    BDTSignalRegionMap["T2bw075_1"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw075_1"        ].BDTOutputCut, customBDTCuts["T2bw075_1"] );
    BDTSignalRegionMap["T2bw075_2"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw075_2"        ].BDTOutputCut, customBDTCuts["T2bw075_2"] );
    BDTSignalRegionMap["T2bw075_3"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw075_3"        ].BDTOutputCut, customBDTCuts["T2bw075_3"] );
    BDTSignalRegionMap["T2bw075_5_lowDM"  ].BDTOutputCut = min( BDTSignalRegionMap["T2bw075_5_lowDM"  ].BDTOutputCut, customBDTCuts["T2bw075_5"] );
    BDTSignalRegionMap["T2bw075_5_highDM" ].BDTOutputCut = min( BDTSignalRegionMap["T2bw075_5_highDM" ].BDTOutputCut, customBDTCuts["T2bw075_5"] );

    BDTSignalRegionMap["T2bw050_1_lowDM_lowLSP" ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_1_lowDM_lowLSP" ].BDTOutputCut, customBDTCuts["T2bw050_1"] );
    BDTSignalRegionMap["T2bw050_1_lowDM_highLSP"].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_1_lowDM_highLSP"].BDTOutputCut, customBDTCuts["T2bw050_1"] );
    BDTSignalRegionMap["T2bw050_1_highDM" ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_1_highDM" ].BDTOutputCut, customBDTCuts["T2bw050_1"] );
    BDTSignalRegionMap["T2bw050_3"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_3"        ].BDTOutputCut, customBDTCuts["T2bw050_3"] );
    BDTSignalRegionMap["T2bw050_4"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_4"        ].BDTOutputCut, customBDTCuts["T2bw050_4"] );
    BDTSignalRegionMap["T2bw050_5"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_5"        ].BDTOutputCut, customBDTCuts["T2bw050_5"] );
    BDTSignalRegionMap["T2bw050_6"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw050_6"        ].BDTOutputCut, customBDTCuts["T2bw050_6"] );

    BDTSignalRegionMap["T2bw025_1"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw025_1"        ].BDTOutputCut, customBDTCuts["T2bw025_1"] );
    BDTSignalRegionMap["T2bw025_3"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw025_3"        ].BDTOutputCut, customBDTCuts["T2bw025_3"] );
    BDTSignalRegionMap["T2bw025_4_lowLSP" ].BDTOutputCut = min( BDTSignalRegionMap["T2bw025_4_lowLSP" ].BDTOutputCut, customBDTCuts["T2bw025_4"] );
    BDTSignalRegionMap["T2bw025_4_highLSP"].BDTOutputCut = min( BDTSignalRegionMap["T2bw025_4_highLSP"].BDTOutputCut, customBDTCuts["T2bw025_4"] );
    BDTSignalRegionMap["T2bw025_6"        ].BDTOutputCut = min( BDTSignalRegionMap["T2bw025_6"        ].BDTOutputCut, customBDTCuts["T2bw025_6"] );

}
#endif
