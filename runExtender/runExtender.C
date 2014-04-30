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
      
// ROOT headers
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TBranch.h>
#include <set>
#include <string>
#include <TLorentzVector.h>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"


// Define format of input file
#include "../Reader.h"
#include "../Writer.h"

using namespace TMVA;

//test
void printProgressBar(int current, int max);

int main (int argc, char *argv[])
{

  // ################################
  // ##       Open the tree        ##
  // ################################

 /*  TH1D* BDT1 = new TH1D("BDT1",",BDT1",80,-1,1) ;
   TH1D* BDT2 = new TH1D("BDT2",",BDT2",80,-1,1) ;
   TH1D* BDT3 = new TH1D("BDT3",",BDT3",80,-1,1) ;
   TH1D* BDT4 = new TH1D("BDT4",",BDT4",80,-1,1) ;
//   TH1D* BDT5 = new TH1D("BDT5",",BDT5",80,-1,1) ;
//   TH1D* BDT6 = new TH1D("BDT6",",BDT6",80,-1,1) ;
*/


  TFile *fin = TFile::Open(argv[1]);
  TTree* theInputTree = (TTree*) fin->Get("babyTuple");
  TFile *fout = new TFile(argv[2],"recreate");

  babyEvent myEvent;
  intermediatePointers pointers;
  InitializeBranchesForReading(theInputTree,&myEvent,&pointers);

  TTree* theOutputTree = new TTree("babyTuple","");
  InitializeBranchesForWriting(theOutputTree,&myEvent);


   Float_t met_phi;
   Float_t met_signif;
   Float_t phi_lepton_met;
   Float_t lepton_pT;
   Float_t lepton_phi;
   Float_t nbjets;
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
   Float_t chargino_mixing;
   Float_t mT2;
   Float_t mT2bl;
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
   Float_t stop_mass;
   Float_t lsp_mass;



   double bdt_R1;
   double bdt_R2;
   double bdt_R3;
   double bdt_R4;
   //double bdt_R5;
   //double bdt_R6;

   Reader* reader;
   reader = new Reader("V");

    string NN_vars = string(argv[3]);
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
   cout << "*   Will use these variables in BDT  * "                    << NN_vars << endl;
   cout << "**********************************************************" << endl;
   cout << "" << endl;


    string setup_directory = string(argv[4]); 

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
   if(NNvariables.find("HT")!=NNvariables.end())
    reader->AddVariable("HT",&HT);


   string Decay_Mode = string(argv[5]);

   TString BDT_dir = "/afs/cern.ch/user/l/lara/public/weights/t2tt";

//   reader->BookMVA("bdt_R1",  BDT_dir + "/BDT_t2tt_Reg1.weights.xml");
   reader->BookMVA("bdt_R2",  BDT_dir + "/BDT_t2tt_Reg3.weights.xml");
   reader->BookMVA("bdt_R3",  BDT_dir + "/BDT_t2tt_Reg4.weights.xml");
//   reader->BookMVA("bdt_R4",  BDT_dir + "/BDT_t2bw075_Reg6.weights.xml");

  // Add a vector<float> branch that will contain the additional
  // info, like BDT outputs.


  vector<Float_t> BDToutputs;
  Int_t isUsedInBDT;
  //theOutputTree->Branch("BDToutputs",     "std::vector<Float_t>",          &(BDToutputs));
  theOutputTree->Branch("BDToutputs",      &(BDToutputs));
  theOutputTree->Branch("isUsedInBDT",     &(isUsedInBDT));


  // ########################################
  // ##        Run over the events         ##
  // ########################################


  for (int i = 0 ; i < theInputTree->GetEntries() ; i++)
  //for (int i = 0 ; i < 1000 ; i++)
  {
      
      if (i % (theInputTree->GetEntries() / 50) == 0) 
              printProgressBar(i,theInputTree->GetEntries());

      // Read entry from input tree 
      
      ReadEvent(theInputTree,i,&pointers,&myEvent);



        bool isSignal = false;
        bool isTTbar  = false;

        if (myEvent.mStop == -1) { isSignal = false;}
                else isSignal = true;

        if (string(argv[1]).find("ttbar") != std::string::npos) isTTbar = true;


        // Electron triggers
        if ((abs(myEvent.leadingLeptonPDGId) == 11) && (myEvent.triggerElec ==false)) continue;
        // Muon triggers

        if (abs(myEvent.leadingLeptonPDGId) == 13)
        {
                if ((myEvent.leadingLepton.Pt() < 25) && (myEvent.xtriggerMuon ==false)) continue;
                else if ((myEvent.leadingLepton.Pt() > 25) && (myEvent.triggerMuon ==false)) continue;
        }

        if (myEvent.isolatedTrackVeto == false ) continue;
        if (myEvent.tauVeto == false) continue;

        if (myEvent.MET < 80) continue;
        if (myEvent.MT < 120) continue;
        if (myEvent.nBTag < 1) continue;
        if (myEvent.nJets < 4) continue;
        if (myEvent.numberOfLepton != 1) continue;


        if ( isSignal && !((myEvent.mStop == atof(argv[6])) && (myEvent.mNeutralino == atof(argv[7]))) )continue;

//        if (myEvent.event%4 == 0) isUsedInBDT = 1; else isUsedInBDT = 0; 

        if ( isSignal && ((myEvent.event%2)==1)) isUsedInBDT = 1;
        else if ( isTTbar && ((myEvent.event%2)==1))  isUsedInBDT = 1;
 
		else isUsedInBDT = 0;
        //cout << "isUsedInBDT: " << isUsedInBDT <<  endl;

      
        met = myEvent.MET;
        mT = myEvent.MT;
        mT2W = myEvent.MT2W;
        HT = myEvent.HT;
        HTfrac = myEvent.HTRatio;
        b1_pt = myEvent.leadingBPt;
        lepton_pT = myEvent.leadingLeptonPt;
        dPhi_JetMet = myEvent.deltaPhiMETJets;
        dR_LepB = myEvent.deltaRLeptonLeadingB;
        m3b = myEvent.M3b;
        mlb_hemi = myEvent.Mlb_hemi;
        jet1_pT = myEvent.leadingJetPt;
        njets = myEvent.nJets;
        METoverSqrtHT = myEvent.METoverSqrtHT;
        //dR_LepJet 
        HT_MET_lep_pt = myEvent.HTPlusLeptonPtPlusMET;
        Chi2SNT = myEvent.hadronicChi2;

        stop_mass = myEvent.mStop;
        lsp_mass = myEvent.mNeutralino;

        bdt_R1 = 0;

  //      bdt_R1 = reader->EvaluateMVA( "bdt_R1" );
        bdt_R2 = reader->EvaluateMVA( "bdt_R2" );
        bdt_R3 = reader->EvaluateMVA( "bdt_R3" );
//        bdt_R4 = reader->EvaluateMVA( "bdt_R4" );

  //      bdt_R2 = 0;
   //     bdt_R3 = 0;

  //      bdt_R4 = 0;


        BDToutputs.clear();           // Don't forget to clear the vector from the previous info
        BDToutputs.push_back(bdt_R1);
        BDToutputs.push_back(bdt_R2);
        BDToutputs.push_back(bdt_R3);
    //    BDToutputs.push_back(bdt_R4);

   //cout << bdt_R2 << endl; 
        theOutputTree->Fill();

 


  }           

  printProgressBar(theInputTree->GetEntries(),theInputTree->GetEntries());
  cout << endl;

  theOutputTree->Write(0, TObject::kOverwrite); 

  return (0); 
}             

void printProgressBar(int current, int max)
{
    std::string bar;
    int percent = 100 * (float) current / (float) max;

    for(int i = 0; i < 50; i++)
    {
        if( i < (percent/2))       bar.replace(i,1,"=");
        else if( i == (percent/2)) bar.replace(i,1,">");
        else                       bar.replace(i,1," ");
    }

    std::cout << "  [Progress]  ";
    std::cout << "[" << bar << "] ";
    std::cout.width( 3 );
    std::cout << percent << "%     ";
    std::cout << "(" << current << " / " << max << ")" << "\r" << std::flush;
}


