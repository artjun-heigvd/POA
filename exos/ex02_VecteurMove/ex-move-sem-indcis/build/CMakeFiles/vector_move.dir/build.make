# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build

# Include any dependencies generated for this target.
include CMakeFiles/vector_move.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vector_move.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vector_move.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector_move.dir/flags.make

CMakeFiles/vector_move.dir/vectormove.o: CMakeFiles/vector_move.dir/flags.make
CMakeFiles/vector_move.dir/vectormove.o: /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/vectormove.cpp
CMakeFiles/vector_move.dir/vectormove.o: CMakeFiles/vector_move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector_move.dir/vectormove.o"
	/usr/lib64/ccache/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vector_move.dir/vectormove.o -MF CMakeFiles/vector_move.dir/vectormove.o.d -o CMakeFiles/vector_move.dir/vectormove.o -c /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/vectormove.cpp

CMakeFiles/vector_move.dir/vectormove.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/vector_move.dir/vectormove.i"
	/usr/lib64/ccache/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/vectormove.cpp > CMakeFiles/vector_move.dir/vectormove.i

CMakeFiles/vector_move.dir/vectormove.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/vector_move.dir/vectormove.s"
	/usr/lib64/ccache/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/vectormove.cpp -o CMakeFiles/vector_move.dir/vectormove.s

# Object files for target vector_move
vector_move_OBJECTS = \
"CMakeFiles/vector_move.dir/vectormove.o"

# External object files for target vector_move
vector_move_EXTERNAL_OBJECTS =

vector_move: CMakeFiles/vector_move.dir/vectormove.o
vector_move: CMakeFiles/vector_move.dir/build.make
vector_move: CMakeFiles/vector_move.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vector_move"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_move.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector_move.dir/build: vector_move
.PHONY : CMakeFiles/vector_move.dir/build

CMakeFiles/vector_move.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector_move.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector_move.dir/clean

CMakeFiles/vector_move.dir/depend:
	cd /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build /home/ajun/Documents/HEIG/POA/exos/ex02_VecteurMove/ex-move-sem-indcis/build/CMakeFiles/vector_move.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/vector_move.dir/depend

