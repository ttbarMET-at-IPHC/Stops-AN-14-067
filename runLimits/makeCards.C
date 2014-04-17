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




using namespace std;

double f_syst = 0.15;
TString ntpdir0 = "."; 
TString plotdir = "Plots22/"; 






double calcSoSqrtB(double S, double B){

if (B < 1) B = 1;

      if (S >= 3)
         return S / sqrt(B + f_syst*f_syst * B*B);
      else

    return 0.;
}



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







double FOM(TString setup, TString BDT, TString dir, int MSTOP, int MLSP, int num){

          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();


          TString dataset_name;

          if (dir == "T2bw025") {dataset_name = "t2bw_025";}
          if (dir == "T2bw050") {dataset_name = "t2bw_050";}
          if (dir == "T2bw075") {dataset_name = "t2bw_075";}
          if (dir == "T2tt")    {dataset_name = "t2tt_all";}



          TFile ttbar(ntpdir0+"/"+setup+"/"+dir+"/ttbar/output/ttbar_all_full.root");
          TFile wjets(ntpdir0+"/"+setup+"/"+dir+"/wjets/output/wjets_all_0.root");
          TFile others(ntpdir0+"/"+setup+"/"+dir+"/others/output/others_all_0.root");
          TFile sig(ntpdir0+"/"+setup+"/"+dir+"/signal/"+TString(stop)+"/"+TString(neut)+"/output/"+dataset_name+"_0.root");



	  TH1D* TTBar= (TH1D*)ttbar.Get(BDT);
	  TH1D* WJets= (TH1D*)wjets.Get(BDT);
	  TH1D* Others= (TH1D*)others.Get(BDT);
	  TH1D* signal= (TH1D*)sig.Get(BDT);


          int nbins = TTBar->GetNbinsX();
          double hmin = TTBar->GetXaxis()->GetBinLowEdge(1);
          double hmax = TTBar->GetXaxis()->GetBinUpEdge(nbins);


          TH1D* FOM = new TH1D("","",nbins,hmin,hmax);
          int max_bin;
          double cutvalue; 
	  double nsignal = signal->Integral();


	      for(int b=1; b<=nbins; ++b){

	      double sig_ = signal->Integral(b,nbins+1);
	      double bkg_ = TTBar->Integral(b,nbins+1) + WJets->Integral(b,nbins+1) + Others->Integral(b,nbins+1) ;
	      
	      double SoSqrtB = calcSoSqrtB(sig_, bkg_ );

	      FOM->SetBinContent(b,SoSqrtB);

	      }


	    max_bin = maxbin(FOM);
	    cutvalue = TTBar->GetBinLowEdge(max_bin);
            double fom = FOM->GetBinContent(max_bin);

   if (num==0) return nsignal;
   if (num==1) return fom;
   if (num==2) return cutvalue;
}



