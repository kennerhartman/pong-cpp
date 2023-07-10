#
# Copyright (c) 2023 by Kenner Hartman. All rights reserved.
# Licensed under the MIT license. See LICENSE.md file in the project root for details.
#

# output directory of executable
directory = bin

# if you supply 'mode=debug', the debug version of the application will be outputted.
# if you do not supply any arguments, (or do not type 'mode' or 'debug' exactly),
# the output will be the regular application. 
ifeq ($(mode), debug) 
	exeName = debug_pong
	CXX_FILE = src/debug_version.cpp
else
	exeName = pong
	CXX_FILE = src/main.cpp
endif

# check whether the target directory $(directory) is present
dir_target = $(directory)-$(wildcard $(directory))
dir_present = $(directory)-$(directory)
dir_absent = $(directory)-

# macOS throws errors if a standard is not defined
# set the proper flags for 'raylib' for the proper platforms (Checks if Windows, else macOS).
#
# -mwindows disables console and opens only the GUI application (Windows only)
# -static makes the executable transferable between computers (Windows only)
# 'assets = resources/assets/pong.rc.data' (Windows only)
ifeq ($(OS), Windows_NT)
	CXX = g++
	raylib = -static -mwindows -L lib/* -lraylib -lopengl32 -lgdi32 -lwinmm
	assets = resources/assets/pong.rc.data
else
	CXX = g++ -std=c++20
	raylib = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/raylib/libraylib.a
endif

myInclude = src/gui/gui.cpp src/game/game.cpp include/paddle/paddle.cpp

all: | $(dir_target)
	$(CXX) \
	$(CXX_FILE) -o $(directory)/$(exeName) \
	-O2 -Wall -Wno-missing-braces \
	$(assets) \
	$(myInclude) \
	$(raylib)

# if target directory $(directory) is present, echo "Folder $(directory) exists"
$(dir_present):
	@echo "Folder '$(directory)' already exists"

# if target directory $(directory) is present, created a directory named $(directory)
$(dir_absent):
	@echo "Creating a directory '$(directory)'"
	@mkdir $(directory)