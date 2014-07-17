#ifndef _SignalRegionDefinitions_h
#define _SignalRegionDefinitions_h

#include "BDTcuts.h"

bool NOMINAL_BDT_CUT = true;
bool CR45_INDEP_BINS =  false;
int CR4_4j_Bin = 0;


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



TString signalregionName(TString decaymode, int stopmass, int lspmass)
{

  TString SR = "nan";


   if (decaymode == "T2bw075") {


          if (lspmass > stopmass - 200)
            SR = "T2bw075_1";
          if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            SR = "T2bw075_2";
          if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            SR = "T2bw075_3";
          if (lspmass <= stopmass - 475)
            SR = "T2bw075_5";

  }



  if (decaymode == "T2bw050") {


          if (lspmass > stopmass - 250) {
		SR = "T2bw050_1_tight" ; 
		    if (lspmass < 150) SR = "T2bw050_1_loose";
		}

          if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            SR = "T2bw050_3";
          if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            SR = "T2bw050_4";
          if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
            SR = "T2bw050_5";
          if (lspmass <= stopmass - 625)
            SR = "T2bw050_6";


  }	

  if (decaymode == "T2bw025") {


          if (lspmass <= 125)
            {
              if (lspmass > stopmass - 275)
                SR = "T2bw025_1";

            }
          if (lspmass > 125)
            {
              if (lspmass > stopmass - 225)
                SR = "T2bw025_1";
              if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
                SR = "T2bw025_3";

            }

          if (lspmass <= stopmass - 275 && lspmass > stopmass - 425)
            SR = "T2bw025_3";
          if (lspmass <= stopmass - 425 && lspmass > stopmass - 600)
            SR = "T2bw025_4";
          if (lspmass <= stopmass - 600)
            SR = "T2bw025_6";



  }


  if (decaymode == "T2tt") {


	  if (lspmass > stopmass - 225)
	    SR = "T2tt_1";
	  if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
	    SR = "T2tt_2";
		  if (lspmass <= stopmass - 275) {

			SR="T2tt_5_loose"; if (lspmass <= stopmass - 400) SR = "T2tt_5_tight";
		   }


 	}

  return SR;
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




int returnIntBDTOffsetValue(TString decaymode, int stopmass, int lspmass)
{

  int intoffset = -999;


   if (decaymode == "T2bw075") {


          if (lspmass > stopmass - 200)
            intoffset = 8;
          if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
            intoffset = 8;
          if (lspmass <= stopmass - 325 && lspmass > stopmass - 475)
            intoffset = 8;
          if (lspmass <= stopmass - 475)
            intoffset = 9;
          if (lspmass <= stopmass - 575)
            intoffset = 10;

  }



  if (decaymode == "T2bw050") {


          if (lspmass > stopmass - 250) {
		intoffset = 7 ; 
		    if (lspmass < 150) intoffset = 6;
		}

          if (lspmass <= stopmass - 250 && lspmass > stopmass - 400)
            intoffset = 5;
          if (lspmass <= stopmass - 400 && lspmass > stopmass - 450)
            intoffset = 6;
          if (lspmass <= stopmass - 450 && lspmass > stopmass - 625)
            intoffset = 8;
          if (lspmass <= stopmass - 625)
            intoffset = 3;


  }	

  if (decaymode == "T2bw025") {

        //  if (lspmass <= 125)
          //  {
           //   if (lspmass > stopmass - 275)
           //     intoffset = 7;

          //  }
         // if (lspmass > 125)
          //  {
              if (lspmass > stopmass - 275)
                intoffset = 7;
           //   if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
            //    intoffset = 5;
          //  }

          if (lspmass <= stopmass - 275 && lspmass > stopmass - 325)
            intoffset = 5;
          if (lspmass <= stopmass - 325 && lspmass > stopmass - 400)
            intoffset = 8;
          if (lspmass <= stopmass - 400 && lspmass > stopmass - 600)
            intoffset = 7;
          if (lspmass <= stopmass - 600)
            intoffset = 8;
  }


  if (decaymode == "T2tt") {


	  if (lspmass > stopmass - 225)
	    intoffset = 8;
	  if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
	    intoffset = 8;
		  if (lspmass <= stopmass - 275) {

			intoffset=8; 

				if (lspmass <= stopmass - 325 && lspmass > stopmass - 400) 
				   intoffset = 10;
			 	if (lspmass <= stopmass - 400 && lspmass > stopmass - 500) 
				   intoffset = 8;
			 	if (lspmass <= stopmass - 500) 
				   intoffset = 9;
		   }


 	}


  return intoffset;
}





float BDToutput(string BDTregion)
{

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

    else return -10.0;
}


float BDTcut(string BDTregion, bool BDTCutIndepSR_NextBin = false) 
// second argument is meaningfull in the context of ttbar-dilepton estimation in CR
{
  if(NOMINAL_BDT_CUT)
  {
         if (BDTregion == "T2tt_1"      )    	return 0.325;
    else if (BDTregion == "T2tt_2_lowDM")    	return 0.35 ;
    else if (BDTregion == "T2tt_2_tight")    	return 0.25 ;
    else if (BDTregion == "T2tt_5_lowDM")    	return 0.35 ;
    else if (BDTregion == "T2tt_5_mediumDM")    	return 0.325;
    else if (BDTregion == "T2tt_5_highDM")    	return 0.375;
    
    else if (BDTregion == "T2bw075_1"   )    	return 0.225;
    else if (BDTregion == "T2bw075_2"   )    	return 0.275;
    else if (BDTregion == "T2bw075_3"   )    	return 0.350;
    else if (BDTregion == "T2bw075_5_lowDM")    return 0.25 ;
    else if (BDTregion == "T2bw075_5_highDM")    return 0.3  ;

    else if (BDTregion == "T2bw050_1_lowDM") 	return 0.175;
    else if (BDTregion == "T2bw050_1_highDM") 	return 0.25 ;
    else if (BDTregion == "T2bw050_3"   )    	return 0.3  ;
    else if (BDTregion == "T2bw050_4"   )    	return 0.250;
    else if (BDTregion == "T2bw050_5"   )    	return 0.225;
    else if (BDTregion == "T2bw050_6"   )    	return 0.2  ;

    else if (BDTregion == "T2bw025_1"   )    	return 0.15  ;
    else if (BDTregion == "T2bw025_3"   )    	return 0.15  ;
    else if (BDTregion == "T2bw025_4"   )    	return 0.15  ;
    else if (BDTregion == "T2bw025_6"   )    	return 0.175;
    
    else return -1.0;
  }
  else if(CR45_INDEP_BINS)
  {
    int ibin = CR4_4j_Bin;
    if(BDTCutIndepSR_NextBin) ibin--;

         if (BDTregion == "T2tt_1"      )    return BDTCutIndepSR[0][ibin];
    else if (BDTregion == "T2tt_2"      )    return BDTCutIndepSR[1][ibin];
    else if (BDTregion == "T2tt_5_loose")    return BDTCutIndepSR[2][ibin];
    else if (BDTregion == "T2tt_5_tight")    return BDTCutIndepSR[2][ibin];
    
    else if (BDTregion == "T2bw075_1"   )    return BDTCutIndepSR[3][ibin];
    else if (BDTregion == "T2bw075_2"   )    return BDTCutIndepSR[4][ibin];
    else if (BDTregion == "T2bw075_3"   )    return BDTCutIndepSR[5][ibin];
    else if (BDTregion == "T2bw075_5"   )    return BDTCutIndepSR[6][ibin];

    else if (BDTregion == "T2bw050_1_loose") return BDTCutIndepSR[7][ibin];
    else if (BDTregion == "T2bw050_1_tight") return BDTCutIndepSR[7][ibin];
    else if (BDTregion == "T2bw050_3"   )    return BDTCutIndepSR[8][ibin];
    else if (BDTregion == "T2bw050_4"   )    return BDTCutIndepSR[9][ibin];
    else if (BDTregion == "T2bw050_5"   )    return BDTCutIndepSR[10][ibin];
    else if (BDTregion == "T2bw050_6"   )    return BDTCutIndepSR[11][ibin];

    else if (BDTregion == "T2bw025_1"   )    return BDTCutIndepSR[12][ibin];
    else if (BDTregion == "T2bw025_3"   )    return BDTCutIndepSR[13][ibin];
    else if (BDTregion == "T2bw025_4"   )    return BDTCutIndepSR[14][ibin];
    else if (BDTregion == "T2bw025_6"   )    return BDTCutIndepSR[15][ibin];
    else return -1.0;
  }
  else
  {
         if (BDTregion == "T2tt_1"      )    return BDTCuts[0];
    else if (BDTregion == "T2tt_2"      )    return BDTCuts[1];
    else if (BDTregion == "T2tt_5_loose")    return BDTCuts[2];
    else if (BDTregion == "T2tt_5_tight")    return BDTCuts[3];
    
    else if (BDTregion == "T2bw075_1"   )    return BDTCuts[4];
    else if (BDTregion == "T2bw075_2"   )    return BDTCuts[5];
    else if (BDTregion == "T2bw075_3"   )    return BDTCuts[6];
    else if (BDTregion == "T2bw075_5"   )    return BDTCuts[7];

    else if (BDTregion == "T2bw050_1_loose") return BDTCuts[8];
    else if (BDTregion == "T2bw050_1_tight") return BDTCuts[9];
    else if (BDTregion == "T2bw050_3"   )    return BDTCuts[10];
    else if (BDTregion == "T2bw050_4"   )    return BDTCuts[11];
    else if (BDTregion == "T2bw050_5"   )    return BDTCuts[12];
    else if (BDTregion == "T2bw050_6"   )    return BDTCuts[13];

    else if (BDTregion == "T2bw025_1"   )    return BDTCuts[14];
    else if (BDTregion == "T2bw025_3"   )    return BDTCuts[15];
    else if (BDTregion == "T2bw025_4"   )    return BDTCuts[16];
    else if (BDTregion == "T2bw025_6"   )    return BDTCuts[17];
    else return -1.0;
  }
}

//bool goesInBDTRegion(string BDTregion) { return (BDToutput(BDTregion) > BDTcut(BDTregion)); }

bool goesInBDTRegion(string BDTregion) { 
	//This treatment in only applied for CR for tt-dilepton estimation
	if(CR45_INDEP_BINS && CR4_4j_Bin>=1){
		return (BDToutput(BDTregion)>BDTcut(BDTregion) && BDToutput(BDTregion)<=BDTcut(BDTregion,true));
	}
	else return (BDToutput(BDTregion) > BDTcut(BDTregion));
}

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

bool LowBDT_T2tt_1         (bool applyMTCut) { return (BDToutput("T2tt_1"         )> -0.00  ); }
bool LowBDT_T2tt_2         (bool applyMTCut) { return (BDToutput("T2tt_2"         )> 0.01   ); }
bool LowBDT_T2tt_5         (bool applyMTCut) { return (BDToutput("T2tt_5_loose"   )> -0.06  ); }
bool LowBDT_T2bw075_1      (bool applyMTCut) { return (BDToutput("T2bw075_1"      )> -0.01  ); }
bool LowBDT_T2bw075_2      (bool applyMTCut) { return (BDToutput("T2bw075_2"      )> -0.04  ); }
bool LowBDT_T2bw075_3      (bool applyMTCut) { return (BDToutput("T2bw075_3"      )> -0.04  ); }
bool LowBDT_T2bw075_5      (bool applyMTCut) { return (BDToutput("T2bw075_5"      )> -0.05  ); }
bool LowBDT_T2bw050_1      (bool applyMTCut) { return (BDToutput("T2bw050_1_loose")> -0.00  ); }
bool LowBDT_T2bw050_3      (bool applyMTCut) { return (BDToutput("T2bw050_3"      )> 0.04   ); }
bool LowBDT_T2bw050_4      (bool applyMTCut) { return (BDToutput("T2bw050_4"      )> 0.01   ); }
bool LowBDT_T2bw050_5      (bool applyMTCut) { return (BDToutput("T2bw050_5"      )> 0.00   ); }
bool LowBDT_T2bw050_6      (bool applyMTCut) { return (BDToutput("T2bw050_6"      )> -0.00  ); }
bool LowBDT_T2bw025_1      (bool applyMTCut) { return (BDToutput("T2bw025_1"      )> 0.04   ); }
bool LowBDT_T2bw025_3      (bool applyMTCut) { return (BDToutput("T2bw025_3"      )> 0.05   ); }
bool LowBDT_T2bw025_4      (bool applyMTCut) { return (BDToutput("T2bw025_4"      )> 0.01   ); }
bool LowBDT_T2bw025_6      (bool applyMTCut) { return (BDToutput("T2bw025_6"      )> -0.01  ); }

#endif
