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
CMAKE_SOURCE_DIR = /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release

# Include any dependencies generated for this target.
include CMakeFiles/test_nativecpu_elementwise.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_nativecpu_elementwise.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_nativecpu_elementwise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_nativecpu_elementwise.dir/flags.make

CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o: CMakeFiles/test_nativecpu_elementwise.dir/flags.make
CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o: ../../test/kernels/nativecpu/test_nativecpu_elementwise.cc
CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o: CMakeFiles/test_nativecpu_elementwise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o -MF CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o.d -o CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o -c /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/test/kernels/nativecpu/test_nativecpu_elementwise.cc

CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/test/kernels/nativecpu/test_nativecpu_elementwise.cc > CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.i

CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/test/kernels/nativecpu/test_nativecpu_elementwise.cc -o CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.s

# Object files for target test_nativecpu_elementwise
test_nativecpu_elementwise_OBJECTS = \
"CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o"

# External object files for target test_nativecpu_elementwise
test_nativecpu_elementwise_EXTERNAL_OBJECTS =

test_nativecpu_elementwise: CMakeFiles/test_nativecpu_elementwise.dir/test/kernels/nativecpu/test_nativecpu_elementwise.cc.o
test_nativecpu_elementwise: CMakeFiles/test_nativecpu_elementwise.dir/build.make
test_nativecpu_elementwise: libInfiniTensor.so
test_nativecpu_elementwise: lib/libgtest_main.a
test_nativecpu_elementwise: lib/libgtest.a
test_nativecpu_elementwise: CMakeFiles/test_nativecpu_elementwise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_nativecpu_elementwise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_nativecpu_elementwise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_nativecpu_elementwise.dir/build: test_nativecpu_elementwise
.PHONY : CMakeFiles/test_nativecpu_elementwise.dir/build

CMakeFiles/test_nativecpu_elementwise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_nativecpu_elementwise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_nativecpu_elementwise.dir/clean

CMakeFiles/test_nativecpu_elementwise.dir/depend:
	cd /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release /home/yswang/winter_learn/ai_compiler/TinyInfiniTensor/build/Release/CMakeFiles/test_nativecpu_elementwise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_nativecpu_elementwise.dir/depend
