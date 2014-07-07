#ifndef _signalRegionDefinitions_h
#define _signalRegionDefinitions_h

#include "../AN-14-067/SecondLeptonInAcceptance.h"

//#define CR4_1j 
//#define CR4_2j 
//#define CR4_3j 
//#define CR4_4j 
//#define CR4_4j_50evts 
//#define CR4_4j_100evts
//#define CR4_4j_150evts

int signalregion(TString decaymode, int stopmass, int lspmass)
{

  int signalregion = 0;

  if (decaymode == "T2bw075") {


	  if (lspmass > stopmass - 200)
	    signalregion = 1;
	  if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
	    signalregion = 2;
	  if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
	    signalregion = 3;
	  if (lspmass <= stopmass - 475)
	    signalregion = 5;

  }



  else if (decaymode == "T2bw050") {

	  if (lspmass > stopmass - 250)
	    signalregion = 1;
	  if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
	    signalregion = 3;
	  if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
	    signalregion = 4;
	  if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
	    signalregion = 5;
	  if (lspmass <= stopmass - 625)
	    signalregion = 6;

  }	

  else if (decaymode == "T2bw025") {


	  if (lspmass <= 125)
	    {
	      if (lspmass > stopmass - 275)
		signalregion = 1;

	    }
	  if (lspmass > 125)
	    {
	      if (lspmass > stopmass - 225)
		signalregion = 1;
	      if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
		signalregion = 3;

	    }

	  if (lspmass <= stopmass - 275 && lspmass > stopmass - 425)
	    signalregion = 3;
	  if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
	    signalregion = 4;
	  if (lspmass <= stopmass - 600)
	    signalregion = 6;

  }


  else if (decaymode == "T2tt") {


	  if (lspmass > stopmass - 225)
	    signalregion = 1;
	  if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
	    signalregion = 2;
	  if (lspmass <= stopmass - 275)
	    signalregion = 5;

  } 

  return signalregion;

}




double signalcut(TString decaymode, int stopmass, int lspmass)
{

  double cutvalue = 0.;


   if (decaymode == "T2bw075") {


          if (lspmass > stopmass - 200)
            cutvalue = 0.225;
          if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            cutvalue = 0.275;
          if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            cutvalue = 0.350;
          if (lspmass <= stopmass - 475)
            cutvalue = 0.2;

  }



  if (decaymode == "T2bw050") {


          if (lspmass > stopmass - 250) {
		cutvalue = 0.25 ; 
		    if (lspmass < 150) cutvalue = 0.175;
		}

          if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            cutvalue = 0.3;
          if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            cutvalue = 0.250;
          if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
            cutvalue = 0.225;
          if (lspmass <= stopmass - 625)
            cutvalue = 0.2;


  }	

  if (decaymode == "T2bw025") {


          if (lspmass <= 125)
            {
              if (lspmass > stopmass - 275)
                cutvalue = 0.2;

            }
          if (lspmass > 125)
            {
              if (lspmass > stopmass - 225)
                cutvalue = 0.2;
              if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
                cutvalue = 0.3;

            }

          if (lspmass <= stopmass - 275 && lspmass > stopmass - 425)
            cutvalue = 0.3;
          if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
            cutvalue = 0.2;
          if (lspmass <= stopmass - 600)
            cutvalue = 0.175;



  }


  if (decaymode == "T2tt") {


	  if (lspmass > stopmass - 225)
	    cutvalue = 0.325;
	  if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
	    cutvalue = 0.350;
		  if (lspmass <= stopmass - 275) {

			cutvalue=0.250; if (lspmass <= stopmass - 400) cutvalue = 0.325;
		   }


 	}


  return cutvalue;
}



