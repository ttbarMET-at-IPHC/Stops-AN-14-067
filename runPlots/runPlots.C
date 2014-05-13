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
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

// Define format and input file
#include "../Reader_final0210.h" 
#include "../Cuts.h" 
#include "../analysisDefinitions.h" 


using namespace TMVA;


// blabla


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

   if( argc != 7   ) help(argc,argv);


  // ################################
  // ##       Open the tree        ##
  // ################################



   TFile *fin = TFile::Open(argv[1]);
   TTree* theInputTree = (TTree*) fin->Get("babyTuple"); 
   TFile *fout = new TFile(argv[2],"recreate");


   babyEvent myEvent;
   intermediatePointers pointers;
   InitializeBranches(theInputTree,&myEvent,&pointers);
     
   bool isDefault = false; 
   bool isBVeto = false; 
   bool isDileptonFailsTrackOrTau = false; 
   bool isDilepton2Leptons = false; 
   bool isMTPeak = false; 
   bool isElec = false; 
   bool isMuon = false; 

   // Selection type	
   if (atoi(argv[3]) == 0) isDefault = true;  
   if (atoi(argv[3]) == 1) isBVeto = true;  
   if (atoi(argv[3]) == 2) isDileptonFailsTrackOrTau = true; 
   if (atoi(argv[3]) == 3) isDilepton2Leptons = true; 
   if (atoi(argv[3]) == 4) isMTPeak = true; 

   // Lepton type
