# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build

# Include any dependencies generated for this target.
include CMakeFiles/Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Algorithm.dir/flags.make

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o: CMakeFiles/Algorithm.dir/flags.make
CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o: ../src/Interface_set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o -c /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/src/Interface_set.cpp

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Algorithm.dir/src/Interface_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/src/Interface_set.cpp > CMakeFiles/Algorithm.dir/src/Interface_set.cpp.i

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Algorithm.dir/src/Interface_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/src/Interface_set.cpp -o CMakeFiles/Algorithm.dir/src/Interface_set.cpp.s

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.requires:

.PHONY : CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.requires

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.provides: CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.requires
	$(MAKE) -f CMakeFiles/Algorithm.dir/build.make CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.provides.build
.PHONY : CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.provides

CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.provides.build: CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o


# Object files for target Algorithm
Algorithm_OBJECTS = \
"CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o"

# External object files for target Algorithm
Algorithm_EXTERNAL_OBJECTS =

libAlgorithm.a: CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o
libAlgorithm.a: CMakeFiles/Algorithm.dir/build.make
libAlgorithm.a: CMakeFiles/Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libAlgorithm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Algorithm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Algorithm.dir/build: libAlgorithm.a

.PHONY : CMakeFiles/Algorithm.dir/build

CMakeFiles/Algorithm.dir/requires: CMakeFiles/Algorithm.dir/src/Interface_set.cpp.o.requires

.PHONY : CMakeFiles/Algorithm.dir/requires

CMakeFiles/Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Algorithm.dir/clean

CMakeFiles/Algorithm.dir/depend:
	cd /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build /mnt/c/Users/simon/Documents/Projects/RocketSimulator/Algorithm/build/CMakeFiles/Algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Algorithm.dir/depend

