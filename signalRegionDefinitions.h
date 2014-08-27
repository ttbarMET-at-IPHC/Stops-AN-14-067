#ifndef _SignalRegionDefinitions_h
#define _SignalRegionDefinitions_h

// This function maps the SRs to the signal plane in the BDT analysis
string signalregionName(string decaymode, int stopmass, int lspmass)
{
    string SR = "nan";
    if (decaymode == "T2bw075")
    {
        if (lspmass > stopmass - 200)
            SR = "T2bw075_1";
        if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            SR = "T2bw075_2";
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            SR = "T2bw075_3";
        if (lspmass <= stopmass - 475)
            SR = "T2bw075_5_lowDM";
        if (lspmass <= stopmass - 575)
            SR = "T2bw075_5_highDM";
    }
    if (decaymode == "T2bw050")
    {
        if (lspmass > stopmass - 250){
            SR = "T2bw050_1_lowLSP";
            if (lspmass > 50) SR = "T2bw050_1_highLSP";
        }
        if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            SR = "T2bw050_3";
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            SR = "T2bw050_4";
        if (lspmass <= stopmass - 450 && lspmass > stopmass - 550)
            SR = "T2bw050_5_lowDM";
        if (lspmass <= stopmass - 550 && lspmass > stopmass - 625)
            SR = "T2bw050_5_highDM";
        if (lspmass <= stopmass - 625)
            SR = "T2bw050_6";
    }
    if (decaymode == "T2bw025")
    {
        if (lspmass > stopmass - 225)
            SR = "T2bw025_1";
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            SR = "T2bw025_3_lowDM";
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 425){
            SR = "T2bw025_3_lowDM";
            if (lspmass > 50) SR = "T2bw025_3_highDM";
        }
        if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
            SR = "T2bw025_4";
        if (lspmass <= stopmass - 600)
            SR = "T2bw025_6";
    }
    if (decaymode == "T2tt")
    {
        if ((lspmass > stopmass - 225 ) && (lspmass <= 100))
            SR = "T2tt_1_lowLSP";
        if ((lspmass > stopmass - 225 ) && (lspmass > 100))
            SR = "T2tt_1_highLSP";
        if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            SR = "T2tt_2_lowDM";
        if (lspmass <= stopmass - 275 && lspmass > stopmass - 325)
            SR = "T2tt_2_highDM";
        if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            SR = "T2tt_5_lowDM";
        if (lspmass <= stopmass - 400 && lspmass > stopmass - 500)
            SR = "T2tt_5_mediumDM";
        if (lspmass <= stopmass - 500)
            SR = "T2tt_5_highDM";
    }
    return SR;
}

// #################################
// #  BDT signal region container  #
// #################################

typedef struct
{
    string  labelRoot;
    string  labelLatex;

    double* BDTOutputPointer;
    float   BDTOutputCut;

} BDTSignalRegion;

#include <map>
map<string, BDTSignalRegion> BDTSignalRegionMap;

void loadBDTSignalRegion(string tag, string labelRoot, string labelLatex, double* BDTOutputPointer, float BDTOutputCut)
{
    BDTSignalRegionMap[tag].labelRoot        = labelRoot;
    BDTSignalRegionMap[tag].labelLatex       = labelLatex;
    BDTSignalRegionMap[tag].BDTOutputPointer = BDTOutputPointer;
    BDTSignalRegionMap[tag].BDTOutputCut     = BDTOutputCut;
}

