#!/bin/csh 

# Check if we have the current directory in the library paths
# and add it if not.

# (I'd be glad if somebody have a solution that doesn't involve
# a dictionnary just so that root knows about vector<TLorentzVector> ...)

#set TEST =`echo $LD_LIBRARY_PATH | grep $PWD`

#if ( $TEST == "") then
setenv LD_LIBRARY_PATH /afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_7_STOP/lib/slc5_amd64_gcc462:/afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_7_STOP/external/slc5_amd64_gcc462/lib:/afs/cern.ch/cms/slc5_amd64_gcc462/cms/cmssw-patch/CMSSW_5_3_7_patch4/lib/slc5_amd64_gcc462:/afs/cern.ch/cms/slc5_amd64_gcc462/cms/cmssw-patch/CMSSW_5_3_7_patch4/external/slc5_amd64_gcc462/lib:/afs/cern.ch/cms/slc5_amd64_gcc462/cms/cmssw/CMSSW_5_3_7/lib/slc5_amd64_gcc462:/afs/cern.ch/cms/slc5_amd64_gcc462/external/gcc/4.6.2/lib64:/afs/cern.ch/cms/slc5_amd64_gcc462/external/gcc/4.6.2/lib:/afs/cern.ch/work/s/sigamani/public/CMSSW_5_3_7_STOP/src/babyReaderSTOPS/runAnalysis
cmsenv
#    setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH\:$PWD
#endif
