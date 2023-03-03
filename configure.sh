#!/bin/bash

apt-get update

apt-get install libboost-all-dev

apt-get install cppcheck

git clone https://github.com/google/googletest.git -b v1.13.0
cd googletest
# Main directory of the cloned repository.
mkdir build

# Create a directory to hold the build output.
cd build
cmake ..
# Generate native build scripts for GoogleTest.

make
make install

apt install liballegro5-dev