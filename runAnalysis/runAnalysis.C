// C / C++ headers
#include <cmath>
#include <iostream>
using namespace std;

#include <utility>
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
#include "../cutAndCountDefinitions.h" 
#include "../signalRegionDefinitions.h" 





// ###################
// #  Main function  #
// ###################

int main (int argc, char *argv[])
{



  // ################################
  // ##       Open the tree        ##
  // ################################



   TFile *fin = TFile::Open(argv[1]);
   TTree* theInputTree = (TTree*) fin->Get("babyTuple"); 
   TFile *fout = new TFile(argv[2],"recreate");


   intermediatePointers pointers;
   InitializeBranchesForReading(theInputTree,&myEvent,&pointers);
     



   char name1[100], title1[100];
   char name2[200], title2[200];
   char name3[300], title3[300];
   char name4[400], title4[400];
   char name5[500], title5[500];
   char name6[500], title6[500];
   char name7[500], title7[500];
   char name8[500], title8[500];
   char name9[500], title9[500];
   char name10[500], title10[500];
   char name11[500], title11[500];
   char name12[500], title12[500];
   char name13[500], title13[500];
   char name14[500], title14[500];
   char name15[500], title15[500];
   char name16[500], title16[500];

   char name17[500], title17[500];
   char name18[500], title18[500];
   char name19[500], title19[500];
   char name20[500], title20[500];
   char name21_loose[500], title21_loose[500];
   char name21_tight[500], title21_tight[500];
   char name22[500], title22[500];
   char name23[500], title23[500];
   char name24[500], title24[500];
   char name25[500], title25[500];
   char name26[500], title26[500];
   char name27[500], title27[500];
   char name28[500], title28[500];
   char name29[500], title29[500];
   char name30[500], title30[500];
   char name31[500], title31[500];
   char name32_loose[500], title32_loose[500];
   char name32_tight[500], title32_tight[500];

   TH1D* Events_Preselection;

   TH1D* Events_T2tt_offShellLoose ; 
   TH1D* Events_T2tt_offShellTight ; 
   TH1D* Events_T2tt_lowDeltaM ; 
   TH1D* Events_T2tt_mediumDeltaM ; 
   TH1D* Events_T2tt_highDeltaM ; 

   TH1D* Events_T2bw025_veryOffShell_loose; 
   TH1D* Events_T2bw025_offShell_loose;
   TH1D* Events_T2bw025_lowDeltaM_tight; 
   TH1D* Events_T2bw025_highDeltaM;

   TH1D* Events_T2bw050_offShell_loose;
   TH1D* Events_T2bw050_lowMass;
   TH1D* Events_T2bw050_mediumDeltaM_loose;
   TH1D* Events_T2bw050_highDeltaM;

   TH1D* Events_T2bw075_lowDeltaM_tight;
   TH1D* Events_T2bw075_mediumDeltaM;
   TH1D* Events_T2bw075_highDeltaM;
 
   TH1D* hist_BDT_output_t2bw025_R1;
   TH1D* hist_BDT_output_t2bw025_R3;
   TH1D* hist_BDT_output_t2bw025_R4;
   TH1D* hist_BDT_output_t2bw025_R6;

   TH1D* hist_BDT_output_t2bw050_R1_loose;
   TH1D* hist_BDT_output_t2bw050_R1_tight;
   TH1D* hist_BDT_output_t2bw050_R3;
   TH1D* hist_BDT_output_t2bw050_R4;
   TH1D* hist_BDT_output_t2bw050_R5;
   TH1D* hist_BDT_output_t2bw050_R6;

   TH1D* hist_BDT_output_t2bw075_R1;
   TH1D* hist_BDT_output_t2bw075_R2;
   TH1D* hist_BDT_output_t2bw075_R3;
   TH1D* hist_BDT_output_t2bw075_R5;

   TH1D* hist_BDT_output_t2tt_R1;
   TH1D* hist_BDT_output_t2tt_R2;
   TH1D* hist_BDT_output_t2tt_R5_loose;
   TH1D* hist_BDT_output_t2tt_R5_tight;

   sprintf(name1,"Events_T2tt_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title1,"Events_T2tt_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name2,"Events_T2tt_offShellTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title2,"Events_T2tt_offShellTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name3,"Events_T2tt_lowDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title3,"Events_T2tt_lowDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name4,"Events_T2tt_mediumDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title4,"Events_T2tt_mediumDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name5,"Events_T2tt_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title5,"Events_T2tt_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name6,"Events_T2bw025_veryOffShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title6,"Events_T2bw025_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name7,"Events_T2bw025_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title7,"Events_T2bw025_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name8,"Events_T2bw025_lowDeltaMTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title8,"Events_T2bw025_lowDeltaMTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name9,"Events_T2bw025_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title9,"Events_T2bw025_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name10,"Events_T2bw050_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title10,"Events_T2bw050_offShellLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name11,"Events_T2bw050_lowMass_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title11,"Events_T2bw050_lowMass_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name12,"Events_T2bw050_mediumDeltaMLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title12,"Events_T2bw050_mediumDeltaMLoose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name13,"Events_T2bw050_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title13,"Events_T2bw050_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name14,"Events_T2bw075_lowDeltaMTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title14,"Events_T2bw075_lowDeltaMTight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name15,"Events_T2bw075_mediumDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title15,"Events_T2bw075_mediumDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name16,"Events_T2bw075_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title16,"Events_T2bw075_highDeltaM_S%i_N%i", atoi(argv[3]), atoi(argv[4]));




   sprintf(name17,"hist_BDT_output_t2bw025_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title17,"hist_BDT_output_t2bw025_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name18,"hist_BDT_output_t2bw025_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title18,"hist_BDT_output_t2bw025_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name19,"hist_BDT_output_t2bw025_R4_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title19,"hist_BDT_output_t2bw025_R4_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name20,"hist_BDT_output_t2bw025_R6_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title20,"hist_BDT_output_t2bw025_R6_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name21_loose,"hist_BDT_output_t2bw050_R1_loose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_loose,"hist_BDT_output_t2bw050_R1_loose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_tight,"hist_BDT_output_t2bw050_R1_tight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_tight,"hist_BDT_output_t2bw050_R1_tight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name22,"hist_BDT_output_t2bw050_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title22,"hist_BDT_output_t2bw050_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name23,"hist_BDT_output_t2bw050_R4_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title23,"hist_BDT_output_t2bw050_R4_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name24,"hist_BDT_output_t2bw050_R5_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title24,"hist_BDT_output_t2bw050_R5_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name25,"hist_BDT_output_t2bw050_R6_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title25,"hist_BDT_output_t2bw050_R6_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name26,"hist_BDT_output_t2bw075_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title26,"hist_BDT_output_t2bw075_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name27,"hist_BDT_output_t2bw075_R2_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title27,"hist_BDT_output_t2bw075_R2_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name28,"hist_BDT_output_t2bw075_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title28,"hist_BDT_output_t2bw075_R3_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name29,"hist_BDT_output_t2bw075_R5_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title29,"hist_BDT_output_t2bw075_R5_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name30,"hist_BDT_output_t2tt_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title30,"hist_BDT_output_t2tt_R1_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name31,"hist_BDT_output_t2tt_R2_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title31,"hist_BDT_output_t2tt_R2_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_loose,"hist_BDT_output_t2tt_R5_loose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_loose,"hist_BDT_output_t2tt_R5_loose_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_tight,"hist_BDT_output_t2tt_R5_tight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_tight,"hist_BDT_output_t2tt_R5_tight_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   Events_Preselection 	= new TH1D("Preselection","",50,0,1000) ; 

   Events_T2tt_offShellLoose 	= new TH1D(name1,title1,50,0,1000) ; 
   Events_T2tt_offShellTight 	= new TH1D(name2,title2,50,0,1000) ; 
   Events_T2tt_lowDeltaM 	= new TH1D(name3,title3,50,0,1000) ; 
   Events_T2tt_mediumDeltaM 	= new TH1D(name4,title4,50,0,1000) ; 
   Events_T2tt_highDeltaM 	= new TH1D(name5,title5,50,0,1000) ; 

   Events_T2bw025_veryOffShell_loose = new TH1D(name6,title6,50,0,1000); 
   Events_T2bw025_offShell_loose = new TH1D(name7,title7,50,0,1000);
   Events_T2bw025_lowDeltaM_tight = new TH1D(name8,title8,50,0,1000); 
   Events_T2bw025_highDeltaM = new TH1D(name9,title9,50,0,1000);

   Events_T2bw050_offShell_loose = new TH1D(name10,title10,50,0,1000);
   Events_T2bw050_lowMass = new TH1D(name11,title11,50,0,1000);
   Events_T2bw050_mediumDeltaM_loose = new TH1D(name12,title12,50,0,1000);
   Events_T2bw050_highDeltaM = new TH1D(name13,title13,50,0,1000);

   Events_T2bw075_lowDeltaM_tight = new TH1D(name14,title14,50,0,1000);
   Events_T2bw075_mediumDeltaM = new TH1D(name15,title15,50,0,1000);
   Events_T2bw075_highDeltaM = new TH1D(name16,title16,50,0,1000);

   	
   hist_BDT_output_t2bw025_R1 = new TH1D(name17,title17,100,-2,2);
   hist_BDT_output_t2bw025_R3 = new TH1D(name18,title18,100,-2,2);
   hist_BDT_output_t2bw025_R4 = new TH1D(name19,title19,100,-2,2);
   hist_BDT_output_t2bw025_R6 = new TH1D(name20,title20,100,-2,2);

   hist_BDT_output_t2bw050_R1_loose = new TH1D(name21_loose,title21_loose,100,-2,2);
   hist_BDT_output_t2bw050_R1_tight = new TH1D(name21_tight,title21_tight,100,-2,2);
   hist_BDT_output_t2bw050_R3 = new TH1D(name22,title22,100,-2,2);
   hist_BDT_output_t2bw050_R4 = new TH1D(name23,title23,100,-2,2);
   hist_BDT_output_t2bw050_R5 = new TH1D(name24,title24,100,-2,2);
   hist_BDT_output_t2bw050_R6 = new TH1D(name25,title25,100,-2,2);

   hist_BDT_output_t2bw075_R1 = new TH1D(name26,title26,100,-2,2);
   hist_BDT_output_t2bw075_R2 = new TH1D(name27,title27,100,-2,2);
   hist_BDT_output_t2bw075_R3 = new TH1D(name28,title28,100,-2,2);
   hist_BDT_output_t2bw075_R5 = new TH1D(name29,title29,100,-2,2);


   hist_BDT_output_t2tt_R1 = new TH1D(name30,title30,100,-2,2);
   hist_BDT_output_t2tt_R2 = new TH1D(name31,title31,100,-2,2);
   hist_BDT_output_t2tt_R5_loose = new TH1D(name32_loose,title32_loose,100,-2,2);
   hist_BDT_output_t2tt_R5_tight = new TH1D(name32_tight,title32_tight,100,-2,2);


   // ########################################
   // ##        Run over the events         ##
   // ########################################
   

   int counter = 0; 
   int counter1 = 0; 
   int counter2 = 0; 
   int counter3 = 0; 
   int counter4 = 0; 
   int counter5 = 0; 
   int counter6 = 0; 
   int counter7 = 0; 
   int counter8 = 0; 
   int counter9 = 0; 
   int counter10 = 0; 
   int counter11 = 0; 
   int counter12 = 0; 
   int counter13 = 0; 
   int counter14 = 0; 
   int counter15 = 0; 
   int counter16 = 0; 

   for (int i = 0 ; i < theInputTree->GetEntries() ; i++){


        ReadEvent(theInputTree,i,&pointers,&myEvent);


        if (string(argv[1]).find("ttbar_madgraph") != std::string::npos)   	{sampleName = "ttbar_madgraph"; } 
        if (string(argv[1]).find("SingleElec") != std::string::npos) 		{sampleName = "SingleElec"; } 
        if (string(argv[1]).find("SingleMuon") != std::string::npos) 		{sampleName = "SingleMuon";} 
        if (string(argv[1]).find("DoubleElec") != std::string::npos) 		{sampleName = "DoubleElec";} 
        if (string(argv[1]).find("DoubleMuon") != std::string::npos) 		{sampleName = "DoubleMuon";} 
        if (string(argv[1]).find("MuEl") != std::string::npos) 	     		{sampleName = "MuEl";} 

        if (myEvent.mStop > 0) 						{sampleType = "signal"; }
        if ( (sampleName == "SingleElec") || (sampleName == "SingleMuon") 
	  || (sampleName == "DoubleElec") || (sampleName == "DoubleMuon") 
	  || (sampleName == "MuEl")) {						 sampleType = "data"; } 





                if (goesInPreselectionMTtail() == 0) continue;
		
                if ( (sampleType == "signal")  &&  !((myEvent.mStop ==  atoi(argv[3]) ) && (myEvent.mNeutralino ==  atoi(argv[4]) )) )continue;


			counter ++;
			Events_Preselection->Fill(  counter , getWeight());

			if ( cutAndCount_T2tt_offShellLoose(true) == true){ 
			counter1 ++;
			Events_T2tt_offShellLoose->Fill(counter1, getWeight());
			}

                        if ( cutAndCount_T2tt_offShellTight(true) == true){
			counter2 ++;
			Events_T2tt_offShellTight->Fill(counter2, getWeight());
			}	
			
                        if ( cutAndCount_T2tt_lowDeltaM(true) == true){
			counter3 ++;
			Events_T2tt_lowDeltaM->Fill(counter3, getWeight());
			}	

                        if ( cutAndCount_T2tt_mediumDeltaM(true) == true){
			counter4 ++;
			Events_T2tt_mediumDeltaM->Fill(counter4, getWeight());
			}	

                        if ( cutAndCount_T2tt_highDeltaM(true) == true){
			counter5 ++;
			Events_T2tt_highDeltaM->Fill(counter5, getWeight());
			}	


                        if ( cutAndCount_T2bw025_veryOffShell_loose(true) == true){
			counter6 ++;
                        Events_T2bw025_veryOffShell_loose->Fill(counter6, getWeight());
                        }

                        if ( cutAndCount_T2bw025_offShell_loose(true) == true){
			counter7 ++;
                        Events_T2bw025_offShell_loose->Fill(counter7, getWeight());
                        }

                        if ( cutAndCount_T2bw025_lowDeltaM_tight(true) == true){
			counter8 ++;
                        Events_T2bw025_lowDeltaM_tight->Fill(counter8, getWeight());
                        }

                        if ( cutAndCount_T2bw025_highDeltaM(true) == true){
			counter9 ++;
                        Events_T2bw025_highDeltaM->Fill(counter9, getWeight());
                        }

	
                        if ( cutAndCount_T2bw050_offShell_loose(true) == true){
			counter10 ++;
                        Events_T2bw050_offShell_loose->Fill(counter10, getWeight());
                        }

                        if ( cutAndCount_T2bw050_lowMass(true) == true){
			counter11 ++;
                        Events_T2bw050_lowMass->Fill(counter11, getWeight());
                        }

                        if ( cutAndCount_T2bw050_mediumDeltaM_loose(true) == true){
			counter12 ++;
                        Events_T2bw050_mediumDeltaM_loose->Fill(counter12, getWeight());
                        }

                        if ( cutAndCount_T2bw050_highDeltaM(true) == true){
			counter13 ++;
                        Events_T2bw050_highDeltaM->Fill(counter13, getWeight());
                        }


                        if ( cutAndCount_T2bw075_lowDeltaM_tight(true) == true){
			counter14 ++;
                        Events_T2bw075_lowDeltaM_tight->Fill(counter14, getWeight());
                        }

                        if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){
			counter15 ++;
                        Events_T2bw075_mediumDeltaM->Fill(counter15, getWeight());
                        }

                        if ( cutAndCount_T2bw075_highDeltaM(true) == true){
			counter16 ++;
                        Events_T2bw075_highDeltaM->Fill(counter16, getWeight());
                        }


			// BDT STUFF
			
			if (myEvent.isUsedInBDT == 1) continue;
			double weight = getWeight() * 2.; 

			hist_BDT_output_t2bw025_R1->Fill(myEvent.BDT_output_t2bw025_R1, weight);		
			hist_BDT_output_t2bw025_R3->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
			hist_BDT_output_t2bw025_R4->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
			hist_BDT_output_t2bw025_R6->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


			hist_BDT_output_t2bw050_R1_tight->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
			hist_BDT_output_t2bw050_R1_loose->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
			hist_BDT_output_t2bw050_R3->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
			hist_BDT_output_t2bw050_R4->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
			hist_BDT_output_t2bw050_R5->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
			hist_BDT_output_t2bw050_R6->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

			hist_BDT_output_t2bw075_R1->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
			hist_BDT_output_t2bw075_R2->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
			hist_BDT_output_t2bw075_R3->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
			hist_BDT_output_t2bw075_R5->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

			hist_BDT_output_t2tt_R1->Fill(myEvent.BDT_output_t2tt_R1, weight);		
			hist_BDT_output_t2tt_R2->Fill(myEvent.BDT_output_t2tt_R2, weight);		
			hist_BDT_output_t2tt_R5_loose->Fill(myEvent.BDT_output_t2tt_R5, weight);		
			hist_BDT_output_t2tt_R5_tight->Fill(myEvent.BDT_output_t2tt_R5, weight);		

 } 

    
      fout->cd();
      fout->Write();
      fout->Close();



      return (0);

}



