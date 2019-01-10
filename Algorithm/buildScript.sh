#!/bin/bash
echo "## Building of the GCOV_CPPUNIT Project work ##"
echo "## "

echo "## Calling setEnv.sh"
. $PROJECTS/scripts/setEnv.sh

if [ ! $setCorrectly ]; 
then
    echo "## Environment has not been set correctly"
	echo "## Exiting Script"
	exit
fi

export PROJECT=$CPP/RocketSimulator/Algorithm
echo "## PROJECT is " $PROJECT

export LOGS=$PROJECT/LOGS
echo "## LOGS is " $LOGS
if [ ! -e $LOGS ];
then
	mkdir $LOGS
fi

cd $PROJECT
echo "## Changing directory to $PROJECT"

cd $PROJECT/build

cmake ..

make

. $PROJECT/build/exeAlgorithm
