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
CMAKE_SOURCE_DIR = /home/jayson/networkcpp_update/networkcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jayson/networkcpp_update/networkcpp/build

# Include any dependencies generated for this target.
include CMakeFiles/udp_client_protobuf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_client_protobuf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_client_protobuf.dir/flags.make

CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o: CMakeFiles/udp_client_protobuf.dir/flags.make
CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o: ../src/udp_client_protobuf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jayson/networkcpp_update/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o -c /home/jayson/networkcpp_update/networkcpp/src/udp_client_protobuf.cpp

CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jayson/networkcpp_update/networkcpp/src/udp_client_protobuf.cpp > CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.i

CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jayson/networkcpp_update/networkcpp/src/udp_client_protobuf.cpp -o CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.s

CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o: CMakeFiles/udp_client_protobuf.dir/flags.make
CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o: ../protobuf/awesomedata.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jayson/networkcpp_update/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o -c /home/jayson/networkcpp_update/networkcpp/protobuf/awesomedata.pb.cc

CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jayson/networkcpp_update/networkcpp/protobuf/awesomedata.pb.cc > CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.i

CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jayson/networkcpp_update/networkcpp/protobuf/awesomedata.pb.cc -o CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.s

# Object files for target udp_client_protobuf
udp_client_protobuf_OBJECTS = \
"CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o" \
"CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o"

# External object files for target udp_client_protobuf
udp_client_protobuf_EXTERNAL_OBJECTS =

udp_client_protobuf: CMakeFiles/udp_client_protobuf.dir/src/udp_client_protobuf.cpp.o
udp_client_protobuf: CMakeFiles/udp_client_protobuf.dir/protobuf/awesomedata.pb.cc.o
udp_client_protobuf: CMakeFiles/udp_client_protobuf.dir/build.make
udp_client_protobuf: CMakeFiles/udp_client_protobuf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jayson/networkcpp_update/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable udp_client_protobuf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_client_protobuf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_client_protobuf.dir/build: udp_client_protobuf

.PHONY : CMakeFiles/udp_client_protobuf.dir/build

CMakeFiles/udp_client_protobuf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_client_protobuf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_client_protobuf.dir/clean

CMakeFiles/udp_client_protobuf.dir/depend:
	cd /home/jayson/networkcpp_update/networkcpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jayson/networkcpp_update/networkcpp /home/jayson/networkcpp_update/networkcpp /home/jayson/networkcpp_update/networkcpp/build /home/jayson/networkcpp_update/networkcpp/build /home/jayson/networkcpp_update/networkcpp/build/CMakeFiles/udp_client_protobuf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_client_protobuf.dir/depend

