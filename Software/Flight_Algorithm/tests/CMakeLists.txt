cmake_minimum_required(VERSION 2.8)
set (PROJECT_TEST_NAME ${PROJECT_TEST_NAME})

enable_testing()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests/googletest-download" )
# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# Test folder
set (TESTS_DIR tests)
# Header files folder
set (INCL_DIR include)
set (MOCKS_DIR mocks)
include_directories (${PROJECT_SOURCE_DIR}/${TESTS_DIR}/${INCL_DIR})
include_directories (${PROJECT_SOURCE_DIR}/${TESTS_DIR}/${INCL_DIR}/${MOCKS_DIR})

set (SRC_DIR src)
set(PROY_UT_SRC
    ${SRC_DIR}/TestAlgorithmWrapper.cpp
)

set (MAIN_SRC_DIR ../src)
include_directories (${PROJECT_SOURCE_DIR}/${INCL_DIR})
# Include all project source files here
set (MAIN_SOURCE
    ${MAIN_SRC_DIR}/rocket.cc
    ${MAIN_SRC_DIR}/thrust.cc
    ${MAIN_SRC_DIR}/world.cc
    ${MAIN_SRC_DIR}/flight_algorithm.cc
)

add_executable (${PROJECT_TEST_NAME} ${PROY_UT_SRC} ${MAIN_SOURCE})

set_target_properties(${PROJECT_TEST_NAME}
                      PROPERTIES
                      COMPILE_FLAGS "-std=c++17 -Wall"
)
# Link libraries
target_link_libraries(${PROJECT_TEST_NAME}
                      gtest
                      gmock_main
                      ${Boost_LIBRARIES} 
                      pthread
                      Threads::Threads)
