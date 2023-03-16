# RocketSimulator

[![C/C++ CI](https://github.com/Rubber-Duck-999/RocketSimulator/actions/workflows/c-cpp.yml/badge.svg?branch=master)](https://github.com/Rubber-Duck-999/RocketSimulator/actions/workflows/c-cpp.yml)

Repository for the Rocket Simulator Software, it consists of a program that generates a simulation of a 2D Rocket. 
Architecture will be included and all components will be partitioned correctly

## Design & Documents

[Documents](./Documents/README.md)



## How To use

This executable is built using CMake, Make and G++.

One executable made up of a few C++ Libraries:
  - Form - Qt Form
  - 2DMap - Terrain creator
  - Controller - Manages what processes are called
  - Flight Algorithm - Calculates route based off data without terrain
  - Land algorithm - Algorithm to calculate point of intercept and landing
  - Simulator - Allegro game 

All components will have interface designs and the data structures will be predefined to allow correct and suitable design.

I am using Googletest framework, stubs for the socket interfaces to help separate testing. Valgrind to check for memory leaks.

## Demo

![Simulation](./Documents/Simulation.gif)
