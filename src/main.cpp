//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//



#include <iostream>

#include "../include/paddle/paddle.hpp"
#include "gui/gui.hpp"

// raylib API
#include "../include/raylib/raylib.h"

using namespace std;

int main() {
    // initialization of program
    const char* TITLE = "Pong";
    
    // paddle positions
    int playerone = SCREEN_HEIGHT / 2;
    int playertwo = SCREEN_HEIGHT / 2;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);
    
    // if uncommented, stop program from exiting by pressing ESC key
    // SetExitKey(KEY_NULL);

    // game loop and updates
    while (!WindowShouldClose()) {
        DrawPaddle DrawPaddleObj;
        Input InputObj;
        
        BeginDrawing();
        ClearBackground(BLACK);

        DrawPaddleObj.drawPaddle(15, playerone);
        playerone += InputObj.playerControls("playerone", playerone);

        DrawPaddleObj.drawPaddle(SCREEN_WIDTH - 25, playertwo);
        playertwo += InputObj.playerControls("playertwo", playertwo);

        EndDrawing();
    }

    // deinitialization of program
    CloseWindow();

    return 0;
}