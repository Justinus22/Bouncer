# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/i589228/data/hwr/s4/c++/Bouncer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/i589228/data/hwr/s4/c++/Bouncer/Release

# Include any dependencies generated for this target.
include _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/flags.make

_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o: _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/flags.make
_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o: _deps/vorbis-src/lib/vorbisfile.c
_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o: _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/i589228/data/hwr/s4/c++/Bouncer/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o"
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o -MF CMakeFiles/vorbisfile.dir/vorbisfile.c.o.d -o CMakeFiles/vorbisfile.dir/vorbisfile.c.o -c /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-src/lib/vorbisfile.c

_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/vorbisfile.dir/vorbisfile.c.i"
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-src/lib/vorbisfile.c > CMakeFiles/vorbisfile.dir/vorbisfile.c.i

_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/vorbisfile.dir/vorbisfile.c.s"
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-src/lib/vorbisfile.c -o CMakeFiles/vorbisfile.dir/vorbisfile.c.s

# Object files for target vorbisfile
vorbisfile_OBJECTS = \
"CMakeFiles/vorbisfile.dir/vorbisfile.c.o"

# External object files for target vorbisfile
vorbisfile_EXTERNAL_OBJECTS =

_deps/sfml-build/lib/libvorbisfile.a: _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/vorbisfile.c.o
_deps/sfml-build/lib/libvorbisfile.a: _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/build.make
_deps/sfml-build/lib/libvorbisfile.a: _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/i589228/data/hwr/s4/c++/Bouncer/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../sfml-build/lib/libvorbisfile.a"
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && $(CMAKE_COMMAND) -P CMakeFiles/vorbisfile.dir/cmake_clean_target.cmake
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vorbisfile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/build: _deps/sfml-build/lib/libvorbisfile.a
.PHONY : _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/build

_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/clean:
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib && $(CMAKE_COMMAND) -P CMakeFiles/vorbisfile.dir/cmake_clean.cmake
.PHONY : _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/clean

_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/depend:
	cd /Users/i589228/data/hwr/s4/c++/Bouncer/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/i589228/data/hwr/s4/c++/Bouncer /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-src/lib /Users/i589228/data/hwr/s4/c++/Bouncer/Release /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib /Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/vorbis-build/lib/CMakeFiles/vorbisfile.dir/depend

