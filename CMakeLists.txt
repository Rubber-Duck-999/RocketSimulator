cmake_minimum_required (VERSION 3.22)

# Change project name
set (PROJECT_NAME exeController)
set (PROJECT_TEST_NAME exeTestController)

project (${PROJECT_NAME} C CXX)

add_subdirectory(2DMap)
add_subdirectory(Flight_Algorithm)
add_subdirectory(Land_Algorithm)
add_subdirectory(Simulator)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.74.0 REQUIRED COMPONENTS log log_setup)
find_package(Threads)

# Folder where the Coverage module is
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Source files folder
set (SRC_DIR src)

# Header files folder
set (INCL_DIR include)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -Wall")

include_directories(${Boost_INCLUDE_DIRS} 
                    "common" 
                    "2DMap/include"
                    "Simulator/include"
                    ${INCL_DIR}
                    "Land_Algorithm/include",
                    "Flight_Algorithm/include")
                    
link_directories(${Boost_LIBRARY_DIRS})
# Important: Include all source files on this list
set (SOURCE
    ${SRC_DIR}/main.cc
    common/socket.cc
    common/start_up_process.cc
    ${SRC_DIR}/interface.cc
)

link_directories(/usr/local/lib "Simulator/build" "Flight_Algorithm/build/" "2DMap/build" "Land_Algorithm/build")

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

# Add the executable for the program
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
                       Flight_Algorithm
                       Land_Algorithm
                       Simulator
                       2DMap
                       ${Boost_LIBRARIES} 
                       pthread
                       Threads::Threads)
# Unit tests
add_subdirectory(tests)
