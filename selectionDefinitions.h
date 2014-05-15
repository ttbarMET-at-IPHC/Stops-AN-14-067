#define MT_CUT    100 
#define MET_CUT   80
#define NJET_CUT  4
#define NBJET_CUT 1
#define NLEP_CUT  1


#include "Reader_final0210.h"

// NB : When you call any of the following functions,
// these three variables must be filled with the current
// event being taken care of, the name of the sample and
// the sample type (background, signal or data)

babyEvent myEvent;
string sampleName;
string sampleType;

// MT cuts definitions
// ###################

bool goesInMTpeak()     { if ((myEvent.MT > 50) && (myEvent.MT < 80)) return true; }
bool goesInMTtail()     { if (myEvent.MT > MT_CUT)                    return true; }
bool goesInMTinverted() { if (myEvent.MT < MT_CUT)                    return true; }

// Control region definitions
// ##########################

bool goesInPreselection() 
{

    if (myEvent.MET < MET_CUT) return false;
    if (myEvent.numberOfLepton != NLEP_CUT) return false;
    if (myEvent.nJets < NJET_CUT)  return false; 
    if (myEvent.nBTag < NBJET_CUT)  return false; 
    if ((!myEvent.isolatedTrackVeto) || (!myEvent.tauVeto)) return false;

    return true; 
}

bool goesInPreselectionMTtail()     { return (goesInPreselection() && goesInMTtail());     } 
bool goesInPreselectionMTpeak()     { return (goesInPreselection() && goesInMTpeak());     } 
bool goesInPreselectionMTinverted() { return (goesInPreselection() && goesInMTinverted()); } 

bool goesIn0BtagControlRegion()
{

    if (myEvent.MET < MET_CUT) return false;
    if (myEvent.numberOfLepton != NLEP_CUT) return false;
    if (myEvent.nJets < NJET_CUT)  return false; 
    if (myEvent.nBTag != 0 )  return false; 
    if ((!myEvent.isolatedTrackVeto) || (!myEvent.tauVeto)) return false;

    return true; 
}

bool goesIn0BtagControlRegionMTtail()     { return (goesIn0BtagControlRegion() && goesInMTtail());     } 
bool goesIn0BtagControlRegionMTpeak()     { return (goesIn0BtagControlRegion() && goesInMTpeak());     } 
bool goesIn0BtagControlRegionMTinverted() { return (goesIn0BtagControlRegion() && goesInMTinverted()); } 

bool goesInDileptonControlRegion() 
{

    // Apply double-lepton trigger requirement (for both MC and data)
    if ((!myEvent.triggerMuonElec) 
     && (!myEvent.triggerDoubleMuon)
     && (!myEvent.triggerDoubleElec)) return false;
    
    if (myEvent.MET < MET_CUT) return false;
    if (myEvent.numberOfLepton != 2) return false;
    if (myEvent.nJets < NJET_CUT)  return false;
    if (myEvent.nBTag < NBJET_CUT)  return false;

    return true; 
}

bool goesInVetosControlRegion() 
{

    // Apply double-lepton trigger requirement (for both MC and data)
    if ((!myEvent.triggerMuonElec) 
     && (!myEvent.triggerDoubleMuon)
     && (!myEvent.triggerDoubleElec)) return false;
   
    if (myEvent.MET < MET_CUT) return false;
    if (myEvent.numberOfLepton != NLEP_CUT) return false;
    if (myEvent.nJets < NJET_CUT)  return false;
    if (myEvent.nBTag < NBJET_CUT)  return false;

    // Apply vetos
    if ( !((myEvent.isolatedTrackVeto == true ) || (myEvent.tauVeto == true))) return false; 

    return true; 
}



// Single-lepton channels definitions
// ##################################

bool goesInSingleElecChannel() 
{
    // Keep only events with numberOfLepton == 1
    if (myEvent.numberOfLepton != NLEP_CUT) return false;
    // For data, keep only events from SingleElec dataset that fired the trigger
    if (sampleType == "data")
    {
        if ((sampleName != "SingleElec") || (!myEvent.triggerElec)) return false;
    }
    // Keep only events with an electron as leading lepton
    return (abs(myEvent.leadingLeptonPDGId) == 11); 
}


