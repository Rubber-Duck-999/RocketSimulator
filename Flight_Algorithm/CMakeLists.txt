cmake_minimum_required (VERSION 3.22)

# Change project name
set (PROJECT_NAME Flight_Algorithm)
set (PROJECT_TEST_NAME exe${PROJECT_NAME}-Test)

project (${PROJECT_NAME} C CXX)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.54.0 REQUIRED COMPONENTS log  log_setup)
find_package(Threads)


# Folder where the Coverage module is
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Source files folder
set (SRC_DIR src)

# Header files folder
set (INCL_DIR include)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

include_directories(${Boost_INCLUDE_DIRS}
                    ${SRC_DIR}/../../common
                    ${SRC_DIR}/../${INCL_DIR})

link_directories(${Boost_LIBRARY_DIRS})
link_directories(/usr/local/lib)
# Important: Include all source files on this list
set (SOURCE
    ${SRC_DIR}/rocket.cc
    ${SRC_DIR}/thrust.cc
    ${SRC_DIR}/world.cc
	${SRC_DIR}/flight_algorithm.cc
)

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

# Add the executable for the program
add_library(${PROJECT_NAME} STATIC ${SOURCE})
# Unit tests
#add_subdirectory(tests)
