###############################################################################
### CSharp Functions
###############################################################################
cSharpClean()
{
  echo "Cleaning $projectName project" 
  rm -rf $PROJECTS/build/
}


cSharpCompile()
{
  echo "Compiling $PROJECT project" 
  printOut "Compiling ------->"
  mkdir $PROJECTS/build/
  cd $PROJECTS/src/
  mcs /optimize *.cs /out:$PROJECTS/build/$EXE
  echo "Finished Compiling"
}


cSharpExe()
{
  echo "Running $projectName project" 
  if [ ! -f "$PROJECTS/build/$EXE" ]; 
  then
	printOut "Exe File doesn't exist"
  else
    cd $PROJECTS/build
	echo "Calling Exe"
	./$EXE
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

export PROJECT=$CPP/RocketSimulator/Graphics
export EXE=Sockets.exe
echo "## PROJECT is " $PROJECT

export LOGS=$PROJECT/LOGS
echo "## LOGS is " $LOGS
if [ ! -e $LOGS ];
then
	mkdir $LOGS
fi

cd $PROJECT
echo "## Changing directory to $PROJECT"

CSharpClean
CSharpCompile
CSharpExe