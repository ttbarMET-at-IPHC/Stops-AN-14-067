#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']


dataset_name 		= ['Single_Elec', 'Single_Muon', 'Double_Elec', 'Double_Muon', 'ttbar_MG', 'wjets_all', 'others_all', 'ttbar_POWHEG']
queue               	= "1nh" 
executable         	= "./runPlots" 
additionalArguments 	= "4 0 0 2 met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 T2bw050"


for index in range(len(dataset_name)):

	inputlist = "../inputFileLists/"+dataset_name[index]+".list"
	outputdir = pwd+"/ntuples/"+dataset_name[index] 
	     

	os.system("rm -r "+outputdir)
	os.system("mkdir -p "+outputdir)
	os.system("mkdir -p "+outputdir+"/log/")
	os.system("mkdir -p "+outputdir+"/input/")
	os.system("mkdir -p "+outputdir+"/output/")
	os.system("mkdir -p "+outputdir+"/src/")


	input = open(inputlist)
	inputfiles = input.readlines()

	ijob=0

	while (len(inputfiles) > 0):
	    inputfilename = outputdir+"/input/input_"+str(ijob)
	    inputfile = open(inputfilename,'w')
	    for line in range(min(1,len(inputfiles))):
		ntpfile = inputfiles.pop()
		if ntpfile != '':
		    inputfile.write(ntpfile)

	    inputfile.close()



	    outputname = outputdir+"/src/"+dataset_name[index]+"_"+str(ijob)+".src"
	    outputfile = open(outputname,'w')
	    outputfile.write('#!/bin/bash\n')
	    outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
	    outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
	    outputfile.write("./"+executable+" "+ntpfile[:-1]+ " "+outputdir+"/output/"+dataset_name[index]+"_"+str(ijob)+".root "+ additionalArguments +";")
	    outputfile.close
	    os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+dataset_name[index]+"_"+str(ijob)+".log source "+outputname)
	    os.system("bsub -q "+queue+" -o "+outputdir+"/log/"+dataset_name[index]+"_"+str(ijob)+".log source "+outputname)

	    ijob = ijob+1
	    continue
