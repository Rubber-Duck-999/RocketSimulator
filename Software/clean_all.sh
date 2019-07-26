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
    ### Algo
    echo "##############################################"
    echo "##### Algorithm                              #"
    echo "##############################################"
    cd $home_wd/Algorithm

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
    ### Simulation
    echo
    echo "##############################################"
    echo "##### Simulation                             #"
    echo "##############################################"
    cd  $home_wd/Simulation

    rm -rf build
    echo "##############################################"
    echo "##############################################"
fi