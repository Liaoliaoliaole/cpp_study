# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/lili/Documents/ExternalInclude/Eigen/source_dir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lili/Documents/ExternalInclude/Eigen/build_dir

# Utility rule file for stddeque.

# Include any custom commands dependencies for this target.
include test/CMakeFiles/stddeque.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/stddeque.dir/progress.make

stddeque: test/CMakeFiles/stddeque.dir/build.make
.PHONY : stddeque

# Rule to build all files generated by this target.
test/CMakeFiles/stddeque.dir/build: stddeque
.PHONY : test/CMakeFiles/stddeque.dir/build

test/CMakeFiles/stddeque.dir/clean:
	cd /home/lili/Documents/ExternalInclude/Eigen/build_dir/test && $(CMAKE_COMMAND) -P CMakeFiles/stddeque.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/stddeque.dir/clean

test/CMakeFiles/stddeque.dir/depend:
	cd /home/lili/Documents/ExternalInclude/Eigen/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lili/Documents/ExternalInclude/Eigen/source_dir /home/lili/Documents/ExternalInclude/Eigen/source_dir/test /home/lili/Documents/ExternalInclude/Eigen/build_dir /home/lili/Documents/ExternalInclude/Eigen/build_dir/test /home/lili/Documents/ExternalInclude/Eigen/build_dir/test/CMakeFiles/stddeque.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/stddeque.dir/depend
