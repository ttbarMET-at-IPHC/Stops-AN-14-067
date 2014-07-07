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
#include "../cutAndCountDefinitions.h" 


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
 	  TString SignalRegion = signalregion(decay_mode, MSTOP, MLSP); 

	  if (decay_mode == "T2bw025") {decay_mode_ = "t2bw025"; }
 	  if (decay_mode == "T2bw050") {decay_mode_ = "t2bw050"; }   
	  if (decay_mode == "T2bw075") {decay_mode_ = "t2bw075"; }
   	  if (decay_mode == "T2tt")    {decay_mode_ = "t2tt";    }

	  if (SignalRegion == "T2bw025_1") {SignalRegion_ = "R1"; }
 	  if (SignalRegion == "T2bw025_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw025_4")   {SignalRegion_ = "R4";   }
   	  if (SignalRegion == "T2bw025_6")   {SignalRegion_ = "R6";   }

	  if (SignalRegion == "T2bw050_1_loose") {SignalRegion_ = "R1_loose"; }
	  if (SignalRegion == "T2bw050_1_tight") {SignalRegion_ = "R1_tight"; }
 	  if (SignalRegion == "T2bw050_3")   {SignalRegion_ = "R3";   }   
	  if (SignalRegion == "T2bw050_4")   {SignalRegion_ = "R4";   }
	  if (SignalRegion == "T2bw050_5")   {SignalRegion_ = "R5";   }
   	  if (SignalRegion == "T2bw050_6")   {SignalRegion_ = "R6";   }


 	  if (SignalRegion == "T2bw075_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2bw075_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2bw075_3")   {SignalRegion_ = "R3";   }
   	  if (SignalRegion == "T2bw075_5")   {SignalRegion_ = "R5";   }

 	  if (SignalRegion == "T2tt_1")   {SignalRegion_ = "R1";   }   
	  if (SignalRegion == "T2tt_2")   {SignalRegion_ = "R2";   }
	  if (SignalRegion == "T2tt_5_loose")   {SignalRegion_ = "R5_loose";   }
   	  if (SignalRegion == "T2tt_5_tight")   {SignalRegion_ = "R5_tight";   }


          TFile sig(decay_mode+".root");
          TH1D* signal= (TH1D*)sig.Get("hist_BDT_output_"+decay_mode_+"_"+SignalRegion_+"_S"+TString(stop)+"_N"+TString(neut));

          int nbins = signal->GetNbinsX();
          double BDTdefCut = signalcut(decay_mode, MSTOP, MLSP); 

          //int max_bin = signal->GetXaxis()->FindBin(BDTdefCut); 
	  double cut = BDTdefCut + BDTdefCutOffset;
          int max_bin = signal->GetXaxis()->FindBin(cut); // Do CLs minimization 
          double nsignal = signal->Integral(max_bin,nbins+1);
	  
	  double bkg = 0.; 
          double bkg_err = 0.; 
          double bkg_err_percentage = 0.; 



	if (SignalRegion == "T2bw025_1") {
	  bkg = Pred_BDT_T2bw025_1().first  ; 
	  bkg_err = Pred_BDT_T2bw025_1().second ; 
	  }

	if (SignalRegion == "T2bw025_3") {
	  bkg = Pred_BDT_T2bw025_3().first  ; 
	  bkg_err = Pred_BDT_T2bw025_3().second ; 
	  }

	if (SignalRegion == "T2bw025_4") {
	  bkg = Pred_BDT_T2bw025_4().first  ; 
	  bkg_err = Pred_BDT_T2bw025_4().second ; 
	  }

	if (SignalRegion == "T2bw025_6") {
	  bkg = Pred_BDT_T2bw025_6().first  ; 
	  bkg_err = Pred_BDT_T2bw025_6().second ; 
	  }

	if (SignalRegion == "T2bw050_1_loose") {
	  bkg = Pred_BDT_T2bw050_1_loose().first  ; 
	  bkg_err = Pred_BDT_T2bw050_1_loose().second ; 
	  }

	if (SignalRegion == "T2bw050_1_tight") {
	  bkg = Pred_BDT_T2bw050_1_tight().first  ; 
	  bkg_err = Pred_BDT_T2bw050_1_tight().second ; 
	  }

	if (SignalRegion == "T2bw050_3") {
	  bkg = Pred_BDT_T2bw050_3().first  ; 
	  bkg_err = Pred_BDT_T2bw050_3().second ; 
	  }

	if (SignalRegion == "T2bw050_4") {
	  bkg = Pred_BDT_T2bw050_4().first  ; 
	  bkg_err = Pred_BDT_T2bw050_4().second ; 
	  }

	if (SignalRegion == "T2bw050_5") {
	  bkg = Pred_BDT_T2bw050_5().first  ; 
	  bkg_err = Pred_BDT_T2bw050_5().second ; 
	  }

	if (SignalRegion == "T2bw050_6") {
	  bkg = Pred_BDT_T2bw050_6().first  ; 
	  bkg_err = Pred_BDT_T2bw050_6().second ; 
	  }

	if (SignalRegion == "T2bw075_1") {
	  bkg = Pred_BDT_T2bw075_1().first  ; 
	  bkg_err = Pred_BDT_T2bw075_1().second ; 
	  }

	if (SignalRegion == "T2bw075_2") {
	  bkg = Pred_BDT_T2bw075_2().first  ; 
	  bkg_err = Pred_BDT_T2bw075_2().second ; 
	  }

	if (SignalRegion == "T2bw075_3") {
	  bkg = Pred_BDT_T2bw075_3().first  ; 
	  bkg_err = Pred_BDT_T2bw075_3().second ; 
	  }

	if (SignalRegion == "T2bw075_5") {
	  bkg = Pred_BDT_T2bw075_5().first  ; 
	  bkg_err = Pred_BDT_T2bw075_5().second ; 
	  }

	if (SignalRegion == "T2tt_1") {
	  bkg = Pred_BDT_T2tt_1(BDTdefCutOffset).first  ; 
	  bkg_err = Pred_BDT_T2tt_1(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_2") {
	  bkg = Pred_BDT_T2tt_2(BDTdefCutOffset).first  ; 
	  bkg_err = Pred_BDT_T2tt_2(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_5_loose") {
	  bkg = Pred_BDT_T2tt_5_loose(BDTdefCutOffset).first  ; 
	  bkg_err = Pred_BDT_T2tt_5_loose(BDTdefCutOffset).second ; 
	  }

	if (SignalRegion == "T2tt_5_tight") {
	  bkg = Pred_BDT_T2tt_5_tight(BDTdefCutOffset).first  ; 
	  bkg_err = Pred_BDT_T2tt_5_tight(BDTdefCutOffset).second ; 
	  }


          bkg_err_percentage = (bkg_err / bkg) + 1. ;

//          cout << "NSIG: "<< nsignal << endl;
//          cout << "NBKG: "<< bkg << " +/- "<< bkg_err_percentage<< endl;

            createTableCLsBDT(decay_mode, BDTdefCutOffset, SignalRegion, MSTOP, MLSP,  nsignal, bkg, bkg_err_percentage);

	  
}





void makeCards(TString decay_mode ){

      cout << decay_mode << endl;  

      //for(int z=-4; z<=4; z+=1){
     for(int z=-6; z<=-5; z+=1){

	double BDTdefCutOffset  = float(z) / 20.;

            //cout << BDTdefCutOffset << endl;
	
             // FIX LATER for(int x=175; x<=800; x+=25){
	
              for(int x=175; x<=775; x+=25){
	
    	              for(int y=25; y<=700; y+=25){

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


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_5/"+TString(decay_mode)+TString(CUT)+"/";
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){

//makeCards("T2bw025");
//makeCards("T2bw050");
//makeCards("T2bw075");
makeCards("T2tt");

}