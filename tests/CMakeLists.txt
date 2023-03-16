cmake_minimum_required(VERSION 3.22)
set (PROJECT_TEST_NAME ${PROJECT_NAME}-Test)

enable_testing()

# Test folder
set (TESTS_DIR tests)
# Header files folder
set (INCL_DIR include)
set (MOCKS_DIR mocks)
include_directories (${PROJECT_SOURCE_DIR}/${TESTS_DIR}/${INCL_DIR})
include_directories (${PROJECT_SOURCE_DIR}/${TESTS_DIR}/${INCL_DIR}/${MOCKS_DIR})


set (SRC_DIR src)
set(PROY_UT_SRC
    ${SRC_DIR}/TestInterface.cc
)

set (MAIN_SRC_DIR ../src)
include_directories (${PROJECT_SOURCE_DIR}/${INCL_DIR})
# Include all project source files here
set (MAIN_SOURCE
    ${MAIN_SRC_DIR}/interface.cc)

add_executable (${PROJECT_TEST_NAME} ${PROY_UT_SRC} ${MAIN_SOURCE})

set_target_properties(${PROJECT_TEST_NAME}
                      PROPERTIES
                      COMPILE_FLAGS "-std=c++17 -Wall"
)

link_directories(/usr/local/lib "../Land_Algorithm/build/" 
"../Flight_Algorithm/build"
"../2DMap/build")

# Link libraries
target_link_libraries(${PROJECT_TEST_NAME}
                      gtest
                      gmock_main
                      Land_Algorithm
                      Flight_Algorithm
                      2DMap
                      ${Boost_LIBRARIES} 
                      pthread
                      Threads::Threads)

