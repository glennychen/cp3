# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/bps/clion-2020.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bps/clion-2020.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bps/CLionProjects/untitled26

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bps/CLionProjects/untitled26/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled26.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled26.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled26.dir/flags.make

CMakeFiles/untitled26.dir/main.cpp.o: CMakeFiles/untitled26.dir/flags.make
CMakeFiles/untitled26.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bps/CLionProjects/untitled26/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled26.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled26.dir/main.cpp.o -c /home/bps/CLionProjects/untitled26/main.cpp

CMakeFiles/untitled26.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled26.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bps/CLionProjects/untitled26/main.cpp > CMakeFiles/untitled26.dir/main.cpp.i

CMakeFiles/untitled26.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled26.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bps/CLionProjects/untitled26/main.cpp -o CMakeFiles/untitled26.dir/main.cpp.s

# Object files for target untitled26
untitled26_OBJECTS = \
"CMakeFiles/untitled26.dir/main.cpp.o"

# External object files for target untitled26
untitled26_EXTERNAL_OBJECTS =

untitled26: CMakeFiles/untitled26.dir/main.cpp.o
untitled26: CMakeFiles/untitled26.dir/build.make
untitled26: CMakeFiles/untitled26.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bps/CLionProjects/untitled26/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled26"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled26.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled26.dir/build: untitled26

.PHONY : CMakeFiles/untitled26.dir/build

CMakeFiles/untitled26.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled26.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled26.dir/clean

CMakeFiles/untitled26.dir/depend:
	cd /home/bps/CLionProjects/untitled26/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bps/CLionProjects/untitled26 /home/bps/CLionProjects/untitled26 /home/bps/CLionProjects/untitled26/cmake-build-debug /home/bps/CLionProjects/untitled26/cmake-build-debug /home/bps/CLionProjects/untitled26/cmake-build-debug/CMakeFiles/untitled26.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled26.dir/depend

