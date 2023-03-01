cmake_minimum_required (VERSION 3.22)

# Change project name
set (PROJECT_NAME Game)

project (${PROJECT_NAME} C CXX)

find_package(PkgConfig REQUIRED)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Source files folder
set (SRC_DIR src)

# Header files folder
set (INCL_DIR include)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -lallegro -lallegro_font -lallegro_primitives -lallegro_ttf")

set (SOURCE
    ${SRC_DIR}/config.cpp
    ${SRC_DIR}/engine.cpp
    ${SRC_DIR}/init.cpp
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/objects.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/${INCL_DIR})

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

# Add the executable for the program
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME})
