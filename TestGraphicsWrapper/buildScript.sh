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
    cd $COMPONENT/dist
	echo "Calling Jar"
	java -jar *.jar
  fi   
}
###############################################################################


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

export COMPONENT=$PROJECT/Graphics
echo "## COMPONENT is " $COMPONENT

cd $COMPONENT
echo "## Changing directory to $PROJECT"

clean
compile
antJar









