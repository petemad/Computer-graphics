# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/sohila/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sohila/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sohila/CLionProjects/ball-trial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sohila/CLionProjects/ball-trial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ball_trial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ball_trial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ball_trial.dir/flags.make

CMakeFiles/ball_trial.dir/main.cpp.o: CMakeFiles/ball_trial.dir/flags.make
CMakeFiles/ball_trial.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohila/CLionProjects/ball-trial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ball_trial.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ball_trial.dir/main.cpp.o -c /home/sohila/CLionProjects/ball-trial/main.cpp

CMakeFiles/ball_trial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ball_trial.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohila/CLionProjects/ball-trial/main.cpp > CMakeFiles/ball_trial.dir/main.cpp.i

CMakeFiles/ball_trial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ball_trial.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohila/CLionProjects/ball-trial/main.cpp -o CMakeFiles/ball_trial.dir/main.cpp.s

# Object files for target ball_trial
ball_trial_OBJECTS = \
"CMakeFiles/ball_trial.dir/main.cpp.o"

# External object files for target ball_trial
ball_trial_EXTERNAL_OBJECTS =

ball_trial: CMakeFiles/ball_trial.dir/main.cpp.o
ball_trial: CMakeFiles/ball_trial.dir/build.make
ball_trial: CMakeFiles/ball_trial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sohila/CLionProjects/ball-trial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ball_trial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ball_trial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ball_trial.dir/build: ball_trial

.PHONY : CMakeFiles/ball_trial.dir/build

CMakeFiles/ball_trial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ball_trial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ball_trial.dir/clean

CMakeFiles/ball_trial.dir/depend:
	cd /home/sohila/CLionProjects/ball-trial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sohila/CLionProjects/ball-trial /home/sohila/CLionProjects/ball-trial /home/sohila/CLionProjects/ball-trial/cmake-build-debug /home/sohila/CLionProjects/ball-trial/cmake-build-debug /home/sohila/CLionProjects/ball-trial/cmake-build-debug/CMakeFiles/ball_trial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ball_trial.dir/depend

