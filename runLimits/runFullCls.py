#! /usr/bin/env python
import os
import sys
import re
import time


pwd = os.environ['PWD']

decay_mode 		= ['T2bw025' , 'T2bw050', 'T2bw075', 'T2tt'] 


for z in range(len(decay_mode)):


    for stopmass in range(175, 800, 25):

        for lspmass in range(25, 700, 25):

	    if (stopmass - lspmass > 75):
           
                outputdir = pwd + "/mT100_FullCls/" + decay_mode[z]
                output = "datacard-S"+str(stopmass)+"-N"+str(lspmass)
                outputname = outputdir+"/"+output+".src"

                outputfile = open(outputname,'w')
                outputfile.write('#!/bin/bash\n')
                outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
                outputfile.write('cd '+outputdir+'; eval `scramv1 runtime -sh`; \n')
                outputfile.write('cd /tmp/sigamani; \n')
                outputfile.write('cp /afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/bin/slc5_amd64_gcc472/combine .; \n')
                outputfile.write('cp /afs/cern.ch/work/s/sigamani/public/CMSSW_6_1_1/src/HiggsAnalysis/CombinedLimit/limit_V2 .; \n')
                outputfile.write('cp '+outputdir+'/'+output+'.txt . ; \n')
                outputfile.write('./limit_V2 '+output+'.txt ; \n') 
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'obs.root; \n')
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.quant0.160.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'quant0.160.root; \n')
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.quant0.025.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'quant0.025.root; \n')
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.quant0.500.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'quant0.500.root; \n')
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.quant0.840.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'quant0.840.root; \n')
                outputfile.write('cp higgsCombineTest.HybridNew.mH120.quant0.975.root '+outputdir+'/FULL_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'quant0.975.root; \n')
                outputfile.write('cp higgsCombineTest.Asymptotic.mH120.root '+outputdir+'/ASYMPTOTIC_CLS_RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'.root; \n')
                outputfile.write('cp datacard-S'+str(stopmass)+"-N"+str(lspmass)+'.txt.result.txt '+outputdir+'/RESULT_S'+str(stopmass)+"-N"+str(lspmass)+'.txt; \n')
                outputfile.write('rm *root; rm *txt; \n')
                outputfile.close
                os.system("echo bsub -q 1nd -o "+outputdir+"/"+output+".log source "+outputname)
    		os.system("bsub -q 1nd -o "+outputdir+"/"+output+".log source "+outputname)
