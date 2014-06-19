// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;

#include <algorithm>
#include "TColor.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include "TString.h"
#include "TPRegexp.h"
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <set>
#include <string>
#include <TLorentzVector.h>

// Define format and input file
#include "../selectionDefinitions.h" 



void help(int argc, char* argv[]) {
  cout << "\n\n usage: \n"
       << "./runPlots <INPUT FILE> <OUTPUT FILE> <SELECTION TYPE> <TTBAR TYPE> <DI-LEPTON TYPE> <DI-LEPTON SELECTION TYPE> <LEPTON TYPE> <VARIABLES USED IN BDT> <SETUP DIRECTORY> <DECAY MODE> \n" 
       << "./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/SingleElec.root SingleElecBVetoElec.root 1 0 0 0 0 \"met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 T2bw050\" " << endl;
       exit(0);
}



// ###################
// #  Main function  #
// ###################

int main (int argc, char *argv[])
{

//   if( argc != 7   ) help(argc,argv);


  // ################################
  // ##       Open the tree        ##
  // ################################



   TFile *fin = TFile::Open(argv[1]);
   TTree* theInputTree = (TTree*) fin->Get("babyTuple"); 
   TFile *fout = new TFile(argv[2],"recreate");


//   babyEvent myEvent;
   intermediatePointers pointers;
   InitializeBranchesForReading(theInputTree,&myEvent,&pointers);
     


   TH1D* h1_met = new TH1D("h1_met","",50,0,1000) ;
   TH1D* h1_lepton_pT = new TH1D("h1_lepton_pT","",40,0,800) ;
   TH1D* h1_lepton_eta = new TH1D("h1_lepton_eta","",40,-2.5,2.5) ;
   TH1D* h1_mlb_hemi = new TH1D("h1_mlb_hemi","",40,0,800) ;
   TH1D* h1_m3b = new TH1D("h1_m3b","",75,0,1500) ;
   TH1D* h1_mT2W = new TH1D("h1_mT2W","",50,0,500) ;
   TH1D* h1_mT = new TH1D("h1_mT","",50,0,500) ;
   TH1D* h1_b1_pt = new TH1D("h1_b1_pt","",40,0,800) ;
   TH1D* h1_dPhi_JetMet = new TH1D("h1_dPhi_JetMet","",50,0,5.) ;
   TH1D* h1_dR_LepB = new TH1D("h1_dR_LepB","",50,0,7.) ;
   TH1D* h1_jet1_pT = new TH1D("h1_jet1_pT","",75,0,1500) ;
   TH1D* h1_HT = new TH1D("h1_HT","",50,0,1.) ;
   TH1D* h1_HTfrac = new TH1D("h1_HTfrac","",50,0,1.) ;
   TH1D* h1_njets = new TH1D("h1_njets","",11,2.5,13.5) ;
   TH1D* h1_Chi2SNT = new TH1D("h1_Chi2SNT","",50,0,10.) ;
   TH1D* h1_METoverSqrtHT = new TH1D("h1_METoverSqrtHT","", 75,0,15) ;
   TH1D* h1_nVtx = new TH1D("h1_nvTX","",50,0,50) ;

   TH1D* h1_BDT_output_t2bw025_R1 = new TH1D("h1_BDT_output_t2bw025_R1","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw025_R3 = new TH1D("h1_BDT_output_t2bw025_R3","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw025_R4 = new TH1D("h1_BDT_output_t2bw025_R4","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw025_R6 = new TH1D("h1_BDT_output_t2bw025_R6","",100,-1,1.) ;

   TH1D* h1_BDT_output_t2bw050_R1 = new TH1D("h1_BDT_output_t2bw050_R1","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw050_R3 = new TH1D("h1_BDT_output_t2bw050_R3","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw050_R4 = new TH1D("h1_BDT_output_t2bw050_R4","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw050_R5 = new TH1D("h1_BDT_output_t2bw050_R5","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw050_R6 = new TH1D("h1_BDT_output_t2bw050_R6","",100,-1,1.) ;

   TH1D* h1_BDT_output_t2bw075_R1 = new TH1D("h1_BDT_output_t2bw075_R1","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw075_R2 = new TH1D("h1_BDT_output_t2bw075_R2","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw075_R3 = new TH1D("h1_BDT_output_t2bw075_R3","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2bw075_R5 = new TH1D("h1_BDT_output_t2bw075_R5","",100,-1,1.) ;

   TH1D* h1_BDT_output_t2tt_R1 = new TH1D("h1_BDT_output_t2tt_R1","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2tt_R2 = new TH1D("h1_BDT_output_t2tt_R2","",100,-1,1.) ;
   TH1D* h1_BDT_output_t2tt_R5 = new TH1D("h1_BDT_output_t2tt_R5","",100,-1,1.) ;


   Float_t lepton_pT;
   Float_t lepton_eta;
   Float_t jet1_pT ;
   Float_t mlb_hemi;
   Float_t HT;
   Float_t HTfrac;
   Float_t mT2W;
   Float_t dR_LepB;
   Float_t dPhi_JetMet;
   Float_t METoverSqrtHT;
   Float_t Chi2SNT;
   Float_t met;
   Float_t mT;
   Float_t b1_pt;
   Float_t m3b;
   Float_t njets;
   Int_t nVtx;

   double METoverSqrtHT_;  // cast as double for the overflow bins
 


  // ########################################
  // ##        Run over the events         ##
  // ########################################

  for (int i = 0 ; i < theInputTree->GetEntries() ; i++){


        ReadEvent(theInputTree,i,&pointers,&myEvent);


        if (string(argv[1]).find("ttbar_madgraph") != std::string::npos)   	{sampleName = "ttbar_madgraph"; } 
        if (string(argv[1]).find("SingleElec") != std::string::npos) 		{sampleName = "SingleElec"; } 
        if (string(argv[1]).find("SingleMuon") != std::string::npos) 		{sampleName = "SingleMuon";} 
        if (string(argv[1]).find("DoubleElec") != std::string::npos) 		{sampleName = "DoubleElec";} 
        if (string(argv[1]).find("DoubleMuon") != std::string::npos) 		{sampleName = "DoubleMuon";} 
        if (string(argv[1]).find("MuEl") != std::string::npos) 	     		{sampleName = "MuEl";} 

        if (myEvent.mStop == -1) 						{sampleType = "signal"; }
        if ( (sampleName == "SingleElec") || (sampleName == "SingleMuon") 
	  || (sampleName == "DoubleElec") || (sampleName == "DoubleMuon") 
	  || (sampleName == "MuEl")) {						 sampleType = "data"; } 




		if ( atoi(argv[3]) == 0 ) {
			if (goesInPreselectionMTtail() == 0) continue;
		}

		if ( atoi(argv[3]) == 1 ) {
			if (goesIn0BtagControlRegion() == 0) continue;
		}

		if ( atoi(argv[3]) == 2 ) {
			if (goesInVetosControlRegion() == 0) continue;
		}

		if ( atoi(argv[3]) == 3 ) {
			if (goesInDileptonControlRegion() == 0) continue;
		}

		if ( atoi(argv[3]) == 4 ) {
			if (goesInPreselectionMTpeak() == 0) continue;
		}


		
		if ( (myEvent.mNeutralino > 0) && !(( myEvent.mStop == atoi(argv[4]) ) && (myEvent.mNeutralino ==  atoi(argv[5]) )) ) continue;

//		cout << myEvent.BDT_output_t2bw025_R1 << endl;

	      
		met = myEvent.MET; 
		mT = myEvent.MT;
		mT2W = myEvent.MT2W;
		HT = myEvent.HT;
		HTfrac = myEvent.HTRatio;
		b1_pt = myEvent.leadingBPt;
		lepton_pT = myEvent.leadingLeptonPt;
		lepton_eta = myEvent.leadingLepton.Eta(); 
		dPhi_JetMet = myEvent.deltaPhiMETJets;
		m3b = myEvent.M3b;
		mlb_hemi = myEvent.Mlb_hemi;
		jet1_pT = myEvent.leadingJetPt;
		njets = myEvent.nJets;
	//	HT_MET_lep_pt = myEvent.HTPlusLeptonPtPlusMET;
		Chi2SNT = myEvent.hadronicChi2;
		METoverSqrtHT_ = myEvent.METoverSqrtHT;
		dR_LepB = myEvent.deltaRLeptonLeadingB;
		nVtx = myEvent.numberOfPrimaryVertices;


		double weight = getWeight(); 

		h1_met->Fill(met, weight);
		h1_lepton_pT->Fill(lepton_pT, weight);
		h1_lepton_eta->Fill(lepton_eta, weight);
		h1_mlb_hemi->Fill(min(799.99, (double)mlb_hemi), weight);
		h1_m3b->Fill(min(1499.99, (double)m3b), weight);
		h1_mT2W->Fill(mT2W, weight);
		h1_mT->Fill(mT, weight);
		h1_b1_pt->Fill(min(799.99,(double)b1_pt), weight);
		h1_dPhi_JetMet->Fill(dPhi_JetMet, weight);
		h1_dR_LepB->Fill(dR_LepB, weight);
		h1_jet1_pT->Fill(min(1499.99, (double)jet1_pT), weight);
		h1_HT->Fill(HT, weight);
		h1_HTfrac->Fill(HTfrac, weight);
		h1_njets->Fill(min(6,(int)njets), weight);
		h1_nVtx->Fill(nVtx, weight);
		h1_Chi2SNT->Fill(min(9.99, (double)Chi2SNT), weight);
		h1_METoverSqrtHT->Fill(min(14.99, (double)METoverSqrtHT_), weight);

		h1_BDT_output_t2bw025_R1->Fill(myEvent.BDT_output_t2bw025_R1, weight);
		h1_BDT_output_t2bw025_R3->Fill(myEvent.BDT_output_t2bw025_R3, weight);
		h1_BDT_output_t2bw025_R4->Fill(myEvent.BDT_output_t2bw025_R4, weight);
		h1_BDT_output_t2bw025_R6->Fill(myEvent.BDT_output_t2bw025_R6, weight);

		h1_BDT_output_t2bw050_R1->Fill(myEvent.BDT_output_t2bw050_R1, weight);
		h1_BDT_output_t2bw050_R3->Fill(myEvent.BDT_output_t2bw050_R3, weight);
		h1_BDT_output_t2bw050_R4->Fill(myEvent.BDT_output_t2bw050_R4, weight);
		h1_BDT_output_t2bw050_R5->Fill(myEvent.BDT_output_t2bw050_R5, weight);
		h1_BDT_output_t2bw050_R6->Fill(myEvent.BDT_output_t2bw050_R6, weight);

		h1_BDT_output_t2bw075_R1->Fill(myEvent.BDT_output_t2bw075_R1, weight);
		h1_BDT_output_t2bw075_R2->Fill(myEvent.BDT_output_t2bw075_R2, weight);
		h1_BDT_output_t2bw075_R3->Fill(myEvent.BDT_output_t2bw075_R3, weight);
		h1_BDT_output_t2bw075_R5->Fill(myEvent.BDT_output_t2bw075_R5, weight);

		h1_BDT_output_t2tt_R1->Fill(myEvent.BDT_output_t2tt_R1, weight);
		h1_BDT_output_t2tt_R2->Fill(myEvent.BDT_output_t2tt_R2, weight);
		h1_BDT_output_t2tt_R5->Fill(myEvent.BDT_output_t2tt_R5, weight);
		
  } 

    
      fout->cd();

      h1_met->Write(); 
      h1_lepton_pT->Write(); 
      h1_lepton_eta->Write(); 
      h1_m3b->Write(); 
      h1_mlb_hemi->Write(); 
      h1_mT2W->Write(); 
      h1_mT->Write(); 
      h1_b1_pt->Write(); 
      h1_dPhi_JetMet->Write(); 
      h1_dR_LepB->Write(); 
      h1_jet1_pT->Write(); 
      h1_HT->Write(); 
      h1_HTfrac->Write(); 
      h1_njets->Write(); 
      h1_Chi2SNT->Write(); 
      h1_METoverSqrtHT->Write(); 
      h1_nVtx->Write();
 
      h1_BDT_output_t2bw025_R1->Write();
      h1_BDT_output_t2bw025_R3->Write();
      h1_BDT_output_t2bw025_R4->Write();
      h1_BDT_output_t2bw025_R6->Write();

      h1_BDT_output_t2bw050_R1->Write();
      h1_BDT_output_t2bw050_R3->Write();
      h1_BDT_output_t2bw050_R4->Write();
      h1_BDT_output_t2bw050_R5->Write();
      h1_BDT_output_t2bw050_R6->Write();

      h1_BDT_output_t2bw075_R1->Write();
      h1_BDT_output_t2bw075_R2->Write();
      h1_BDT_output_t2bw075_R3->Write();
      h1_BDT_output_t2bw075_R5->Write();

      h1_BDT_output_t2tt_R1->Write();
      h1_BDT_output_t2tt_R2->Write();
      h1_BDT_output_t2tt_R5->Write();

      fout->Write();
      fout->Close();



      return (0);

}



