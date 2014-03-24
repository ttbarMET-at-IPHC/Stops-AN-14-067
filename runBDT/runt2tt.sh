#!/bin/csh


if ($argv[1] == 0) then

cd Reg1_T2tt/ 
python ../makeconfigs.py

cd ../Reg2_T2tt/ 
python ../makeconfigs.py

cd ../Reg3_T2tt/ 
python ../makeconfigs.py


cd ..

else   

cd Reg1_T2tt/ 
rm -rf JM*
source ../make.sh

cd ../Reg2_T2tt/
rm -rf JM*
source ../make.sh

cd ../Reg3_T2tt/
rm -rf JM*
source ../make.sh

cd ..

endif