TString returnSetup(TString decaymode, TString BDT){

	TString setup;

	if (decaymode == "T2bw075")
	  {
	    setup = "setup_105";
	    if (BDT == "BDT1")
	      setup = "setup_8";
	    if (BDT == "BDT2")
	      setup = "setup_7";
	  }

	else if (decaymode == "T2bw050")
	  {
	    setup = "setup_105";
	    if (BDT == "BDT1")
	      setup = "setup_8";
	    if (BDT == "BDT3")
	      setup = "setup_3";
	  }

	else if (decaymode == "T2bw025")
	  {
	    setup = "setup_105";
	    if (BDT == "BDT2")
	      setup = "setup_9";
	    if (BDT == "BDT3")
	      setup = "setup_9";
	    if (BDT == "BDT4")
	      setup = "setup_9";
	    if (BDT == "BDT5")
	      setup = "setup_9";
	  }



	else if (decaymode == "T2tt")
	  {
	    setup = "setup_1";
	    if (BDT == "BDT3")
	      setup = "setup_4";
	    if (BDT == "BDT4")
	      setup = "setup_7";
	    if (BDT == "BDT5")
	      setup = "setup_5";
	  }

  return setup;

}

float BDToutput(string BDTregion)
{
    #ifdef BDT_OUTPUT_AVAILABLE
             if (BDTregion == "T2tt_1"      )    return myEvent.BDT_output_t2tt_R1;
        else if (BDTregion == "T2tt_2"      )    return myEvent.BDT_output_t2tt_R2;
        else if (BDTregion == "T2tt_5_loose")    return myEvent.BDT_output_t2tt_R5;
        else if (BDTregion == "T2tt_5_tight")    return myEvent.BDT_output_t2tt_R5;
        
        else if (BDTregion == "T2bw075_1"   )    return myEvent.BDT_output_t2bw075_R1;
        else if (BDTregion == "T2bw075_2"   )    return myEvent.BDT_output_t2bw075_R2;
        else if (BDTregion == "T2bw075_3"   )    return myEvent.BDT_output_t2bw075_R3;
        else if (BDTregion == "T2bw075_5"   )    return myEvent.BDT_output_t2bw075_R5;

        else if (BDTregion == "T2bw050_1_loose") return myEvent.BDT_output_t2bw050_R1;
        else if (BDTregion == "T2bw050_1_tight") return myEvent.BDT_output_t2bw050_R1;
        else if (BDTregion == "T2bw050_3"   )    return myEvent.BDT_output_t2bw050_R3;
        else if (BDTregion == "T2bw050_4"   )    return myEvent.BDT_output_t2bw050_R4;
        else if (BDTregion == "T2bw050_5"   )    return myEvent.BDT_output_t2bw050_R5;
        else if (BDTregion == "T2bw050_6"   )    return myEvent.BDT_output_t2bw050_R6;

        else if (BDTregion == "T2bw025_1"   )    return myEvent.BDT_output_t2bw025_R1;
        else if (BDTregion == "T2bw025_3"   )    return myEvent.BDT_output_t2bw025_R3;
        else if (BDTregion == "T2bw025_4"   )    return myEvent.BDT_output_t2bw025_R4;
        else if (BDTregion == "T2bw025_6"   )    return myEvent.BDT_output_t2bw025_R6;
        return -10.0;
    #else
        return -10.0;
    #endif
}



/*
float BDTcut(string BDTregion)
{
         if (BDTregion == "T2tt_1"      )    return 0.325;
    else if (BDTregion == "T2tt_2"      )    return 0.35 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.25 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.325;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.225;
    else if (BDTregion == "T2bw075_2"   )    return 0.275;
    else if (BDTregion == "T2bw075_3"   )    return 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.175;
    else if (BDTregion == "T2bw050_1_tight") return 0.25 ;
    else if (BDTregion == "T2bw050_3"   )    return 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.2  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.2  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.175;
    
    else return -1.0;
}
*/

// Definition of BDT cut including loosened cuts for control regions

