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
include CMakeFiles/tcp_client_multi_protobuf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tcp_client_multi_protobuf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tcp_client_multi_protobuf.dir/flags.make

CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o: CMakeFiles/tcp_client_multi_protobuf.dir/flags.make
CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o: ../src/tcp_client_multi_protobuf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jayson/networkcpp/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o -c /home/jayson/networkcpp/networkcpp/src/tcp_client_multi_protobuf.cpp

CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jayson/networkcpp/networkcpp/src/tcp_client_multi_protobuf.cpp > CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.i

CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jayson/networkcpp/networkcpp/src/tcp_client_multi_protobuf.cpp -o CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.s

CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o: CMakeFiles/tcp_client_multi_protobuf.dir/flags.make
CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o: ../protobuf/awesomedata.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jayson/networkcpp/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o -c /home/jayson/networkcpp/networkcpp/protobuf/awesomedata.pb.cc

CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jayson/networkcpp/networkcpp/protobuf/awesomedata.pb.cc > CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.i

CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jayson/networkcpp/networkcpp/protobuf/awesomedata.pb.cc -o CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.s

# Object files for target tcp_client_multi_protobuf
tcp_client_multi_protobuf_OBJECTS = \
"CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o" \
"CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o"

# External object files for target tcp_client_multi_protobuf
tcp_client_multi_protobuf_EXTERNAL_OBJECTS =

tcp_client_multi_protobuf: CMakeFiles/tcp_client_multi_protobuf.dir/src/tcp_client_multi_protobuf.cpp.o
tcp_client_multi_protobuf: CMakeFiles/tcp_client_multi_protobuf.dir/protobuf/awesomedata.pb.cc.o
tcp_client_multi_protobuf: CMakeFiles/tcp_client_multi_protobuf.dir/build.make
tcp_client_multi_protobuf: CMakeFiles/tcp_client_multi_protobuf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jayson/networkcpp/networkcpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tcp_client_multi_protobuf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp_client_multi_protobuf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tcp_client_multi_protobuf.dir/build: tcp_client_multi_protobuf

.PHONY : CMakeFiles/tcp_client_multi_protobuf.dir/build

CMakeFiles/tcp_client_multi_protobuf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tcp_client_multi_protobuf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tcp_client_multi_protobuf.dir/clean

CMakeFiles/tcp_client_multi_protobuf.dir/depend:
	cd /home/jayson/networkcpp/networkcpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jayson/networkcpp/networkcpp /home/jayson/networkcpp/networkcpp /home/jayson/networkcpp/networkcpp/build /home/jayson/networkcpp/networkcpp/build /home/jayson/networkcpp/networkcpp/build/CMakeFiles/tcp_client_multi_protobuf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tcp_client_multi_protobuf.dir/depend

