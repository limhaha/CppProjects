# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/halim/CLionProjects/PHW1-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/halim/CLionProjects/PHW1-3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PHW1_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PHW1_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PHW1_3.dir/flags.make

CMakeFiles/PHW1_3.dir/main.c.o: CMakeFiles/PHW1_3.dir/flags.make
CMakeFiles/PHW1_3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halim/CLionProjects/PHW1-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PHW1_3.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PHW1_3.dir/main.c.o   -c /Users/halim/CLionProjects/PHW1-3/main.c

CMakeFiles/PHW1_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PHW1_3.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halim/CLionProjects/PHW1-3/main.c > CMakeFiles/PHW1_3.dir/main.c.i

CMakeFiles/PHW1_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PHW1_3.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halim/CLionProjects/PHW1-3/main.c -o CMakeFiles/PHW1_3.dir/main.c.s

# Object files for target PHW1_3
PHW1_3_OBJECTS = \
"CMakeFiles/PHW1_3.dir/main.c.o"

# External object files for target PHW1_3
PHW1_3_EXTERNAL_OBJECTS =

PHW1_3: CMakeFiles/PHW1_3.dir/main.c.o
PHW1_3: CMakeFiles/PHW1_3.dir/build.make
PHW1_3: CMakeFiles/PHW1_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/halim/CLionProjects/PHW1-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PHW1_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PHW1_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PHW1_3.dir/build: PHW1_3

.PHONY : CMakeFiles/PHW1_3.dir/build

CMakeFiles/PHW1_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PHW1_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PHW1_3.dir/clean

CMakeFiles/PHW1_3.dir/depend:
	cd /Users/halim/CLionProjects/PHW1-3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/halim/CLionProjects/PHW1-3 /Users/halim/CLionProjects/PHW1-3 /Users/halim/CLionProjects/PHW1-3/cmake-build-debug /Users/halim/CLionProjects/PHW1-3/cmake-build-debug /Users/halim/CLionProjects/PHW1-3/cmake-build-debug/CMakeFiles/PHW1_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PHW1_3.dir/depend
