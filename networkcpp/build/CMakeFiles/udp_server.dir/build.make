# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jayson/networkcpp/networkcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jayson/networkcpp/networkcpp/build

# Include any dependencies generated for this target.
include CMakeFiles/udp_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_server.dir/flags.make

CMakeFiles/udp_server.dir/src/udp_server.cpp.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/src/udp_server.cpp.o: ../src/udp_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jayson/networkcpp/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udp_server.dir/src/udp_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_server.dir/src/udp_server.cpp.o -c /home/jayson/networkcpp/networkcpp/src/udp_server.cpp

CMakeFiles/udp_server.dir/src/udp_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_server.dir/src/udp_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jayson/networkcpp/networkcpp/src/udp_server.cpp > CMakeFiles/udp_server.dir/src/udp_server.cpp.i

CMakeFiles/udp_server.dir/src/udp_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_server.dir/src/udp_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jayson/networkcpp/networkcpp/src/udp_server.cpp -o CMakeFiles/udp_server.dir/src/udp_server.cpp.s

# Object files for target udp_server
udp_server_OBJECTS = \
"CMakeFiles/udp_server.dir/src/udp_server.cpp.o"

# External object files for target udp_server
udp_server_EXTERNAL_OBJECTS =

udp_server: CMakeFiles/udp_server.dir/src/udp_server.cpp.o
udp_server: CMakeFiles/udp_server.dir/build.make
udp_server: CMakeFiles/udp_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jayson/networkcpp/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable udp_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_server.dir/build: udp_server

.PHONY : CMakeFiles/udp_server.dir/build

CMakeFiles/udp_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_server.dir/clean

CMakeFiles/udp_server.dir/depend:
	cd /home/jayson/networkcpp/networkcpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jayson/networkcpp/networkcpp /home/jayson/networkcpp/networkcpp /home/jayson/networkcpp/networkcpp/build /home/jayson/networkcpp/networkcpp/build /home/jayson/networkcpp/networkcpp/build/CMakeFiles/udp_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_server.dir/depend

