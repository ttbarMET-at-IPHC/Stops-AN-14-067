#!/bin/csh -f

set postpend = "met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 T2bw050"

./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/SingleElec.root SingleElecBVetoElec.root 1 0 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsBVetoElec.root 1 0 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersBVetoElec.root 1 0 0 0 0 $postpend 
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLBVetoElec.root 1 1 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLBVetoElec.root 1 2 0 0 0 $postpend
hadd -f dataBVetoElec.root SingleElecBVetoElec.root; rm Single*root;


./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/SingleMuon.root SingleMuonBVetoMuon.root 1 0 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsBVetoMuon.root 1 0 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersBVetoMuon.root 1 0 0 0 1 $postpend 
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLBVetoMuon.root 1 1 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLBVetoMuon.root 1 2 0 0 1 $postpend
hadd -f dataBVetoMuon.root SingleMuonBVetoMuon.root; rm Single*root;

./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/DoubleElec.root DoubleElecDilepton_2LeptonsElec.root 2 0 1 1 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/MuEl.root DoubleMuElec.root 2 0 1 1 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsDilepton_2LeptonsElec.root 2 0 1 1 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersDilepton_2LeptonsElec.root 2 0 1 1 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLDilepton_2LeptonsElec.root 2 1 1 1 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLDilepton_2LeptonsElec.root 2 2 1 1 0 $postpend
hadd -f dataDilepton_2LeptonsElec.root DoubleElec*; rm Double*root;

./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/DoubleMuon.root DoubleMuonDilepton_2LeptonsMuon.root 2 0 1 1 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/MuEl.root DoubleMuElec.root 2 0 1 1 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsDilepton_2LeptonsMuon.root 2 0 1 1 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersDilepton_2LeptonsMuon.root 2 0 1 1 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLDilepton_2LeptonsMuon.root 2 1 1 1 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLDilepton_2LeptonsMuon.root 2 2 1 1 1 $postpend
hadd -f dataDilepton_2LeptonsMuon.root DoubleMuon*; rm Double*root;


./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/SingleElec.root SingleElecMTPeakElec.root 4 0 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsMTPeakElec.root 4 0 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersMTPeakElec.root 4 0 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLMTPeakElec.root 4 1 0 0 0 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLMTPeakElec.root 4 2 0 0 0 $postpend
hadd -f dataMTPeakElec.root SingleElecMTPeakElec.root; rm Single*root;

./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/SingleMuon.root SingleMuonMTPeakMuon.root 4 0 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/Wjets.root WjetsMTPeakMuon.root 4 0 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/others.root othersMTPeakMuon.root 4 0 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarSLMTPeakMuon.root 4 1 0 0 1 $postpend
./runPlots root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04/ttbar.root ttbarDLMTPeakMuon.root 4 2 0 0 1 $postpend
hadd -f dataMTPeakMuon.root SingleMuonMTPeakMuon.root; rm Single*root;

