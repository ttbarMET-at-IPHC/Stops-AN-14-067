#!/usr/bin/env tcsh

set decaymode = T2tt_Onshell

#	foreach dataset ( DoubleElec DoubleMuon MuEl SingleElec SingleMuon Wjets others ttbar )

#	./runExtender root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/$dataset.root $dataset.root met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 $decaymode 
#        xrdcp $dataset.root root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-04/$decaymode/$dataset.root 
         
#	end




#	foreach dataset ( DoubleElec DoubleMuon MuEl SingleElec SingleMuon Wjets others ttbar )

#	./runExtender root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/$dataset.root $dataset.root met,lepton_pT,njets,mlb_hemi,m3b,mT2W,HT,dPhi_JetMet,jet1_pT setup_103 $decaymode 
#        xrdcp $dataset.root root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-04/$decaymode/$dataset.root 
        
#	end


#	foreach dataset ( DoubleElec DoubleMuon MuEl SingleElec SingleMuon Wjets others ttbar )

#	./runExtender root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/$dataset.root $dataset.root met,lepton_pT,mlb_hemi,HTfrac,njets,dPhi_JetMet,b1_pt setup_104 $decaymode 
#        xrdcp $dataset.root root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-04/$decaymode/$dataset.root 
        
#	end

	foreach dataset ( DoubleElec DoubleMuon MuEl SingleElec SingleMuon Wjets others ttbar )

	set cmd = "./runExtender root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/$dataset.root $dataset.root met,mT2W,HTfrac,njets,dPhi_JetMet,lepton_pT,dR_LepB,Chi2SNT,jet1_pT setup_104 $decaymode"
	echo $cmd 
#        xrdcp $dataset.root root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-04/$decaymode/$dataset.root 
        
	end
