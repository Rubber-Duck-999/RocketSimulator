cmake_minimum_required(VERSION 3.10)
project(TestAlgorithmWrapper)

#For the static library:
set ( PROJECT_LINK_LIBS libAlgorithm.a )
link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../Algorithm/build )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Algorithm/include",
                    ${CMAKE_CURRENT_SOURCE_DIR}/../common",
                    ${CMAKE_CURRENT_SOURCE_DIR}/include)

#However, the file(GLOB...) allows for wildcard additions:
#file(SOURCES "./src/main.cpp")

add_executable(exeTestAlgorithmWrapper src/main.cpp)
target_link_libraries(exeTestAlgorithmWrapper ${PROJECT_LINK_LIBS} )