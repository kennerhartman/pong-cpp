# output directory of executable
directory = bin

# if you supply 'mode=debug', the debug version of the application will be outputted.
# if you do not supply any arguments, (or do not type 'mode' or 'debug' exactly),
# the output will be the regular application. 
ifeq ($(mode), debug) 
	exeName = debug_pong
	CXX_FILE = src/debugVersion.cpp
else
	exeName = pong
	CXX_FILE = src/main.cpp
endif

# check whether the target directory $(directory) is present
dir_target = $(directory)-$(wildcard $(directory))
dir_present = $(directory)-$(directory)
dir_absent = $(directory)-

# MacOS throws errors if a standard is not defined
# set the proper flags for 'raylib' for the proper platforms (Windows or MacOS)
ifeq ($(OS), Windows_NT)
	CXX = g++
	raylib = -static -mwindows -L lib/* -lraylib -lopengl32 -lgdi32 -lwinmm
else
	CXX = g++ -std=c++20
	raylib = -mwindows -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/raylib/libraylib.a
endif

myInclude = src/gui/gui.cpp include/paddle/paddle.cpp

# must include '-static' for Windows computers that do not have MingGW 
all: | $(dir_target)
	$(CXX) \
	$(CXX_FILE) -o $(directory)/$(exeName) \
	-O2 -Wall -Wno-missing-braces \
	$(myInclude) \
	$(raylib)

# if target directory $(directory) is present, echo "Folder $(directory) exists"
$(dir_present):
	@echo "Folder '$(directory)' already exists"

# if target directory $(directory) is present, created a directory named $(directory)
$(dir_absent):
	@echo "Creating a directory '$(directory)'"
	@mkdir $(directory)