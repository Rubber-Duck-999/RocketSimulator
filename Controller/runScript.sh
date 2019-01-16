#!/bin/bash
echo "## Building of the project work ##"
echo "## "

echo "## Calling setEnv.sh"
. $PROJECTS/scripts/setEnv.sh

if [ ! $setCorrectly ]; 
then
    echo "## Environment has not been set correctly"
	echo "## Exiting Script"
	exit
fi

export COMPONENT=$PROJECT/Controller
echo "## PROJECT is " $COMPONENT
. $COMPONENT/build/exeController