float BDTcut(string BDTregion)
{
    #ifdef CR4_1j
         if (BDTregion == "T2tt_1"      )    return 0.305;
    else if (BDTregion == "T2tt_2"      )    return 0.395 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.265 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.265;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.225;
    else if (BDTregion == "T2bw075_2"   )    return 0.315;
    else if (BDTregion == "T2bw075_3"   )    return 0.305;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.175;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.225 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.225;
    else if (BDTregion == "T2bw050_3"   )    return 0.295;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.185;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.175;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.145;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.205  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.185;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.135  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.105;
    else return -1.0;
  #endif
  #ifdef CR4_2j
         if (BDTregion == "T2tt_1"      )    return 0.305;
    else if (BDTregion == "T2tt_2"      )    return 0.365 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.225 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.225;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.225;
    else if (BDTregion == "T2bw075_2"   )    return 0.285;
    else if (BDTregion == "T2bw075_3"   )    return 0.275;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.155;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.215 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.215;
    else if (BDTregion == "T2bw050_3"   )    return 0.245;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.155;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.155;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.125;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.195  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.175;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.125  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.095;
    else return -1.0;
   #endif 
   #ifdef CR4_3j
         if (BDTregion == "T2tt_1"      )    return 0.285;
    else if (BDTregion == "T2tt_2"      )    return 0.335 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.185 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.185;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.195;
    else if (BDTregion == "T2bw075_2"   )    return 0.245;
    else if (BDTregion == "T2bw075_3"   )    return 0.245;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.145;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.185 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.185;
    else if (BDTregion == "T2bw050_3"   )    return 0.205;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.145;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.135;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.105;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.175  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.155;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.115  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.095;
    else return -1.0;
   #endif 
   #ifdef CR4_4j
         if (BDTregion == "T2tt_1"      )    return 0.265;
    else if (BDTregion == "T2tt_2"      )    return 0.285 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.135 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.135;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.155;
    else if (BDTregion == "T2bw075_2"   )    return 0.205;
    else if (BDTregion == "T2bw075_3"   )    return 0.205;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.115;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.165 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.165;
    else if (BDTregion == "T2bw050_3"   )    return 0.105;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.095;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.095;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.075;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.155  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.125;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.085  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.075;
    else return -1.0;
   #endif
   #ifdef CR4_4j_50evts
         if (BDTregion == "T2tt_1"      )    return 0.255;
    else if (BDTregion == "T2tt_2"      )    return 0.255 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.105 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.105;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.135;
    else if (BDTregion == "T2bw075_2"   )    return 0.175;
    else if (BDTregion == "T2bw075_3"   )    return 0.165;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.095;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.135 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.135;
    else if (BDTregion == "T2bw050_3"   )    return 0.135;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.085;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.075;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.055;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.125  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.095;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.065  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.045;
    else return -1.0;
  #endif
  #ifdef CR4_4j_100evts
         if (BDTregion == "T2tt_1"      )    return 0.165;
    else if (BDTregion == "T2tt_2"      )    return 0.205 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.065 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.065;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.105;
    else if (BDTregion == "T2bw075_2"   )    return 0.135;
    else if (BDTregion == "T2bw075_3"   )    return 0.115;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.055;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.105 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.105;
    else if (BDTregion == "T2bw050_3"   )    return 0.095;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.055;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.035;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.015;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.085  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.065;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.035  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.015;
    else return -1.0;
  #endif
  #ifdef CR4_4j_150evts
         if (BDTregion == "T2tt_1"      )    return 0.135;
    else if (BDTregion == "T2tt_2"      )    return 0.165 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.035 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.035;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.085;
    else if (BDTregion == "T2bw075_2"   )    return 0.115;
    else if (BDTregion == "T2bw075_3"   )    return 0.085;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.025;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.085 ;
    else if (BDTregion == "T2bw050_1_tight") return 0.085;
    else if (BDTregion == "T2bw050_3"   )    return 0.065;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.035;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.015;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return -0.005;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.065  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.035;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.015  ;
    else if (BDTregion == "T2bw025_6"   )    return -0.015;
    else return -1.0;
  #endif
  
  // NOMINAL ANALYSIS       
	     if (BDTregion == "T2tt_1"      )    return 0.325;
    else if (BDTregion == "T2tt_2"      )    return 0.35 ;
    else if (BDTregion == "T2tt_5_loose")    return 0.25 ;
    else if (BDTregion == "T2tt_5_tight")    return 0.325;
    
    else if (BDTregion == "T2bw075_1"   )    return 0.225;
    else if (BDTregion == "T2bw075_2"   )    return 0.275;
    else if (BDTregion == "T2bw075_3"   )    return 0.325;  // previous 0.350;
    else if (BDTregion == "T2bw075_5"   )    return 0.175;  // previous 0.2  ;

    else if (BDTregion == "T2bw050_1_loose") return 0.175;
    else if (BDTregion == "T2bw050_1_tight") return 0.25 ;
    else if (BDTregion == "T2bw050_3"   )    return 0.275;  // previous 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    return 0.225;  // previous 0.250;
    else if (BDTregion == "T2bw050_5"   )    return 0.200;  //previous 0.225;
    else if (BDTregion == "T2bw050_6"   )    return 0.175;  // previous 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    return 0.2  ;
    else if (BDTregion == "T2bw025_3"   )    return 0.275;  // previous 0.3  ;
    else if (BDTregion == "T2bw025_4"   )    return 0.2  ;
    else if (BDTregion == "T2bw025_6"   )    return 0.175;
    
    else return -1.0;

    return -1.0;
}

