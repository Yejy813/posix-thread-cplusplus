# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/willy/myshare/thread-pool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/willy/myshare/thread-pool/build

# Include any dependencies generated for this target.
include 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../3rdlib/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/willy/myshare/thread-pool/3rdlib/googletest/googletest/src/gtest-all.cc

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/willy/myshare/thread-pool/3rdlib/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/willy/myshare/thread-pool/3rdlib/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../lib/libgtest.a"
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires: 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean

3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/willy/myshare/thread-pool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/willy/myshare/thread-pool /home/willy/myshare/thread-pool/3rdlib/googletest/googletest /home/willy/myshare/thread-pool/build /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest /home/willy/myshare/thread-pool/build/3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdlib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend
