# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-10.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain

# Include any dependencies generated for this target.
include CMakeFiles/move.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/move.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/move.dir/flags.make

CMakeFiles/move.dir/move.cpp.o: CMakeFiles/move.dir/flags.make
CMakeFiles/move.dir/move.cpp.o: ../move.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/move.dir/move.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/move.dir/move.cpp.o -c /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/move.cpp

CMakeFiles/move.dir/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move.dir/move.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/move.cpp > CMakeFiles/move.dir/move.cpp.i

CMakeFiles/move.dir/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move.dir/move.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/move.cpp -o CMakeFiles/move.dir/move.cpp.s

CMakeFiles/move.dir/move.cpp.o.requires:
.PHONY : CMakeFiles/move.dir/move.cpp.o.requires

CMakeFiles/move.dir/move.cpp.o.provides: CMakeFiles/move.dir/move.cpp.o.requires
	$(MAKE) -f CMakeFiles/move.dir/build.make CMakeFiles/move.dir/move.cpp.o.provides.build
.PHONY : CMakeFiles/move.dir/move.cpp.o.provides

CMakeFiles/move.dir/move.cpp.o.provides.build: CMakeFiles/move.dir/move.cpp.o

CMakeFiles/move.dir/main.cpp.o: CMakeFiles/move.dir/flags.make
CMakeFiles/move.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/move.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/move.dir/main.cpp.o -c /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/main.cpp

CMakeFiles/move.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/main.cpp > CMakeFiles/move.dir/main.cpp.i

CMakeFiles/move.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/main.cpp -o CMakeFiles/move.dir/main.cpp.s

CMakeFiles/move.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/move.dir/main.cpp.o.requires

CMakeFiles/move.dir/main.cpp.o.provides: CMakeFiles/move.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/move.dir/build.make CMakeFiles/move.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/move.dir/main.cpp.o.provides

CMakeFiles/move.dir/main.cpp.o.provides.build: CMakeFiles/move.dir/main.cpp.o

# Object files for target move
move_OBJECTS = \
"CMakeFiles/move.dir/move.cpp.o" \
"CMakeFiles/move.dir/main.cpp.o"

# External object files for target move
move_EXTERNAL_OBJECTS =

sdk/bin/move: CMakeFiles/move.dir/move.cpp.o
sdk/bin/move: CMakeFiles/move.dir/main.cpp.o
sdk/bin/move: CMakeFiles/move.dir/build.make
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libalmemoryfastaccess.a
sdk/bin/move: sdk/lib/libalproxies.dylib
sdk/bin/move: sdk/lib/libalproxies.dylib
sdk/bin/move: sdk/lib/libalcommon.dylib
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libalsoap.a
sdk/bin/move: sdk/lib/librttools.dylib
sdk/bin/move: sdk/lib/libalthread.dylib
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libboost_signals-mt.a
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libboost_program_options-mt.a
sdk/bin/move: sdk/lib/libalvalue.dylib
sdk/bin/move: sdk/lib/libtinyxml.dylib
sdk/bin/move: sdk/lib/libqi.dylib
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libboost_filesystem-mt.a
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libboost_thread-mt.a
sdk/bin/move: /Users/nicolasbernier/Documents/NAO/1.14.1/naoqi-sdk-1.14.1-mac64/lib/libboost_system-mt.a
sdk/bin/move: /usr/lib/libpthread.dylib
sdk/bin/move: /usr/lib/libdl.dylib
sdk/bin/move: sdk/lib/libalerror.dylib
sdk/bin/move: CMakeFiles/move.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sdk/bin/move"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/move.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/move.dir/build: sdk/bin/move
.PHONY : CMakeFiles/move.dir/build

CMakeFiles/move.dir/requires: CMakeFiles/move.dir/move.cpp.o.requires
CMakeFiles/move.dir/requires: CMakeFiles/move.dir/main.cpp.o.requires
.PHONY : CMakeFiles/move.dir/requires

CMakeFiles/move.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/move.dir/cmake_clean.cmake
.PHONY : CMakeFiles/move.dir/clean

CMakeFiles/move.dir/depend:
	cd /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain /Users/nicolasbernier/Documents/NAO/1.14.1/PROJECT/move/build-nao_toolchain/CMakeFiles/move.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/move.dir/depend

