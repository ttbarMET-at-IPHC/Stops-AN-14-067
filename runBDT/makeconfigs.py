#!/bin/python

import os, sys
import ConfigParser

def makeconfigfile(configfilename,BDT_book_options,BDT_vars,train_test,backgroundfilelist,signalsample):
    config = ConfigParser.RawConfigParser()
    
    config.add_section('BDT')
    config.set('BDT', "BDT_book_options", BDT_book_options)
    config.set('BDT', "BDT_vars", BDT_vars)
    config.set('BDT', "backgroundfilelist", backgroundfilelist)
    config.set('BDT', "signalfilelist", signalsample)
    config.set('BDT', "BDT_train_test", train_test)
    
    with open(configfilename, 'wb') as configfile:
        config.write(configfile)

def getconfigname(counter,basedir):
    if not os.path.isdir(basedir):
        os.makedirs(basedir)
    return basedir + "setup_" + str(counter) + ".cfg"

if __name__ == "__main__":

    basedir = ""
    if not len(sys.argv) is 2:
        print "will use default directory for setups"
        basedir = os.getcwd() + "/setup/"
    else:
        basedir = sys.argv[1] #dir where you want the setups

    print basedir
   

    BDT_vars_list = [
		    #t2bw	
                    #"met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB" # 102 
                    #"met,lepton_pT,njets,mlb_hemi,m3b,mT2W,HT,dPhi_JetMet,jet1_pT" # 103

		    #t2tt
		    #"met,mT2W,HTfrac,njets,dPhi_JetMet,lepton_pT,dR_LepB,Chi2SNT,jet1_pT"  #104
		    "met,lepton_pT,mlb_hemi,HTfrac,njets,dPhi_JetMet,b1_pt" #105 

                  ]



    BDT_book_options_list = []
    BDT_book_options_list.append("!H:!V:NTrees=400:nEventsMin=400:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:PruneMethod=NoPruning")

    
    counter = 105 
    train_test = "nTrain_Signal=0:nTrain_Background=0:nTest_Signal=0:nTest_Background=0:SplitMode=Random:NormMode=EqualNumEvents"


    for BDT_vars in BDT_vars_list:
        for BDT_book_options in BDT_book_options_list:
            configfilename = getconfigname(counter,basedir)
            print configfilename
            backgroundfilelist = os.getcwd() + "/filelists/filelist_TTbar_skim.txt"
            signalsample = os.getcwd() + "/filelists/filelist_signal_skim.txt"
            makeconfigfile(configfilename,BDT_book_options,BDT_vars,train_test,backgroundfilelist,signalsample)
            counter = counter + 1
            


    
