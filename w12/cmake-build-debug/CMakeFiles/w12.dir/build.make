# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Github\data-structure\w12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Github\data-structure\w12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/w12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/w12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/w12.dir/flags.make

CMakeFiles/w12.dir/main.cpp.obj: CMakeFiles/w12.dir/flags.make
CMakeFiles/w12.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\data-structure\w12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/w12.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\w12.dir\main.cpp.obj -c D:\Github\data-structure\w12\main.cpp

CMakeFiles/w12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w12.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Github\data-structure\w12\main.cpp > CMakeFiles\w12.dir\main.cpp.i

CMakeFiles/w12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w12.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Github\data-structure\w12\main.cpp -o CMakeFiles\w12.dir\main.cpp.s

# Object files for target w12
w12_OBJECTS = \
"CMakeFiles/w12.dir/main.cpp.obj"

# External object files for target w12
w12_EXTERNAL_OBJECTS =

w12.exe: CMakeFiles/w12.dir/main.cpp.obj
w12.exe: CMakeFiles/w12.dir/build.make
w12.exe: CMakeFiles/w12.dir/linklibs.rsp
w12.exe: CMakeFiles/w12.dir/objects1.rsp
w12.exe: CMakeFiles/w12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Github\data-structure\w12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable w12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\w12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/w12.dir/build: w12.exe

.PHONY : CMakeFiles/w12.dir/build

CMakeFiles/w12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\w12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/w12.dir/clean

CMakeFiles/w12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Github\data-structure\w12 D:\Github\data-structure\w12 D:\Github\data-structure\w12\cmake-build-debug D:\Github\data-structure\w12\cmake-build-debug D:\Github\data-structure\w12\cmake-build-debug\CMakeFiles\w12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/w12.dir/depend
