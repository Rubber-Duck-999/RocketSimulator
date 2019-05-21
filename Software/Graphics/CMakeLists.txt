cmake_minimum_required (VERSION 2.8)

# Change project name
set (PROJECT_NAME Graphics)

project (${PROJECT_NAME} C CXX)

# Folder where the Coverage module is
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Source files folder
set (SRC_DIR src)

# Header files folder
set (INCL_DIR include)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

include_directories(${SRC_DIR}/../../common ${PROJECT_SOURCE_DIR}/${INCL_DIR})

# Important: Include all source files on this list
set (SOURCE
    ${SRC_DIR}/Graphics.cpp
)

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# Add the executable for the program
add_executable(exe${PROJECT_NAME} ${SOURCE})
# Unit tests

target_link_libraries(exeGraphics glut GLU GL)


