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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Franco\CLionProjects\template-alumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/template_alumnos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/template_alumnos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template_alumnos.dir/flags.make

CMakeFiles/template_alumnos.dir/src/main.cpp.obj: CMakeFiles/template_alumnos.dir/flags.make
CMakeFiles/template_alumnos.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template_alumnos.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\template_alumnos.dir\src\main.cpp.obj -c C:\Users\Franco\CLionProjects\template-alumnos\src\main.cpp

CMakeFiles/template_alumnos.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_alumnos.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Franco\CLionProjects\template-alumnos\src\main.cpp > CMakeFiles\template_alumnos.dir\src\main.cpp.i

CMakeFiles/template_alumnos.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_alumnos.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Franco\CLionProjects\template-alumnos\src\main.cpp -o CMakeFiles\template_alumnos.dir\src\main.cpp.s

CMakeFiles/template_alumnos.dir/src/vectores.cpp.obj: CMakeFiles/template_alumnos.dir/flags.make
CMakeFiles/template_alumnos.dir/src/vectores.cpp.obj: ../src/vectores.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/template_alumnos.dir/src/vectores.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\template_alumnos.dir\src\vectores.cpp.obj -c C:\Users\Franco\CLionProjects\template-alumnos\src\vectores.cpp

CMakeFiles/template_alumnos.dir/src/vectores.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_alumnos.dir/src/vectores.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Franco\CLionProjects\template-alumnos\src\vectores.cpp > CMakeFiles\template_alumnos.dir\src\vectores.cpp.i

CMakeFiles/template_alumnos.dir/src/vectores.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_alumnos.dir/src/vectores.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Franco\CLionProjects\template-alumnos\src\vectores.cpp -o CMakeFiles\template_alumnos.dir\src\vectores.cpp.s

# Object files for target template_alumnos
template_alumnos_OBJECTS = \
"CMakeFiles/template_alumnos.dir/src/main.cpp.obj" \
"CMakeFiles/template_alumnos.dir/src/vectores.cpp.obj"

# External object files for target template_alumnos
template_alumnos_EXTERNAL_OBJECTS =

../template_alumnos.exe: CMakeFiles/template_alumnos.dir/src/main.cpp.obj
../template_alumnos.exe: CMakeFiles/template_alumnos.dir/src/vectores.cpp.obj
../template_alumnos.exe: CMakeFiles/template_alumnos.dir/build.make
../template_alumnos.exe: CMakeFiles/template_alumnos.dir/linklibs.rsp
../template_alumnos.exe: CMakeFiles/template_alumnos.dir/objects1.rsp
../template_alumnos.exe: CMakeFiles/template_alumnos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\template_alumnos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\template_alumnos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template_alumnos.dir/build: ../template_alumnos.exe

.PHONY : CMakeFiles/template_alumnos.dir/build

CMakeFiles/template_alumnos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\template_alumnos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/template_alumnos.dir/clean

CMakeFiles/template_alumnos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Franco\CLionProjects\template-alumnos C:\Users\Franco\CLionProjects\template-alumnos C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug C:\Users\Franco\CLionProjects\template-alumnos\cmake-build-debug\CMakeFiles\template_alumnos.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template_alumnos.dir/depend

