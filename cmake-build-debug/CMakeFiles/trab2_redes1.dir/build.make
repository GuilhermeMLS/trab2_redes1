# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/guilhermemorais/CLionProjects/trab2_redes1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/trab2_redes1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trab2_redes1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trab2_redes1.dir/flags.make

CMakeFiles/trab2_redes1.dir/main.c.o: CMakeFiles/trab2_redes1.dir/flags.make
CMakeFiles/trab2_redes1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trab2_redes1.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/trab2_redes1.dir/main.c.o   -c /Users/guilhermemorais/CLionProjects/trab2_redes1/main.c

CMakeFiles/trab2_redes1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trab2_redes1.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/guilhermemorais/CLionProjects/trab2_redes1/main.c > CMakeFiles/trab2_redes1.dir/main.c.i

CMakeFiles/trab2_redes1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trab2_redes1.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/guilhermemorais/CLionProjects/trab2_redes1/main.c -o CMakeFiles/trab2_redes1.dir/main.c.s

# Object files for target trab2_redes1
trab2_redes1_OBJECTS = \
"CMakeFiles/trab2_redes1.dir/main.c.o"

# External object files for target trab2_redes1
trab2_redes1_EXTERNAL_OBJECTS =

trab2_redes1: CMakeFiles/trab2_redes1.dir/main.c.o
trab2_redes1: CMakeFiles/trab2_redes1.dir/build.make
trab2_redes1: CMakeFiles/trab2_redes1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable trab2_redes1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trab2_redes1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trab2_redes1.dir/build: trab2_redes1

.PHONY : CMakeFiles/trab2_redes1.dir/build

CMakeFiles/trab2_redes1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trab2_redes1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trab2_redes1.dir/clean

CMakeFiles/trab2_redes1.dir/depend:
	cd /Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/guilhermemorais/CLionProjects/trab2_redes1 /Users/guilhermemorais/CLionProjects/trab2_redes1 /Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug /Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug /Users/guilhermemorais/CLionProjects/trab2_redes1/cmake-build-debug/CMakeFiles/trab2_redes1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trab2_redes1.dir/depend
