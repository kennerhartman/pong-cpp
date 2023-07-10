//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

// my API 
#include "../include/paddle/paddle.hpp"
#include "gui/gui.hpp"

// "textures" for buttons
#include "../resources/textures_binary/two_player_button.hpp"
#include "../resources/textures_binary/exit_button.hpp"

// raylib API
#include "../include/raylib/raylib.h"

int main() {
    // // initialization of program
    const char* TITLE = "Pong C++";
    GUI GUIObj;

    // initialization of program
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    // "sprite sheet" for '2P' button
    Image twoPlayerImage = {
        .data = TWO_PLAYER_BUTTON_DATA,
        .width = TWO_PLAYER_BUTTON_WIDTH,
        .height = TWO_PLAYER_BUTTON_HEIGHT,
        .format = TWO_PLAYER_BUTTON_FORMAT,
        .mipmaps = 1
    };

    // "sprite sheet" for 'EXIT' button
    Image exitImage = {
        .data = EXIT_BUTTON_DATA,
        .width = EXIT_BUTTON_WIDTH,
        .height = EXIT_BUTTON_HEIGHT,
        .format = EXIT_BUTTON_FORMAT,
        .mipmaps = 1
    };

    // load textures from "sprite sheets"
    Texture2D twoPlayer = LoadTextureFromImage(twoPlayerImage); 
    Texture2D exitButton = LoadTextureFromImage(exitImage); 

    // game loop and updates
    while(!WindowShouldClose()) { 
        BeginDrawing();
            DrawText("pong", (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - SCREEN_HEIGHT) + 50, 55, WHITE);
            int ShouldBreakLoop = GUIObj.menu(exitButton, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 39, "EXIT", true); // button for exiting game
            GUIObj.menu(twoPlayer, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 39, "2P", true); // button for starting 2P game
        EndDrawing();

        if (ShouldBreakLoop == 1) {
            break;
        }
    }

    // deinitialization of program
    CloseWindow();

    return 0;
}