void makeCLsCards(TString setup, TString BDT, TString dir, int MSTOP, int MLSP){


          std::ostringstream ostr1;
          ostr1 << MSTOP;
          std::string stop = ostr1.str();

          std::ostringstream ostr2;
          ostr2 << MLSP;
          std::string neut = ostr2.str();


          TString dataset_name;

          if (dir == "T2tt")    {dataset_name = "t2tt_all";}
          if (dir == "T2bw025") {dataset_name = "t2bw_025";}
          if (dir == "T2bw050") {dataset_name = "t2bw_050";}
          if (dir == "T2bw075") {dataset_name = "t2bw_075";}

          TFile ttbar(ntpdir0+"/"+setup+"/"+dir+"/ttbar/output/ttbar_all_full.root");
          TFile wjets(ntpdir0+"/"+setup+"/"+dir+"/wjets/output/wjets_all_0.root");
          TFile others(ntpdir0+"/"+setup+"/"+dir+"/others/output/others_all_0.root");
          TFile sig(ntpdir0+"/"+setup+"/"+dir+"/signal/"+TString(stop)+"/"+TString(neut)+"/output/"+dataset_name+"_0.root");



          TH1D* TTBar= (TH1D*)ttbar.Get(BDT);
          TH1D* WJets= (TH1D*)wjets.Get(BDT);
          TH1D* Others= (TH1D*)others.Get(BDT);
          TH1D* signal= (TH1D*)sig.Get(BDT);


          int nbins = TTBar->GetNbinsX();
          double hmin = TTBar->GetXaxis()->GetBinLowEdge(1);
          double hmax = TTBar->GetXaxis()->GetBinUpEdge(nbins);


          TH1D* FOM = new TH1D("","",nbins,hmin,hmax);
          int max_bin;
          double cutvalue;
          double nsignal = signal->Integral();

   
              TH1D* SoB = new TH1D("","",nbins,hmin,hmax);
              int max_bin;

	
              for(int b=1; b<=nbins; ++b){

              double sig_ = signal->Integral(b,nbins+1);
              double bkg_ = TTBar->Integral(b,nbins+1) + WJets->Integral(b,nbins+1) + Others->Integral(b,nbins+1) ;

              double SoSqrtB = calcSoSqrtB(sig_, bkg_ );


              SoB->SetBinContent(b,SoSqrtB);
              }

	           max_bin = maxbin(SoB);


	     double signal_ = signal->Integral(max_bin,nbins+1);
	     double ttbar_ = TTBar->Integral(max_bin,nbins+1);
	     double wjets_ = WJets->Integral(max_bin,nbins+1);
	     double others_ = Others->Integral(max_bin,nbins+1);

				
             createTableCLs(dir, setup, BDT, MSTOP, MLSP,  signal_, ttbar_, wjets_, others_);

}





