# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.dgzV3O5sJt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host

# Include any dependencies generated for this target.
include test/CMakeFiles/test_thread.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_thread.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_thread.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_thread.dir/flags.make

test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o: test/CMakeFiles/test_thread.dir/flags.make
test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o: /tmp/tmp.dgzV3O5sJt/test/Test_Thread.cpp
test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o: test/CMakeFiles/test_thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o"
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o -MF CMakeFiles/test_thread.dir/Test_Thread.cpp.o.d -o CMakeFiles/test_thread.dir/Test_Thread.cpp.o -c /tmp/tmp.dgzV3O5sJt/test/Test_Thread.cpp

test/CMakeFiles/test_thread.dir/Test_Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_thread.dir/Test_Thread.cpp.i"
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.dgzV3O5sJt/test/Test_Thread.cpp > CMakeFiles/test_thread.dir/Test_Thread.cpp.i

test/CMakeFiles/test_thread.dir/Test_Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_thread.dir/Test_Thread.cpp.s"
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.dgzV3O5sJt/test/Test_Thread.cpp -o CMakeFiles/test_thread.dir/Test_Thread.cpp.s

# Object files for target test_thread
test_thread_OBJECTS = \
"CMakeFiles/test_thread.dir/Test_Thread.cpp.o"

# External object files for target test_thread
test_thread_EXTERNAL_OBJECTS =

test/test_thread: test/CMakeFiles/test_thread.dir/Test_Thread.cpp.o
test/test_thread: test/CMakeFiles/test_thread.dir/build.make
test/test_thread: base/libbase.a
test/test_thread: test/CMakeFiles/test_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_thread"
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_thread.dir/build: test/test_thread
.PHONY : test/CMakeFiles/test_thread.dir/build

test/CMakeFiles/test_thread.dir/clean:
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test && $(CMAKE_COMMAND) -P CMakeFiles/test_thread.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_thread.dir/clean

test/CMakeFiles/test_thread.dir/depend:
	cd /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.dgzV3O5sJt /tmp/tmp.dgzV3O5sJt/test /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test /tmp/tmp.dgzV3O5sJt/cmake-build-relwithdebinfo-remote-host/test/CMakeFiles/test_thread.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/test_thread.dir/depend
