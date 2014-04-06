#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']



dataset_name 		= ['Single_Elec', 'Single_Muon', 'Double_Elec', 'Double_Muon', 'Muon_Elec', 'wjets_all', 'others_all', 'ttbar_1l', 'ttbar_2l']
queue               	= "1nh" 
executable         	= "runPlots" 
selection 		= ['1','2','4']		
lepton 			= ['1','2']		
additionalArguments1    = ['0 0', '0 0', '0 0', '0 0', '0 0', '0 0', '0 0', '1 1', '1 2']
additionalArguments2 	= "met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 T2bw050"


for x in range(len(selection)):

    if selection[x] == '1':
       selectionname = 'BVeto'
    if selection[x] == '2':
       selectionname = 'Dilepton_2Leptons'
    if selection[x] == '4':
       selectionname = 'MTPeak'

          
    for y in range(len(lepton)):

	    if lepton[y] == '1':
	        leptonname = 'Elec'
	    if lepton[y] == '2':
	        leptonname = 'Muon'

            for z in range(len(dataset_name)):

			inputlist = "../inputFileLists/"+dataset_name[z]+".list"
			outputdir = pwd+"/ntuples/"+dataset_name[z] 
			     

#			os.system("rm -r "+outputdir)
#			os.system("mkdir -p "+outputdir)
#			os.system("mkdir -p "+outputdir+"/log/")
#			os.system("mkdir -p "+outputdir+"/input/")
#			os.system("mkdir -p "+outputdir+"/output/")
#			os.system("mkdir -p "+outputdir+"/src/")


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


			    outputname_ = dataset_name[z]+"_"+selectionname+"_"+leptonname
			    outputname = outputdir+"/src/"+outputname_+".src"
			    outputfile = open(outputname,'w')
			    outputfile.write('#!/bin/bash\n')
			    outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
			    outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
			    outputfile.write("./"+executable+" "+ntpfile[:-1]+ " "+outputdir+"/output/"+outputname_+".root "+ selection[x]+ " " + additionalArguments1[z] +" "+ lepton[y] +" " + additionalArguments2+" ;")
			    outputfile.close
			    os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+outputname_+".log source "+outputname)
			    os.system("bsub -q 1nd -o "+outputdir+"/log/"+outputname_+".log source "+outputname)
			    print selectionname
			    ijob = ijob+1
			    continue