void loadBDTSignalRegions()
{
    loadBDTSignalRegion("T2tt_1_lowLSP",     "BDT T2tt-1, low m(LSP)",       "BDT T2tt-1, low $m$(LSP)",        &myEvent.BDT_output_t2tt_R1,    0.175);
    loadBDTSignalRegion("T2tt_1_mediumLSP",  "BDT T2tt-1, medium m(LSP)",    "BDT T2tt-1, medium $m$(LSP)",     &myEvent.BDT_output_t2tt_R1,    0.325);
    loadBDTSignalRegion("T2tt_1_highLSP",    "BDT T2tt-1, high m(LSP)",      "BDT T2tt-1, high $m$(LSP)",       &myEvent.BDT_output_t2tt_R1,    0.375);
    loadBDTSignalRegion("T2tt_2",            "BDT T2tt-2",                   "BDT T2tt-2",                      &myEvent.BDT_output_t2tt_R2,    0.35 );
    loadBDTSignalRegion("T2tt_5_lowDM",      "BDT T2tt-5, low #Deltam",      "BDT T2tt-5, low $\\Delta m$",     &myEvent.BDT_output_t2tt_R5,    0.30 );
    loadBDTSignalRegion("T2tt_5_highDM",     "BDT T2tt-5, high #Deltam",     "BDT T2tt-5, high $\\Delta m$",    &myEvent.BDT_output_t2tt_R5,    0.325);

    loadBDTSignalRegion("T2bw075_1",         "BDT T2bw075-1",                "BDT T2bw075-1",                   &myEvent.BDT_output_t2bw075_R1, 0.225);
    loadBDTSignalRegion("T2bw075_2",         "BDT T2bw075-2",                "BDT T2bw075-2",                   &myEvent.BDT_output_t2bw075_R2, 0.275);
    loadBDTSignalRegion("T2bw075_3",         "BDT T2bw075-3",                "BDT T2bw075-3",                   &myEvent.BDT_output_t2bw075_R3, 0.3  );
    loadBDTSignalRegion("T2bw075_5_lowDM",   "BDT T2bw075-5, low #Deltam",   "BDT T2bw075-5, low $\\Delta m$",  &myEvent.BDT_output_t2bw075_R5, 0.25 );
    loadBDTSignalRegion("T2bw075_5_highDM",  "BDT T2bw075-5, high #Deltam",  "BDT T2bw075-5, high $\\Delta m$", &myEvent.BDT_output_t2bw075_R5, 0.3  );

    loadBDTSignalRegion("T2bw050_1_lowDM_lowLSP",  "BDT T2bw050-1, low #Deltam low m(LSP)",  "BDT T2bw050-1, low $\\Delta m$ low $m$(LSP)",  &myEvent.BDT_output_t2bw050_R1, 0.275);
    loadBDTSignalRegion("T2bw050_1_lowDM_highLSP", "BDT T2bw050-1, low #Deltam high m(LSP)", "BDT T2bw050-1, low $\\Delta m$ high $m$(LSP)", &myEvent.BDT_output_t2bw050_R1, 0.175);
    loadBDTSignalRegion("T2bw050_1_highDM",  "BDT T2bw050-1, high #Deltam",  "BDT T2bw050-1, high $\\Delta m$", &myEvent.BDT_output_t2bw050_R1, 0.375);
    loadBDTSignalRegion("T2bw050_3",         "BDT T2bw050-3",                "BDT T2bw050-3",                   &myEvent.BDT_output_t2bw050_R3, 0.3  );
    loadBDTSignalRegion("T2bw050_4",         "BDT T2bw050-4",                "BDT T2bw050-4",                   &myEvent.BDT_output_t2bw050_R4, 0.250);
    loadBDTSignalRegion("T2bw050_5",         "BDT T2bw050-5",                "BDT T2bw050-5",                   &myEvent.BDT_output_t2bw050_R5, 0.275);
    loadBDTSignalRegion("T2bw050_6",         "BDT T2bw050-6",                "BDT T2bw050-6",                   &myEvent.BDT_output_t2bw050_R6, 0.2  );

    loadBDTSignalRegion("T2bw025_1",         "BDT T2bw025-1",                "BDT T2bw025-1",                   &myEvent.BDT_output_t2bw025_R1, 0.2  );
    loadBDTSignalRegion("T2bw025_3",         "BDT T2bw025-3",                "BDT T2bw025-3",                   &myEvent.BDT_output_t2bw025_R3, 0.2  );
    loadBDTSignalRegion("T2bw025_4_lowLSP",  "BDT T2bw025-4, low m(LSP)",    "BDT T2bw025-4, low $m$(LSP)",     &myEvent.BDT_output_t2bw025_R4, 0.15 );
    loadBDTSignalRegion("T2bw025_4_highLSP", "BDT T2bw025-4, high m(LSP)",   "BDT T2bw025-4, high $m$(LSP)",    &myEvent.BDT_output_t2bw025_R4, 0.2  );
    loadBDTSignalRegion("T2bw025_6",         "BDT T2bw025-6",                "BDT T2bw025-6",                   &myEvent.BDT_output_t2bw025_R6, 0.175);
}



// #############################################
// #  Accessors to the BDT signal regions map  #
// #############################################

bool doesBDTSignalRegionExists(string BDTSignalRegionTag)
{
    // Check if entry exist in map
    if (BDTSignalRegionMap.find(BDTSignalRegionTag) == BDTSignalRegionMap.end())
    {
        cerr << "WARNING (" << __FILE__ << ", l." << __LINE__ << ")"
             << "Trying to access unknown BDT signal region tag '" << BDTSignalRegionTag << "'" << endl;
        return false;
    }
    else return true;
}

float BDToutput(string BDTSignalRegionTag)
{
    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return -10.0;
    else return *(BDTSignalRegionMap[BDTSignalRegionTag].BDTOutputPointer);
}

float BDTcut(string BDTSignalRegionTag)
{
    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return -1.0;
    else return BDTSignalRegionMap[BDTSignalRegionTag].BDTOutputCut;
}

