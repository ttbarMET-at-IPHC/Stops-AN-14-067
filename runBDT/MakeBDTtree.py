#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']

#dataset_name        = ['t2bw_025','t2bw_050', 't2bw_075', 't2tt_all', 'ttbar_1l', 'ttbar_2l', 'wjets_all', 'others_all'] 
dataset_name        = ['t2bw_025','t2bw_050', 't2bw_075', 't2tt_all']
queue               = '1nh'
executable          = 'MakeBDTtree'
deltaMRegion        = ['R1','R2','R3','R4','R5','R6']
deltaMArguments     = ['100 200 0 800', '200 300 0 800', '300 400 0 800', '400 500 0 800', '500 600 0 800', '600 700 0 800']


for z in range(len(dataset_name)):


    for y in range(len(deltaMRegion)):


	inputlist = "../inputFileLists/"+dataset_name[z]+".list"
	outputdir = pwd+"/BDT3_skim_MT100/"+dataset_name[z]+"/"+deltaMRegion[y]
	     
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


            #if (y > 6):
    	    #    output = dataset_name[z]
	    #else:
	    output = dataset_name[z]+"_"+deltaMRegion[y]
            outputname = outputdir+"/src/"+output+".src"
            outputfile = open(outputname,'w')
            outputfile.write('#!/bin/bash\n')
            outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
            outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
	    outputfile.write("./"+executable+" "+ntpfile[:-1]+ " "+outputdir+"/output/"+output+".root "+deltaMArguments[y]+";")
            outputfile.close
            os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
            os.system("bsub -q 1nd -o "+outputdir+"/log/"+output+".log source "+outputname)
            ijob = ijob+1
                                                                                                                                                                                        
            continue