//   if (atoi(argv[4]) == 1) isElec = true; 
//   if (atoi(argv[4]) == 2) isMuon = true; 

   TH1D* h1_met = new TH1D("h1_met","",50,0,1000) ;
   TH1D* h1_lepton_pT = new TH1D("h1_lepton_pT","",40,0,800) ;
   TH1D* h1_lepton_pT_Zoom = new TH1D("h1_lepton_pT_Zoom","",30,20,50) ;
   TH1D* h1_lepton_eta = new TH1D("h1_lepton_eta","",40,-2.5,2.5) ;
   TH1D* h1_mlb_hemi = new TH1D("h1_mlb_hemi","",40,0,800) ;
   TH1D* h1_m3b = new TH1D("h1_m3b","",75,0,1500) ;
   TH1D* h1_mT2W = new TH1D("h1_mT2W","",50,0,500) ;
   TH1D* h1_mT = new TH1D("h1_mT","",50,0,500) ;
   TH1D* h1_b1_pt = new TH1D("h1_b1_pt","",40,0,800) ;
   TH1D* h1_dPhi_JetMet = new TH1D("h1_dPhi_JetMet","",50,0,5.) ;
   TH1D* h1_dR_LepB = new TH1D("h1_dR_LepB","",50,0,7.) ;
   TH1D* h1_jet1_pT = new TH1D("h1_jet1_pT","",75,0,1500) ;
   TH1D* h1_jet2_pT = new TH1D("h1_jet2_pT","",75,0,1500) ;
   TH1D* h1_jet3_pT = new TH1D("h1_jet3_pT","",75,0,1500) ;
   TH1D* h1_jet4_pT = new TH1D("h1_jet4_pT","",75,0,1500) ;
   TH1D* h1_jet1_eta = new TH1D("h1_jet1_eta","",40,-2.5,2.5) ;
   TH1D* h1_HTfrac = new TH1D("h1_HTfrac","",50,0,1.) ;
   TH1D* h1_njets = new TH1D("h1_njets","",11,2.5,13.5) ;
   TH1D* h1_Chi2SNT = new TH1D("h1_Chi2SNT","",50,0,10.) ;
   TH1D* h1_METoverSqrtHT = new TH1D("h1_METoverSqrtHT","", 75,0,15) ;
   TH1D* h1_nVtx = new TH1D("h1_nvTX","",50,0,50) ;
   TH1D* BDT1 = new TH1D("BDT1",",BDT1",10,0.,0.6) ;
   TH1D* BDT2 = new TH1D("BDT2",",BDT2",10,0.,0.6) ;
   TH1D* BDT3 = new TH1D("BDT3",",BDT3",10,0.,0.6) ;
   TH1D* BDT4 = new TH1D("BDT4",",BDT4",10,0.,0.6) ;
   TH1D* BDT5 = new TH1D("BDT5",",BDT5",10,0.,0.6) ;
   TH1D* BDT6 = new TH1D("BDT6",",BDT6",10,0.,0.6) ;



   Float_t met_phi;
   Float_t met_signif;
   Float_t phi_lepton_met;
   Float_t lepton_pT;
   Float_t lepton_eta;
   Float_t lepton_phi;
   Float_t mlpjpa;
   Float_t dphiljpa;
   Float_t dphiljb;
   Float_t dphimetl;
   Float_t missmass;
   Float_t mjetlepmax;
   Float_t m3;
   Float_t m3_pt;
   Float_t mi34;
   Float_t mi34b;
   Float_t mi34b_m2;
   Float_t m3topW ;
   Float_t jet1_eta ;
   Float_t jet1_pT ;
   Float_t jet2_pT ;
   Float_t jet3_pT ;
   Float_t jet4_pT ;
   Float_t jet1_phi ;
   Float_t jet2_phi ;
   Float_t jet3_phi ;
   Float_t jet4_phi ;
   Float_t b2_pt;
   Float_t b1_eta;
   Float_t b1plusb2_pt;
   Float_t dR_b1b2;
   Float_t dPhi_b1b2;
   Float_t b1_pt_2;
   Float_t b2_pt_2;
   Float_t b1_eta_2;
   Float_t b1plusb2_pt_2;
   Float_t dR_b1b2_2;
   Float_t dPhi_b1b2_2;
   Float_t mlb1_2;
   Float_t HT;
   Float_t HT_av;
   Float_t HT_MET_lep_pt;
   Float_t mlb_hemi;
   Float_t HTfrac;
   Float_t HTfrac_FNAL;
   Float_t mT2W;
   Float_t dR_LepB;
   Float_t dR_LepJet;
   Float_t dPhi_JetMet;
   Float_t METoverSqrtHT;
   Float_t Chi2SNT;
   Float_t met;
   Float_t mT;
   Float_t b1_pt;
   Float_t m3b;
   Float_t njets;
   Float_t nbjets;
   Int_t nVtx;

   double METoverSqrtHT_;
   double bdt_R1;
   double bdt_R2;
   double bdt_R3;
   double bdt_R4;
   double bdt_R5;
   double bdt_R6;
 

   Reader* reader; 
   reader = new Reader("V");

   string NN_vars = string(argv[5]);
   TString str_NNvariables = TString(NN_vars);
   TPMERegexp _variables(",");

   set<string> NNvariables;
   int nvariables = 0;
 
   nvariables = _variables.Split(str_NNvariables);
 
   for(int i=0; i<nvariables; i++){
   NNvariables.insert(_variables[i].Data());
   }
 

   cout << "" << endl;
   cout << "**********************************************************" << endl;
   cout << "*   Will use these variables in BDT  * \n "                    
        <<             NN_vars			   			<< endl;
   cout << "**********************************************************" << endl;
   cout << "" << endl;




  if(NNvariables.find("met")!=NNvariables.end())
    reader->AddVariable("met",&met);
  if(NNvariables.find("met_phi")!=NNvariables.end())
    reader->AddVariable("met_phi",&met_phi);
  if(NNvariables.find("met_signif")!=NNvariables.end())
    reader->AddVariable("met_signif",&met_signif);
  if(NNvariables.find("mT")!=NNvariables.end())
    reader->AddVariable("mT",&mT);
  if(NNvariables.find("lepton_pT")!=NNvariables.end())
    reader->AddVariable("lepton_pT",&lepton_pT);
  if(NNvariables.find("lepton_phi")!=NNvariables.end())
    reader->AddVariable("lepton_phi",&lepton_phi);
  if(NNvariables.find("njets")!=NNvariables.end())
    reader->AddVariable("njets",&njets);
  if(NNvariables.find("nbjets")!=NNvariables.end())
    reader->AddVariable("nbjets",&nbjets);
  if(NNvariables.find("m3")!=NNvariables.end())
    reader->AddVariable("m3",&m3);
  if(NNvariables.find("m3_pt")!=NNvariables.end())
    reader->AddVariable("m3_pt",&m3_pt);
  if(NNvariables.find("m3b")!=NNvariables.end())
    reader->AddVariable("m3b",&m3b);
  if(NNvariables.find("mi34")!=NNvariables.end())
    reader->AddVariable("mi34",&mi34);
  if(NNvariables.find("mi34b")!=NNvariables.end())
    reader->AddVariable("mi34b",&mi34b);
  if(NNvariables.find("mi34b_m2")!=NNvariables.end())
    reader->AddVariable("mi34b_m2",&mi34b_m2);
  if(NNvariables.find("mjetlepmax")!=NNvariables.end())
    reader->AddVariable("mjetlepmax",&mjetlepmax);
  if(NNvariables.find("phi_lepton_met")!=NNvariables.end())
    reader->AddVariable("phi_lepton_met",&phi_lepton_met);
  if(NNvariables.find("jet1_pT")!=NNvariables.end())
    reader->AddVariable("jet1_pT",&jet1_pT);
  if(NNvariables.find("jet2_pT")!=NNvariables.end())
    reader->AddVariable("jet2_pT",&jet2_pT);
  if(NNvariables.find("jet3_pT")!=NNvariables.end())
    reader->AddVariable("jet3_pT",&jet3_pT);
  if(NNvariables.find("jet4_pT")!=NNvariables.end())
    reader->AddVariable("jet4_pT",&jet4_pT);
  if(NNvariables.find("jet1_phi")!=NNvariables.end())
    reader->AddVariable("jet1_phi",&jet1_phi);
  if(NNvariables.find("jet2_phi")!=NNvariables.end())
    reader->AddVariable("jet2_phi",&jet2_phi);
  if(NNvariables.find("jet3_phi")!=NNvariables.end())
    reader->AddVariable("jet3_phi",&jet3_phi);
  if(NNvariables.find("jet4_phi")!=NNvariables.end())
    reader->AddVariable("jet4_phi",&jet4_phi);
  if(NNvariables.find("missmass")!=NNvariables.end())
    reader->AddVariable("missmass",&missmass);
  if(NNvariables.find("mlpjpa")!=NNvariables.end())
    reader->AddVariable("mlpjpa",&mlpjpa);
  if(NNvariables.find("dphiljpa")!=NNvariables.end())
    reader->AddVariable("dphiljpa",&dphiljpa);
  if(NNvariables.find("dphimetl")!=NNvariables.end())
    reader->AddVariable("dphimetl",&dphimetl);
  if(NNvariables.find("dphiljb")!=NNvariables.end())
    reader->AddVariable("dphiljb",&dphiljb);
  if(NNvariables.find("m3topW")!=NNvariables.end())
    reader->AddVariable("m3topW",&m3topW);
  if(NNvariables.find("b1_pt")!=NNvariables.end())
    reader->AddVariable("b1_pt",&b1_pt);
  if(NNvariables.find("b1_pt_2")!=NNvariables.end())
    reader->AddVariable("b1_pt_2",&b1_pt_2);
  if(NNvariables.find("b2_pt")!=NNvariables.end())
    reader->AddVariable("b2_pt",&b2_pt);
  if(NNvariables.find("b2_pt_2")!=NNvariables.end())
    reader->AddVariable("b2_pt_2",&b2_pt_2);
  if(NNvariables.find("b1plusb2_pt")!=NNvariables.end())
    reader->AddVariable("b1plusb2_pt",&b1plusb2_pt);
  if(NNvariables.find("b1plusb2_pt_2")!=NNvariables.end())
    reader->AddVariable("b1plusb2_pt_2",&b1plusb2_pt_2);
  if(NNvariables.find("b1_eta")!=NNvariables.end())
    reader->AddVariable("b1_eta",&b1_eta);
  if(NNvariables.find("b1_eta_2")!=NNvariables.end())
    reader->AddVariable("b1_eta_2",&b1_eta_2);
  if(NNvariables.find("dR_b1b2")!=NNvariables.end())
    reader->AddVariable("dR_b1b2",&dR_b1b2);
  if(NNvariables.find("dR_b1b2_2")!=NNvariables.end())
    reader->AddVariable("dR_b1b2_2",&dR_b1b2_2);
  if(NNvariables.find("dPhi_b1b2")!=NNvariables.end())
    reader->AddVariable("dPhi_b1b2",&dPhi_b1b2);
  if(NNvariables.find("dPhi_b1b2_2")!=NNvariables.end())
    reader->AddVariable("dPhi_b1b2_2",&dPhi_b1b2_2);
  if(NNvariables.find("mlb1_2")!=NNvariables.end())
    reader->AddVariable("mlb1_2",&mlb1_2);
  if(NNvariables.find("HT")!=NNvariables.end())
    reader->AddVariable("HT",&HT);
  if(NNvariables.find("HT_av")!=NNvariables.end())
    reader->AddVariable("HT_av",&HT_av);
  if(NNvariables.find("HT_MET_lep_pt")!=NNvariables.end())
    reader->AddVariable("HT_MET_lep_pt",&HT_MET_lep_pt);
  if(NNvariables.find("mlb_hemi")!=NNvariables.end())
    reader->AddVariable("mlb_hemi",&mlb_hemi);
  if(NNvariables.find("HTfrac")!=NNvariables.end())
    reader->AddVariable("HTfrac",&HTfrac);
  if(NNvariables.find("HTfrac_FNAL")!=NNvariables.end())
    reader->AddVariable("HTfrac_FNAL",&HTfrac_FNAL);
  if(NNvariables.find("mT2W")!=NNvariables.end())
    reader->AddVariable("mT2W",&mT2W);
  if(NNvariables.find("mT")!=NNvariables.end())
    reader->AddVariable("mT",&mT);
  if(NNvariables.find("dR_LepB")!=NNvariables.end())
    reader->AddVariable("dR_LepB",&dR_LepB);
  if(NNvariables.find("dR_LepJet")!=NNvariables.end())
    reader->AddVariable("dR_LepJet",&dR_LepJet);
  if(NNvariables.find("dPhi_JetMet")!=NNvariables.end())
    reader->AddVariable("dPhi_JetMet",&dPhi_JetMet);
  if(NNvariables.find("METoverSqrtHT")!=NNvariables.end())
    reader->AddVariable("METoverSqrtHT",&METoverSqrtHT);
  if(NNvariables.find("Chi2SNT")!=NNvariables.end())
    reader->AddVariable("Chi2SNT",&Chi2SNT);



   string Decay_Mode = string(argv[6]);

 
   TString BDT_dir = "../30AprWeights/";



   if (Decay_Mode == "t2bw025") {
   reader->BookMVA("bdt_R1",  BDT_dir + "BDT_"+Decay_Mode+"_Reg1.weights.xml");
   reader->BookMVA("bdt_R2",  BDT_dir + "BDT_"+Decay_Mode+"_Reg1.weights.xml");
   reader->BookMVA("bdt_R3",  BDT_dir + "BDT_"+Decay_Mode+"_Reg3.weights.xml");
   reader->BookMVA("bdt_R4",  BDT_dir + "BDT_"+Decay_Mode+"_Reg4.weights.xml");
   reader->BookMVA("bdt_R5",  BDT_dir + "BDT_"+Decay_Mode+"_Reg4.weights.xml");
   reader->BookMVA("bdt_R6",  BDT_dir + "BDT_"+Decay_Mode+"_Reg6.weights.xml");
   }

   if (Decay_Mode == "t2bw050") {
   reader->BookMVA("bdt_R1",  BDT_dir + "BDT_"+Decay_Mode+"_Reg1.weights.xml");
   reader->BookMVA("bdt_R2",  BDT_dir + "BDT_"+Decay_Mode+"_Reg1.weights.xml");
   reader->BookMVA("bdt_R3",  BDT_dir + "BDT_"+Decay_Mode+"_Reg3.weights.xml");
   reader->BookMVA("bdt_R4",  BDT_dir + "BDT_"+Decay_Mode+"_Reg5.weights.xml");
   reader->BookMVA("bdt_R5",  BDT_dir + "BDT_"+Decay_Mode+"_Reg5.weights.xml");
   reader->BookMVA("bdt_R6",  BDT_dir + "BDT_"+Decay_Mode+"_Reg6.weights.xml");
   }


   if (Decay_Mode == "t2bw075") {
   reader->BookMVA("bdt_R1",  BDT_dir + "BDT_"+Decay_Mode+"_Reg1.weights.xml");
   reader->BookMVA("bdt_R2",  BDT_dir + "BDT_"+Decay_Mode+"_Reg2.weights.xml");
   reader->BookMVA("bdt_R3",  BDT_dir + "BDT_"+Decay_Mode+"_Reg3.weights.xml");
   reader->BookMVA("bdt_R4",  BDT_dir + "BDT_"+Decay_Mode+"_Reg3.weights.xml");
   reader->BookMVA("bdt_R5",  BDT_dir + "BDT_"+Decay_Mode+"_Reg5.weights.xml");
   reader->BookMVA("bdt_R6",  BDT_dir + "BDT_"+Decay_Mode+"_Reg5.weights.xml");
   }


  // ########################################
  // ##        Run over the events         ##
  // ########################################

  for (int i = 0 ; i < theInputTree->GetEntries() ; i++){

      ReadEvent(theInputTree,i,&pointers,&myEvent);

      
//        bool isTTbar  	   = false;
        bool isSignal 	   = false;
        bool isData  	   = false;
        bool isDoubleElec  = false;
        bool isDoubleMuon  = false;
        bool isMuEl  	   = false;
        bool isSingleElec  = false;
        bool isSingleMuon  = false;


        if (myEvent.mStop == -1) { isSignal = false;}
                else isSignal = true;

//        if (string(argv[1]).find("ttbar") != std::string::npos) isTTbar = true; 
        if (string(argv[1]).find("SingleElec") != std::string::npos) isSingleElec = true; 
        if (string(argv[1]).find("SingleMuon") != std::string::npos) isSingleMuon = true; 
        if (string(argv[1]).find("DoubleElec") != std::string::npos) isDoubleElec = true; 
        if (string(argv[1]).find("DoubleMuon") != std::string::npos) isDoubleMuon = true; 
        if (string(argv[1]).find("MuEl") != std::string::npos) isMuEl = true; 

        if (isSingleElec || isSingleMuon || isDoubleElec || isDoubleMuon || isMuEl) isData = true;

        if (isElec && ((abs(myEvent.leadingLeptonPDGId) != 11))) continue;
        if (isMuon && ((abs(myEvent.leadingLeptonPDGId) != 13))) continue;
        if (isMuEl && ((abs(myEvent.leadingLeptonPDGId) + abs(myEvent.secondLeptonPDGId) == 24))) continue;




  //      if ( !(isData && isDilepton) ) {

		if ( !(isDileptonFailsTrackOrTau || isDilepton2Leptons) ){ 

			if ((abs(myEvent.leadingLeptonPDGId) == 11) && (myEvent.triggerElec ==false)) continue;
			if ((abs(myEvent.leadingLeptonPDGId) == 13) && (myEvent.triggerMuon ==false)) continue; 

		}


		if ( isDileptonFailsTrackOrTau || isDilepton2Leptons ) {

			if ((abs(myEvent.leadingLeptonPDGId) == 11) && (myEvent.triggerDoubleElec ==false)) continue;
			if (((abs(myEvent.leadingLeptonPDGId) == 13) && (myEvent.triggerDoubleMuon ==false))) continue;
			if (isMuEl && (myEvent.triggerMuonElec ==false)) continue;

		}

//	}



        if (myEvent.MET < MET_CUT) continue;
        if (myEvent.nJets < JET_CUT) continue;
        if (myEvent.leadingLepton.Pt() < LEPTON_PT_CUT) continue;





        if ( isDefault ) {

		if (myEvent.MT < MT_CUT ) continue;
		if (myEvent.nBTag < NBTAGS_CUT) continue;
	    	if (myEvent.numberOfLepton != NLEP_CUT) continue;
	        if (myEvent.isolatedTrackVeto == false ) continue;
 	        if (myEvent.tauVeto == false) continue;
        }



        if ( isBVeto ) {

	if (myEvent.MT < MT_CUT ) continue;
        if (myEvent.nBTag != 0) continue;
        if (myEvent.numberOfLepton != NLEP_CUT) continue;
        if (myEvent.isolatedTrackVeto == false ) continue;
        if (myEvent.tauVeto == false) continue;

	}


        if ( isMTPeak ) {

//goesIn0BtagCR1();
		if (myEvent.MT < 50) continue;
		if (myEvent.MT > 80) continue;
		if (myEvent.nBTag < NBTAGS_CUT) continue;
	    	if (myEvent.numberOfLepton != NLEP_CUT) continue;
	        if (myEvent.isolatedTrackVeto == false ) continue;
 	        if (myEvent.tauVeto == false) continue;

        }




        if ( isDileptonFailsTrackOrTau ) {

		if (myEvent.MT < MT_CUT) continue;
		if (myEvent.nBTag < NBTAGS_CUT) continue;
		if ( isDoubleElec && (( abs(myEvent.leadingLeptonPDGId) != 11) || abs(myEvent.secondLeptonPDGId) != 11) ) continue;
		if ( isDoubleMuon && (( abs(myEvent.leadingLeptonPDGId) != 13) || abs(myEvent.secondLeptonPDGId) != 13) ) continue;
		if ( isMuEl && ( abs(myEvent.leadingLeptonPDGId) +  abs(myEvent.secondLeptonPDGId) != 24) ) continue;
	        if ( (isDoubleElec || isDoubleMuon) && (myEvent.leadingLeptonPDGId + myEvent.secondLeptonPDGId !=0))  continue;       
		if ( !((myEvent.isolatedTrackVeto == true ) || (myEvent.tauVeto == true))) continue; 

        }




        if ( isDilepton2Leptons ) {

		if (myEvent.MT < MT_CUT) continue;
		if (myEvent.nBTag < NBTAGS_CUT) continue;
		if ( isDoubleElec && (( abs(myEvent.leadingLeptonPDGId) != 11) || abs(myEvent.secondLeptonPDGId) != 11) ) continue;
		if ( isDoubleMuon && (( abs(myEvent.leadingLeptonPDGId) != 13) || abs(myEvent.secondLeptonPDGId) != 13) ) continue;
		if ( isMuEl && ( abs(myEvent.leadingLeptonPDGId) +  abs(myEvent.secondLeptonPDGId) != 24) ) continue;
	        if ( (isDoubleElec || isDoubleMuon) && (myEvent.leadingLeptonPDGId + myEvent.secondLeptonPDGId !=0))  continue;       
		if (myEvent.numberOfLepton != 2) continue;  

        }



        if ( isSignal && !((myEvent.mStop == 200) && (myEvent.mNeutralino == 25)) )continue;


      
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
	jet2_pT = myEvent.jets[1].Pt();
	jet3_pT = myEvent.jets[2].Pt();
	jet4_pT = myEvent.jets[3].Pt();
	jet1_eta = myEvent.jets[0].Eta(); 
	njets = myEvent.nJets;
	HT_MET_lep_pt = myEvent.HTPlusLeptonPtPlusMET;
	Chi2SNT = myEvent.hadronicChi2;
	METoverSqrtHT_ = myEvent.METoverSqrtHT;
	dR_LepB = myEvent.deltaRLeptonLeadingB;
	nVtx = myEvent.numberOfPrimaryVertices;


 
        bdt_R1 = reader->EvaluateMVA( "bdt_R1" );
        bdt_R2 = reader->EvaluateMVA( "bdt_R2" );
        bdt_R3 = reader->EvaluateMVA( "bdt_R3" );
        bdt_R4 = reader->EvaluateMVA( "bdt_R4" );
        bdt_R5 = reader->EvaluateMVA( "bdt_R5" );
        bdt_R6 = reader->EvaluateMVA( "bdt_R6" );


//	if  (bdt_R1 < 0.3)  continue;

                double lumi = 1.0;
                double weight = 1.0; 


		if  ( abs(myEvent.leadingLeptonPDGId) == 11 )  {lumi = 19250.;}
		if  ( abs(myEvent.leadingLeptonPDGId) == 13 )  {lumi = 19190.;}
		if  ( (isDoubleMuon && abs(myEvent.leadingLeptonPDGId) == 13) )  {lumi = 14690.;}
		if  ( (isDoubleElec && abs(myEvent.leadingLeptonPDGId) == 11) )  {lumi = 19316.;}
		if  ( isMuEl )        {lumi = 19447.;}


             //weight *= myEvent.weightCrossSection * myEvent.weightPileUp * lumi * myEvent.weightTopPt;
       
             if ( !(isDileptonFailsTrackOrTau || isDilepton2Leptons) ) weight *= myEvent.weightTriggerEfficiency;


  	     if (isData){ 

             h1_met->Fill(met);
             h1_lepton_pT->Fill(lepton_pT);
             h1_lepton_pT_Zoom->Fill(lepton_pT);
             h1_lepton_eta->Fill(lepton_eta);
             h1_mlb_hemi->Fill(min(799.99, (double)mlb_hemi));
             h1_m3b->Fill(min(1499.99,(double)m3b));
             h1_mT2W->Fill(mT2W);
             h1_mT->Fill(mT);
             h1_b1_pt->Fill(min(799.99, (double)b1_pt));
             h1_dPhi_JetMet->Fill(dPhi_JetMet);
             h1_dR_LepB->Fill(dR_LepB);
             h1_jet1_pT->Fill(min(1499.99,(double)jet1_pT));
             h1_jet2_pT->Fill(min(1499.99,(double)jet2_pT));
             h1_jet3_pT->Fill(min(1499.99,(double)jet3_pT));
             h1_jet4_pT->Fill(min(1499.99,(double)jet4_pT));
             h1_jet1_eta->Fill(jet1_eta);
             h1_HTfrac->Fill(HTfrac);
             h1_njets->Fill(min(6,(int)njets));
             h1_nVtx->Fill(nVtx);
             h1_Chi2SNT->Fill(min(9.99,(double)Chi2SNT));  
             h1_METoverSqrtHT->Fill(min(14.99, (double)METoverSqrtHT_));
             BDT1->Fill(bdt_R1);
	     BDT2->Fill(bdt_R2);
	     BDT3->Fill(bdt_R3);
	     BDT4->Fill(bdt_R4);
	     BDT5->Fill(bdt_R5);
	     BDT6->Fill(bdt_R6);

	     } else
      
		     h1_met->Fill(met, weight);
		     h1_lepton_pT->Fill(lepton_pT, weight);
		     h1_lepton_pT_Zoom->Fill(lepton_pT, weight);
		     h1_lepton_eta->Fill(lepton_eta, weight);
		     h1_mlb_hemi->Fill(min(799.99, (double)mlb_hemi), weight);
		     h1_m3b->Fill(min(1499.99, (double)m3b), weight);
		     h1_mT2W->Fill(mT2W, weight);
		     h1_mT->Fill(mT, weight);
		     h1_b1_pt->Fill(min(799.99,(double)b1_pt), weight);
		     h1_dPhi_JetMet->Fill(dPhi_JetMet, weight);
		     h1_dR_LepB->Fill(dR_LepB, weight);
		     h1_jet1_pT->Fill(min(1499.99, (double)jet1_pT), weight);
		     h1_jet2_pT->Fill(min(1499.99, (double)jet2_pT), weight);
		     h1_jet3_pT->Fill(min(1499.99, (double)jet3_pT), weight);
		     h1_jet4_pT->Fill(min(1499.99, (double)jet4_pT), weight);
		     h1_jet1_eta->Fill(jet1_eta, weight);
		     h1_HTfrac->Fill(HTfrac, weight);
             	     h1_njets->Fill(min(6,(int)njets), weight);
             	     h1_nVtx->Fill(nVtx, weight);
		     h1_Chi2SNT->Fill(min(9.99, (double)Chi2SNT), weight);
		     h1_METoverSqrtHT->Fill(min(14.99, (double)METoverSqrtHT_), weight);
		     BDT1->Fill(bdt_R1, weight);
		     BDT2->Fill(bdt_R2, weight);
		     BDT3->Fill(bdt_R3, weight);
		     BDT4->Fill(bdt_R4, weight);
		     BDT5->Fill(bdt_R5, weight);
		     BDT6->Fill(bdt_R6, weight);


  } 
    
      fout->cd();
      h1_met->Write(); 
      h1_lepton_pT->Write(); 
      h1_lepton_pT_Zoom->Write(); 
      h1_lepton_eta->Write(); 
      h1_m3b->Write(); 
      h1_mlb_hemi->Write(); 
      h1_mT2W->Write(); 
      h1_mT->Write(); 
      h1_b1_pt->Write(); 
      h1_dPhi_JetMet->Write(); 
      h1_dR_LepB->Write(); 
      h1_jet1_pT->Write(); 
      h1_jet1_eta->Write(); 
      h1_HTfrac->Write(); 
      h1_njets->Write(); 
      h1_Chi2SNT->Write(); 
      h1_METoverSqrtHT->Write(); 
      h1_nVtx->Write(); 
      BDT1->Write(); 
      BDT2->Write(); 
      BDT3->Write(); 
      BDT4->Write(); 
      fout->Write();
      fout->Close();

  return (0);

}


