#!/bin/bash
###############################################################################
### Ant Functions
###############################################################################
antClean()
{
  echo "Cleaning $projectName project" 
  ant clean
}


antCompile()
{
  echo "Compiling $projectName project" 
  ant compile
}


antJar()
{
  echo "Creating $projectName jar project" 
  ant jar
}


runJar()
{
  echo "Running $projectName jar project" 
  if [ ! -f "$HOUSE_ALARM/$project/dist/anagrams.jar" ]; then
    echo
    echo "Jar File doesn't exist"
  else
    cd $PROJECT/dist
	echo "Calling Jar"
	java -jar *.jar
  fi   
}
###############################################################################


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

export PROJECT=$CPP/RocketSimulator/Console
echo "## PROJECT is " $PROJECT

export LOGS=$PROJECT/LOGS
echo "## LOGS is " $LOGS
if [ ! -e $LOGS ];
then
	mkdir $LOGS
fi

cd $PROJECT
echo "## Changing directory to $PROJECT"

clean
compile
antJar









