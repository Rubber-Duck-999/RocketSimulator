# RocketSimulator
Repository for the Rocket Simulator Software, it consists of multiple applications communicating over Sockets. 
Architecture will be included and all components will be partitioned correctly

Component based architecture

5 separate components as of initial design structure
  - Console - Python PySimpleGUI
  - 2DMap - Terrain creator
  - Controller - C++
  - Algorithm - C++
  - Simulator - Algorithm to calculate point of intercept and landing
All components will have interface designs and the data structures will be predefined to allow correct and suitable design.

I am using Googletest framework, stubs for the socket interfaces to help separate testing. Valgrind to check for memory leaks.


