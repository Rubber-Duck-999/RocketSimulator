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
CMAKE_SOURCE_DIR = "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build"

# Include any dependencies generated for this target.
include CMakeFiles/Controller.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Controller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Controller.dir/flags.make

CMakeFiles/Controller.dir/src/Main.cpp.o: CMakeFiles/Controller.dir/flags.make
CMakeFiles/Controller.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Controller.dir/src/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/src/Main.cpp.o -c "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Main.cpp"

CMakeFiles/Controller.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Main.cpp" > CMakeFiles/Controller.dir/src/Main.cpp.i

CMakeFiles/Controller.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Main.cpp" -o CMakeFiles/Controller.dir/src/Main.cpp.s

CMakeFiles/Controller.dir/src/Main.cpp.o.requires:

.PHONY : CMakeFiles/Controller.dir/src/Main.cpp.o.requires

CMakeFiles/Controller.dir/src/Main.cpp.o.provides: CMakeFiles/Controller.dir/src/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Controller.dir/build.make CMakeFiles/Controller.dir/src/Main.cpp.o.provides.build
.PHONY : CMakeFiles/Controller.dir/src/Main.cpp.o.provides

CMakeFiles/Controller.dir/src/Main.cpp.o.provides.build: CMakeFiles/Controller.dir/src/Main.cpp.o


CMakeFiles/Controller.dir/src/Socket.cpp.o: CMakeFiles/Controller.dir/flags.make
CMakeFiles/Controller.dir/src/Socket.cpp.o: ../src/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Controller.dir/src/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/src/Socket.cpp.o -c "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Socket.cpp"

CMakeFiles/Controller.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/src/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Socket.cpp" > CMakeFiles/Controller.dir/src/Socket.cpp.i

CMakeFiles/Controller.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/src/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Socket.cpp" -o CMakeFiles/Controller.dir/src/Socket.cpp.s

CMakeFiles/Controller.dir/src/Socket.cpp.o.requires:

.PHONY : CMakeFiles/Controller.dir/src/Socket.cpp.o.requires

CMakeFiles/Controller.dir/src/Socket.cpp.o.provides: CMakeFiles/Controller.dir/src/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/Controller.dir/build.make CMakeFiles/Controller.dir/src/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/Controller.dir/src/Socket.cpp.o.provides

CMakeFiles/Controller.dir/src/Socket.cpp.o.provides.build: CMakeFiles/Controller.dir/src/Socket.cpp.o


CMakeFiles/Controller.dir/src/Config_Reader.cpp.o: CMakeFiles/Controller.dir/flags.make
CMakeFiles/Controller.dir/src/Config_Reader.cpp.o: ../src/Config_Reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Controller.dir/src/Config_Reader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Controller.dir/src/Config_Reader.cpp.o -c "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Config_Reader.cpp"

CMakeFiles/Controller.dir/src/Config_Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controller.dir/src/Config_Reader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Config_Reader.cpp" > CMakeFiles/Controller.dir/src/Config_Reader.cpp.i

CMakeFiles/Controller.dir/src/Config_Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controller.dir/src/Config_Reader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/src/Config_Reader.cpp" -o CMakeFiles/Controller.dir/src/Config_Reader.cpp.s

CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.requires:

.PHONY : CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.requires

CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.provides: CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Controller.dir/build.make CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.provides.build
.PHONY : CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.provides

CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.provides.build: CMakeFiles/Controller.dir/src/Config_Reader.cpp.o


# Object files for target Controller
Controller_OBJECTS = \
"CMakeFiles/Controller.dir/src/Main.cpp.o" \
"CMakeFiles/Controller.dir/src/Socket.cpp.o" \
"CMakeFiles/Controller.dir/src/Config_Reader.cpp.o"

# External object files for target Controller
Controller_EXTERNAL_OBJECTS =

../bin/Controller: CMakeFiles/Controller.dir/src/Main.cpp.o
../bin/Controller: CMakeFiles/Controller.dir/src/Socket.cpp.o
../bin/Controller: CMakeFiles/Controller.dir/src/Config_Reader.cpp.o
../bin/Controller: CMakeFiles/Controller.dir/build.make
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_log.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_date_time.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_log_setup.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_system.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_filesystem.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_thread.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_regex.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_chrono.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libboost_atomic.a
../bin/Controller: /usr/lib/x86_64-linux-gnu/libpthread.so
../bin/Controller: CMakeFiles/Controller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/Controller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Controller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Controller.dir/build: ../bin/Controller

.PHONY : CMakeFiles/Controller.dir/build

CMakeFiles/Controller.dir/requires: CMakeFiles/Controller.dir/src/Main.cpp.o.requires
CMakeFiles/Controller.dir/requires: CMakeFiles/Controller.dir/src/Socket.cpp.o.requires
CMakeFiles/Controller.dir/requires: CMakeFiles/Controller.dir/src/Config_Reader.cpp.o.requires

.PHONY : CMakeFiles/Controller.dir/requires

CMakeFiles/Controller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Controller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Controller.dir/clean

CMakeFiles/Controller.dir/depend:
	cd "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller" "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller" "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build" "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build" "/mnt/c/Users/simon/Google Drive/Projects/RocketSimulator/Software/Controller/build/CMakeFiles/Controller.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Controller.dir/depend

