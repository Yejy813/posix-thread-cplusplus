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
include src/CMakeFiles/posixthread.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/posixthread.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/posixthread.dir/flags.make

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o: src/CMakeFiles/posixthread.dir/flags.make
src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o: ../src/CountDownLatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/posixthread.dir/CountDownLatch.cpp.o -c /home/willy/myshare/thread-pool/src/CountDownLatch.cpp

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/posixthread.dir/CountDownLatch.cpp.i"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/willy/myshare/thread-pool/src/CountDownLatch.cpp > CMakeFiles/posixthread.dir/CountDownLatch.cpp.i

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/posixthread.dir/CountDownLatch.cpp.s"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/willy/myshare/thread-pool/src/CountDownLatch.cpp -o CMakeFiles/posixthread.dir/CountDownLatch.cpp.s

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.requires:

.PHONY : src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.requires

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.provides: src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/posixthread.dir/build.make src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.provides.build
.PHONY : src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.provides

src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.provides.build: src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o


src/CMakeFiles/posixthread.dir/posix_port.cpp.o: src/CMakeFiles/posixthread.dir/flags.make
src/CMakeFiles/posixthread.dir/posix_port.cpp.o: ../src/posix_port.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/posixthread.dir/posix_port.cpp.o"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/posixthread.dir/posix_port.cpp.o -c /home/willy/myshare/thread-pool/src/posix_port.cpp

src/CMakeFiles/posixthread.dir/posix_port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/posixthread.dir/posix_port.cpp.i"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/willy/myshare/thread-pool/src/posix_port.cpp > CMakeFiles/posixthread.dir/posix_port.cpp.i

src/CMakeFiles/posixthread.dir/posix_port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/posixthread.dir/posix_port.cpp.s"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/willy/myshare/thread-pool/src/posix_port.cpp -o CMakeFiles/posixthread.dir/posix_port.cpp.s

src/CMakeFiles/posixthread.dir/posix_port.cpp.o.requires:

.PHONY : src/CMakeFiles/posixthread.dir/posix_port.cpp.o.requires

src/CMakeFiles/posixthread.dir/posix_port.cpp.o.provides: src/CMakeFiles/posixthread.dir/posix_port.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/posixthread.dir/build.make src/CMakeFiles/posixthread.dir/posix_port.cpp.o.provides.build
.PHONY : src/CMakeFiles/posixthread.dir/posix_port.cpp.o.provides

src/CMakeFiles/posixthread.dir/posix_port.cpp.o.provides.build: src/CMakeFiles/posixthread.dir/posix_port.cpp.o


src/CMakeFiles/posixthread.dir/posix_thread.cpp.o: src/CMakeFiles/posixthread.dir/flags.make
src/CMakeFiles/posixthread.dir/posix_thread.cpp.o: ../src/posix_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/posixthread.dir/posix_thread.cpp.o"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/posixthread.dir/posix_thread.cpp.o -c /home/willy/myshare/thread-pool/src/posix_thread.cpp

src/CMakeFiles/posixthread.dir/posix_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/posixthread.dir/posix_thread.cpp.i"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/willy/myshare/thread-pool/src/posix_thread.cpp > CMakeFiles/posixthread.dir/posix_thread.cpp.i

src/CMakeFiles/posixthread.dir/posix_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/posixthread.dir/posix_thread.cpp.s"
	cd /home/willy/myshare/thread-pool/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/willy/myshare/thread-pool/src/posix_thread.cpp -o CMakeFiles/posixthread.dir/posix_thread.cpp.s

src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.requires:

.PHONY : src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.requires

src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.provides: src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/posixthread.dir/build.make src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.provides.build
.PHONY : src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.provides

src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.provides.build: src/CMakeFiles/posixthread.dir/posix_thread.cpp.o


# Object files for target posixthread
posixthread_OBJECTS = \
"CMakeFiles/posixthread.dir/CountDownLatch.cpp.o" \
"CMakeFiles/posixthread.dir/posix_port.cpp.o" \
"CMakeFiles/posixthread.dir/posix_thread.cpp.o"

# External object files for target posixthread
posixthread_EXTERNAL_OBJECTS =

src/libposixthread.a: src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o
src/libposixthread.a: src/CMakeFiles/posixthread.dir/posix_port.cpp.o
src/libposixthread.a: src/CMakeFiles/posixthread.dir/posix_thread.cpp.o
src/libposixthread.a: src/CMakeFiles/posixthread.dir/build.make
src/libposixthread.a: src/CMakeFiles/posixthread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/willy/myshare/thread-pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libposixthread.a"
	cd /home/willy/myshare/thread-pool/build/src && $(CMAKE_COMMAND) -P CMakeFiles/posixthread.dir/cmake_clean_target.cmake
	cd /home/willy/myshare/thread-pool/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/posixthread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/posixthread.dir/build: src/libposixthread.a

.PHONY : src/CMakeFiles/posixthread.dir/build

src/CMakeFiles/posixthread.dir/requires: src/CMakeFiles/posixthread.dir/CountDownLatch.cpp.o.requires
src/CMakeFiles/posixthread.dir/requires: src/CMakeFiles/posixthread.dir/posix_port.cpp.o.requires
src/CMakeFiles/posixthread.dir/requires: src/CMakeFiles/posixthread.dir/posix_thread.cpp.o.requires

.PHONY : src/CMakeFiles/posixthread.dir/requires

src/CMakeFiles/posixthread.dir/clean:
	cd /home/willy/myshare/thread-pool/build/src && $(CMAKE_COMMAND) -P CMakeFiles/posixthread.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/posixthread.dir/clean

src/CMakeFiles/posixthread.dir/depend:
	cd /home/willy/myshare/thread-pool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/willy/myshare/thread-pool /home/willy/myshare/thread-pool/src /home/willy/myshare/thread-pool/build /home/willy/myshare/thread-pool/build/src /home/willy/myshare/thread-pool/build/src/CMakeFiles/posixthread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/posixthread.dir/depend
