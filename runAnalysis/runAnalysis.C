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


   char name1BVetoBCUp[100], title1BVetoBCUp[100];
   char name1BVetoBCDown[100], title1BVetoBCDown[100];
   char name1BVetoLightUp[100], title1BVetoLightUp[100];
   char name1BVetoLightDown[100], title1BVetoLightDown[100];

   char name2BVetoBCUp[100], title2BVetoBCUp[100];
   char name2BVetoBCDown[100], title2BVetoBCDown[100];
   char name2BVetoLightUp[100], title2BVetoLightUp[100];
   char name2BVetoLightDown[100], title2BVetoLightDown[100];

   char name3BVetoBCUp[100], title3BVetoBCUp[100];
   char name3BVetoBCDown[100], title3BVetoBCDown[100];
   char name3BVetoLightUp[100], title3BVetoLightUp[100];
   char name3BVetoLightDown[100], title3BVetoLightDown[100];

   char name4BVetoBCUp[100], title4BVetoBCUp[100];
   char name4BVetoBCDown[100], title4BVetoBCDown[100];
   char name4BVetoLightUp[100], title4BVetoLightUp[100];
   char name4BVetoLightDown[100], title4BVetoLightDown[100];

   char name5BVetoBCUp[100], title5BVetoBCUp[100];
   char name5BVetoBCDown[100], title5BVetoBCDown[100];
   char name5BVetoLightUp[100], title5BVetoLightUp[100];
   char name5BVetoLightDown[100], title5BVetoLightDown[100];

   char name6BVetoBCUp[100], title6BVetoBCUp[100];
   char name6BVetoBCDown[100], title6BVetoBCDown[100];
   char name6BVetoLightUp[100], title6BVetoLightUp[100];
   char name6BVetoLightDown[100], title6BVetoLightDown[100];

   char name7BVetoBCUp[100], title7BVetoBCUp[100];
   char name7BVetoBCDown[100], title7BVetoBCDown[100];
   char name7BVetoLightUp[100], title7BVetoLightUp[100];
   char name7BVetoLightDown[100], title7BVetoLightDown[100];

   char name8BVetoBCUp[100], title8BVetoBCUp[100];
   char name8BVetoBCDown[100], title8BVetoBCDown[100];
   char name8BVetoLightUp[100], title8BVetoLightUp[100];
   char name8BVetoLightDown[100], title8BVetoLightDown[100];

   char name9BVetoBCUp[100], title9BVetoBCUp[100];
   char name9BVetoBCDown[100], title9BVetoBCDown[100];
   char name9BVetoLightUp[100], title9BVetoLightUp[100];
   char name9BVetoLightDown[100], title9BVetoLightDown[100];

   char name10BVetoBCUp[100], title10BVetoBCUp[100];
   char name10BVetoBCDown[100], title10BVetoBCDown[100];
   char name10BVetoLightUp[100], title10BVetoLightUp[100];
   char name10BVetoLightDown[100], title10BVetoLightDown[100];

   char name11BVetoBCUp[100], title11BVetoBCUp[100];
   char name11BVetoBCDown[100], title11BVetoBCDown[100];
   char name11BVetoLightUp[100], title11BVetoLightUp[100];
   char name11BVetoLightDown[100], title11BVetoLightDown[100];

   char name12BVetoBCUp[100], title12BVetoBCUp[100];
   char name12BVetoBCDown[100], title12BVetoBCDown[100];
   char name12BVetoLightUp[100], title12BVetoLightUp[100];
   char name12BVetoLightDown[100], title12BVetoLightDown[100];

   char name13BVetoBCUp[100], title13BVetoBCUp[100];
   char name13BVetoBCDown[100], title13BVetoBCDown[100];
   char name13BVetoLightUp[100], title13BVetoLightUp[100];
   char name13BVetoLightDown[100], title13BVetoLightDown[100];

   char name14BVetoBCUp[100], title14BVetoBCUp[100];
   char name14BVetoBCDown[100], title14BVetoBCDown[100];
   char name14BVetoLightUp[100], title14BVetoLightUp[100];
   char name14BVetoLightDown[100], title14BVetoLightDown[100];

   char name15BVetoBCUp[100], title15BVetoBCUp[100];
   char name15BVetoBCDown[100], title15BVetoBCDown[100];
   char name15BVetoLightUp[100], title15BVetoLightUp[100];
   char name15BVetoLightDown[100], title15BVetoLightDown[100];

   char name16BVetoBCUp[100], title16BVetoBCUp[100];
   char name16BVetoBCDown[100], title16BVetoBCDown[100];
   char name16BVetoLightUp[100], title16BVetoLightUp[100];
   char name16BVetoLightDown[100], title16BVetoLightDown[100];

   // BDT stuff
   //
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


   char name17BVetoBCUp[500], title17BVetoBCUp[500];
   char name17BVetoBCDown[500], title17BVetoBCDown[500];
   char name17BVetoLightUp[500], title17BVetoLightUp[500];
   char name17BVetoLightDown[500], title17BVetoLightDown[500];

   char name18BVetoBCUp[500], title18BVetoBCUp[500];
   char name18BVetoBCDown[500], title18BVetoBCDown[500];
   char name18BVetoLightUp[500], title18BVetoLightUp[500];
   char name18BVetoLightDown[500], title18BVetoLightDown[500];

   char name19BVetoBCUp[500], title19BVetoBCUp[500];
   char name19BVetoBCDown[500], title19BVetoBCDown[500];
   char name19BVetoLightUp[500], title19BVetoLightUp[500];
   char name19BVetoLightDown[500], title19BVetoLightDown[500];

   char name20BVetoBCUp[500], title20BVetoBCUp[500];
   char name20BVetoBCDown[500], title20BVetoBCDown[500];
   char name20BVetoLightUp[500], title20BVetoLightUp[500];
   char name20BVetoLightDown[500], title20BVetoLightDown[500];

   char name21_looseBVetoBCUp[500], title21_looseBVetoBCUp[500];
   char name21_looseBVetoBCDown[500], title21_looseBVetoBCDown[500];
   char name21_looseBVetoLightUp[500], title21_looseBVetoLightUp[500];
   char name21_looseBVetoLightDown[500], title21_looseBVetoLightDown[500];

   char name21_tightBVetoBCUp[500], title21_tightBVetoBCUp[500];
   char name21_tightBVetoBCDown[500], title21_tightBVetoBCDown[500];
   char name21_tightBVetoLightUp[500], title21_tightBVetoLightUp[500];
   char name21_tightBVetoLightDown[500], title21_tightBVetoLightDown[500];

   char name22BVetoBCUp[500], title22BVetoBCUp[500];
   char name22BVetoBCDown[500], title22BVetoBCDown[500];
   char name22BVetoLightUp[500], title22BVetoLightUp[500];
   char name22BVetoLightDown[500], title22BVetoLightDown[500];

   char name23BVetoBCUp[500], title23BVetoBCUp[500];
   char name23BVetoBCDown[500], title23BVetoBCDown[500];
   char name23BVetoLightUp[500], title23BVetoLightUp[500];
   char name23BVetoLightDown[500], title23BVetoLightDown[500];

   char name24BVetoBCUp[500], title24BVetoBCUp[500];
   char name24BVetoBCDown[500], title24BVetoBCDown[500];
   char name24BVetoLightUp[500], title24BVetoLightUp[500];
   char name24BVetoLightDown[500], title24BVetoLightDown[500];

   char name25BVetoBCUp[500], title25BVetoBCUp[500];
   char name25BVetoBCDown[500], title25BVetoBCDown[500];
   char name25BVetoLightUp[500], title25BVetoLightUp[500];
   char name25BVetoLightDown[500], title25BVetoLightDown[500];


   char name26BVetoBCUp[500], title26BVetoBCUp[500];
   char name26BVetoBCDown[500], title26BVetoBCDown[500];
   char name26BVetoLightUp[500], title26BVetoLightUp[500];
   char name26BVetoLightDown[500], title26BVetoLightDown[500];

   char name27BVetoBCUp[500], title27BVetoBCUp[500];
   char name27BVetoBCDown[500], title27BVetoBCDown[500];
   char name27BVetoLightUp[500], title27BVetoLightUp[500];
   char name27BVetoLightDown[500], title27BVetoLightDown[500];

   char name28BVetoBCUp[500], title28BVetoBCUp[500];
   char name28BVetoBCDown[500], title28BVetoBCDown[500];
   char name28BVetoLightUp[500], title28BVetoLightUp[500];
   char name28BVetoLightDown[500], title28BVetoLightDown[500];


   char name29BVetoBCUp[500], title29BVetoBCUp[500];
   char name29BVetoBCDown[500], title29BVetoBCDown[500];
   char name29BVetoLightUp[500], title29BVetoLightUp[500];
   char name29BVetoLightDown[500], title29BVetoLightDown[500];


   char name30BVetoBCUp[500], title30BVetoBCUp[500];
   char name30BVetoBCDown[500], title30BVetoBCDown[500];
   char name30BVetoLightUp[500], title30BVetoLightUp[500];
   char name30BVetoLightDown[500], title30BVetoLightDown[500];


   char name31BVetoBCUp[500], title31BVetoBCUp[500];
   char name31BVetoBCDown[500], title31BVetoBCDown[500];
   char name31BVetoLightUp[500], title31BVetoLightUp[500];
   char name31BVetoLightDown[500], title31BVetoLightDown[500];


   char name32_looseBVetoBCUp[500], title32_looseBVetoBCUp[500];
   char name32_looseBVetoBCDown[500], title32_looseBVetoBCDown[500];
   char name32_looseBVetoLightUp[500], title32_looseBVetoLightUp[500];
   char name32_looseBVetoLightDown[500], title32_looseBVetoLightDown[500];

   char name32_tightBVetoBCUp[500], title32_tightBVetoBCUp[500];
   char name32_tightBVetoBCDown[500], title32_tightBVetoBCDown[500];
   char name32_tightBVetoLightUp[500], title32_tightBVetoLightUp[500];
   char name32_tightBVetoLightDown[500], title32_tightBVetoLightDown[500];


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


   // BVETO systematics
  

   TH1D* Events_T2tt_offShellLooseBVetoBCUp ; 
   TH1D* Events_T2tt_offShellLooseBVetoBCDown ; 
   TH1D* Events_T2tt_offShellLooseBVetoLightUp ; 
   TH1D* Events_T2tt_offShellLooseBVetoLightDown ; 

   TH1D* Events_T2tt_offShellTightBVetoBCUp ;        
   TH1D* Events_T2tt_offShellTightBVetoBCDown ;      
   TH1D* Events_T2tt_offShellTightBVetoLightUp ;     
   TH1D* Events_T2tt_offShellTightBVetoLightDown ;   


   TH1D* Events_T2tt_lowDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_lowDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_lowDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_lowDeltaMBVetoLightDown ;   


   TH1D* Events_T2tt_mediumDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_mediumDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_mediumDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_mediumDeltaMBVetoLightDown ;   

   TH1D* Events_T2tt_highDeltaMBVetoBCUp ;        
   TH1D* Events_T2tt_highDeltaMBVetoBCDown ;      
   TH1D* Events_T2tt_highDeltaMBVetoLightUp ;     
   TH1D* Events_T2tt_highDeltaMBVetoLightDown ;   


   TH1D* Events_T2bw025_veryOffShell_looseBVetoBCUp ;      
   TH1D* Events_T2bw025_veryOffShell_looseBVetoBCDown ;    
   TH1D* Events_T2bw025_veryOffShell_looseBVetoLightUp ;   
   TH1D* Events_T2bw025_veryOffShell_looseBVetoLightDown ; 


   TH1D* Events_T2bw025_offShell_looseBVetoBCUp ;      
   TH1D* Events_T2bw025_offShell_looseBVetoBCDown ;   
   TH1D* Events_T2bw025_offShell_looseBVetoLightUp ;  
   TH1D* Events_T2bw025_offShell_looseBVetoLightDown ;

   TH1D* Events_T2bw025_lowDeltaM_tightBVetoBCUp ;      
   TH1D* Events_T2bw025_lowDeltaM_tightBVetoBCDown ;    
   TH1D* Events_T2bw025_lowDeltaM_tightBVetoLightUp ;   
   TH1D* Events_T2bw025_lowDeltaM_tightBVetoLightDown ; 

   TH1D* Events_T2bw025_highDeltaMBVetoBCUp ;      
   TH1D* Events_T2bw025_highDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw025_highDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw025_highDeltaMBVetoLightDown ;

   TH1D* Events_T2bw050_offShell_looseBVetoBCUp ;     
   TH1D* Events_T2bw050_offShell_looseBVetoBCDown ;   
   TH1D* Events_T2bw050_offShell_looseBVetoLightUp ;  
   TH1D* Events_T2bw050_offShell_looseBVetoLightDown ;

   TH1D* Events_T2bw050_lowMassBVetoBCUp ;     
   TH1D* Events_T2bw050_lowMassBVetoBCDown ;   
   TH1D* Events_T2bw050_lowMassBVetoLightUp ;  
   TH1D* Events_T2bw050_lowMassBVetoLightDown ;

   TH1D* Events_T2bw050_mediumDeltaM_looseBVetoBCUp ;     
   TH1D* Events_T2bw050_mediumDeltaM_looseBVetoBCDown ;   
   TH1D* Events_T2bw050_mediumDeltaM_looseBVetoLightUp ;  
   TH1D* Events_T2bw050_mediumDeltaM_looseBVetoLightDown ;

   TH1D* Events_T2bw050_highDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw050_highDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw050_highDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw050_highDeltaMBVetoLightDown ;

   TH1D* Events_T2bw075_lowDeltaM_tightBVetoBCUp ;     
   TH1D* Events_T2bw075_lowDeltaM_tightBVetoBCDown ;   
   TH1D* Events_T2bw075_lowDeltaM_tightBVetoLightUp ;  
   TH1D* Events_T2bw075_lowDeltaM_tightBVetoLightDown ;

   TH1D* Events_T2bw075_mediumDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw075_mediumDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw075_mediumDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw075_mediumDeltaMBVetoLightDown ;

   TH1D* Events_T2bw075_highDeltaMBVetoBCUp ;     
   TH1D* Events_T2bw075_highDeltaMBVetoBCDown ;   
   TH1D* Events_T2bw075_highDeltaMBVetoLightUp ;  
   TH1D* Events_T2bw075_highDeltaMBVetoLightDown ;


 
   TH1D* hist_BDT_output_t2bw025_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R4BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R4BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R4BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R4BVetoLightDown;

   TH1D* hist_BDT_output_t2bw025_R6BVetoBCUp;
   TH1D* hist_BDT_output_t2bw025_R6BVetoBCDown;
   TH1D* hist_BDT_output_t2bw025_R6BVetoLightUp;
   TH1D* hist_BDT_output_t2bw025_R6BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R1_looseBVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R1_looseBVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R1_looseBVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R1_looseBVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R1_tightBVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R1_tightBVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R1_tightBVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R1_tightBVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R4BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R4BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R4BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R4BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R5BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R5BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R5BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R5BVetoLightDown;

   TH1D* hist_BDT_output_t2bw050_R6BVetoBCUp;
   TH1D* hist_BDT_output_t2bw050_R6BVetoBCDown;
   TH1D* hist_BDT_output_t2bw050_R6BVetoLightUp;
   TH1D* hist_BDT_output_t2bw050_R6BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R2BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R2BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R2BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R2BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R3BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R3BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R3BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R3BVetoLightDown;

   TH1D* hist_BDT_output_t2bw075_R5BVetoBCUp;
   TH1D* hist_BDT_output_t2bw075_R5BVetoBCDown;
   TH1D* hist_BDT_output_t2bw075_R5BVetoLightUp;
   TH1D* hist_BDT_output_t2bw075_R5BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R1BVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R1BVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R1BVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R1BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R2BVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R2BVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R2BVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R2BVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R5_looseBVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R5_looseBVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R5_looseBVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R5_looseBVetoLightDown;

   TH1D* hist_BDT_output_t2tt_R5_tightBVetoBCUp;
   TH1D* hist_BDT_output_t2tt_R5_tightBVetoBCDown;
   TH1D* hist_BDT_output_t2tt_R5_tightBVetoLightUp;
   TH1D* hist_BDT_output_t2tt_R5_tightBVetoLightDown;


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



   sprintf(name1BVetoBCUp,"Events_T2tt_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title1BVetoBCUp,"Events_T2tt_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name1BVetoBCDown,"Events_T2tt_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title1BVetoBCDown,"Events_T2tt_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name1BVetoLightUp,"Events_T2tt_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title1BVetoLightUp,"Events_T2tt_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name1BVetoLightDown,"Events_T2tt_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title1BVetoLightDown,"Events_T2tt_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name2BVetoBCUp,"Events_T2tt_offShellTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title2BVetoBCUp,"Events_T2tt_offShellTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name2BVetoBCDown,"Events_T2tt_offShellTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title2BVetoBCDown,"Events_T2tt_offShellTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name2BVetoLightUp,"Events_T2tt_offShellTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title2BVetoLightUp,"Events_T2tt_offShellTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name2BVetoLightDown,"Events_T2tt_offShellTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title2BVetoLightDown,"Events_T2tt_offShellTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name3BVetoBCUp,"Events_T2tt_lowDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title3BVetoBCUp,"Events_T2tt_lowDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name3BVetoBCDown,"Events_T2tt_lowDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title3BVetoBCDown,"Events_T2tt_lowDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name3BVetoLightUp,"Events_T2tt_lowDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title3BVetoLightUp,"Events_T2tt_lowDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name3BVetoLightDown,"Events_T2tt_lowDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title3BVetoLightDown,"Events_T2tt_lowDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name4BVetoBCUp,"Events_T2tt_mediumDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title4BVetoBCUp,"Events_T2tt_mediumDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name4BVetoBCDown,"Events_T2tt_mediumDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title4BVetoBCDown,"Events_T2tt_mediumDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name4BVetoLightUp,"Events_T2tt_mediumDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title4BVetoLightUp,"Events_T2tt_mediumDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name4BVetoLightDown,"Events_T2tt_mediumDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title4BVetoLightDown,"Events_T2tt_mediumDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name5BVetoBCUp,"Events_T2tt_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title5BVetoBCUp,"Events_T2tt_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name5BVetoBCDown,"Events_T2tt_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title5BVetoBCDown,"Events_T2tt_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name5BVetoLightUp,"Events_T2tt_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title5BVetoLightUp,"Events_T2tt_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name5BVetoLightDown,"Events_T2tt_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title5BVetoLightDown,"Events_T2tt_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name6BVetoBCUp,"Events_T2bw025_veryOffShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title6BVetoBCUp,"Events_T2bw025_veryOffShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name6BVetoBCDown,"Events_T2bw025_veryOffShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title6BVetoBCDown,"Events_T2bw025_veryOffShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name6BVetoLightUp,"Events_T2bw025_veryOffShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title6BVetoLightUp,"Events_T2bw025_veryOffShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name6BVetoLightDown,"Events_T2bw025_veryOffShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title6BVetoLightDown,"Events_T2bw025_veryOffShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name7BVetoBCUp,"Events_T2bw025_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title7BVetoBCUp,"Events_T2bw025_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name7BVetoBCDown,"Events_T2bw025_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title7BVetoBCDown,"Events_T2bw025_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name7BVetoLightUp,"Events_T2bw025_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title7BVetoLightUp,"Events_T2bw025_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name7BVetoLightDown,"Events_T2bw025_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title7BVetoLightDown,"Events_T2bw025_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name8BVetoBCUp,"Events_T2bw025_lowDeltaMTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title8BVetoBCUp,"Events_T2bw025_lowDeltaMTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name8BVetoBCDown,"Events_T2bw025_lowDeltaMTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title8BVetoBCDown,"Events_T2bw025_lowDeltaMTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name8BVetoLightUp,"Events_T2bw025_lowDeltaMTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title8BVetoLightUp,"Events_T2bw025_lowDeltaMTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name8BVetoLightDown,"Events_T2bw025_lowDeltaMTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title8BVetoLightDown,"Events_T2bw025_lowDeltaMTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name9BVetoBCUp,"Events_T2bw025_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title9BVetoBCUp,"Events_T2bw025_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name9BVetoBCDown,"Events_T2bw025_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title9BVetoBCDown,"Events_T2bw025_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name9BVetoLightUp,"Events_T2bw025_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title9BVetoLightUp,"Events_T2bw025_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name9BVetoLightDown,"Events_T2bw025_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title9BVetoLightDown,"Events_T2bw025_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));




   sprintf(name10BVetoBCUp,"Events_T2bw050_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title10BVetoBCUp,"Events_T2bw050_offShellLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name10BVetoBCDown,"Events_T2bw050_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title10BVetoBCDown,"Events_T2bw050_offShellLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name10BVetoLightUp,"Events_T2bw050_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title10BVetoLightUp,"Events_T2bw050_offShellLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name10BVetoLightDown,"Events_T2bw050_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title10BVetoLightDown,"Events_T2bw050_offShellLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name11BVetoBCUp,"Events_T2bw050_lowMassBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title11BVetoBCUp,"Events_T2bw050_lowMassBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name11BVetoBCDown,"Events_T2bw050_lowMassBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title11BVetoBCDown,"Events_T2bw050_lowMassBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name11BVetoLightUp,"Events_T2bw050_lowMassBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title11BVetoLightUp,"Events_T2bw050_lowMassBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name11BVetoLightDown,"Events_T2bw050_lowMassBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title11BVetoLightDown,"Events_T2bw050_lowMassBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name12BVetoBCUp,"Events_T2bw050_mediumDeltaMLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title12BVetoBCUp,"Events_T2bw050_mediumDeltaMLooseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name12BVetoBCDown,"Events_T2bw050_mediumDeltaMLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title12BVetoBCDown,"Events_T2bw050_mediumDeltaMLooseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name12BVetoLightUp,"Events_T2bw050_mediumDeltaMLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title12BVetoLightUp,"Events_T2bw050_mediumDeltaMLooseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name12BVetoLightDown,"Events_T2bw050_mediumDeltaMLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title12BVetoLightDown,"Events_T2bw050_mediumDeltaMLooseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name13BVetoBCUp,"Events_T2bw050_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title13BVetoBCUp,"Events_T2bw050_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name13BVetoBCDown,"Events_T2bw050_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title13BVetoBCDown,"Events_T2bw050_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name13BVetoLightUp,"Events_T2bw050_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title13BVetoLightUp,"Events_T2bw050_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name13BVetoLightDown,"Events_T2bw050_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title13BVetoLightDown,"Events_T2bw050_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name14BVetoBCUp,"Events_T2bw075_lowDeltaMTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title14BVetoBCUp,"Events_T2bw075_lowDeltaMTightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name14BVetoBCDown,"Events_T2bw075_lowDeltaMTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title14BVetoBCDown,"Events_T2bw075_lowDeltaMTightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name14BVetoLightUp,"Events_T2bw075_lowDeltaMTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title14BVetoLightUp,"Events_T2bw075_lowDeltaMTightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name14BVetoLightDown,"Events_T2bw075_lowDeltaMTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title14BVetoLightDown,"Events_T2bw075_lowDeltaMTightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name15BVetoBCUp,"Events_T2bw075_mediumDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title15BVetoBCUp,"Events_T2bw075_mediumDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name15BVetoBCDown,"Events_T2bw075_mediumDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title15BVetoBCDown,"Events_T2bw075_mediumDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name15BVetoLightUp,"Events_T2bw075_mediumDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title15BVetoLightUp,"Events_T2bw075_mediumDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name15BVetoLightDown,"Events_T2bw075_mediumDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title15BVetoLightDown,"Events_T2bw075_mediumDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name16BVetoBCUp,"Events_T2bw075_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title16BVetoBCUp,"Events_T2bw075_highDeltaMBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name16BVetoBCDown,"Events_T2bw075_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title16BVetoBCDown,"Events_T2bw075_highDeltaMBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name16BVetoLightUp,"Events_T2bw075_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title16BVetoLightUp,"Events_T2bw075_highDeltaMBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name16BVetoLightDown,"Events_T2bw075_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title16BVetoLightDown,"Events_T2bw075_highDeltaMBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));




   sprintf(name17BVetoBCUp,"hist_BDT_output_t2bw025_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title17BVetoBCUp,"hist_BDT_output_t2bw025_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name17BVetoBCDown,"hist_BDT_output_t2bw025_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title17BVetoBCDown,"hist_BDT_output_t2bw025_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name17BVetoLightUp,"hist_BDT_output_t2bw025_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title17BVetoLightUp,"hist_BDT_output_t2bw025_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name17BVetoLightDown,"hist_BDT_output_t2bw025_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title17BVetoLightDown,"hist_BDT_output_t2bw025_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name18BVetoBCUp,"hist_BDT_output_t2bw025_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title18BVetoBCUp,"hist_BDT_output_t2bw025_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name18BVetoBCDown,"hist_BDT_output_t2bw025_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title18BVetoBCDown,"hist_BDT_output_t2bw025_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name18BVetoLightUp,"hist_BDT_output_t2bw025_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title18BVetoLightUp,"hist_BDT_output_t2bw025_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name18BVetoLightDown,"hist_BDT_output_t2bw025_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title18BVetoLightDown,"hist_BDT_output_t2bw025_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name19BVetoBCUp,"hist_BDT_output_t2bw025_R4BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title19BVetoBCUp,"hist_BDT_output_t2bw025_R4BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name19BVetoBCDown,"hist_BDT_output_t2bw025_R4BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title19BVetoBCDown,"hist_BDT_output_t2bw025_R4BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name19BVetoLightUp,"hist_BDT_output_t2bw025_R4BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title19BVetoLightUp,"hist_BDT_output_t2bw025_R4BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name19BVetoLightDown,"hist_BDT_output_t2bw025_R4BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title19BVetoLightDown,"hist_BDT_output_t2bw025_R4BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name20BVetoBCUp,"hist_BDT_output_t2bw025_R6BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title20BVetoBCUp,"hist_BDT_output_t2bw025_R6BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name20BVetoBCDown,"hist_BDT_output_t2bw025_R6BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title20BVetoBCDown,"hist_BDT_output_t2bw025_R6BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name20BVetoLightUp,"hist_BDT_output_t2bw025_R6BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title20BVetoLightUp,"hist_BDT_output_t2bw025_R6BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name20BVetoLightDown,"hist_BDT_output_t2bw025_R6BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title20BVetoLightDown,"hist_BDT_output_t2bw025_R6BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   

   sprintf(name21_looseBVetoBCUp,"hist_BDT_output_t2bw050_R1_looseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_looseBVetoBCUp,"hist_BDT_output_t2bw050_R1_looseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_looseBVetoBCDown,"hist_BDT_output_t2bw050_R1_looseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_looseBVetoBCDown,"hist_BDT_output_t2bw050_R1_looseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_looseBVetoLightUp,"hist_BDT_output_t2bw050_R1_looseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_looseBVetoLightUp,"hist_BDT_output_t2bw050_R1_looseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_looseBVetoLightDown,"hist_BDT_output_t2bw050_R1_looseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_looseBVetoLightDown,"hist_BDT_output_t2bw050_R1_looseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name21_tightBVetoBCUp,"hist_BDT_output_t2bw050_R1_tightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_tightBVetoBCUp,"hist_BDT_output_t2bw050_R1_tightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_tightBVetoBCDown,"hist_BDT_output_t2bw050_R1_tightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_tightBVetoBCDown,"hist_BDT_output_t2bw050_R1_tightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_tightBVetoLightUp,"hist_BDT_output_t2bw050_R1_tightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_tightBVetoLightUp,"hist_BDT_output_t2bw050_R1_tightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name21_tightBVetoLightDown,"hist_BDT_output_t2bw050_R1_tightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title21_tightBVetoLightDown,"hist_BDT_output_t2bw050_R1_tightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name22BVetoBCUp,"hist_BDT_output_t2bw050_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title22BVetoBCUp,"hist_BDT_output_t2bw050_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name22BVetoBCDown,"hist_BDT_output_t2bw050_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title22BVetoBCDown,"hist_BDT_output_t2bw050_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name22BVetoLightUp,"hist_BDT_output_t2bw050_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title22BVetoLightUp,"hist_BDT_output_t2bw050_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name22BVetoLightDown,"hist_BDT_output_t2bw050_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title22BVetoLightDown,"hist_BDT_output_t2bw050_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name23BVetoBCUp,"hist_BDT_output_t2bw050_R4BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title23BVetoBCUp,"hist_BDT_output_t2bw050_R4BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name23BVetoBCDown,"hist_BDT_output_t2bw050_R4BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title23BVetoBCDown,"hist_BDT_output_t2bw050_R4BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name23BVetoLightUp,"hist_BDT_output_t2bw050_R4BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title23BVetoLightUp,"hist_BDT_output_t2bw050_R4BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name23BVetoLightDown,"hist_BDT_output_t2bw050_R4BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title23BVetoLightDown,"hist_BDT_output_t2bw050_R4BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name24BVetoBCUp,"hist_BDT_output_t2bw050_R5BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title24BVetoBCUp,"hist_BDT_output_t2bw050_R5BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name24BVetoBCDown,"hist_BDT_output_t2bw050_R5BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title24BVetoBCDown,"hist_BDT_output_t2bw050_R5BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name24BVetoLightUp,"hist_BDT_output_t2bw050_R5BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title24BVetoLightUp,"hist_BDT_output_t2bw050_R5BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name24BVetoLightDown,"hist_BDT_output_t2bw050_R5BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title24BVetoLightDown,"hist_BDT_output_t2bw050_R5BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name25BVetoBCUp,"hist_BDT_output_t2bw050_R6BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title25BVetoBCUp,"hist_BDT_output_t2bw050_R6BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name25BVetoBCDown,"hist_BDT_output_t2bw050_R6BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title25BVetoBCDown,"hist_BDT_output_t2bw050_R6BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name25BVetoLightUp,"hist_BDT_output_t2bw050_R6BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title25BVetoLightUp,"hist_BDT_output_t2bw050_R6BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name25BVetoLightDown,"hist_BDT_output_t2bw050_R6BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title25BVetoLightDown,"hist_BDT_output_t2bw050_R6BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name26BVetoBCUp,"hist_BDT_output_t2bw075_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title26BVetoBCUp,"hist_BDT_output_t2bw075_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name26BVetoBCDown,"hist_BDT_output_t2bw075_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title26BVetoBCDown,"hist_BDT_output_t2bw075_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name26BVetoLightUp,"hist_BDT_output_t2bw075_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title26BVetoLightUp,"hist_BDT_output_t2bw075_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name26BVetoLightDown,"hist_BDT_output_t2bw075_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title26BVetoLightDown,"hist_BDT_output_t2bw075_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name27BVetoBCUp,"hist_BDT_output_t2bw075_R2BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title27BVetoBCUp,"hist_BDT_output_t2bw075_R2BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name27BVetoBCDown,"hist_BDT_output_t2bw075_R2BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title27BVetoBCDown,"hist_BDT_output_t2bw075_R2BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name27BVetoLightUp,"hist_BDT_output_t2bw075_R2BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title27BVetoLightUp,"hist_BDT_output_t2bw075_R2BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name27BVetoLightDown,"hist_BDT_output_t2bw075_R2BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title27BVetoLightDown,"hist_BDT_output_t2bw075_R2BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));


   sprintf(name28BVetoBCUp,"hist_BDT_output_t2bw075_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title28BVetoBCUp,"hist_BDT_output_t2bw075_R3BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name28BVetoBCDown,"hist_BDT_output_t2bw075_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title28BVetoBCDown,"hist_BDT_output_t2bw075_R3BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name28BVetoLightUp,"hist_BDT_output_t2bw075_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title28BVetoLightUp,"hist_BDT_output_t2bw075_R3BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name28BVetoLightDown,"hist_BDT_output_t2bw075_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title28BVetoLightDown,"hist_BDT_output_t2bw075_R3BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name29BVetoBCUp,"hist_BDT_output_t2bw075_R5BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title29BVetoBCUp,"hist_BDT_output_t2bw075_R5BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name29BVetoBCDown,"hist_BDT_output_t2bw075_R5BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title29BVetoBCDown,"hist_BDT_output_t2bw075_R5BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name29BVetoLightUp,"hist_BDT_output_t2bw075_R5BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title29BVetoLightUp,"hist_BDT_output_t2bw075_R5BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name29BVetoLightDown,"hist_BDT_output_t2bw075_R5BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title29BVetoLightDown,"hist_BDT_output_t2bw075_R5BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));



   sprintf(name30BVetoBCUp,"hist_BDT_output_t2tt_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title30BVetoBCUp,"hist_BDT_output_t2tt_R1BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name30BVetoBCDown,"hist_BDT_output_t2tt_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title30BVetoBCDown,"hist_BDT_output_t2tt_R1BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name30BVetoLightUp,"hist_BDT_output_t2tt_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title30BVetoLightUp,"hist_BDT_output_t2tt_R1BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name30BVetoLightDown,"hist_BDT_output_t2tt_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title30BVetoLightDown,"hist_BDT_output_t2tt_R1BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name31BVetoBCUp,"hist_BDT_output_t2tt_R2BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title31BVetoBCUp,"hist_BDT_output_t2tt_R2BVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name31BVetoBCDown,"hist_BDT_output_t2tt_R2BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title31BVetoBCDown,"hist_BDT_output_t2tt_R2BVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name31BVetoLightUp,"hist_BDT_output_t2tt_R2BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title31BVetoLightUp,"hist_BDT_output_t2tt_R2BVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name31BVetoLightDown,"hist_BDT_output_t2tt_R2BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title31BVetoLightDown,"hist_BDT_output_t2tt_R2BVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_looseBVetoBCUp,"hist_BDT_output_t2tt_R5_looseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_looseBVetoBCUp,"hist_BDT_output_t2tt_R5_looseBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_looseBVetoBCDown,"hist_BDT_output_t2tt_R5_looseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_looseBVetoBCDown,"hist_BDT_output_t2tt_R5_looseBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_looseBVetoLightUp,"hist_BDT_output_t2tt_R5_looseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_looseBVetoLightUp,"hist_BDT_output_t2tt_R5_looseBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_looseBVetoLightDown,"hist_BDT_output_t2tt_R5_looseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_looseBVetoLightDown,"hist_BDT_output_t2tt_R5_looseBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_tightBVetoBCUp,"hist_BDT_output_t2tt_R5_tightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_tightBVetoBCUp,"hist_BDT_output_t2tt_R5_tightBVetoBCUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_tightBVetoBCDown,"hist_BDT_output_t2tt_R5_tightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_tightBVetoBCDown,"hist_BDT_output_t2tt_R5_tightBVetoBCDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_tightBVetoLightUp,"hist_BDT_output_t2tt_R5_tightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_tightBVetoLightUp,"hist_BDT_output_t2tt_R5_tightBVetoLightUp_S%i_N%i", atoi(argv[3]), atoi(argv[4]));

   sprintf(name32_tightBVetoLightDown,"hist_BDT_output_t2tt_R5_tightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));
   sprintf(title32_tightBVetoLightDown,"hist_BDT_output_t2tt_R5_tightBVetoLightDown_S%i_N%i", atoi(argv[3]), atoi(argv[4]));





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


   Events_T2tt_offShellLooseBVetoBCUp 				= new TH1D(name1BVetoBCUp,title1BVetoBCUp,50,0,1000) ; 
   Events_T2tt_offShellLooseBVetoBCDown 			= new TH1D(name1BVetoBCDown,title1BVetoBCDown,50,0,1000) ; 
   Events_T2tt_offShellLooseBVetoLightUp 			= new TH1D(name1BVetoLightUp,title1BVetoLightUp,50,0,1000) ; 
   Events_T2tt_offShellLooseBVetoLightDown 			= new TH1D(name1BVetoLightDown,title1BVetoLightDown,50,0,1000) ; 

   Events_T2tt_offShellTightBVetoBCUp 	    			= new TH1D(name2BVetoBCUp,title2BVetoBCUp,50,0,1000) ;           	
   Events_T2tt_offShellTightBVetoBCDown     	                = new TH1D(name2BVetoBCDown,title2BVetoBCDown,50,0,1000) ; 
   Events_T2tt_offShellTightBVetoLightUp    	                = new TH1D(name2BVetoLightUp,title2BVetoLightUp,50,0,1000) ; 
   Events_T2tt_offShellTightBVetoLightDown  	                = new TH1D(name2BVetoLightDown,title2BVetoLightDown,50,0,1000) ; 

   Events_T2tt_lowDeltaMBVetoBCUp 	    			= new TH1D(name3BVetoBCUp,title3BVetoBCUp,50,0,1000) ;           	
   Events_T2tt_lowDeltaMBVetoBCDown     	                = new TH1D(name3BVetoBCDown,title3BVetoBCDown,50,0,1000) ; 
   Events_T2tt_lowDeltaMBVetoLightUp    	                = new TH1D(name3BVetoLightUp,title3BVetoLightUp,50,0,1000) ; 
   Events_T2tt_lowDeltaMBVetoLightDown  	                = new TH1D(name3BVetoLightDown,title3BVetoLightDown,50,0,1000) ; 

   Events_T2tt_mediumDeltaMBVetoBCUp 	    			= new TH1D(name4BVetoBCUp,title4BVetoBCUp,50,0,1000) ;           	
   Events_T2tt_mediumDeltaMBVetoBCDown     	                = new TH1D(name4BVetoBCDown,title4BVetoBCDown,50,0,1000) ; 
   Events_T2tt_mediumDeltaMBVetoLightUp    	                = new TH1D(name4BVetoLightUp,title4BVetoLightUp,50,0,1000) ; 
   Events_T2tt_mediumDeltaMBVetoLightDown  	                = new TH1D(name4BVetoLightDown,title4BVetoLightDown,50,0,1000) ; 

   Events_T2tt_highDeltaMBVetoBCUp 	    			= new TH1D(name5BVetoBCUp,title5BVetoBCUp,50,0,1000) ;           	
   Events_T2tt_highDeltaMBVetoBCDown     	                = new TH1D(name5BVetoBCDown,title5BVetoBCDown,50,0,1000) ; 
   Events_T2tt_highDeltaMBVetoLightUp    	                = new TH1D(name5BVetoLightUp,title5BVetoLightUp,50,0,1000) ; 
   Events_T2tt_highDeltaMBVetoLightDown  	                = new TH1D(name5BVetoLightDown,title5BVetoLightDown,50,0,1000) ; 

   Events_T2bw025_veryOffShell_looseBVetoBCUp 	   		 = new TH1D(name6BVetoBCUp,title6BVetoBCUp,50,0,1000) ;           	
   Events_T2bw025_veryOffShell_looseBVetoBCDown                 = new TH1D(name6BVetoBCDown,title6BVetoBCDown,50,0,1000) ; 
   Events_T2bw025_veryOffShell_looseBVetoLightUp                = new TH1D(name6BVetoLightUp,title6BVetoLightUp,50,0,1000) ; 
   Events_T2bw025_veryOffShell_looseBVetoLightDown              = new TH1D(name6BVetoLightDown,title6BVetoLightDown,50,0,1000) ; 

   Events_T2bw025_offShell_looseBVetoBCUp 	   		= new TH1D(name7BVetoBCUp,title7BVetoBCUp,50,0,1000) ;           			 
   Events_T2bw025_offShell_looseBVetoBCDown                    = new TH1D(name7BVetoBCDown,title7BVetoBCDown,50,0,1000) ; 
   Events_T2bw025_offShell_looseBVetoLightUp                   = new TH1D(name7BVetoLightUp,title7BVetoLightUp,50,0,1000) ; 
   Events_T2bw025_offShell_looseBVetoLightDown                 = new TH1D(name7BVetoLightDown,title7BVetoLightDown,50,0,1000) ; 

   Events_T2bw025_lowDeltaM_tightBVetoBCUp 	   		 = new TH1D(name8BVetoBCUp,title8BVetoBCUp,50,0,1000) ;           	
   Events_T2bw025_lowDeltaM_tightBVetoBCDown                    = new TH1D(name8BVetoBCDown,title8BVetoBCDown,50,0,1000) ; 
   Events_T2bw025_lowDeltaM_tightBVetoLightUp                   = new TH1D(name8BVetoLightUp,title8BVetoLightUp,50,0,1000) ; 
   Events_T2bw025_lowDeltaM_tightBVetoLightDown                 = new TH1D(name8BVetoLightDown,title8BVetoLightDown,50,0,1000) ; 

   Events_T2bw025_highDeltaMBVetoBCUp 	   			= new TH1D(name9BVetoBCUp,title9BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw025_highDeltaMBVetoBCDown                        = new TH1D(name9BVetoBCDown,title9BVetoBCDown,50,0,1000) ; 
   Events_T2bw025_highDeltaMBVetoLightUp                       = new TH1D(name9BVetoLightUp,title9BVetoLightUp,50,0,1000) ; 
   Events_T2bw025_highDeltaMBVetoLightDown                     = new TH1D(name9BVetoLightDown,title9BVetoLightDown,50,0,1000) ; 

   Events_T2bw050_offShell_looseBVetoBCUp 	   		= new TH1D(name10BVetoBCUp,title10BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw050_offShell_looseBVetoBCDown                    = new TH1D(name10BVetoBCDown,title10BVetoBCDown,50,0,1000) ; 
   Events_T2bw050_offShell_looseBVetoLightUp                   = new TH1D(name10BVetoLightUp,title10BVetoLightUp,50,0,1000) ; 
   Events_T2bw050_offShell_looseBVetoLightDown                 = new TH1D(name10BVetoLightDown,title10BVetoLightDown,50,0,1000) ; 

   Events_T2bw050_lowMassBVetoBCUp 	   			= new TH1D(name11BVetoBCUp,title11BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw050_lowMassBVetoBCDown                           = new TH1D(name11BVetoBCDown,title11BVetoBCDown,50,0,1000) ; 
   Events_T2bw050_lowMassBVetoLightUp                          = new TH1D(name11BVetoLightUp,title11BVetoLightUp,50,0,1000) ; 
   Events_T2bw050_lowMassBVetoLightDown                        = new TH1D(name11BVetoLightDown,title11BVetoLightDown,50,0,1000) ; 

   Events_T2bw050_mediumDeltaM_looseBVetoBCUp 	   		= new TH1D(name12BVetoBCUp,title12BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw050_mediumDeltaM_looseBVetoBCDown                = new TH1D(name12BVetoBCDown,title12BVetoBCDown,50,0,1000) ; 
   Events_T2bw050_mediumDeltaM_looseBVetoLightUp               = new TH1D(name12BVetoLightUp,title12BVetoLightUp,50,0,1000) ; 
   Events_T2bw050_mediumDeltaM_looseBVetoLightDown             = new TH1D(name12BVetoLightDown,title12BVetoLightDown,50,0,1000) ; 

   Events_T2bw050_highDeltaMBVetoBCUp 	   			= new TH1D(name13BVetoBCUp,title13BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw050_highDeltaMBVetoBCDown                        = new TH1D(name13BVetoBCDown,title13BVetoBCDown,50,0,1000) ; 
   Events_T2bw050_highDeltaMBVetoLightUp                       = new TH1D(name13BVetoLightUp,title13BVetoLightUp,50,0,1000) ; 
   Events_T2bw050_highDeltaMBVetoLightDown                     = new TH1D(name13BVetoLightDown,title13BVetoLightDown,50,0,1000) ; 


   Events_T2bw075_lowDeltaM_tightBVetoBCUp 	   		= new TH1D(name14BVetoBCUp,title14BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw075_lowDeltaM_tightBVetoBCDown                   = new TH1D(name14BVetoBCDown,title14BVetoBCDown,50,0,1000) ; 
   Events_T2bw075_lowDeltaM_tightBVetoLightUp                  = new TH1D(name14BVetoLightUp,title14BVetoLightUp,50,0,1000) ; 
   Events_T2bw075_lowDeltaM_tightBVetoLightDown                = new TH1D(name14BVetoLightDown,title14BVetoLightDown,50,0,1000) ; 

   Events_T2bw075_mediumDeltaMBVetoBCUp    			= new TH1D(name15BVetoBCUp,title15BVetoBCUp,50,0,1000) ;           	
   Events_T2bw075_mediumDeltaMBVetoBCDown                      = new TH1D(name15BVetoBCDown,title15BVetoBCDown,50,0,1000) ; 
   Events_T2bw075_mediumDeltaMBVetoLightUp                     = new TH1D(name15BVetoLightUp,title15BVetoLightUp,50,0,1000) ; 
   Events_T2bw075_mediumDeltaMBVetoLightDown                   = new TH1D(name15BVetoLightDown,title15BVetoLightDown,50,0,1000) ; 

   Events_T2bw075_highDeltaMBVetoBCUp 	   			= new TH1D(name16BVetoBCUp,title16BVetoBCUp,50,0,1000) ;           	 
   Events_T2bw075_highDeltaMBVetoBCDown                        = new TH1D(name16BVetoBCDown,title16BVetoBCDown,50,0,1000) ; 
   Events_T2bw075_highDeltaMBVetoLightUp                       = new TH1D(name16BVetoLightUp,title16BVetoLightUp,50,0,1000) ; 
   Events_T2bw075_highDeltaMBVetoLightDown                     = new TH1D(name16BVetoLightDown,title16BVetoLightDown,50,0,1000) ; 



   	
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

   // BVETO SYST
   
   hist_BDT_output_t2bw025_R1BVetoBCUp = new TH1D(name17BVetoBCUp,title17BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoBCDown = new TH1D(name17BVetoBCDown,title17BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoLightUp = new TH1D(name17BVetoLightUp,title17BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R1BVetoLightDown = new TH1D(name17BVetoLightDown,title17BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R3BVetoBCUp = new TH1D(name18BVetoBCUp,title18BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoBCDown = new TH1D(name18BVetoBCDown,title18BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoLightUp = new TH1D(name18BVetoLightUp,title18BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R3BVetoLightDown = new TH1D(name18BVetoLightDown,title18BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R4BVetoBCUp = new TH1D(name19BVetoBCUp,title19BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoBCDown = new TH1D(name19BVetoBCDown,title19BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoLightUp = new TH1D(name19BVetoLightUp,title19BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R4BVetoLightDown = new TH1D(name19BVetoLightDown,title19BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw025_R6BVetoBCUp = new TH1D(name20BVetoBCUp,title20BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoBCDown = new TH1D(name20BVetoBCDown,title20BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoLightUp = new TH1D(name20BVetoLightUp,title20BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw025_R6BVetoLightDown = new TH1D(name20BVetoLightDown,title20BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R1_looseBVetoBCUp = new TH1D(name21_looseBVetoBCUp,title21_looseBVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R1_looseBVetoBCDown = new TH1D(name21_looseBVetoBCDown,title21_looseBVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R1_looseBVetoLightUp = new TH1D(name21_looseBVetoLightUp,title21_looseBVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R1_looseBVetoLightDown = new TH1D(name21_looseBVetoLightDown,title21_looseBVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R1_tightBVetoBCUp = new TH1D(name21_tightBVetoBCUp,title21_tightBVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R1_tightBVetoBCDown = new TH1D(name21_tightBVetoBCDown,title21_tightBVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R1_tightBVetoLightUp = new TH1D(name21_tightBVetoLightUp,title21_tightBVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R1_tightBVetoLightDown = new TH1D(name21_tightBVetoLightDown,title21_tightBVetoLightDown,100,-2,2);


   hist_BDT_output_t2bw050_R3BVetoBCUp = new TH1D(name22BVetoBCUp,title22BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoBCDown = new TH1D(name22BVetoBCDown,title22BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoLightUp = new TH1D(name22BVetoLightUp,title22BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R3BVetoLightDown = new TH1D(name22BVetoLightDown,title22BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R4BVetoBCUp = new TH1D(name23BVetoBCUp,title23BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoBCDown = new TH1D(name23BVetoBCDown,title23BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoLightUp = new TH1D(name23BVetoLightUp,title23BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R4BVetoLightDown = new TH1D(name23BVetoLightDown,title23BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R5BVetoBCUp = new TH1D(name24BVetoBCUp,title24BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoBCDown = new TH1D(name24BVetoBCDown,title24BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoLightUp = new TH1D(name24BVetoLightUp,title24BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R5BVetoLightDown = new TH1D(name24BVetoLightDown,title24BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw050_R6BVetoBCUp = new TH1D(name25BVetoBCUp,title25BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoBCDown = new TH1D(name25BVetoBCDown,title25BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoLightUp = new TH1D(name25BVetoLightUp,title25BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw050_R6BVetoLightDown = new TH1D(name25BVetoLightDown,title25BVetoLightDown,100,-2,2);


   hist_BDT_output_t2bw075_R1BVetoBCUp = new TH1D(name26BVetoBCUp,title26BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoBCDown = new TH1D(name26BVetoBCDown,title26BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoLightUp = new TH1D(name26BVetoLightUp,title26BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R1BVetoLightDown = new TH1D(name26BVetoLightDown,title26BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R2BVetoBCUp = new TH1D(name27BVetoBCUp,title27BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoBCDown = new TH1D(name27BVetoBCDown,title27BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoLightUp = new TH1D(name27BVetoLightUp,title27BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R2BVetoLightDown = new TH1D(name27BVetoLightDown,title27BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R3BVetoBCUp = new TH1D(name28BVetoBCUp,title28BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoBCDown = new TH1D(name28BVetoBCDown,title28BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoLightUp = new TH1D(name28BVetoLightUp,title28BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R3BVetoLightDown = new TH1D(name28BVetoLightDown,title28BVetoLightDown,100,-2,2);

   hist_BDT_output_t2bw075_R5BVetoBCUp = new TH1D(name29BVetoBCUp,title29BVetoBCUp,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoBCDown = new TH1D(name29BVetoBCDown,title29BVetoBCDown,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoLightUp = new TH1D(name29BVetoLightUp,title29BVetoLightUp,100,-2,2);
   hist_BDT_output_t2bw075_R5BVetoLightDown = new TH1D(name29BVetoLightDown,title29BVetoLightDown,100,-2,2);


   hist_BDT_output_t2tt_R1BVetoBCUp = new TH1D(name30BVetoBCUp,title30BVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoBCDown = new TH1D(name30BVetoBCDown,title30BVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoLightUp = new TH1D(name30BVetoLightUp,title30BVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R1BVetoLightDown = new TH1D(name30BVetoLightDown,title30BVetoLightDown,100,-2,2);


   hist_BDT_output_t2tt_R2BVetoBCUp = new TH1D(name31BVetoBCUp,title31BVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoBCDown = new TH1D(name31BVetoBCDown,title31BVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoLightUp = new TH1D(name31BVetoLightUp,title31BVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R2BVetoLightDown = new TH1D(name31BVetoLightDown,title31BVetoLightDown,100,-2,2);

   hist_BDT_output_t2tt_R5_looseBVetoBCUp = new TH1D(name32_looseBVetoBCUp,title32_looseBVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R5_looseBVetoBCDown = new TH1D(name32_looseBVetoBCDown,title32_looseBVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R5_looseBVetoLightUp = new TH1D(name32_looseBVetoLightUp,title32_looseBVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R5_looseBVetoLightDown = new TH1D(name32_looseBVetoLightDown,title32_looseBVetoLightDown,100,-2,2);

   hist_BDT_output_t2tt_R5_tightBVetoBCUp = new TH1D(name32_tightBVetoBCUp,title32_tightBVetoBCUp,100,-2,2);
   hist_BDT_output_t2tt_R5_tightBVetoBCDown = new TH1D(name32_tightBVetoBCDown,title32_tightBVetoBCDown,100,-2,2);
   hist_BDT_output_t2tt_R5_tightBVetoLightUp = new TH1D(name32_tightBVetoLightUp,title32_tightBVetoLightUp,100,-2,2);
   hist_BDT_output_t2tt_R5_tightBVetoLightDown = new TH1D(name32_tightBVetoLightDown,title32_tightBVetoLightDown,100,-2,2);

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


   int counter1BVetoBCUp = 0; 
   int counter1BVetoBCDown = 0; 
   int counter1BVetoLightUp = 0; 
   int counter1BVetoLightDown = 0; 

   int counter2BVetoBCUp = 0; 
   int counter2BVetoBCDown = 0; 
   int counter2BVetoLightUp = 0; 
   int counter2BVetoLightDown = 0; 

   int counter3BVetoBCUp = 0; 
   int counter3BVetoBCDown = 0; 
   int counter3BVetoLightUp = 0; 
   int counter3BVetoLightDown = 0; 

   int counter4BVetoBCUp = 0; 
   int counter4BVetoBCDown = 0; 
   int counter4BVetoLightUp = 0; 
   int counter4BVetoLightDown = 0; 

   int counter5BVetoBCUp = 0; 
   int counter5BVetoBCDown = 0; 
   int counter5BVetoLightUp = 0; 
   int counter5BVetoLightDown = 0; 

   int counter6BVetoBCUp = 0; 
   int counter6BVetoBCDown = 0; 
   int counter6BVetoLightUp = 0; 
   int counter6BVetoLightDown = 0; 

   int counter7BVetoBCUp = 0; 
   int counter7BVetoBCDown = 0; 
   int counter7BVetoLightUp = 0; 
   int counter7BVetoLightDown = 0; 

   int counter8BVetoBCUp = 0; 
   int counter8BVetoBCDown = 0; 
   int counter8BVetoLightUp = 0; 
   int counter8BVetoLightDown = 0; 

   int counter9BVetoBCUp = 0; 
   int counter9BVetoBCDown = 0; 
   int counter9BVetoLightUp = 0; 
   int counter9BVetoLightDown = 0; 

   int counter10BVetoBCUp = 0; 
   int counter10BVetoBCDown = 0; 
   int counter10BVetoLightUp = 0; 
   int counter10BVetoLightDown = 0; 

   int counter11BVetoBCUp = 0; 
   int counter11BVetoBCDown = 0; 
   int counter11BVetoLightUp = 0; 
   int counter11BVetoLightDown = 0; 

   int counter12BVetoBCUp = 0; 
   int counter12BVetoBCDown = 0; 
   int counter12BVetoLightUp = 0; 
   int counter12BVetoLightDown = 0; 

   int counter13BVetoBCUp = 0; 
   int counter13BVetoBCDown = 0; 
   int counter13BVetoLightUp = 0; 
   int counter13BVetoLightDown = 0; 

   int counter14BVetoBCUp = 0; 
   int counter14BVetoBCDown = 0; 
   int counter14BVetoLightUp = 0; 
   int counter14BVetoLightDown = 0; 

   int counter15BVetoBCUp = 0; 
   int counter15BVetoBCDown = 0; 
   int counter15BVetoLightUp = 0; 
   int counter15BVetoLightDown = 0; 

   int counter16BVetoBCUp = 0; 
   int counter16BVetoBCDown = 0; 
   int counter16BVetoLightUp = 0; 
   int counter16BVetoLightDown = 0; 



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



			if ( (sampleType == "signal")  &&  !((myEvent.mStop ==  atoi(argv[3]) ) && (myEvent.mNeutralino ==  atoi(argv[4]) )) )continue;


			if (goesInPreselectionMTtail() == true) {
			
		

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



				if (goesInPreselectionMTtailNoBeto() == true) {

				int nBJetsUpBC = 0;
				int nBJetsDownBC = 0;
				int nBJetsUpLight = 0;
				int nBJetsDownLight = 0;
	
				for (unsigned i=0; i < myEvent.jets_CSV_reshapedUpBC.size(); i++) {
					     if (myEvent.jets_CSV_reshapedUpBC[i] > 0.679 ) 

						nBJetsUpBC++;			 
				}	

				for (unsigned i=0; i < myEvent.jets_CSV_reshapedDownBC.size(); i++) {
					     if (myEvent.jets_CSV_reshapedDownBC[i] > 0.679 ) 

						nBJetsDownBC++;			 
				}	


				for (unsigned i=0; i < myEvent.jets_CSV_reshapedUpLight.size(); i++) {
					     if (myEvent.jets_CSV_reshapedUpLight[i] > 0.679 ) 

						nBJetsUpLight++;			 
				}	


				for (unsigned i=0; i < myEvent.jets_CSV_reshapedDownLight.size(); i++) {
					     if (myEvent.jets_CSV_reshapedDownLight[i] > 0.679 ) 

						nBJetsDownLight++;			 
				}	


					/*	cout << "1: "<< nBJetsUpBC << endl;
						cout << "2: " << nBJetsDownBC << endl;
						cout << "3: " << nBJetsUpLight << endl;
						cout << "4: " << nBJetsDownLight << endl;
					*/


				if ( cutAndCount_T2tt_offShellLoose(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter1BVetoBCUp ++;
						Events_T2tt_offShellLooseBVetoBCUp->Fill(counter1BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter1BVetoBCDown ++;
						Events_T2tt_offShellLooseBVetoBCDown->Fill(counter1BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter1BVetoLightUp ++;
						Events_T2tt_offShellLooseBVetoLightUp->Fill(counter1BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter1BVetoLightDown ++;
						Events_T2tt_offShellLooseBVetoLightDown->Fill(counter1BVetoLightDown, getWeight());
					}

			  	}



				if ( cutAndCount_T2tt_offShellTight(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter2BVetoBCUp ++;
						Events_T2tt_offShellTightBVetoBCUp->Fill(counter2BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter2BVetoBCDown ++;
						Events_T2tt_offShellTightBVetoBCDown->Fill(counter2BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter2BVetoLightUp ++;
						Events_T2tt_offShellTightBVetoLightUp->Fill(counter2BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter2BVetoLightDown ++;
						Events_T2tt_offShellTightBVetoLightDown->Fill(counter2BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2tt_lowDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter3BVetoBCUp ++;
						Events_T2tt_lowDeltaMBVetoBCUp->Fill(counter3BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter3BVetoBCDown ++;
						Events_T2tt_lowDeltaMBVetoBCDown->Fill(counter3BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter3BVetoLightUp ++;
						Events_T2tt_lowDeltaMBVetoLightUp->Fill(counter3BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter3BVetoLightDown ++;
						Events_T2tt_lowDeltaMBVetoLightDown->Fill(counter3BVetoLightDown, getWeight());
					}

			  	}



				if ( cutAndCount_T2tt_mediumDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter4BVetoBCUp ++;
						Events_T2tt_mediumDeltaMBVetoBCUp->Fill(counter4BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter4BVetoBCDown ++;
						Events_T2tt_mediumDeltaMBVetoBCDown->Fill(counter4BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter4BVetoLightUp ++;
						Events_T2tt_mediumDeltaMBVetoLightUp->Fill(counter4BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter4BVetoLightDown ++;
						Events_T2tt_mediumDeltaMBVetoLightDown->Fill(counter4BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2tt_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter5BVetoBCUp ++;
						Events_T2tt_highDeltaMBVetoBCUp->Fill(counter5BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter5BVetoBCDown ++;
						Events_T2tt_highDeltaMBVetoBCDown->Fill(counter5BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter5BVetoLightUp ++;
						Events_T2tt_highDeltaMBVetoLightUp->Fill(counter5BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter5BVetoLightDown ++;
						Events_T2tt_highDeltaMBVetoLightDown->Fill(counter5BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw025_veryOffShell_loose(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter6BVetoBCUp ++;
						Events_T2bw025_veryOffShell_looseBVetoBCUp->Fill(counter6BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter6BVetoBCDown ++;
						Events_T2bw025_veryOffShell_looseBVetoBCDown->Fill(counter6BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter6BVetoLightUp ++;
						Events_T2bw025_veryOffShell_looseBVetoLightUp->Fill(counter6BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter6BVetoLightDown ++;
						Events_T2bw025_veryOffShell_looseBVetoLightDown->Fill(counter6BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw025_offShell_loose(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter7BVetoBCUp ++;
						Events_T2bw025_offShell_looseBVetoBCUp->Fill(counter7BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter7BVetoBCDown ++;
						Events_T2bw025_offShell_looseBVetoBCDown->Fill(counter7BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter7BVetoLightUp ++;
						Events_T2bw025_offShell_looseBVetoLightUp->Fill(counter7BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter7BVetoLightDown ++;
						Events_T2bw025_offShell_looseBVetoLightDown->Fill(counter7BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw025_lowDeltaM_tight(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter8BVetoBCUp ++;
						Events_T2bw025_lowDeltaM_tightBVetoBCUp->Fill(counter8BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter8BVetoBCDown ++;
						Events_T2bw025_lowDeltaM_tightBVetoBCDown->Fill(counter8BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter8BVetoLightUp ++;
						Events_T2bw025_lowDeltaM_tightBVetoLightUp->Fill(counter8BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter8BVetoLightDown ++;
						Events_T2bw025_lowDeltaM_tightBVetoLightDown->Fill(counter8BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw025_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter9BVetoBCUp ++;
						Events_T2bw025_highDeltaMBVetoBCUp->Fill(counter9BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter9BVetoBCDown ++;
						Events_T2bw025_highDeltaMBVetoBCDown->Fill(counter9BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter9BVetoLightUp ++;
						Events_T2bw025_highDeltaMBVetoLightUp->Fill(counter9BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter9BVetoLightDown ++;
						Events_T2bw025_highDeltaMBVetoLightDown->Fill(counter9BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_offShell_loose(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter10BVetoBCUp ++;
						Events_T2bw050_offShell_looseBVetoBCUp->Fill(counter10BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter10BVetoBCDown ++;
						Events_T2bw050_offShell_looseBVetoBCDown->Fill(counter10BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter10BVetoLightUp ++;
						Events_T2bw050_offShell_looseBVetoLightUp->Fill(counter10BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter10BVetoLightDown ++;
						Events_T2bw050_offShell_looseBVetoLightDown->Fill(counter10BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw050_lowMass(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter11BVetoBCUp ++;
						Events_T2bw050_lowMassBVetoBCUp->Fill(counter11BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter11BVetoBCDown ++;
						Events_T2bw050_lowMassBVetoBCDown->Fill(counter11BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter11BVetoLightUp ++;
						Events_T2bw050_lowMassBVetoLightUp->Fill(counter11BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter11BVetoLightDown ++;
						Events_T2bw050_lowMassBVetoLightDown->Fill(counter11BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_mediumDeltaM_loose(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter12BVetoBCUp ++;
						Events_T2bw050_mediumDeltaM_looseBVetoBCUp->Fill(counter12BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter12BVetoBCDown ++;
						Events_T2bw050_mediumDeltaM_looseBVetoBCDown->Fill(counter12BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter12BVetoLightUp ++;
						Events_T2bw050_mediumDeltaM_looseBVetoLightUp->Fill(counter12BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter12BVetoLightDown ++;
						Events_T2bw050_mediumDeltaM_looseBVetoLightDown->Fill(counter12BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw050_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter13BVetoBCUp ++;
						Events_T2bw050_highDeltaMBVetoBCUp->Fill(counter13BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter13BVetoBCDown ++;
						Events_T2bw050_highDeltaMBVetoBCDown->Fill(counter13BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter13BVetoLightUp ++;
						Events_T2bw050_highDeltaMBVetoLightUp->Fill(counter13BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter13BVetoLightDown ++;
						Events_T2bw050_highDeltaMBVetoLightDown->Fill(counter13BVetoLightDown, getWeight());
					}

			  	}

				if ( cutAndCount_T2bw075_lowDeltaM_tight(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter14BVetoBCUp ++;
						Events_T2bw075_lowDeltaM_tightBVetoBCUp->Fill(counter14BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter14BVetoBCDown ++;
						Events_T2bw075_lowDeltaM_tightBVetoBCDown->Fill(counter14BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter14BVetoLightUp ++;
						Events_T2bw075_lowDeltaM_tightBVetoLightUp->Fill(counter14BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter14BVetoLightDown ++;
						Events_T2bw075_lowDeltaM_tightBVetoLightDown->Fill(counter14BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw075_mediumDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter15BVetoBCUp ++;
						Events_T2bw075_mediumDeltaMBVetoBCUp->Fill(counter15BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter15BVetoBCDown ++;
						Events_T2bw075_mediumDeltaMBVetoBCDown->Fill(counter15BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter15BVetoLightUp ++;
						Events_T2bw075_mediumDeltaMBVetoLightUp->Fill(counter15BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter15BVetoLightDown ++;
						Events_T2bw075_mediumDeltaMBVetoLightDown->Fill(counter15BVetoLightDown, getWeight());
					}

			  	}


				if ( cutAndCount_T2bw075_highDeltaM(true) == true){ 

					if (nBJetsUpBC > 0 ) {
						counter16BVetoBCUp ++;
						Events_T2bw075_highDeltaMBVetoBCUp->Fill(counter16BVetoBCUp, getWeight());
					}


					if (nBJetsDownBC > 0 ) {
						counter16BVetoBCDown ++;
						Events_T2bw075_highDeltaMBVetoBCDown->Fill(counter16BVetoBCDown, getWeight());
					}


					if (nBJetsUpLight > 0 ) {
						counter16BVetoLightUp ++;
						Events_T2bw075_highDeltaMBVetoLightUp->Fill(counter16BVetoLightUp, getWeight());
					}


					if (nBJetsDownLight > 0 ) {
						counter16BVetoLightDown ++;
						Events_T2bw075_highDeltaMBVetoLightDown->Fill(counter16BVetoLightDown, getWeight());
					}

			  	}






				if (myEvent.isUsedInBDT == 1) continue;
				double weight = getWeight() * 2.; 



				if (nBJetsUpBC > 0 ) {
	                        hist_BDT_output_t2bw025_R1BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R1, weight);
				hist_BDT_output_t2bw025_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
				hist_BDT_output_t2bw025_R4BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
				hist_BDT_output_t2bw025_R6BVetoBCUp->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


				hist_BDT_output_t2bw050_R1_tightBVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R1_looseBVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
				hist_BDT_output_t2bw050_R4BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
				hist_BDT_output_t2bw050_R5BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
				hist_BDT_output_t2bw050_R6BVetoBCUp->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

				hist_BDT_output_t2bw075_R1BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
				hist_BDT_output_t2bw075_R2BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
				hist_BDT_output_t2bw075_R3BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
				hist_BDT_output_t2bw075_R5BVetoBCUp->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

				hist_BDT_output_t2tt_R1BVetoBCUp->Fill(myEvent.BDT_output_t2tt_R1, weight);		
				hist_BDT_output_t2tt_R2BVetoBCUp->Fill(myEvent.BDT_output_t2tt_R2, weight);		
				hist_BDT_output_t2tt_R5_looseBVetoBCUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		
				hist_BDT_output_t2tt_R5_tightBVetoBCUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		

				}

				if (nBJetsDownBC > 0 ) {
	                        hist_BDT_output_t2bw025_R1BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R1, weight);
				hist_BDT_output_t2bw025_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
				hist_BDT_output_t2bw025_R4BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
				hist_BDT_output_t2bw025_R6BVetoBCDown->Fill(myEvent.BDT_output_t2bw025_R6, weight);		

				hist_BDT_output_t2bw050_R1_tightBVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R1_looseBVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
				hist_BDT_output_t2bw050_R4BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
				hist_BDT_output_t2bw050_R5BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
				hist_BDT_output_t2bw050_R6BVetoBCDown->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

				hist_BDT_output_t2bw075_R1BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
				hist_BDT_output_t2bw075_R2BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
				hist_BDT_output_t2bw075_R3BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
				hist_BDT_output_t2bw075_R5BVetoBCDown->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

				hist_BDT_output_t2tt_R1BVetoBCDown->Fill(myEvent.BDT_output_t2tt_R1, weight);		
				hist_BDT_output_t2tt_R2BVetoBCDown->Fill(myEvent.BDT_output_t2tt_R2, weight);		
				hist_BDT_output_t2tt_R5_looseBVetoBCDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		
				hist_BDT_output_t2tt_R5_tightBVetoBCDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		

				}

				if (nBJetsUpLight > 0 ) {
	                        hist_BDT_output_t2bw025_R1BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R1, weight);
				hist_BDT_output_t2bw025_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
				hist_BDT_output_t2bw025_R4BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
				hist_BDT_output_t2bw025_R6BVetoLightUp->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


				hist_BDT_output_t2bw050_R1_tightBVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R1_looseBVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
				hist_BDT_output_t2bw050_R4BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
				hist_BDT_output_t2bw050_R5BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
				hist_BDT_output_t2bw050_R6BVetoLightUp->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

				hist_BDT_output_t2bw075_R1BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
				hist_BDT_output_t2bw075_R2BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
				hist_BDT_output_t2bw075_R3BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
				hist_BDT_output_t2bw075_R5BVetoLightUp->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

				hist_BDT_output_t2tt_R1BVetoLightUp->Fill(myEvent.BDT_output_t2tt_R1, weight);		
				hist_BDT_output_t2tt_R2BVetoLightUp->Fill(myEvent.BDT_output_t2tt_R2, weight);		
				hist_BDT_output_t2tt_R5_looseBVetoLightUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		
				hist_BDT_output_t2tt_R5_tightBVetoLightUp->Fill(myEvent.BDT_output_t2tt_R5, weight);		
				}

				if (nBJetsDownLight > 0 ) {
	                        hist_BDT_output_t2bw025_R1BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R1, weight);
				hist_BDT_output_t2bw025_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R3, weight);		
				hist_BDT_output_t2bw025_R4BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R4, weight);		
				hist_BDT_output_t2bw025_R6BVetoLightDown->Fill(myEvent.BDT_output_t2bw025_R6, weight);		


				hist_BDT_output_t2bw050_R1_tightBVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R1_looseBVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R1, weight);		
				hist_BDT_output_t2bw050_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R3, weight);		
				hist_BDT_output_t2bw050_R4BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R4, weight);		
				hist_BDT_output_t2bw050_R5BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R5, weight);		
				hist_BDT_output_t2bw050_R6BVetoLightDown->Fill(myEvent.BDT_output_t2bw050_R6, weight);		

				hist_BDT_output_t2bw075_R1BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R1, weight);		
				hist_BDT_output_t2bw075_R2BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R2, weight);		
				hist_BDT_output_t2bw075_R3BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R3, weight);		
				hist_BDT_output_t2bw075_R5BVetoLightDown->Fill(myEvent.BDT_output_t2bw075_R5, weight);		

				hist_BDT_output_t2tt_R1BVetoLightDown->Fill(myEvent.BDT_output_t2tt_R1, weight);		
				hist_BDT_output_t2tt_R2BVetoLightDown->Fill(myEvent.BDT_output_t2tt_R2, weight);		
				hist_BDT_output_t2tt_R5_looseBVetoLightDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		
				hist_BDT_output_t2tt_R5_tightBVetoLightDown->Fill(myEvent.BDT_output_t2tt_R5, weight);		

				}


			}			

 } 

    
      fout->cd();
      fout->Write();
      fout->Close();



      return (0);

}



