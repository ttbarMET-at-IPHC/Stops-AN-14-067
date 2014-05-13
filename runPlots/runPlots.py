#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']



dataset_name 		= ['Single_Elec', 'Single_Muon', 'Double_Elec', 'Double_Muon', 'Muon_Elec', 'wjets_all', 'others_all', 'ttbar_1l', 'ttbar_2l']
queue               	= "1nh" 
executable         	= "runPlots" 
selection 		= ['0','1','2','3','4']		
#lepton 			= ['0']		
lepton 			= ['1','2']		
additionalArguments 	= "met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB t2bw025"


for z in range(len(dataset_name)):

    inputlist = "../inputFileLists/"+dataset_name[z]+".list"
    outputdir = pwd+"/ntuples/"+dataset_name[z] 
			     
    os.system("rm -r "+outputdir)
    os.system("mkdir -p "+outputdir)
    os.system("mkdir -p "+outputdir+"/log/")
    os.system("mkdir -p "+outputdir+"/input/")
    os.system("mkdir -p "+outputdir+"/output/")
    os.system("mkdir -p "+outputdir+"/src/")
    

    for x in range(len(selection)):
    
        if selection[x] == '0':
           selectionname = 'Default'
        if selection[x] == '1':
           selectionname = 'BVeto'
        if selection[x] == '2':
           selectionname = 'Dilepton_2Leptons'
        #   selectionname = 'Dilepton_FailsTrackOrTau'
        if selection[x] == '4':
           selectionname = 'MTPeak'

          
        for y in range(len(lepton)):

            if lepton[y] == '0':
                leptonname = 'All'
            if lepton[y] == '1':
                leptonname = 'Elec'
            if lepton[y] == '2':
                leptonname = 'Muon'
        

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


                output = dataset_name[z]+"_"+selectionname+"_"+leptonname
                outputname = outputdir+"/src/"+output+".src"
		print selectionname
                outputfile = open(outputname,'w')
                outputfile.write('#!/bin/bash\n')
                outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
                outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
                outputfile.write("./"+executable+" "+ntpfile[:-1]+ " "+outputdir+"/output/"+output+".root "+ selection[x]+ " " + lepton[y] +" " + additionalArguments+" ;")
                outputfile.close
                os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
                os.system("bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
                ijob = ijob+1
                                                                                                                                                                                        
                continue