string BDTlabel(string BDTSignalRegionTag, string mode)
{
    // If tag starts with "BDT_", remove the 4 first characters
    // (so that "BDT_T2tt_1" and "T2tt_1" returns the same thing)
    if (BDTSignalRegionTag.find("BDT_") == 0)
        BDTSignalRegionTag = BDTSignalRegionTag.substr(4,BDTSignalRegionTag.size());

    if (doesBDTSignalRegionExists(BDTSignalRegionTag) == false) return "";

         if (mode == "root")  return BDTSignalRegionMap[BDTSignalRegionTag].labelRoot;
    else if (mode == "latex") return BDTSignalRegionMap[BDTSignalRegionTag].labelLatex;
    else                      return "";
}


bool goesInBDTRegion(string BDTregion) { return (BDToutput(BDTregion) > BDTcut(BDTregion)); }

// FIXME : these hardcoded functions shouldn't be needed because it introduces tight coupling w.r.t. the signal region definitions.

bool BDT_T2tt_1_lowLSP    (bool applyMTCut) { return goesInBDTRegion("T2tt_1_lowLSP"    ); }
bool BDT_T2tt_1_mediumLSP (bool applyMTCut) { return goesInBDTRegion("T2tt_1_mediumLSP" ); }
bool BDT_T2tt_1_highLSP   (bool applyMTCut) { return goesInBDTRegion("T2tt_1_highLSP"   ); }
bool BDT_T2tt_2           (bool applyMTCut) { return goesInBDTRegion("T2tt_2"           ); }
bool BDT_T2tt_5_lowDM     (bool applyMTCut) { return goesInBDTRegion("T2tt_5_lowDM"     ); }
bool BDT_T2tt_5_highDM    (bool applyMTCut) { return goesInBDTRegion("T2tt_5_highDM"    ); }
bool BDT_T2bw075_1        (bool applyMTCut) { return goesInBDTRegion("T2bw075_1"        ); }
bool BDT_T2bw075_2        (bool applyMTCut) { return goesInBDTRegion("T2bw075_2"        ); }
bool BDT_T2bw075_3        (bool applyMTCut) { return goesInBDTRegion("T2bw075_3"        ); }
bool BDT_T2bw075_5_lowDM  (bool applyMTCut) { return goesInBDTRegion("T2bw075_5_lowDM"  ); }
bool BDT_T2bw075_5_highDM (bool applyMTCut) { return goesInBDTRegion("T2bw075_5_highDM" ); }
bool BDT_T2bw050_1_lowDM_lowLSP  (bool applyMTCut) { return goesInBDTRegion("T2bw050_1_lowDM_lowLSP"  ); }
bool BDT_T2bw050_1_lowDM_highLSP (bool applyMTCut) { return goesInBDTRegion("T2bw050_1_lowDM_highLSP" ); }
bool BDT_T2bw050_1_highDM (bool applyMTCut) { return goesInBDTRegion("T2bw050_1_highDM" ); }
bool BDT_T2bw050_3        (bool applyMTCut) { return goesInBDTRegion("T2bw050_3"        ); }
bool BDT_T2bw050_4        (bool applyMTCut) { return goesInBDTRegion("T2bw050_4"        ); }
bool BDT_T2bw050_5        (bool applyMTCut) { return goesInBDTRegion("T2bw050_5"        ); }
bool BDT_T2bw050_6        (bool applyMTCut) { return goesInBDTRegion("T2bw050_6"        ); }
bool BDT_T2bw025_1        (bool applyMTCut) { return goesInBDTRegion("T2bw025_1"        ); }
bool BDT_T2bw025_3        (bool applyMTCut) { return goesInBDTRegion("T2bw025_3"        ); }
bool BDT_T2bw025_4_lowLSP (bool applyMTCut) { return goesInBDTRegion("T2bw025_4_lowLSP" ); }
bool BDT_T2bw025_4_highLSP(bool applyMTCut) { return goesInBDTRegion("T2bw025_4_highLSP"); }
bool BDT_T2bw025_6        (bool applyMTCut) { return goesInBDTRegion("T2bw025_6"        ); }

// Aliases to loosest BDT signal regions in case of different cuts that apply to same BDT output
bool BDT_T2tt_1           (bool applyMTCut) { return BDT_T2tt_1_lowLSP   (applyMTCut); }
bool BDT_T2tt_5           (bool applyMTCut) { return BDT_T2tt_5_lowDM    (applyMTCut); }
bool BDT_T2bw075_5        (bool applyMTCut) { return BDT_T2bw075_5_lowDM (applyMTCut); }
bool BDT_T2bw050_1        (bool applyMTCut) { return BDT_T2bw050_1_lowDM_highLSP(applyMTCut); }
bool BDT_T2bw025_4        (bool applyMTCut) { return BDT_T2bw025_4_lowLSP(applyMTCut); }

#endif
