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

# Include any dependencies generated for this target.
include CMakeFiles/SSIntersection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SSIntersection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SSIntersection.dir/flags.make

CMakeFiles/SSIntersection.dir/src/main.cpp.o: CMakeFiles/SSIntersection.dir/flags.make
CMakeFiles/SSIntersection.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/viacheslav/cg-course/sphere/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSIntersection.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSIntersection.dir/src/main.cpp.o -c /home/viacheslav/cg-course/sphere/src/main.cpp

CMakeFiles/SSIntersection.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSIntersection.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/viacheslav/cg-course/sphere/src/main.cpp > CMakeFiles/SSIntersection.dir/src/main.cpp.i

CMakeFiles/SSIntersection.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSIntersection.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/viacheslav/cg-course/sphere/src/main.cpp -o CMakeFiles/SSIntersection.dir/src/main.cpp.s

CMakeFiles/SSIntersection.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/SSIntersection.dir/src/main.cpp.o.requires

CMakeFiles/SSIntersection.dir/src/main.cpp.o.provides: CMakeFiles/SSIntersection.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSIntersection.dir/build.make CMakeFiles/SSIntersection.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/SSIntersection.dir/src/main.cpp.o.provides

CMakeFiles/SSIntersection.dir/src/main.cpp.o.provides.build: CMakeFiles/SSIntersection.dir/src/main.cpp.o

# Object files for target SSIntersection
SSIntersection_OBJECTS = \
"CMakeFiles/SSIntersection.dir/src/main.cpp.o"

# External object files for target SSIntersection
SSIntersection_EXTERNAL_OBJECTS =

SSIntersection: CMakeFiles/SSIntersection.dir/src/main.cpp.o
SSIntersection: CMakeFiles/SSIntersection.dir/build.make
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Core.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Gui.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5OpenGL.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libgmp.so
SSIntersection: /usr/lib/libgtest.a
SSIntersection: /usr/lib/libgtest_main.a
SSIntersection: 3rdparty/geometry/libGeometry2.a
SSIntersection: /usr/lib/i386-linux-gnu/libQt5OpenGL.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Gui.so.5.0.2
SSIntersection: /usr/lib/i386-linux-gnu/libQt5Core.so.5.0.2
SSIntersection: CMakeFiles/SSIntersection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SSIntersection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SSIntersection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SSIntersection.dir/build: SSIntersection
.PHONY : CMakeFiles/SSIntersection.dir/build

CMakeFiles/SSIntersection.dir/requires: CMakeFiles/SSIntersection.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/SSIntersection.dir/requires

CMakeFiles/SSIntersection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SSIntersection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SSIntersection.dir/clean

CMakeFiles/SSIntersection.dir/depend:
	cd /home/viacheslav/cg-course/sphere/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viacheslav/cg-course/sphere /home/viacheslav/cg-course/sphere /home/viacheslav/cg-course/sphere/build /home/viacheslav/cg-course/sphere/build /home/viacheslav/cg-course/sphere/build/CMakeFiles/SSIntersection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SSIntersection.dir/depend

