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
    echo "##### 2DMap                           #"
    echo "##############################################"
    cd $home_wd/2DMap

    mkdir build
    cd build

    cmake ..

    make

    #./exe2DMap-Test

    echo "##############################################"
    echo "##############################################"
    ### Algo
    echo "##############################################"
    echo "##### Algorithm                              #"
    echo "##############################################"
    cd $home_wd/Algorithm

    mkdir build
    cd build

    cmake ..

    make

    #./exeAlgorithm-Test

    echo "##############################################"
    echo "##############################################"
    ### Graphics
    echo
    echo "##############################################"
    echo "##### Graphics                               #"
    echo "##############################################"
    cd  $home_wd/Graphics

    mkdir build
    cd build

    cmake ..

    make

    #./exeSimulation-Test
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

    #./exeController-Test
    echo "##############################################"
    echo "##############################################"
fi