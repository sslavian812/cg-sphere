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

# Utility rule file for Geometry2_automoc.

# Include the progress variables for this target.
include 3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/progress.make

3rdparty/geometry/CMakeFiles/Geometry2_automoc:
	$(CMAKE_COMMAND) -E cmake_progress_report /home/viacheslav/cg-course/sphere/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Automoc for target Geometry2"
	cd /home/viacheslav/cg-course/sphere/build/3rdparty/geometry && /usr/bin/cmake -E cmake_automoc /home/viacheslav/cg-course/sphere/build/3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/

Geometry2_automoc: 3rdparty/geometry/CMakeFiles/Geometry2_automoc
Geometry2_automoc: 3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/build.make
.PHONY : Geometry2_automoc

# Rule to build all files generated by this target.
3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/build: Geometry2_automoc
.PHONY : 3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/build

3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/clean:
	cd /home/viacheslav/cg-course/sphere/build/3rdparty/geometry && $(CMAKE_COMMAND) -P CMakeFiles/Geometry2_automoc.dir/cmake_clean.cmake
.PHONY : 3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/clean

3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/depend:
	cd /home/viacheslav/cg-course/sphere/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viacheslav/cg-course/sphere /home/viacheslav/cg-course/sphere/3rdparty/geometry /home/viacheslav/cg-course/sphere/build /home/viacheslav/cg-course/sphere/build/3rdparty/geometry /home/viacheslav/cg-course/sphere/build/3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdparty/geometry/CMakeFiles/Geometry2_automoc.dir/depend
