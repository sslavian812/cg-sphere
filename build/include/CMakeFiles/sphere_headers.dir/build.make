# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/viacheslav/cg-course/sphere

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/viacheslav/cg-course/sphere/build

# Utility rule file for sphere_headers.

# Include the progress variables for this target.
include include/CMakeFiles/sphere_headers.dir/progress.make

include/CMakeFiles/sphere_headers:

sphere_headers: include/CMakeFiles/sphere_headers
sphere_headers: include/CMakeFiles/sphere_headers.dir/build.make
.PHONY : sphere_headers

# Rule to build all files generated by this target.
include/CMakeFiles/sphere_headers.dir/build: sphere_headers
.PHONY : include/CMakeFiles/sphere_headers.dir/build

include/CMakeFiles/sphere_headers.dir/clean:
	cd /home/viacheslav/cg-course/sphere/build/include && $(CMAKE_COMMAND) -P CMakeFiles/sphere_headers.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/sphere_headers.dir/clean

include/CMakeFiles/sphere_headers.dir/depend:
	cd /home/viacheslav/cg-course/sphere/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viacheslav/cg-course/sphere /home/viacheslav/cg-course/sphere/include /home/viacheslav/cg-course/sphere/build /home/viacheslav/cg-course/sphere/build/include /home/viacheslav/cg-course/sphere/build/include/CMakeFiles/sphere_headers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/sphere_headers.dir/depend
