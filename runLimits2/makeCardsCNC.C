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


//#include "../cutAndCountDefinitions.h"
#include "../backgroundPredictions_LATEST_MT100.h" 


using namespace std;



void makeCLsCards(TString decay_mode, TString SignalRegion, int MSTOP, int MLSP){


          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();




          TFile sig("ntp_2_MT100/"+decay_mode+".root");

          TH1D* signal= (TH1D*)sig.Get("Events_"+decay_mode+"_"+SignalRegion+"_S"+TString(stop)+"_N"+TString(neut));
          double nsignal = signal->Integral();


	  double bkg = 0.; 
          double bkg_err = 0.; 
          double bkg_err_percentage = 0.; 




	  if (decay_mode == "T2bw025") {

		if (SignalRegion == "offShell") {
		  bkg = backgroundPrediction_cutAndCount_T2bw025_offShell().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw025_offShell().second ; 
		  }

		if (SignalRegion == "lowMasses") {
		  bkg = backgroundPrediction_cutAndCount_T2bw025_lowMasses().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw025_lowMasses().second ; 
		  }

		if (SignalRegion == "highMasses") {
		  bkg = backgroundPrediction_cutAndCount_T2bw025_highMasses().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw025_highMasses().second ; 
		  }

	  }



	  else if (decay_mode == "T2bw050") {

		if (SignalRegion == "offShell") {
		  bkg = backgroundPrediction_cutAndCount_T2bw050_offShell().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw050_offShell().second ; 
		  }

		if (SignalRegion == "lowMasses") {
		  bkg = backgroundPrediction_cutAndCount_T2bw050_lowMasses().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw050_lowMasses().second ; 
		  }

		if (SignalRegion == "mediumDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2bw050_mediumDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw050_mediumDeltaM().second ; 
		  }

		if (SignalRegion == "highDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2bw050_highDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw050_highDeltaM().second ; 
		  }

	  }



	   if (decay_mode == "T2bw075") {


		if (SignalRegion == "lowDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2bw075_lowDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw075_lowDeltaM().second ; 
		  }

		if (SignalRegion == "mediumDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2bw075_mediumDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw075_mediumDeltaM().second ; 
		  }

		if (SignalRegion == "highDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2bw075_highDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2bw075_highDeltaM().second ; 
		  }

	  }



	  else if (decay_mode == "T2tt") {

		if (SignalRegion == "offShellLoose") {
		  bkg = backgroundPrediction_cutAndCount_T2tt_offShellLoose().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2tt_offShellLoose().second ; 
		  }

		if (SignalRegion == "offShellTight") {
		  bkg = backgroundPrediction_cutAndCount_T2tt_offShellTight().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2tt_offShellTight().second ; 
		  }

		if (SignalRegion == "lowDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2tt_lowDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2tt_lowDeltaM().second ; 
		  }

		if (SignalRegion == "mediumDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2tt_mediumDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2tt_mediumDeltaM().second ; 
		  }

		if (SignalRegion == "highDeltaM") {
		  bkg = backgroundPrediction_cutAndCount_T2tt_highDeltaM().first  ; 
		  bkg_err = backgroundPrediction_cutAndCount_T2tt_highDeltaM().second ; 
		  }

	  }




            bkg_err_percentage = (bkg_err / bkg) + 1. ;


//          cout << "NSIG: "<< nsignal << endl;
 //         cout << "NBKG: "<< bkg << " +/- "<< bkg_err_percentage<< endl;

            createTableCLsCNC(decay_mode, SignalRegion, MSTOP, MLSP,  nsignal, bkg, bkg_err_percentage);


     
	  
}





void makeCards(TString decay_mode, TString SignalRegion ){

	  cout << "Making CLs cards" << endl;  


              for(int x=100; x<=800; x+=25){

	
    	              for(int y=0; y<=700; y+=25){

	
				 if (x - y > 99){  
					 cout << "S:"<<x << "N"<<y<<endl;	
					 makeCLsCards(decay_mode, SignalRegion, x, y);
				 }

		  		
			}
	       }	
	   
}








void createTableCLsCNC(TString decay_mode, TString SignalRegion, int S, int N, double signal, double bkg, double bkg_err_percentage){


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
             << "------------"<<endl; 
 
   
  tablesFile.close();


  TString savedir = "/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsCNC_8/"+TString(decay_mode)+"/"+TString(SignalRegion);
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}



void makeCards(){

makeCards("T2tt", "offShellLoose");
makeCards("T2tt", "offShellTight");
makeCards("T2tt", "lowDeltaM");
makeCards("T2tt", "mediumDeltaM");
makeCards("T2tt", "highDeltaM");

makeCards("T2bw025", "offShell");
makeCards("T2bw025", "lowMasses");
makeCards("T2bw025", "highMasses");

makeCards("T2bw050", "offShell");
makeCards("T2bw050", "lowMasses");
makeCards("T2bw050", "mediumDeltaM");
makeCards("T2bw050", "highDeltaM");

makeCards("T2bw075", "lowDeltaM");
makeCards("T2bw075", "mediumDeltaM");
makeCards("T2bw075", "highDeltaM");

}
