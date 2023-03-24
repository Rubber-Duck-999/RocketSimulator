cmake_minimum_required (VERSION 3.22)

# Change project name
set (PROJECT_NAME Simulator)

project (${PROJECT_NAME} C CXX)

find_package(PkgConfig REQUIRED)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Source files folder
set (SRC_DIR src)

# Header files folder
set (INCL_DIR include)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set (SOURCE
    ${SRC_DIR}/rocket.cc
    ${SRC_DIR}/config.cc
    ${SRC_DIR}/engine.cc
    ${SRC_DIR}/init.cc
)

include_directories(${PROJECT_SOURCE_DIR}/${INCL_DIR})

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

# Add the executable for the program
add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_link_libraries(${PROJECT_NAME}
                    allegro
                    allegro_font
                    allegro_primitives
                    allegro_ttf
                    allegro_image)
