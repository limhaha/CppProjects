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
CMAKE_SOURCE_DIR = /Users/halim/CLionProjects/cpp/baekjun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/baekjun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/baekjun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/baekjun.dir/flags.make

CMakeFiles/baekjun.dir/main.cpp.o: CMakeFiles/baekjun.dir/flags.make
CMakeFiles/baekjun.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/baekjun.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baekjun.dir/main.cpp.o -c /Users/halim/CLionProjects/cpp/baekjun/main.cpp

CMakeFiles/baekjun.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baekjun.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/halim/CLionProjects/cpp/baekjun/main.cpp > CMakeFiles/baekjun.dir/main.cpp.i

CMakeFiles/baekjun.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baekjun.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/halim/CLionProjects/cpp/baekjun/main.cpp -o CMakeFiles/baekjun.dir/main.cpp.s

# Object files for target baekjun
baekjun_OBJECTS = \
"CMakeFiles/baekjun.dir/main.cpp.o"

# External object files for target baekjun
baekjun_EXTERNAL_OBJECTS =

baekjun: CMakeFiles/baekjun.dir/main.cpp.o
baekjun: CMakeFiles/baekjun.dir/build.make
baekjun: CMakeFiles/baekjun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable baekjun"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/baekjun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/baekjun.dir/build: baekjun

.PHONY : CMakeFiles/baekjun.dir/build

CMakeFiles/baekjun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/baekjun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/baekjun.dir/clean

CMakeFiles/baekjun.dir/depend:
	cd /Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/halim/CLionProjects/cpp/baekjun /Users/halim/CLionProjects/cpp/baekjun /Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug /Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug /Users/halim/CLionProjects/cpp/baekjun/cmake-build-debug/CMakeFiles/baekjun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/baekjun.dir/depend

