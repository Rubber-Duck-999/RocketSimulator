#!/bin/bash
#This Shell script will
#check folder and enviornment variables

if [ -e $PROJECTS ];
then
	echo "## Projects is = " $PROJECTS
else
	echo "## Projects has not been set \n"
	echo "## Please set this in the .bashrc file"
	exit
fi

export setCorrectly=true

export CPPLINT=$PROJECTS/Python/StyleChecker/cpplint

if [ -e $CPPLINT ];
then
	echo "## CPPLINT folder does exist"
	export CPPLINT=$PROJECTS/Python/StyleChecker/cpplint
	if [ -f $CPPLINT/cpplint.py ];
	then
		echo "## CPPLINT py does exist"
	else
		echo "## CPPLINT py does not exist"
		export setCorrectly=false
	fi
else
	echo "## CPPLINT folder does not exist"
	export setCorrectly=false
fi

export LOGS=$PROJECT/LOGS
echo "## LOGS is " $LOGS
if [ ! -e $LOGS ];
then
	mkdir $LOGS
fi

export SCRIPTS=$PROJECTS/scripts
