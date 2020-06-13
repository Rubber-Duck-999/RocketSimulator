#!/bin/bash

if [ $1 == "Azure" ];
then
    home_wd="$PWD"
fi

if [ ! -z $PROJECTS ];
then
    current=$PROJECTS
    export home_wd=$current/RocketSimulator/Software
fi
if [ ! -z $CPP ];
then
    current=$CPP
    export home_wd=$current/RocketSimulator/Software
fi
echo $current
ps -$$

if [ -d $home_wd ];
then
    echo  $home_wd
    cd  $home_wd
    ### 2DMap
    echo "##############################################"
    echo "##### 2DMap                           #"
    echo "##############################################"
    cd $home_wd/2DMap

    mkdir build
    cd build

    cmake ..

    make

    ./exe2DMap-Test

    echo "##############################################"
    echo "##############################################"
    ### Flight Algo
    echo "##############################################"
    echo "##### Flight_Algorithm                       #"
    echo "##############################################"
    cd $home_wd/Flight_Algorithm

    mkdir build
    cd build

    cmake ..

    make

    ./exeFlight_Algorithm-Test

    echo "##############################################"
    echo "##############################################"
    ### Land Algorithm
    echo
    echo "##############################################"
    echo "##### Land Algorithm                            #"
    echo "##############################################"
    cd  $home_wd/Land_Algorithm

    mkdir build
    cd build

    cmake ..

    make

    ./exeLand_Algorithm-Test
    echo "##############################################"
    echo "##############################################"
    ### Controller
    echo
    echo "##############################################"
    echo "##### Controller                             #"
    echo "##############################################"
    cd  $home_wd/Controller

    mkdir build
    cd build

    cmake ..

    make

    ./exeController-Test
    echo "##############################################"
    echo "##############################################"
fi