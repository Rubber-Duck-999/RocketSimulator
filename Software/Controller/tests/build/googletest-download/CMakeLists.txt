cmake_minimum_required(VERSION 2.8)
 
project(googletest-download NONE)
 
include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/tests/build/googletest-src"
  BINARY_DIR        "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/tests/build/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
