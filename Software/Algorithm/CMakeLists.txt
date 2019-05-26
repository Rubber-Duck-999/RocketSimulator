cmake_minimum_required (VERSION 2.8)

# Change project name
set (PROJECT_NAME Algorithm)
set (PROJECT_TEST_NAME test${PROJECT_NAME})

project (${PROJECT_NAME} C CXX)

set(Boost_USE_STATIC_LIBS ON)
#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
# Boost::log required Boost version >= 1.54.0 
find_package(Boost 1.54.0 REQUIRED COMPONENTS log)
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
                    ${PROJECT_SOURCE_DIR}/${INCL_DIR})

link_directories(${Boost_LIBRARY_DIRS})
link_directories(/usr/local/lib)
# Important: Include all source files on this list
set (SOURCE
    ${SRC_DIR}/rocket.cc
    ${SRC_DIR}/thrust.cc
    ${SRC_DIR}/world.cc
	${SRC_DIR}/algorithm.cc
)

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# Add the executable for the program
add_library(${PROJECT_NAME} STATIC ${SOURCE})
# Unit tests
#add_subdirectory(tests)

# Code coverage
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    set(COVERAGE_EXCLUDES
		'/usr/*'
		'${PROJECT_SOURCE_DIR}/tests/*'
		'${CMAKE_BINARY_DIR}/googletest-src/googletest/include/gtest/*'
		'${CMAKE_BINARY_DIR}/googletest-src/googletest/src/*'
		'${CMAKE_BINARY_DIR}/googletest-src/googlemock/include/gmock/*'
		'${CMAKE_BINARY_DIR}/googletest-src/googlemock/src/*'
    )
    SETUP_TARGET_FOR_COVERAGE(
		NAME coverage
		EXECUTABLE ${PROJECT_TEST_NAME}
		DEPENDENCIES ${PROJECT_NAME}
    )
	set_target_properties(${PROJECT_NAME}
        PROPERTIES
        COMPILE_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage"
    )
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"


