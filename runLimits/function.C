
using namespace std;



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

//  cout << "Region: "<< signalregion << endl;
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
	    cutvalue = 0.3;
	  if (lspmass <= stopmass - 225 && lspmass > stopmass - 275)
	    cutvalue = 0.275;
		  if (lspmass <= stopmass - 275) {

			cutvalue=0.250; if (lspmass <= stopmass - 400) cutvalue = 0.325;
		   }


 	}


  //  cout << "Cut: "<< cutvalue << endl;

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
	    setup = "setup_105";
	    if (BDT == "BDT3")
	      setup = "setup_6";
	    if (BDT == "BDT4")
	      setup = "setup_7";
	    if (BDT == "BDT5")
	      setup = "setup_5";
	  }

  return setup;

}
