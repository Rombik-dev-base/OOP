# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\1285166\CLionProjects\parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\1285166\CLionProjects\parser\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

CMakeFiles/parser.dir/main.cpp.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\1285166\CLionProjects\parser\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parser.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\parser.dir\main.cpp.obj -c C:\Users\1285166\CLionProjects\parser\main.cpp

CMakeFiles/parser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\1285166\CLionProjects\parser\main.cpp > CMakeFiles\parser.dir\main.cpp.i

CMakeFiles/parser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\1285166\CLionProjects\parser\main.cpp -o CMakeFiles\parser.dir\main.cpp.s

CMakeFiles/parser.dir/pars.cpp.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/pars.cpp.obj: ../pars.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\1285166\CLionProjects\parser\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/parser.dir/pars.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\parser.dir\pars.cpp.obj -c C:\Users\1285166\CLionProjects\parser\pars.cpp

CMakeFiles/parser.dir/pars.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/pars.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\1285166\CLionProjects\parser\pars.cpp > CMakeFiles\parser.dir\pars.cpp.i

CMakeFiles/parser.dir/pars.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/pars.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\1285166\CLionProjects\parser\pars.cpp -o CMakeFiles\parser.dir\pars.cpp.s

# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/main.cpp.obj" \
"CMakeFiles/parser.dir/pars.cpp.obj"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser.exe: CMakeFiles/parser.dir/main.cpp.obj
parser.exe: CMakeFiles/parser.dir/pars.cpp.obj
parser.exe: CMakeFiles/parser.dir/build.make
parser.exe: CMakeFiles/parser.dir/linklibs.rsp
parser.exe: CMakeFiles/parser.dir/objects1.rsp
parser.exe: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\1285166\CLionProjects\parser\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable parser.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\parser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser.exe

.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\parser.dir\cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\1285166\CLionProjects\parser C:\Users\1285166\CLionProjects\parser C:\Users\1285166\CLionProjects\parser\cmake-build-debug C:\Users\1285166\CLionProjects\parser\cmake-build-debug C:\Users\1285166\CLionProjects\parser\cmake-build-debug\CMakeFiles\parser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend

