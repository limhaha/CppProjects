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
CMAKE_SOURCE_DIR = /Users/halim/CLionProjects/PHW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/halim/CLionProjects/PHW2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PHW2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PHW2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PHW2.dir/flags.make

CMakeFiles/PHW2.dir/main.c.o: CMakeFiles/PHW2.dir/flags.make
CMakeFiles/PHW2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halim/CLionProjects/PHW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PHW2.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PHW2.dir/main.c.o   -c /Users/halim/CLionProjects/PHW2/main.c

CMakeFiles/PHW2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PHW2.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halim/CLionProjects/PHW2/main.c > CMakeFiles/PHW2.dir/main.c.i

CMakeFiles/PHW2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PHW2.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halim/CLionProjects/PHW2/main.c -o CMakeFiles/PHW2.dir/main.c.s

# Object files for target PHW2
PHW2_OBJECTS = \
"CMakeFiles/PHW2.dir/main.c.o"

# External object files for target PHW2
PHW2_EXTERNAL_OBJECTS =

PHW2: CMakeFiles/PHW2.dir/main.c.o
PHW2: CMakeFiles/PHW2.dir/build.make
PHW2: CMakeFiles/PHW2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/halim/CLionProjects/PHW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PHW2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PHW2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PHW2.dir/build: PHW2

.PHONY : CMakeFiles/PHW2.dir/build

CMakeFiles/PHW2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PHW2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PHW2.dir/clean

CMakeFiles/PHW2.dir/depend:
	cd /Users/halim/CLionProjects/PHW2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/halim/CLionProjects/PHW2 /Users/halim/CLionProjects/PHW2 /Users/halim/CLionProjects/PHW2/cmake-build-debug /Users/halim/CLionProjects/PHW2/cmake-build-debug /Users/halim/CLionProjects/PHW2/cmake-build-debug/CMakeFiles/PHW2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PHW2.dir/depend
