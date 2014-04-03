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





void DataMCplots(TString plotname){


	  gStyle->SetOptStat(0);
	  gStyle->SetCanvasColor(0);
	  gStyle->SetPadColor(0);
	  gStyle->SetMarkerStyle(15);
	  gStyle->SetMarkerSize(0.25);
	  gStyle->SetTextFont(42);
	  gStyle->SetMarkerColor(37);



          TFile data("dataDilepton_2LeptonsMuon.root");
          TFile ttbar2l("ttbar2lDilepton_2LeptonsMuon.root");
          TFile ttbar1l("ttbar1lDilepton_2LeptonsMuon.root");
          TFile wjets("WjetsDilepton_2LeptonsMuon.root");
          TFile others("othersDilepton_2LeptonsMuon.root");


	  TH1D* Data= (TH1D*)data.Get(plotname);
	  TH1D* TTBar2l= (TH1D*)ttbar2l.Get(plotname);
	  TH1D* TTBar1l= (TH1D*)ttbar1l.Get(plotname);
	  TH1D* WJets= (TH1D*)wjets.Get(plotname);
	  TH1D* Others= (TH1D*)others.Get(plotname);


          Data->SetMarkerStyle(20);
	  Data->SetMarkerSize(1.1);
	  Data->SetMarkerColor(kBlack);

	  TTBar2l->SetFillColor(7);
	  TTBar2l->SetLineWidth(0.);
	  TTBar1l->SetFillColor(46);
	  TTBar1l->SetLineWidth(0.);

    	  WJets->SetFillColor(42);
    	  Others->SetFillColor(40);



          TH1F * h_data = Data->Clone();
          TH1F * h_mc = Others->Clone();
	  h_mc->Add(WJets);
	  h_mc->Add(TTBar2l);
	  h_mc->Add(TTBar1l);

          double num = Data->Integral();
          double denom = h_mc->Integral();
  /*        h_mc->Scale(num/denom);
          Others->Scale(num/denom);
          WJets->Scale(num/denom);
          TTBar2l->Scale(num/denom);
          TTBar1l->Scale(num/denom);
*/           
 

          THStack *stack= new THStack("stack", "");
          stack->Add(Others);
          stack->Add(WJets);
          stack->Add(TTBar2l);
          stack->Add(TTBar1l);


              TAxis *data_yaxis = h_data->GetYaxis();
              TAxis *data_xaxis = h_data->GetXaxis();
              string binunits;


              if(plotname =="h1_b1_pt"){
              data_xaxis->SetTitle("Leading b-jet P_{T} [GeV]");
	      binunits = "GeV";	 
             }
               else if(plotname =="h1_HTfrac"){
               data_xaxis->SetTitle("HT(SSM) / HT");
              }
              else if(plotname == "h1_m3b"){
                data_xaxis->SetTitle("m3b [GeV]");
	      binunits = "GeV";	 
              }
              else if(plotname == "h1_dR_LepB"){
                data_xaxis->SetTitle("#DeltaR(lepton_{1}, b_{1})");
              }
              else if(plotname == "h1_METoverSqrtHT"){
               data_xaxis->SetTitle("MET /#sqrt{HT}");
               //Data->SetMaximum(2000);
	       binunits = "GeV";	 
              }
              else if(plotname == "h1_mT2W"){
                data_xaxis->SetTitle("m^{W}_{T2} [GeV]");
	      binunits = "GeV";	 
              }
              else if(plotname == "h1_mT"){
                data_xaxis->SetTitle("m_{T} [GeV]");
	      binunits = "GeV";	 
              }
              else if(plotname == "h1_mlb_hemi"){
                data_xaxis->SetTitle("mlb_{hemi} [GeV]");
	      binunits = "GeV";	 
              }
              else if( (plotname == "h1_lepton_pT")  || (plotname == "h1_lepton_pT_Zoom")){
                data_xaxis->SetTitle("Leading lepton p_{T} [GeV]");
	      binunits = "GeV";	 
              }
              else if(plotname == "h1_njets"){
                //Data->SetMaximum(35000);
                data_xaxis->SetTitle("Jet Multiplicity");
              }
              else if(plotname == "h1_dR_LepJet"){
                data_xaxis->SetTitle("#DeltaR(lepton_{1}, jet_{1})");
              }
              else if(plotname == "h1_dPhi_JetMet"){
                data_xaxis->SetTitle("#Delta#Phi(jet_{1,2}, MET)");
              }
              else if(plotname =="h1_jet1_pT"){
               data_xaxis->SetTitle("Leading jet P_{T} [GeV]");
               binunits = "GeV";  
              }
              else if(plotname =="h1_Chi2SNT"){
               data_xaxis->SetTitle("Hadronic #chi^{2}");
              }
              else if(plotname == "h1_met"){
                data_xaxis->SetTitle("MET [GeV]");
                binunits = "GeV";  
              }
              else if(plotname =="BDT1"){
               data_xaxis->SetTitle("BDT1");
              }
              else if(plotname =="BDT2"){
               data_xaxis->SetTitle("BDT2");
              }
              else if(plotname =="BDT3"){
               data_xaxis->SetTitle("BDT3");
              }
              else if(plotname =="BDT4"){
               data_xaxis->SetTitle("BDT4");
              }

	


           TLegendEntry *legge;
           TLegend *leg;

           TLegendEntry *legge;
           TLegend *leg;
           leg = new TLegend(0.58,0.62,0.88,0.92);
           leg->SetFillStyle(0); leg->SetBorderSize(0); leg->SetTextSize(0.043);
           legge = leg->AddEntry(Data,   "Data", "pl");
           legge = leg->AddEntry(TTBar1l,   "1 #it{l} top", "F");
           legge = leg->AddEntry(TTBar2l,   "t#bar{t} #rightarrow #it{ll}", "F");
           legge = leg->AddEntry(WJets,   "W + Jets", "F");
           legge = leg->AddEntry(Others,   "Rare", "F");
           leg->SetFillColor(0);

 

           double binsize = Data->GetBinWidth(4);
	
           std::ostringstream ostr1;
           ostr1 << binsize;
           std::string binsizename = ostr1.str();


	   TCanvas *c1 = new TCanvas("c1","example",650,700);
	   TPad *pad1 = new TPad("pad1","pad1",0,0.29,1,0.97);
	   pad1->SetBottomMargin(0);
	   pad1->Draw();
	   pad1->cd();

           Data->GetXaxis()->SetLabelSize(0.);

           Data->Draw("");
           stack->Draw("same");
	   Data->Draw("samepe");
           if (plotname == "h1_njets") { Data->GetYaxis()->SetTitle("Entries");  } else
           Data->GetYaxis()->SetTitle("Entries / "+TString(binsizename)+" "+TString(binunits));
           leg->Draw();
           TLatex l1;
           l1.SetTextAlign(12);
           l1.SetTextSize(0.05);
           l1.SetNDC();
           l1.DrawLatex(0.18, 0.98, "CMS preliminary, L = 19.5 fb^{-1}");
           l1.DrawLatex(0.7, 0.98, "#sqrt{s} = 8 TeV");
//           pad1->SetLogy();
           pad1->RedrawAxis();

	   c1->cd();

	   TPad *pad2 = new TPad("pad2","pad2",0,0.07,1,0.26);
  	   Double_t xmax = h_data->GetXaxis()->GetXmax();
           Double_t xmin = h_data->GetXaxis()->GetXmin();
  
           TLine* line = new TLine(xmin,1.,xmax,1.);

	   pad2->SetTopMargin(0);
	   pad2->Draw();
	   pad2->cd();
	   pad2->SetGrid();
	   Data->Sumw2();
	   h_data->GetYaxis()->SetRangeUser(0., 2.);
	   h_data->GetYaxis()->SetNdivisions(4,false);
	   h_data->GetXaxis()->SetTitleSize(0.23);
	   h_data->GetXaxis()->SetLabelSize(0.20);
	   h_data->GetYaxis()->SetLabelSize(0.20);
	   h_data->GetYaxis()->SetTitleSize(0.20);
	   h_data->GetYaxis()->SetTitleOffset(0.4);
	   h_data->GetXaxis()->SetTitleOffset(0.9);
	   h_data->GetYaxis()->SetTitle("Data / MC");
	   h_data->SetMarkerColor(kBlack);
	   h_data->SetMarkerStyle(20);
	   h_data->SetMarkerSize(1.1);
	   h_data->Sumw2();
	   h_data->Divide(h_mc);
 	   line->SetLineWidth(1.5);
 	   line->SetLineColor(kRed);
	   h_data->Draw("ep");
  	   line->Draw("same");
	   h_data->Draw("epsame");
           pad2->RedrawAxis();

	   c1->cd();

           TString savedir = "~/www/STOP/NNTraining/8TeV/Plots17/dataMC/";
           c1->Print(savedir+"/"+plotname+".png");

	   delete c1;
}




void makeAllPlots(){


DataMCplots("h1_met");
DataMCplots("h1_mT");
DataMCplots("h1_lepton_pT");
//DataMCplots("h1_lepton_pT_Zoom");
DataMCplots("h1_mlb_hemi");
DataMCplots("h1_m3b");
DataMCplots("h1_mT2W");
DataMCplots("h1_b1_pt");
DataMCplots("h1_dPhi_JetMet");
DataMCplots("h1_dR_LepB");
DataMCplots("h1_jet1_pT");
DataMCplots("h1_jet2_pT");
DataMCplots("h1_jet3_pT");
DataMCplots("h1_jet4_pT");
DataMCplots("h1_HTfrac");
DataMCplots("h1_njets");
DataMCplots("h1_Chi2SNT");
DataMCplots("h1_METoverSqrtHT");
DataMCplots("h1_nvTX");
//DataMCplots("BDT1");
DataMCplots("BDT2");
//DataMCplots("BDT3");
//DataMCplots("BDT4");


}


