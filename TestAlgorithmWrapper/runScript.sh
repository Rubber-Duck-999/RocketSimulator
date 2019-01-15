#!/bin/bash
echo "## Building of the project work ##"
echo "## "

echo "## Calling setEnv.sh"
. $PROJECT/scripts/setEnv.sh

if [ ! $setCorrectly ]; 
then
    echo "## Environment has not been set correctly"
	echo "## Exiting Script"
	exit
fi

export COMPONENT=$PROJECT/Console
echo "## PROJECT is " $COMPONENT

cd $COMPONENT
echo "## Changing directory to $PROJECT"

python Console.py