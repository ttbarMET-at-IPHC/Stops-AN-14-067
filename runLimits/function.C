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





int signalregion(string decaymode, int stopmass, int lspmass)
{

  int signalregion = 0;

  if (decaymode = "T2bw075") {

	  if (lspmass > stopmass - 175)
	    signalregion = 1;
	  if (lspmass <= stopmass - 175 && lspmass > stopmass - 275)
	    signalregion = 2;
	  if (lspmass <= stopmass - 275 && lspmass > stopmass - 450)
	    signalregion = 3;
	  if (lspmass <= stopmass - 450)
	    signalregion = 6;

  }



  if (decaymode = "T2bw050") {

	  if (lspmass > stopmass - 200)
	    signalregion = 1;
	  if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
	    signalregion = 2;
	  if (lspmass <= stopmass - 325 && lspmass > stopmass - 500)
	    signalregion = 3;
	  if (lspmass <= stopmass - 500)
	    signalregion = 4;

  }	

  if (decaymode = "T2bw025") {

	  if (lspmass > stopmass - 200)
	    signalregion = 1;
	  if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
	    signalregion = 2;
	  if (lspmass <= stopmass - 325 && lspmass > stopmass - 425)
	    signalregion = 3;
	  if (lspmass <= stopmass - 425)
	    signalregion = 5;

  }


  else if (decaymode = "T2tt") {

	  if (stopmass >= 175 && stopmass <= 325)
	    signalregion = 1;

	  else if (stopmass >= 350 && stopmass <= 700)
	    {
	      if (lspmass > stopmass - 225)
		signalregion = 1;
	      else
		signalregion = 3;

	    }

	  else if (stopmass >= 725)
	    {
	      if (lspmass >= 500)
		signalregion = 1;
	      else
		signalregion = 4;
	    }

  } 

  //cout << "Region: "<< signalregion << endl;
  return signalregion;

}




double signalcut(string decaymode, int stopmass, int lspmass)
{

  double cutvalue = 0.;

  if (decaymode = "T2bw075") {

	  if (lspmass > stopmass - 175)
	    cutvalue = 0.3;
	  if (lspmass <= stopmass - 175 && lspmass > stopmass - 275)
	    cutvalue = 0.3;
	  if (lspmass <= stopmass - 275 && lspmass > stopmass - 450)
	    cutvalue = 0.3;
	  if (lspmass <= stopmass - 450)
	    cutvalue = 0.2;

  }



  if (decaymode = "T2bw050") {

	  if (lspmass > stopmass - 200)
	    cutvalue = 0.25;
	  if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
	    cutvalue = 0.3;
	  if (lspmass <= stopmass - 325 && lspmass > stopmass - 500)
	    cutvalue = 0.35;
	  if (lspmass <= stopmass - 500)
	    cutvalue = 0.25;

  }	

   if (decaymode = "T2bw025") {

          if (lspmass > stopmass - 200)
	    cutvalue = 0.2;
	  if (lspmass <= stopmass - 200 && lspmass > stopmass - 325)
	    cutvalue = 0.35;
	  if (lspmass <= stopmass - 325 && lspmass > stopmass - 425)
	    cutvalue = 0.2;
	  if (lspmass <= stopmass - 425)
	    cutvalue = 0.2;

  }


  else if (decaymode = "T2tt") {

	  if (stopmass >= 175 && stopmass <= 325)
	    cutvalue = 0.35;

	  else if (stopmass >= 350 && stopmass <= 700)
	    {
	      if (lspmass > stopmass - 225)
		cutvalue = 0.35;
	      else
		cutvalue = 0.45;

	    }

	  else if (stopmass >= 725)
	    {
	      if (lspmass >= 500)
		cutvalue = 0.35;
	      else
		cutvalue = 0.45;
	    }

  } 

  //  cout << "Cut: "<< cutvalue << endl;
    
  return cutvalue;

}
