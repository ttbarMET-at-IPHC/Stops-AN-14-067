#include "TColor.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TF2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPolyLine.h"
#include "TROOT.h"
#include "TF1.h"
#include "TGaxis.h"


#include <iomanip>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>




using namespace std;
void rootlogon();


TString savedir = "~/www/";





void plot_limit(TString dir){

 
          gStyle->SetCanvasColor(0);
          gStyle->SetPadColor(0);
          gStyle->SetMarkerStyle(15);
          gStyle->SetMarkerSize(0.25);
          gStyle->SetPalette(1);
          gStyle->SetTextFont(42);
          gStyle->SetMarkerColor(37);


  //palette settings - completely independent
  const Int_t NRGBs = 6;
  const Int_t NCont = 999;

  Double_t stops[NRGBs] = { 0.00, 0.1, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.99, 0.0, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.0, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.99, 0.0, 1.00, 0.12, 0.00, 0.00 };


  //TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  //gStyle->SetNumberContours(NCont);

  gStyle->SetOptStat(0);


   double shell;

   if (dir == "T2bw025") {dataset_name = "T2bw025_CUT0"; shell = 80. / 0.25;}
   if (dir == "T2bw050") {dataset_name = "T2bw050_CUT0"; shell = 80. / 0.50;}
   if (dir == "T2bw075") {dataset_name = "T2bw075_CUT0"; shell = 80. / 0.75;}
   if (dir == "T2tt")    {dataset_name = "T2tt_CUT0";    shell = 173.;}


   TFile *fout = new TFile(TString(dataset_name)+"_BDT.root","recreate");

   TH2D *SMS = new TH2D(dataset_name,"",29,87.5, 812.5, 16, 12.5,412.5); 


              for(int x=100; x<=800; x+=25){


                      for(int y=0; y<=700; y+=25){


  		  char shortfilename[500];
  		  char filename[500];


                  sprintf(filename,"/afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/LimitsBDT_8_mT100/%s/ASYMPTOTIC_CLS_RESULT_S%d-N%d.root", dataset_name, x, y);

   
                  ifstream ifile(filename);
	          if (!ifile.good()) continue; 

	         
		  TFile* file  = new TFile(filename, "READ");  
		  char* name = (char*)file->GetName();



		TTree *limittree = (TTree*)file->Get("limit");

		double high_val = 100.;


		TH1F* exp = new TH1F("exp","",100,0,high_val);
		limittree->Draw("limit>>exp", "quantileExpected==0.5");



		        if (exp->GetMean() < 1.0){
		        SMS->Fill(x,y,exp->GetMean());

			cout << "x: "<< x << ", y: " << y << endl;
			cout << exp->GetMean() << endl;

		  file->Close();

		}
	  }

	}
              TAxis *data_yaxis = SMS->GetYaxis();
              TAxis *data_zaxis = SMS->GetZaxis();
              TAxis *data_xaxis = SMS->GetXaxis();

              data_xaxis->SetTitle("Mass STOP");
              data_yaxis->SetTitle("Mass LSP");
              data_zaxis->SetTitle("Signal strength R");


           TCanvas c1("c1","c1",800,600);
           c1.SetLeftMargin(0.1706731);
           c1.SetRightMargin(0.1983173);
           c1.SetTopMargin(0.04895105);
           c1.SetBottomMargin(0.1416084);
           c1.Range(-289.7381,-191.8196,1334.643,1074.487);


	  TLegendEntry *legge;
	  TLegend *leg;
	  leg = new TLegend(0.4,0.55,0.7,0.85);
	  leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
	  legge = leg->AddEntry(SMS,   "Expected U.L. @95\% CL", "");
	  leg->SetFillColor(0);
	  SMS->Draw("colz");
	  leg->Draw();


	   c1.SaveAs("~/www/test.png");

      fout->cd();
      fout->Write();
      fout->Close();

}

