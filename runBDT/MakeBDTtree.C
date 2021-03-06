
// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;

// ROOT headers
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <TLorentzVector.h>

// Define format and input file
#include "../Reader_final0210.h"
#include "../Cuts.h"

// ###################
// #  Main function  #
// ###################


bool deltaM(double, double, double, double, double, double);


int main (int argc, char *argv[])
{

  // ################################
  // ##       Open the tree        ##
  // ################################

  // Input tree   


  TFile *fin = TFile::Open(argv[1]);
  TTree* theInputTree = (TTree*) fin->Get("babyTuple");
  TFile *fout = new TFile(argv[2],"recreate");

  Float_t met;
  Float_t mT;
  Float_t mT2W;
  Float_t HTfrac;
  Float_t HT;
  Float_t b1_pt;
  Float_t lepton_pT;
  Float_t dPhi_JetMet;
  Float_t dR_LepB;
  Float_t m3b;
  Float_t mlb_hemi;
  Float_t jet1_pT;
  Float_t njets;
  Float_t METoverSqrtHT;
  Float_t dR_LepJet;
  Float_t HT_MET_lep_pt;
  Float_t Chi2SNT;
  Int_t event; 
  Float_t stop_mass;
  Float_t lsp_mass;

  TTree *BDTtree     = new TTree("BDTtree","Tree of variables");
  BDTtree->Branch("met", &met, "met/F");
  BDTtree->Branch("mT", &mT, "mT/F");
  BDTtree->Branch("mT2W", &mT2W, "mT2W/F");
  BDTtree->Branch("HTfrac", &HTfrac, "HTfrac/F");
  BDTtree->Branch("HT", &HT, "HT/F");
  BDTtree->Branch("b1_pt", &b1_pt, "b1_pt/F");
  BDTtree->Branch("lepton_pT", &lepton_pT, "lepton_pT/F");
  BDTtree->Branch("dPhi_JetMet", &dPhi_JetMet, "dPhi_JetMet/F");
  BDTtree->Branch("dR_LepB", &dR_LepB, "dR_LepB/F");
  BDTtree->Branch("m3b", &m3b, "m3b/F");
  BDTtree->Branch("mlb_hemi", &mlb_hemi, "mlb_hemi/F");
  BDTtree->Branch("jet1_pT", &jet1_pT, "jet1_pT/F");
  BDTtree->Branch("njets", &njets, "njets/F");
  BDTtree->Branch("METoverSqrtHT", &METoverSqrtHT, "METoverSqrtHT/F");
  BDTtree->Branch("dR_LepJet", &dR_LepJet, "dR_LepJet/F");
  BDTtree->Branch("HT_MET_lep_pt", &HT_MET_lep_pt, "HT_MET_lep_pt/F");
  BDTtree->Branch("Chi2SNT", &Chi2SNT, "Chi2SNT/F");
  BDTtree->Branch("event", &event, "event/I");
  BDTtree->Branch("stop_mass", &stop_mass, "stop_mass/F");
  BDTtree->Branch("lsp_mass", &lsp_mass, "lsp_mass/F");

  babyEvent myEvent;
  intermediatePointers pointers;
  InitializeBranches(theInputTree,&myEvent,&pointers);
  

  // ########################################
  // ##        Run pre-selection           ##
  // ########################################

  int counter1 = 1;
    
  for (int i = 0 ; i < theInputTree->GetEntries() ; i++)
  {
      ReadEvent(theInputTree,i,&pointers,&myEvent);


        bool isSignal = false;

        if (myEvent.mStop == -1) { isSignal = false;}
               else isSignal = true;


	
 	// Electron triggers
        if ((abs(myEvent.leadingLeptonPDGId) == 11) && (myEvent.triggerElec ==false)) continue;
        // Muon triggers

        if (abs(myEvent.leadingLeptonPDGId) == 13)
        {
                if ((myEvent.leadingLepton.Pt() < LEPTON_PT_CUT) && (myEvent.xtriggerMuon ==false)) continue;
                else if ((myEvent.leadingLepton.Pt() > LEPTON_PT_CUT) && (myEvent.triggerMuon ==false)) continue;
        }

        if (myEvent.isolatedTrackVeto == false ) continue;
        if (myEvent.tauVeto == false) continue;

        if (myEvent.MET < MET_CUT) continue;
        if (myEvent.MT < MT_CUT) continue;
        if (myEvent.nBTag < NBTAGS_CUT) continue;
        if (myEvent.nJets < JET_CUT) continue;
        if (myEvent.numberOfLepton != NLEP_CUT) continue;

        if ( isSignal && deltaM( myEvent.mStop, myEvent.mNeutralino, atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6])) == 0) continue;



        met = myEvent.MET;
        mT = myEvent.MT;
        mT2W = myEvent.MT2W;
        HTfrac = myEvent.HTRatio;
        HT = myEvent.HT;
        b1_pt = myEvent.leadingBPt;
        lepton_pT = myEvent.leadingLeptonPt;
        dPhi_JetMet = myEvent.deltaPhiMETJets;
        dR_LepB = myEvent.deltaRLeptonLeadingB;
        m3b = myEvent.M3b;
        mlb_hemi = myEvent.Mlb_hemi;
        jet1_pT = myEvent.leadingJetPt;
        njets = myEvent.nJets;
        METoverSqrtHT = myEvent.METoverSqrtHT;
        HT_MET_lep_pt = myEvent.HTPlusLeptonPtPlusMET;
        Chi2SNT = myEvent.hadronicChi2;
        event = myEvent.event;

        stop_mass = myEvent.mStop;
        lsp_mass = myEvent.mNeutralino;
      
        BDTtree->Fill();
 
        counter1++;
  } 

	      BDTtree->Write();
	      fout->Write();
	      fout->Close();  

  return (0);

}


bool deltaM( double mstop, double lsp, double range1, double range2, double x1cutoff, double x2cutoff){

  bool deltam = false;
  double deltaM = mstop - lsp;

	  if ( ((deltaM > range1 ) && (deltaM < range2 )) && (mstop > x1cutoff)   &&  (mstop < x2cutoff) ) {

	      deltam = true;

	  }

 return deltam;

}

