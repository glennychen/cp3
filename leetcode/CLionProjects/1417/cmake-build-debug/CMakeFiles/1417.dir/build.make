# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/glenn/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/glenn/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/glenn/CLionProjects/1417

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glenn/CLionProjects/1417/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1417.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/1417.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1417.dir/flags.make

CMakeFiles/1417.dir/main.cpp.o: CMakeFiles/1417.dir/flags.make
CMakeFiles/1417.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glenn/CLionProjects/1417/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1417.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1417.dir/main.cpp.o -c /home/glenn/CLionProjects/1417/main.cpp

CMakeFiles/1417.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1417.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/glenn/CLionProjects/1417/main.cpp > CMakeFiles/1417.dir/main.cpp.i

CMakeFiles/1417.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1417.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/glenn/CLionProjects/1417/main.cpp -o CMakeFiles/1417.dir/main.cpp.s

# Object files for target 1417
1417_OBJECTS = \
"CMakeFiles/1417.dir/main.cpp.o"

# External object files for target 1417
1417_EXTERNAL_OBJECTS =

1417: CMakeFiles/1417.dir/main.cpp.o
1417: CMakeFiles/1417.dir/build.make
1417: CMakeFiles/1417.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glenn/CLionProjects/1417/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1417"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1417.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1417.dir/build: 1417
.PHONY : CMakeFiles/1417.dir/build

CMakeFiles/1417.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1417.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1417.dir/clean

CMakeFiles/1417.dir/depend:
	cd /home/glenn/CLionProjects/1417/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glenn/CLionProjects/1417 /home/glenn/CLionProjects/1417 /home/glenn/CLionProjects/1417/cmake-build-debug /home/glenn/CLionProjects/1417/cmake-build-debug /home/glenn/CLionProjects/1417/cmake-build-debug/CMakeFiles/1417.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1417.dir/depend