void make2Dplot_MAX_OffShell(TString setup1, TString setup2, TString dir, int num){

          gStyle->SetOptStat(0);
          gStyle->SetCanvasColor(0);
          gStyle->SetPadColor(0);
          gStyle->SetMarkerStyle(15);
          gStyle->SetMarkerSize(0.25);
          gStyle->SetTextFont(42);
          gStyle->SetMarkerColor(37);
	  if (num <3) {gStyle->SetPaintTextFormat("4.1f");}
	  else if (num ==3) {gStyle->SetPaintTextFormat("0.0f");}
	  else if (num ==4) { cout << "Making CLs cards" << endl; } 

              TH2D* TwoDPlot = new TH2D("","",26,162.5, 812.5, 28, 12.5,712.5); 

 	 
              //for(int x=175; x<=800; x+=25){
              for(int x=225; x<=800; x+=25){

	
    	              for(int y=25; y<=700; y+=25){
			       if (x - y > 99){ 
 
					if (num <3){
					double array[6] = {
							   FOM(setup1,"BDT1",dir,x,y,num), 
							   FOM(setup1,"BDT2",dir,x,y,num), 
							   FOM(setup1,"BDT3",dir,x,y,num), 
							   FOM(setup1,"BDT4",dir,x,y,num), 
							   FOM(setup1,"BDT5",dir,x,y,num), 
							   FOM(setup1,"BDT6",dir,x,y,num)
							   };

					double array2[6] = {
							   FOM(setup2,"BDT1",dir,x,y,num), 
							   FOM(setup2,"BDT2",dir,x,y,num), 
							   FOM(setup2,"BDT3",dir,x,y,num), 
							   FOM(setup2,"BDT4",dir,x,y,num), 
							   FOM(setup2,"BDT5",dir,x,y,num), 
							   FOM(setup2,"BDT6",dir,x,y,num)
							   };
					} else 
					                                        
					double array[6] = {
                                                           FOM(setup1,"BDT1",dir,x,y,1),
                                                           FOM(setup1,"BDT2",dir,x,y,1),
                                                           FOM(setup1,"BDT3",dir,x,y,1),
                                                           FOM(setup1,"BDT4",dir,x,y,1),
                                                           FOM(setup1,"BDT5",dir,x,y,1),
                                                           FOM(setup1,"BDT6",dir,x,y,1)
                                                           };

					double array2[6] = {
                                                           FOM(setup2,"BDT1",dir,x,y,1),
                                                           FOM(setup2,"BDT2",dir,x,y,1),
                                                           FOM(setup2,"BDT3",dir,x,y,1),
                                                           FOM(setup2,"BDT4",dir,x,y,1),
                                                           FOM(setup2,"BDT5",dir,x,y,1),
                                                           FOM(setup2,"BDT6",dir,x,y,1)
                                                           };

					double temp = 0.;
					int mvaval = 0;

					double temp2 = 0.;
					int mvaval2 = 0;

						// Get the maximum of each point for all MVAs
						  for(int i=0;i<6;i++){

							if(array[i]>temp){ 

								temp	= array[i]; 
								mvaval 	= i; 
		
							}  
						  }
		
						  for(int j=0;j<6;j++){

							if(array2[j]>temp2){ 

								temp2	= array2[j]; 
								mvaval2 	= j; 
						
							}  
						  }
	
								double shell;
								if (dir == "T2bw025") {shell = 80.385 / 0.25;}
							        if (dir == "T2bw050") {shell = 80.385 / 0.50;}
								if (dir == "T2bw075") {shell = 80.385 / 0.75;}
								if (dir == "T2tt")    {shell = 173.;}
	
							        std::ostringstream iStr;
								iStr << mvaval + 1;
								std::string bdtNUM = iStr.str();

							        std::ostringstream iStr2;
								iStr2 << mvaval2 + 1;
								std::string bdtNUM2 = iStr2.str();

								TString BDTval  = "BDT"+bdtNUM;
								TString BDTval2  = "BDT"+bdtNUM2;

								if ( (double(x) - double(y)) < shell ) {	

									if (num == 4) {cout << "BDT being used (Off-Shell): "<<  bdtNUM2 << endl;
									makeCLsCards(setup2, BDTval2, dir, x, y);}

								//if (num <3) {TwoDPlot->Fill(x,y,temp2);}
                                                                //else {TwoDPlot->Fill(x,y,mvaval2+1);}

								} else {
									if (num == 4) {cout << "BDT being used (On-Shell): "<<  bdtNUM << endl;
									makeCLsCards(setup1, BDTval, dir, x, y);}

								//if (num <3) {TwoDPlot->Fill(x,y,temp);}
								//else {TwoDPlot->Fill(x,y,mvaval+1);}

								}
			       }	
              	        }
	   }


           TCanvas c1("c1","c1",800,600);
	   c1.SetLeftMargin(0.1706731);
	   c1.SetRightMargin(0.1983173);
	   c1.SetTopMargin(0.04895105);
	   c1.SetBottomMargin(0.1416084);
	   c1.Range(-289.7381,-191.8196,1334.643,1074.487);
           TwoDPlot->SetMarkerSize(1.); 
           TwoDPlot->SetMarkerColor(kWhite); 
           TwoDPlot->Draw("COLZ TEXT");
	   //TLine lm(125, 0 , 800, 675);
	   TLine lm(shell, 0 , 800. , 800-shell);
	   lm.SetLineColor(kBlack); lm.SetLineWidth(2); lm.SetLineStyle(2); lm.Draw();
 
           TwoDPlot->GetYaxis()->SetTitle("LSP mass"); 
           TwoDPlot->GetXaxis()->SetTitle("Stop mass");  
           if (num==0) {TwoDPlot->GetZaxis()->SetTitle("Entries"); TwoDPlot->GetZaxis()->SetRangeUser(0,5000);}
           if (num==1) {TwoDPlot->GetZaxis()->SetTitle("FOM"); TwoDPlot->GetZaxis()->SetRangeUser(0,15);}
           if (num==2) {TwoDPlot->GetZaxis()->SetTitle("Optimal cut point"); TwoDPlot->GetZaxis()->SetRangeUser(0,1);}
           if (num==3) {TwoDPlot->GetZaxis()->SetTitle("Best performing BDT region"); TwoDPlot->GetZaxis()->SetRangeUser(0,6);}
           TLatex l1;
           l1.SetTextAlign(12);
           l1.SetTextSize(0.04);
           l1.SetNDC();
           l1.DrawLatex(0.155, 0.98, "CMS Simulation, 20 fb^{-1}");
           l1.DrawLatex(0.7, 0.98, "#sqrt{s} = 8 TeV");
           l1.SetTextSize(0.03);
	   if (num==3){
 

      tex = new TLatex(0.7449749,0.8251748,"#color[5]{BDT1}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.7449749,0.7097902,"#color[5]{BDT2}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.7437186,0.5891608,"#color[5]{BDT3}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.7424623,0.4755245,"#color[5]{BDT4}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.7424623,0.3583916,"#color[5]{BDT5}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.7424623,0.2447552,"#color[5]{BDT6}");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03);
   tex->SetTextAngle(41.15586);
   tex->SetLineWidth(2);
   tex->Draw();


	   }





          TString dataset_name;
          TString ntpdir;

          if (dir == "T2bw025") {dataset_name = "t2bw_025";}
          if (dir == "T2bw050") {dataset_name = "t2bw_050";}
          if (dir == "T2bw075") {dataset_name = "t2bw_075";}
          if (dir == "T2tt")    {dataset_name = "t2tt";}

          if (num==1) { ntpdir = "~/www/STOP/NNTraining/8TeV/"+TString(plotdir)+"/"+TString(dataset_name);}
          if (num==2) { ntpdir = "~/www/STOP/NNTraining/8TeV/"+TString(plotdir)+"/"+TString(dataset_name);}
          if (num==3) { ntpdir = "~/www/STOP/NNTraining/8TeV/"+TString(plotdir)+"/"+TString(dataset_name);}

           gSystem->Exec("mkdir -p "+ntpdir);
           gSystem->Exec("cp ~/www/index.php "+ntpdir);

          if (num==1) {c1.Print(ntpdir)+"/FOM.png"; }
          if (num==2) {c1.Print(ntpdir)+"/BDT_cuts.png"; }
          if (num==3) {c1.Print(ntpdir)+"/BDT_Regions.png"; }


}









void makeAllPlots(){



//make2Dplot_MAX_OffShell("setup_105","setup_105","T2bw025",4);
make2Dplot_MAX_OffShell("setup_105","setup_105","T2bw050",4);
make2Dplot_MAX_OffShell("setup_105","setup_105","T2bw075",4);
//make2Dplot_MAX_OffShell("setup_104","setup_105","T2tt",1);


}



void createTableCLs(TString dir, TString setup, TString BDT, int S, int N, double signal, double ttbar, double wjets, double others){


  char datacardname[100];
  sprintf(datacardname,"datacard-S%d-N%d.txt", S,N);  
 

  ofstream  tablesFile(datacardname);
  tablesFile.setf(ios::fixed);
  tablesFile.precision(1);
 
  tablesFile << "imax 1  number of channels" << endl
             << "jmax 3 number of backgrounds" << endl
             << "kmax 3  number of nuisance parameters (sources of systematical uncertainties)" << endl
             << "------------"<<endl
             << "bin 1"<<endl    
             << "observation \t 5.0" << endl
             << "bin            	\t 1              \t 1          	\t  1        \t 1" << endl
             << "process        	\t signal         \t TTJets     	\t  Wjets    \t others" << endl
             << "process        	\t 0              \t 1          	\t  2        \t 3" << endl
             << "rate           	\t " << signal << "  \t \t \t "<< ttbar <<  " \t \t "  << wjets << " \t \t \t " << others << endl
             << "------------" << endl
             << "lumi       \t lnN 	\t 1.022         \t 1.022          	\t 1.022     \t 1.022         \t  lumi affects both signal and mc. lnN = lognormal" << endl
             << "signal_unc \t lnN 	\t 1.1           \t -              	\t -         \t -             \t  stop cross section + signal efficiency + other minor ones." << endl
             << "bkg_unc    \t lnN 	\t -             \t 1.15             	\t 1.15      \t 1.15           \t  30\% uncertainty on the rest of the backgrounds" << endl
             << "------------"<<endl
             << "#DEBUG (setup, BDT value): "  << setup << ", "<< BDT << endl;
 
 
  tablesFile.close();


  TString savedir = "mT100/"+TString(dir);
  gSystem->Exec("mkdir -p "+savedir); 
  gSystem->Exec("mv "+TString(datacardname)+" "+savedir); 


}