bool goesInBDTRegion(string BDTregion) { return (BDToutput(BDTregion) > BDTcut(BDTregion)); }

bool BDT_T2tt_1         (bool applyMTCut) { return goesInBDTRegion("T2tt_1"         ); }
bool BDT_T2tt_2         (bool applyMTCut) { return goesInBDTRegion("T2tt_2"         ); }
bool BDT_T2tt_5_loose   (bool applyMTCut) { return goesInBDTRegion("T2tt_5_loose"   ); }
bool BDT_T2tt_5_tight   (bool applyMTCut) { return goesInBDTRegion("T2tt_5_tight"   ); }
bool BDT_T2bw075_1      (bool applyMTCut) { return goesInBDTRegion("T2bw075_1"      ); }
bool BDT_T2bw075_2      (bool applyMTCut) { return goesInBDTRegion("T2bw075_2"      ); }
bool BDT_T2bw075_3      (bool applyMTCut) { return goesInBDTRegion("T2bw075_3"      ); }
bool BDT_T2bw075_5      (bool applyMTCut) { return goesInBDTRegion("T2bw075_5"      ); }
bool BDT_T2bw050_1_loose(bool applyMTCut) { return goesInBDTRegion("T2bw050_1_loose"); }
bool BDT_T2bw050_1_tight(bool applyMTCut) { return goesInBDTRegion("T2bw050_1_tight"); }
bool BDT_T2bw050_3      (bool applyMTCut) { return goesInBDTRegion("T2bw050_3"      ); }
bool BDT_T2bw050_4      (bool applyMTCut) { return goesInBDTRegion("T2bw050_4"      ); }
bool BDT_T2bw050_5      (bool applyMTCut) { return goesInBDTRegion("T2bw050_5"      ); }
bool BDT_T2bw050_6      (bool applyMTCut) { return goesInBDTRegion("T2bw050_6"      ); }
bool BDT_T2bw025_1      (bool applyMTCut) { return goesInBDTRegion("T2bw025_1"      ); }
bool BDT_T2bw025_3      (bool applyMTCut) { return goesInBDTRegion("T2bw025_3"      ); }
bool BDT_T2bw025_4      (bool applyMTCut) { return goesInBDTRegion("T2bw025_4"      ); }
bool BDT_T2bw025_6      (bool applyMTCut) { return goesInBDTRegion("T2bw025_6"      ); }

#endif
