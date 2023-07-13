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
# Windows and macOS compile different 'libraylib.a' library files.  I used to have
# these files listed on .gitignore.  However, I have setup workflows which require
# the libraries to be on Github and Windows and macOS generate different
# 'libraylib.a' library files.  "lib/raylib/macos/libraylib.a" and
# "lib\raylib\windows\*"
#
# -mwindows disables console and opens only the GUI application (Windows only)
# -static makes the executable transferable between computers (Windows only)
# 'assets = resources/assets/pong.rc.data' (Windows only)
ifeq ($(OS), Windows_NT)
	CXX = g++
	raylib = -static -mwindows -L lib\raylib\windows\* -lraylib -lopengl32 -lgdi32 -lwinmm
	assets = resources/assets/pong.rc.data
else
	CXX = g++ -std=c++20
	raylib = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/raylib/macos/libraylib.a
endif

myInclude = src/gui/gui.cpp src/game/game.cpp include/paddle/paddle.cpp

all: | $(dir_target)
	$(CXX) \
	$(CXX_FILE) -o $(directory)/$(exeName) \
	-O2 -Wall -Wno-missing-braces \
	$(assets) \
	$(myInclude) \
	$(raylib)

image_to_hex:
	$(CXX) \
	src/image_to_hex.cpp -o $(directory)/image_to_hex \
	-O2 -Wall -Wno-missing-braces \
	$(raylib)

# it is important that you pass in $(directory), as defined at the top of the Makefile, 
# so the shell script can know which directory to create the app bundle for macOS.  
# I use /bin, someone else might use /build
#
# This command will first compile $(directory)/$(exeName) to make sure the executable is
# up to date.  Then we will run a shell script to bundle the executable into an app.
shell = zsh
script = ./bundle.sh $(directory)
macOSBundle: 
	@ echo
	@ echo "Compiling $(directory)/$(exeName) then bundling as an app..."
	@ make all
	$(shell) $(script) $(mode)

# if target directory $(directory) is present, echo "Folder $(directory) exists"
$(dir_present):
	@echo "Folder '$(directory)' already exists"

# if target directory $(directory) is present, created a directory named $(directory)
$(dir_absent):
	@echo "Creating a directory '$(directory)'"
	@mkdir $(directory)