cmake_minimum_required(VERSION 3.10)
project(Controller)

set ( PROJECT_LINK_LIBS libAlgorithm.so )
link_directories( $ENV{LIB}/build )

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

include_directories($ENV{LIB}/include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(exeController ${SOURCES})
