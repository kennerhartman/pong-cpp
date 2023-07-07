//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <iostream>

// raylib API
#include "../include/raylib/raylib.h"

using namespace std;

int main() {
    // initialization of program
    const int screenWidth = 858;
    const int screenHeight = 525;
    const char* TITLE = "Game";

    int square_x = 100;
    int square_y = 100;
    int square_speed_x = 5;
    int square_speed_y = 5;
    int square_width = 10;
    int square_height = 10;

    InitWindow(screenWidth, screenHeight, TITLE);
    SetTargetFPS(60);
    
    // if uncommented, stop program from exiting by pressing ESC key
    // SetExitKey(KEY_NULL);

    // game loop and updates
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        square_x += square_speed_x;
        square_y += square_speed_y;

        if(square_x + square_width >= screenWidth  || square_x - square_width <= 0) {
            square_speed_x *= -1;
        }

        if(square_y + square_height >= screenHeight  || square_y - square_height <= 0) {
            square_speed_y *= -1;
        }

        DrawRectangle(square_x, square_y, 10, 10, WHITE);
        EndDrawing();
    }

    // deinitialization of program
    CloseWindow();

    return 0;
}