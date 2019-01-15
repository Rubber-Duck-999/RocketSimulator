#!/bin/bash
#Calls cpplint.py
echo "## Cpplint.py Run - Static Analysis ##"
echo "## "

echo "## Calling setEnv.sh"
. $PROJECTS/scripts/setEnv.sh


if [ ! $setCorrectly ]; 
then
    echo "## Environment has not been set correctly"
	echo "## Exiting Script"
	exit
fi

projectArea=$1
echo "## The project area used is = " $projectArea
LOG=$2
echo "## The log file used is = " $LOG

python $CPPLINT/cpplint.py $projectArea/*.cpp $projectArea/*.h > $LOG 2>&1
 
