#ifndef _BDTCUTSWITHCUSTOMREQUIREMENT_H
#define _BDTCUTSWITHCUSTOMREQUIREMENT_H

// Loading the loosened BDT cuts used for the CR 4/5 modeling checks
// customRequirement correspond to the requirement choosen

map<string,float> customBDTCuts;
void LoadBDTCutWithCustomRequirement(string customRequirement)
{
    if (customRequirement == "CR4_1j")
    {
        customBDTCuts["T2tt_1"]    = 0.305;  
        customBDTCuts["T2tt_2"]    = 0.25 ; // 0.395
        customBDTCuts["T2tt_5"]    = 0.265; 
        customBDTCuts["T2bw075_1"] = 0.225;
        customBDTCuts["T2bw075_2"] = 0.275; // 0.315
        customBDTCuts["T2bw075_3"] = 0.305;
        customBDTCuts["T2bw075_5"] = 0.175;
        customBDTCuts["T2bw050_1"] = 0.175; // 0.225
        customBDTCuts["T2bw050_3"] = 0.295; 
        customBDTCuts["T2bw050_4"] = 0.185; 
        customBDTCuts["T2bw050_5"] = 0.175; 
        customBDTCuts["T2bw050_6"] = 0.145; 
        customBDTCuts["T2bw025_1"] = 0.15 ; // 0.205
        customBDTCuts["T2bw025_3"] = 0.15 ; // 0.185
        customBDTCuts["T2bw025_4"] = 0.135; 
        customBDTCuts["T2bw025_6"] = 0.105; 
    }
    if (customRequirement == "CR4_2j")
    {
        customBDTCuts["T2tt_1"]    = 0.305;
        customBDTCuts["T2tt_2"]    = 0.25 ; // 0.365
        customBDTCuts["T2tt_5"]    = 0.225;
        customBDTCuts["T2bw075_1"] = 0.225;
        customBDTCuts["T2bw075_2"] = 0.275; // 0.285
        customBDTCuts["T2bw075_3"] = 0.275;
        customBDTCuts["T2bw075_5"] = 0.155;
        customBDTCuts["T2bw050_1"] = 0.175; // 0.215
        customBDTCuts["T2bw050_3"] = 0.245;
        customBDTCuts["T2bw050_4"] = 0.155;
        customBDTCuts["T2bw050_5"] = 0.155;
        customBDTCuts["T2bw050_6"] = 0.125;
        customBDTCuts["T2bw025_1"] = 0.15 ; // 0.195
        customBDTCuts["T2bw025_3"] = 0.15 ; // 0.175
        customBDTCuts["T2bw025_4"] = 0.125; 
        customBDTCuts["T2bw025_6"] = 0.095;
    }
    if (customRequirement == "CR4_3j")
    {
        customBDTCuts["T2tt_1"]    = 0.285;
        customBDTCuts["T2tt_2"]    = 0.25 ; // 0.335
        customBDTCuts["T2tt_5"]    = 0.185;
        customBDTCuts["T2bw075_1"] = 0.195;
        customBDTCuts["T2bw075_2"] = 0.245;
        customBDTCuts["T2bw075_3"] = 0.245;
        customBDTCuts["T2bw075_5"] = 0.145;
        customBDTCuts["T2bw050_1"] = 0.175; // 0.185
        customBDTCuts["T2bw050_3"] = 0.205;
        customBDTCuts["T2bw050_4"] = 0.145;
        customBDTCuts["T2bw050_5"] = 0.135;
        customBDTCuts["T2bw050_6"] = 0.105;
        customBDTCuts["T2bw025_1"] = 0.15 ; // 0.175
        customBDTCuts["T2bw025_3"] = 0.15 ; // 0.155
        customBDTCuts["T2bw025_4"] = 0.115;
        customBDTCuts["T2bw025_6"] = 0.095;
    }
    if (customRequirement == "CR4_4j")
    {
        customBDTCuts["T2tt_1"]    = 0.265;
        customBDTCuts["T2tt_2"]    = 0.25 ; // 0.285
        customBDTCuts["T2tt_5"]    = 0.135;
        customBDTCuts["T2bw075_1"] = 0.155;
        customBDTCuts["T2bw075_2"] = 0.205;
        customBDTCuts["T2bw075_3"] = 0.205;
        customBDTCuts["T2bw075_5"] = 0.115;
        customBDTCuts["T2bw050_1"] = 0.165;
        customBDTCuts["T2bw050_3"] = 0.105;
        customBDTCuts["T2bw050_4"] = 0.095;
        customBDTCuts["T2bw050_5"] = 0.095;
        customBDTCuts["T2bw050_6"] = 0.075;
        customBDTCuts["T2bw025_1"] = 0.15 ; // 0.155
        customBDTCuts["T2bw025_3"] = 0.125;
        customBDTCuts["T2bw025_4"] = 0.085;
        customBDTCuts["T2bw025_6"] = 0.075;
    }
    if (customRequirement == "CR4_4j_50evts")
    {
        customBDTCuts["T2tt_1"]    = 0.255;
        customBDTCuts["T2tt_2"]    = 0.25 ; // 0.255
        customBDTCuts["T2tt_5"]    = 0.105;
        customBDTCuts["T2bw075_1"] = 0.135;
        customBDTCuts["T2bw075_2"] = 0.175;
        customBDTCuts["T2bw075_3"] = 0.165;
        customBDTCuts["T2bw075_5"] = 0.095;
        customBDTCuts["T2bw050_1"] = 0.135;
        customBDTCuts["T2bw050_3"] = 0.135;
        customBDTCuts["T2bw050_4"] = 0.085;
        customBDTCuts["T2bw050_5"] = 0.075;
        customBDTCuts["T2bw050_6"] = 0.055;
        customBDTCuts["T2bw025_1"] = 0.125;
        customBDTCuts["T2bw025_3"] = 0.095;
        customBDTCuts["T2bw025_4"] = 0.065;
        customBDTCuts["T2bw025_6"] = 0.045;
    }
    if (customRequirement == "CR4_4j_100evts")
    {
        customBDTCuts["T2tt_1"]    = 0.165;
        customBDTCuts["T2tt_2"]    = 0.205;
        customBDTCuts["T2tt_5"]    = 0.065;
        customBDTCuts["T2bw075_1"] = 0.105;
        customBDTCuts["T2bw075_2"] = 0.135;
        customBDTCuts["T2bw075_3"] = 0.115;
        customBDTCuts["T2bw075_5"] = 0.055;
        customBDTCuts["T2bw050_1"] = 0.105;
        customBDTCuts["T2bw050_3"] = 0.095;
        customBDTCuts["T2bw050_4"] = 0.055;
        customBDTCuts["T2bw050_5"] = 0.035;
        customBDTCuts["T2bw050_6"] = 0.015;
        customBDTCuts["T2bw025_1"] = 0.085;
        customBDTCuts["T2bw025_3"] = 0.065;
        customBDTCuts["T2bw025_4"] = 0.035;
        customBDTCuts["T2bw025_6"] = 0.015;
    }
    if (customRequirement == "CR4_4j_150evts")
    {
        customBDTCuts["T2tt_1"]    =  0.135;
        customBDTCuts["T2tt_2"]    =  0.165;
        customBDTCuts["T2tt_5"]    =  0.035;
        customBDTCuts["T2bw075_1"] =  0.085;
        customBDTCuts["T2bw075_2"] =  0.115;
        customBDTCuts["T2bw075_3"] =  0.085;
        customBDTCuts["T2bw075_5"] =  0.025;
        customBDTCuts["T2bw050_1"] =  0.085;
        customBDTCuts["T2bw050_3"] =  0.065;
        customBDTCuts["T2bw050_4"] =  0.035;
        customBDTCuts["T2bw050_5"] =  0.015;
        customBDTCuts["T2bw050_6"] = -0.005;
        customBDTCuts["T2bw025_1"] =  0.065;
        customBDTCuts["T2bw025_3"] =  0.035;
        customBDTCuts["T2bw025_4"] =  0.015;
        customBDTCuts["T2bw025_6"] = -0.015;
    }
    
    if (customRequirement == "25percentEfficiency")
    {
        customBDTCuts["T2tt_1"]          =  0.00;
        customBDTCuts["T2tt_2_lowDM"]    =  0.01;
        customBDTCuts["T2tt_5"]          = -0.06;
        customBDTCuts["T2bw075_1"]       = -0.01;
        customBDTCuts["T2bw075_2"]       = -0.04;
        customBDTCuts["T2bw075_3"]       = -0.04;
        customBDTCuts["T2bw075_5"]       = -0.05;
        customBDTCuts["T2bw050_1_lowDM"] =  0.00;
        customBDTCuts["T2bw050_3"]       =  0.04;
        customBDTCuts["T2bw050_4"]       =  0.01;
        customBDTCuts["T2bw050_5"]       =  0.00;
        customBDTCuts["T2bw050_6"]       =  0.00;
        customBDTCuts["T2bw025_1"]       =  0.04;
        customBDTCuts["T2bw025_3"]       =  0.05;
        customBDTCuts["T2bw025_4"]       =  0.01;
        customBDTCuts["T2bw025_6"]       = -0.01;
    }
}
#endif
