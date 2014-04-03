#!/bin/csh -f

set input = "root://eoscms//eos/cms/store/group/phys_susy/StopBabies/V00-04"
set postpend = "met,lepton_pT,njets,mlb_hemi,m3b,mT2W,b1_pt,dPhi_JetMet,dR_LepB setup_102 T2bw050"


foreach lepton (Muon Elec)

./runPlots $input/Single$lepton.root dataMTPeak$lepton.root 4 0 0 2 $postpend
./runPlots $input/Wjets.root WjetsMTPeak$lepton.root 4 0 0 2 $postpend
./runPlots $input/others.root othersMTPeak$lepton.root 4 0 0 2 $postpend
./runPlots $input/ttbar_madgraph_1l.root ttbar1lMTPeak$lepton.root 4 1 0 2 $postpend
./runPlots $input/ttbar_madgraph_2l.root ttbar2lMTPeak$lepton.root 4 2 0 2 $postpend

./runPlots $input/Single$lepton.root dataBVeto$lepton.root 1 0 0 2 $postpend
./runPlots $input/Wjets.root WjetsBVeto$lepton.root 1 0 0 2 $postpend
./runPlots $input/others.root othersBVeto$lepton.root 1 0 0 2 $postpend 
./runPlots $input/ttbar_madgraph_1l.root ttbar1lBVeto$lepton.root 1 1 0 2 $postpend
./runPlots $input/ttbar_madgraph_2l.root ttbar2lBVeto$lepton.root 1 2 0 2 $postpend

./runPlots $input/Double$lepton.root dataDilepton_2Leptons$lepton.root 2 0 1 2 $postpend
./runPlots $input/Wjets.root WjetsDilepton_2Leptons$lepton.root 2 0 1 2 $postpend
./runPlots $input/others.root othersDilepton_2Leptons$lepton.root 2 0 1 2 $postpend
./runPlots $input/ttbar_madgraph_1l.root ttbar1lDilepton_2Leptons$lepton.root 2 1 1 2 $postpend
./runPlots $input/ttbar_madgraph_2l.root ttbar2lDilepton_2Leptons$lepton.root 2 2 1 2 $postpend

endif 

./runPlots $input/MuEl.root dataDilepton_2LeptonsMuEl.root 2 0 1 2 $postpend
./runPlots $input/Wjets.root WjetsDilepton_2LeptonsMuEl.root 2 0 1 2 $postpend
./runPlots $input/others.root othersDilepton_2LeptonsMuEl.root 2 0 1 2 $postpend
./runPlots $input/ttbar_madgraph_1l.root ttbar1lDilepton_2LeptonsMuEl.root 2 1 1 2 $postpend
./runPlots $input/ttbar_madgraph_2l.root ttbar2lDilepton_2LeptonsMuEl.root 2 2 1 2 $postpend
