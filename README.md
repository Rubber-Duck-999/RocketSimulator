# RocketSimulator

[![C/C++ CI](https://github.com/Rubber-Duck-999/RocketSimulator/actions/workflows/c-cpp.yml/badge.svg?branch=master)](https://github.com/Rubber-Duck-999/RocketSimulator/actions/workflows/c-cpp.yml)

Repository for the Rocket Simulator Software, it consists of multiple applications communicating over Sockets. 
Architecture will be included and all components will be partitioned correctly

Component based architecture

5 separate components as of initial design structure
  - Console - Python PySimpleGUI data entry
  - 2DMap - Terrain creator C++
  - Controller - Manages what processes are called C++
  - Flight Algorithm - Calculates route based off data without terrain C++
  - Land algorithm - Algorithm to calculate point of intercept and landing C++
  - Simulator - Pygame draws diagram of rocket

All components will have interface designs and the data structures will be predefined to allow correct and suitable design.

I am using Googletest framework, stubs for the socket interfaces to help separate testing. Valgrind to check for memory leaks.


