cmake_minimum_required(VERSION 3.10)
project(TestAlgorithmWrapper)

set ( PROJECT_LINK_LIBS libAlgorithm.so )
#link_directories( ./Algorithm/build )


include_directories("./../common",
                    "../Algorithm/include",
                    ./include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/main.cpp")

add_executable(exeTestAlgorithmWrapper ${SOURCES})
