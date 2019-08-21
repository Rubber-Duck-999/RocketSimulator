#!/bin/bash

if [ ! -z $PROJECTS ];
then
    current=$PROJECTS
fi
if [ ! -z $CPP ];
then
    current=$CPP
fi
echo $current
ps -$$
export home_wd=$current/RocketSimulator/Software
if [ -d $home_wd ];
then
    echo  $home_wd
    cd  $home_wd
    ### 2DMap
    echo "##############################################"
    echo "##### 2DMap                                  #"
    echo "##############################################"
    cd $home_wd/2DMap

    rm -rf build

    echo "##############################################"
    echo "##############################################"
    ### Flight Algo
    echo
    echo "##############################################"
    echo "##### Flight_Algorithm                       #"
    echo "##############################################"
    cd $home_wd/Flight_Algorithm

    rm -rf build

    echo "##############################################"
    echo "##############################################"
    ### Controller
    echo
    echo "##############################################"
    echo "##### Controller                             #"
    echo "##############################################"
    cd  $home_wd/Controller

    rm -rf build

    echo "##############################################"
    echo "##############################################"
    ### Land Algorithm
    echo
    echo "##############################################"
    echo "##### Land Algorithm                         #"
    echo "##############################################"
    cd  $home_wd/Land_Algorithm

    rm -rf build
    echo "##############################################"
    echo "##############################################"
fi
