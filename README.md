# Overview

What game is better to recreate than Pong?  This is my implementation of Pong for C++.  This project uses Raylib (see [#External API](#external-api) to learn how to install).

# Compiling

Ensure you have a C++ compiler installed (I am using GNU G++) and GNU Make installed.  Clone this project into a directory.  Follow the steps in [#External API](#external-api) to install Raylib.  Once you are done, run ```make all``` and an executable will outputed to /bin in the root of the project.

If you want the debug version, run ```make all mode=debug```.  If not, or the incorrect arguments are supplied, you will get the regular version.

# App Bundle

For macOS, you can create an app bundle by running ```make macOSBundle```, which will compile the program and then run a shell script.  If you want the debug version, run ```make macOSBundle mode=debug```.  If not, or the incorrect arguments are supplied, you will get the regular version.

# Playing

Player one: W (up) and S (down)

Player two: Up arrow and down arrow

# External API

This software uses an external library called Raylib (See [LICENSE.md](LICENSE.md) for more information).  This repository already includes the necessary library and header files.  If you want to download and compile the library yourself, here are the steps to do so:

- [Download ZIP](https://github.com/raysan5/raylib/archive/refs/heads/master.zip) from raylib repo

1. Unzip the contents of the ZIP
2. From there, open an instance of a terminal and cd to the source directory of the unziped folder "raylib-master/src"
3. In the terminal, run ```make PLATFORM=PLATFORM_DESKTOP```
4. In /src, a file named 'libraylib.a' should have been generated
5. In the root of this project, create the directory 'lib' and subdirectory 'raylib'
6. In the root of this project, create the directory 'include' directory and subdirectory 'raylib'
7. Move 'libraylib.a' from "raylib-master/src" into 'lib/raylib'
8. Move 'raylib.h' from "raylib-master/src" into 'include/raylib'

# License

This project uses the MIT license. Please ensure you retain the license notice if you use any part of my program. For more information about the licensing of this project, please see [LICENSE.md](LICENSE.md).