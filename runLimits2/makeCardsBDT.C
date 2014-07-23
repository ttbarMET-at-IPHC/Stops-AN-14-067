#include <iostream>   
#include <algorithm>  
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include "TColor.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include <stdio.h>
#include <stdlib.h>


#include "../signalRegionDefinitions.h" 
#include "../backgroundPredictions_LATEST_MT100.h" 


using namespace std;




int maxbin(TH1D* histo){
  int bi = 0;
  double max = 0;
  for( int i = 1; i <= histo->GetNbinsX(); i++){

    //if( histo->GetBinContent(i) > max && histo->GetBinError(i) < histo->GetBinContent(i) ){
    if( histo->GetBinContent(i) > max ){
      max = histo->GetBinContent(i);
      bi = i;
    }
  }
  return bi;
}





void makeCLsCards(TString decay_mode, double BDTdefCutOffset, int MSTOP, int MLSP){


          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();


	  TString decay_mode_; 
	  TString SignalRegion_; 
 	  TString SignalRegion = signalregionName(decay_mode, MSTOP, MLSP); 

	  if (decay_mode == "T2bw025") {decay_mode_ = "t2bw025"; }
 	  if (decay_mode == "T2bw050") {decay_mode_ = "t2bw050"; }   
	  if (decay_mode == "T2bw075") {decay_mode_ = "t2bw075"; }
   	  if (decay_mode == "T2tt")    {decay_mode_ = "t2tt";    }

	  if (SignalRegion == "T2bw025_1") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw025_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw025_4")   {SignalRegion_ = "R4";   }
   	  if (SignalRegion == "T2bw025_6")   {SignalRegion_ = "R6";   }

	  if (SignalRegion == "T2bw050_1_lowDM") {SignalRegion_ = "R1"; }
	  if (SignalRegion == "T2bw050_1_highDM") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw050_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw050_4")   {SignalRegion_ = "R4";   }
	  if (SignalRegion == "T2bw050_5")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw050_6")   {SignalRegion_ = "R6";   }


 	  if (SignalRegion == "T2bw075_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2bw075_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2bw075_3")   {SignalRegion_ = "R3";   }
   	  if (SignalRegion == "T2bw075_5_lowDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw075_5_highDM")   {SignalRegion_ = "R5";   }

 	  if (SignalRegion == "T2tt_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2tt_2_lowDM")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_2_highDM")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_5_lowDM")   {SignalRegion_ = "R5";   }
	  if (SignalRegion == "T2tt_5_mediumDM")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2tt_5_highDM")   {SignalRegion_ = "R5";   }


          TFile sig("ntp_2_MT100/"+decay_mode+".root");
          TH1D* signal= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_S"+TString(stop)+"_N"+TString(neut));

          int nbins = signal->GetNbinsX();
          double BDTdefCut = signalcut(decay_mode, MSTOP, MLSP); 

	  double cut = BDTdefCut + BDTdefCutOffset;
	  //double cut = BDTdefCut; 
          int max_bin = signal->GetXaxis()->FindBin(cut); // Do CLs minimization 
          double nsignal = signal->Integral(max_bin,nbins+1);
	   
	  double bkg = 0.; 
          double bkg_err = 0.; 
          double bkg_err_percentage = 0.; 


	if (SignalRegion == "T2bw025_1") {
	  bkg = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw025_1(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw025_3") {
	  bkg = backgroundPrediction_BDT_T2bw025_3(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw025_3(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw025_4") {
	  bkg = backgroundPrediction_BDT_T2bw025_4(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw025_4(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw025_6") {
	  bkg = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw025_6(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_1_lowDM") {
	  bkg = backgroundPrediction_BDT_T2bw050_1_lowDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_1_lowDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_1_highDM") {
	  bkg = backgroundPrediction_BDT_T2bw050_1_highDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_1_highDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_3") {
	  bkg = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_3(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_4") {
	  bkg = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_4(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_5") {
	  bkg = backgroundPrediction_BDT_T2bw050_5(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_5(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw050_6") {
	  bkg = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw050_6(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw075_1") {
	  bkg = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw075_1(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw075_2") {
	  bkg = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw075_2(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw075_3") {
	  bkg = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw075_3(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw075_5_lowDM") {
	  bkg = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw075_5_lowDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2bw075_5_highDM") {
	  bkg = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2bw075_5_highDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_1") {
	  bkg = backgroundPrediction_BDT_T2tt_1(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_1(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_2_lowDM") {
	  bkg = backgroundPrediction_BDT_T2tt_2_lowDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_2_lowDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_2_highDM") {
	  bkg = backgroundPrediction_BDT_T2tt_2_highDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_2_highDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_5_lowDM") {
	  bkg = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_5_lowDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_5_mediumDM") {
	  bkg = backgroundPrediction_BDT_T2tt_5_mediumDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_5_mediumDM(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_5_highDM") {
	  bkg = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).first  ; 
	  bkg_err = backgroundPrediction_BDT_T2tt_5_highDM(BDTdefCutOffset).second ; 
	  }

          bkg_err_percentage = (bkg_err / bkg) + 1. ;

         // cout << "NSIG: "<< nsignal << endl;
         // cout << "NBKG: "<< bkg << " +/- "<< bkg_err_percentage<< endl;
         // cout << "SR: "<< SignalRegion << endl;
         // cout << "cut: "<< BDTdefCut << endl;
         // cout << "cut offset: "<< BDTdefCutOffset << endl;

            createTableCLsBDT(decay_mode, BDTdefCutOffset, SignalRegion, MSTOP, MLSP,  nsignal, bkg, bkg_err_percentage);

	  
}





void makeCards(TString decay_mode ){

      cout << decay_mode << endl;  
      int start;
      int end;
      // -9 to 4 is 0.45 to 0.2
 
      if (decay_mode == "T2tt") { start = 4; end = 4;}
      if (decay_mode == "T2bw025") { start = 4; end = 4;}
      if (decay_mode == "T2bw050") { start = 4; end = 4;}
      if (decay_mode == "T2bw075") { start = 4; end = 4;}


      for(int z= start; z<= end; z+=1){

	double BDTdefCutOffset  = float(z) / 20.;

            //cout << BDTdefCutOffset << endl;
	
              for(int x=100; x<=800; x+=25){
	
    	              for(int y=0; y<=700; y+=25){

				 if (x - y > 99){  
					 cout << "S"<<x << "N"<<y<<endl;	
					 makeCLsCards(decay_mode, BDTdefCutOffset, x, y);
				 }

		  		
			}
	       }	
        }	   
}








void createTableCLsBDT(TString decay_mode, double BDTdefCutOffset, TString SignalRegion, int S, int N, double signal, double bkg, double bkg_err_percentage){

  
  std::ostringstream cut1;
  cut1 << BDTdefCutOffset;
  std::string CUT = cut1.str();

  char datacardname[100];
  sprintf(datacardname,"datacard-S%d-N%d.txt", S,N);  

  ofstream  tablesFile(datacardname);
  tablesFile.setf(ios::fixed);
  tablesFile.precision(3);
 
  tablesFile << "imax 1  number of channels" << endl
             << "jmax 1  number of backgrounds" << endl
             << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl
             << "------------"<<endl
             << "bin 1"<<endl    
             << "observation \t 0.0" << endl
             << "bin            	\t\t 1              \t 1          	" << endl
             << "process        	\t\t signal         \t bkg     		" << endl
             << "process        	\t\t 0              \t 1          	" << endl
             << "rate           	\t\t " << signal << "  \t \t "<< bkg << endl
             << "------------" << endl
             << "lumi       \t lnN 	\t 1.022         \t\t -                 \t  lumi uncertainty" << endl
             << "signal_unc \t lnN 	\t 1.10          \t\t -              	\t  efficiency uncertainty (set to 10\% for now)" << endl
             << "bkg_unc    \t lnN 	\t -             \t\t "<< bkg_err_percentage <<"          	\t  Total uncertainty on the background" << endl
             << "------------"<<endl 
             << "#DEBUG (SR): "  << TString(SignalRegion) << endl;
 
   
  tablesFile.close();


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_8_mT100/"+TString(decay_mode)+"_CUT"+TString(CUT)+"/";
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){

makeCards("T2bw025");
makeCards("T2bw050");
makeCards("T2bw075");
makeCards("T2tt");

}
