cmake_minimum_required(VERSION 3.10)
project(TestAlgorithmWrapper)


include_directories("../Algorithm/include",
                    "./../common",
                    ./include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./src/main.cpp")

add_executable(exeTestAlgorithmWrapper ${SOURCES})
