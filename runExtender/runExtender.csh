#!/usr/bin/env tcsh


	foreach dataset ( DoubleElec DoubleMuon MuEl SingleElec SingleMuon Wjets others ttbar ttbar_madgraph_1l+2l T2bw-025 T2bw-050 T2bw-075)


	set cmd = "./babyExtender root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/$dataset.root /tmp/sigamani/$dataset.root met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB met,lepton_pT,njets,mlb_hemi,m3b,mT2W,dR_LepB,dPhi_JetMet,b1_pt met,lepton_pT,njets,jet1_pT,HT,mlb_hemi,m3b,mT2W,dPhi_JetMet met,lepton_pT,mlb_hemi,HTfrac,njets,dPhi_JetMet,b1_pt met,mT2W,HTfrac,njets,dPhi_JetMet,lepton_pT,dR_LepB,Chi2SNT,jet1_pT"

	echo $cmd
        $cmd
 
	xrdcp /tmp/sigamani/$dataset.root root://eoscms//eos/cms/store/caf/user/sigamani/StopBabies/V00-04/$dataset.root 
	rm /tmp/sigamani/$dataset.root

	end

