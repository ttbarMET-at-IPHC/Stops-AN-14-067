#! /usr/bin/env python
import os
import sys
import re
import time



pwd = os.environ['PWD']

dataset_name 		= ['SingleElec', 'SingleMuon', 'DoubleElec', 'DoubleMuon', 'MuEl', 'W+jets', 'rare', 'singleTop_st', 'ttbar_powheg', 'ttbar_madgraph_1l', 'ttbar_madgraph_2l', 'T2bw-025', 'T2bw-050', 'T2bw-075', 'T2tt']
#dataset_name 		= ['SingleElec', 'SingleMuon', 'DoubleElec', 'DoubleMuon'] 
queue               	= "1nd" 
outputEOSdir		= "root://eoscms//eos/cms/store/caf/user/sigamani/test/"

for z in range(len(dataset_name)):

    outputdir = pwd+"/batch_output/"+dataset_name[z] 

    os.system("rm -r "+outputdir)
    os.system("mkdir -p "+outputdir)
    os.system("mkdir -p "+outputdir+"/log/")
    os.system("mkdir -p "+outputdir+"/src/")

    outputname = outputdir+"/src/"+dataset_name[z]+".src"
    outputfile = open(outputname,'w')
    outputfile.write('#!/bin/bash\n')
    outputfile.write('export SCRAM_ARCH=slc6_amd64_gcc472\n')
    outputfile.write('cd '+pwd+'; eval `scramv1 runtime -sh`; source setup.sh; \n')
    outputfile.write("./runExtender /afs/cern.ch/work/a/aaubin/stopBabies/"+dataset_name[z]+".root /tmp/sigamani/"+dataset_name[z]+".root met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB met,lepton_pT,njets,mlb_hemi,m3b,mT2W,dR_LepB,dPhi_JetMet,b1_pt met,lepton_pT,njets,jet1_pT,HT,mlb_hemi,m3b,mT2W,dPhi_JetMet met,lepton_pT,mlb_hemi,HTfrac,njets,dPhi_JetMet,b1_pt met,mT2W,HTfrac,njets,dPhi_JetMet,lepton_pT,dR_LepB,Chi2SNT,jet1_pT;")
    outputfile.write("eos rm "+outputEOSdir+"/"+dataset_name[z]+".root; xrdcp /tmp/sigamani/"+dataset_name[z]+".root "+outputEOSdir+"/"+dataset_name[z]+".root; rm /tmp/sigamani/"+dataset_name[z]+".root")
    outputfile.close
    os.system("echo bsub -q 1nd -o "+outputdir+"/log/"+outputname+".log source "+outputname)
    os.system("bsub -q 1nd -o "+outputdir+"/log/"+outputname+".log source "+outputname)
