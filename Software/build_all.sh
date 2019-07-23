#!/bin/bash

export home_wd=$PROJECTS/RocketSimulator/Software
echo "$home_wd"
cd "$home_wd"
### Algo
echo "##############################################"
echo "##### Algorithm                              #"
echo "##############################################"
cd "$home_wd"/Algorithm

mkdir build
cd build

cmake ..

make

./exeAlgorithm-Test

echo "##############################################"
echo "##############################################"
### Controller
echo
echo "##############################################"
echo "##### Controller                             #"
echo "##############################################"

cd "$home_wd"/Controller

mkdir build
cd build

cmake ..

make

./exeController-Test
echo "##############################################"
echo "##############################################"
### Simulation
echo
echo "##############################################"
echo "##### Simulation                             #"
echo "##############################################"
cd "$home_wd"/Simulation

mkdir build
cd build

cmake ..

make

./exeSimulation-Test
echo "##############################################"
echo "##############################################"