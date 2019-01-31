cmake_minimum_required(VERSION 3.10)
project(Algorithm)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers, such as Student.h into the project
include_directories("./Alogrithm/include")

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./Algorithm/src/Interface.cpp")

#Generate the shared library from the sources
add_library(Algorithm SHARED ${SOURCES})
