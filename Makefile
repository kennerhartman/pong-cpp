# output directory of executable
directory = bin

# check whether the target directory $(directory) is present
dir_target = $(directory)-$(wildcard $(directory))
dir_present = $(directory)-$(directory)
dir_absent = $(directory)-

# MacOS throws errors if a standard is not defined
# set the proper flags for 'raylib' for the proper platforms (Windows or MacOS)
ifeq ($(OS), Windows_NT)
	CXX = g++
	raylib = -L lib/* -lraylib -lopengl32 -lgdi32 -lwinmm
else
	CXX = g++ -std=c++20
	raylib = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/raylib/libraylib.a
endif

myInclude = src/gui/gui.cpp include/paddle/paddle.cpp

all: | $(dir_target)
	$(CXX) \
	src/main.cpp -o $(directory)/main \
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