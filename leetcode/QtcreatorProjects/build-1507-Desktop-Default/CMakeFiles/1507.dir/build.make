# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/1507.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1507.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1507.dir/flags.make

CMakeFiles/1507.dir/main.cpp.o: CMakeFiles/1507.dir/flags.make
CMakeFiles/1507.dir/main.cpp.o: /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1507.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1507.dir/main.cpp.o -c /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507/main.cpp

CMakeFiles/1507.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1507.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507/main.cpp > CMakeFiles/1507.dir/main.cpp.i

CMakeFiles/1507.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1507.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507/main.cpp -o CMakeFiles/1507.dir/main.cpp.s

CMakeFiles/1507.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/1507.dir/main.cpp.o.requires

CMakeFiles/1507.dir/main.cpp.o.provides: CMakeFiles/1507.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/1507.dir/build.make CMakeFiles/1507.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/1507.dir/main.cpp.o.provides

CMakeFiles/1507.dir/main.cpp.o.provides.build: CMakeFiles/1507.dir/main.cpp.o


# Object files for target 1507
1507_OBJECTS = \
"CMakeFiles/1507.dir/main.cpp.o"

# External object files for target 1507
1507_EXTERNAL_OBJECTS =

1507: CMakeFiles/1507.dir/main.cpp.o
1507: CMakeFiles/1507.dir/build.make
1507: CMakeFiles/1507.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1507"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1507.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1507.dir/build: 1507

.PHONY : CMakeFiles/1507.dir/build

CMakeFiles/1507.dir/requires: CMakeFiles/1507.dir/main.cpp.o.requires

.PHONY : CMakeFiles/1507.dir/requires

CMakeFiles/1507.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1507.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1507.dir/clean

CMakeFiles/1507.dir/depend:
	cd /home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507 /home/glenn/src/cp3/leetcode/QtcreatorProjects/1507 /home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default /home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default /home/glenn/src/cp3/leetcode/QtcreatorProjects/build-1507-Desktop-Default/CMakeFiles/1507.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1507.dir/depend