bool goesInSingleMuonChannel() 
{ 
    // Keep only events with numberOfLepton == 1
    if (myEvent.numberOfLepton != 1) return false;
    // For data, keep only events from SingleMuon dataset that fired the trigger
    if (sampleType == "data")
    {
        if ((sampleName != "SingleMuon") || ((!myEvent.triggerMuon) && (!myEvent.xtriggerMuon))) return false;
    }    
    
    // Take care of the splitting due to x-trigger
    if ((myEvent.leadingLepton.Pt() >= 26) && (!myEvent.triggerMuon))  return false;
    if ((myEvent.leadingLepton.Pt() <  26) && (!myEvent.xtriggerMuon)) return false;
   
    // TODO : remove this temporary fix for the eta(muon) < -2.1 after its propagated in the babyTuples
    if (myEvent.leadingLepton.Eta() < -2.1) return false;

    // Keep only events with a muon as leading lepton
    return (abs(myEvent.leadingLeptonPDGId) == 13); 
}


bool goesInSingleLeptonChannel() 
{ 
    // Single-lepton channel is the union of e-channel + mu-channel
    bool test = (goesInSingleElecChannel() 
              || goesInSingleMuonChannel());
    return test;
}



// Double-lepton channels definitions
// ##################################

bool goesInDoubleElecChannel() 
{ 
    // Keep only events with numberOfLepton == 2
    if (myEvent.numberOfLepton != 2) return false;
    // For data, keep only events from DoubleElec dataset that fired the trigger
    if (sampleType == "data")
    {
        if ((sampleName != "DoubleElec") || (!myEvent.triggerDoubleElec)) return false;
    }
    // Keep only events with two electrons
    return ((abs(myEvent.leadingLeptonPDGId) == 11) 
         && (abs(myEvent.secondLeptonPDGId)  == 11)); 
}



bool goesInDoubleMuonChannel() 
{ 
    // Keep only events with numberOfLepton == 2
    if (myEvent.numberOfLepton != 2) return false;
    // For data, keep only events from DoubleMuon dataset that fired the trigger
    if (sampleType == "data")
    {
        if ((sampleName != "DoubleMuon") || (!myEvent.triggerDoubleMuon)) return false;
    }
    // Keep only events with two muons
    return ((abs(myEvent.leadingLeptonPDGId) == 13) 
         && (abs(myEvent.secondLeptonPDGId)  == 13)); 
}



bool goesInMuonElecChannel() 
{ 
    // Keep only events with numberOfLepton == 2
    if (myEvent.numberOfLepton != 2) return false;
    // For data, keep only events from SingleMuon channel that fired the trigger
    if (sampleType == "data")
    {
        if ((sampleName != "MuEl") || (!myEvent.triggerMuonElec)) return false;
    }
    // Keep only events with an electron and a muon
    return   (((abs(myEvent.leadingLeptonPDGId) == 13) 
            && (abs(myEvent.secondLeptonPDGId)  == 11))
       ||     ((abs(myEvent.leadingLeptonPDGId) == 11) 
            && (abs(myEvent.secondLeptonPDGId)  == 13)));
}



bool goesInDoubleLeptonChannel() 
{ 
    // Double-lepton channel is the union of ee, mumu and emu channels
    bool test = (goesInDoubleElecChannel() 
              || goesInDoubleMuonChannel()
              ||   goesInMuonElecChannel()  ); 
    return test;
}



// Weighting information
// #####################

float getLumi()
{
    // TODO : upload these numbers after missing lumi is recovered
         if (goesInSingleElecChannel())  return 19154.0;
    else if (goesInSingleMuonChannel())  return 19096.0;
    else if (goesInMuonElecChannel  ())  return 19347.0;
    else if (goesInDoubleMuonChannel())  return 14595.0;
    else if (goesInDoubleElecChannel())  return 19216.0;
    else                                                       return 0.0;
}

float getWeight()
{
    float weight = 1.0;
    if (sampleType == "data") return weight;

    // Get the lumi
    float lumi = getLumi();

    // Normalize to cross section times lumi
    weight *= myEvent.weightCrossSection * lumi;

    // Apply trigger efficiency weights for singleLepton channels
    // TODO : Add trigger efficiency for dilepton in babyTuple
    if (myEvent.numberOfLepton == 1)
        weight *= myEvent.weightTriggerEfficiency;

    // Apply pile-up weight 
    // TODO : Do we confirm we'll use also this for signal ?
    weight *= myEvent.weightPileUp;

    // For signal, apply ISR reweighting
    if (sampleType == "signal")  
        weight *= myEvent.weightISRmodeling;

    // For ttbar only, apply topPt reweighting
    if (sampleName.find("ttbar") != string::npos) 
        weight *= myEvent.weightTopPt;

    return weight;
}


