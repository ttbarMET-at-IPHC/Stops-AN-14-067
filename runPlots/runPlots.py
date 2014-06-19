#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']



dataset_name 		= ['SingleElec', 'SingleMuon', 'DoubleElec', 'DoubleMuon', 'MuEl', 'W+jets', 'rare', 'singleTop_st', 'ttbar_madgraph_1l', 'ttbar_madgraph_2l', 'T2bw-025' , 'T2bw-050' , 'T2bw-075' , 'T2tt' ]
queue               	= "1nh" 
executable         	= "runPlots" 
selection 		= ['0','1','2','3','4']		
additionalArguments 	= '0 0'		

for z in range(len(dataset_name)):

    inputfile = "root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-05/"+dataset_name[z]+".root"
    outputdir = pwd+"/batch_output/"+dataset_name[z] 
			     
    os.system("rm -r "+outputdir)
    os.system("mkdir -p "+outputdir)
    os.system("mkdir -p "+outputdir+"/log/")
    os.system("mkdir -p "+outputdir+"/input/")
    os.system("mkdir -p "+outputdir+"/output/")
    os.system("mkdir -p "+outputdir+"/src/")
    

    for x in range(len(selection)):
    
        if selection[x] == '1':
           selectionname = 'BVeto'
        if selection[x] == '2':
           selectionname = 'Dilepton_2Leptons'
        if selection[x] == '3':
           selectionname = 'Dilepton_FailsTrackOrTau'
        if selection[x] == '4':
           selectionname = 'MTPeak'
        if selection[x] == '0':
           selectionname = 'Default'

          
           output = dataset_name[z]+"_"+selectionname
           outputname = outputdir+"/src/"+output+".src"
   	   print selectionname
           outputfile = open(outputname,'w')
           outputfile.write('#!/bin/bash\n')
           outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
           outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
           outputfile.write('cd /tmp/sigamani; \n')
           outputfile.write('cp /afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_14_STOPS/src/Stops-AN-14-067/runPlots/runPlots .; \n')
           outputfile.write("./"+executable+" "+inputfile+ " "+output+".root "+ selection[x]+ " " + additionalArguments+" ;")
           outputfile.write("cp "+output+".root "+outputdir+"/output/ ; rm "+output+".root")
           outputfile.close
           os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
           os.system("bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
