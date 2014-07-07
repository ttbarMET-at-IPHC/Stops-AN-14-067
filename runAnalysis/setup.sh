#!/bin/bash 

# Check if we have the current directory in the library paths
# and add it if not.

TEST=`echo $LD_LIBRARY_PATH | grep $PWD`
if [[ "$TEST" == "" ]]
then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
fi
