Instructions
============

To check-out: git clone git@github.com:sigamani/Stops-AN-14-067.git 


1) cd runPlots, then in a ROOT session do: 

root [0] .L dataMC.C 

root [1] makeAllPlots()

Maybe add 'gROOT->ProcessLine("setTDRStyle.C");' in .rootlogon.C
