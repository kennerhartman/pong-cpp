//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

// my API 
#include "../include/paddle/paddle.hpp"
#include "gui/gui.hpp"

// "textures" for buttons
#include "../resources/textures_binary/one_player_button.hpp"
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

    // "sprite sheet" for '1P' button
    Image onePlayerImage = {
        .data = ONE_PLAYER_BUTTON_DATA,
        .width = ONE_PLAYER_BUTTON_WIDTH,
        .height = ONE_PLAYER_BUTTON_HEIGHT,
        .mipmaps = 1,
        .format = ONE_PLAYER_BUTTON_FORMAT
    };

    // "sprite sheet" for '2P' button
    Image twoPlayerImage = {
        .data = TWO_PLAYER_BUTTON_DATA,
        .width = TWO_PLAYER_BUTTON_WIDTH,
        .height = TWO_PLAYER_BUTTON_HEIGHT,
        .mipmaps = 1,
        .format = TWO_PLAYER_BUTTON_FORMAT
    };

    // "sprite sheet" for 'EXIT' button
    Image exitImage = {
        .data = EXIT_BUTTON_DATA,
        .width = EXIT_BUTTON_WIDTH,
        .height = EXIT_BUTTON_HEIGHT,
        .mipmaps = 1,
        .format = EXIT_BUTTON_FORMAT
    };

    // load textures from "sprite sheets"
    Texture2D onePlayerButton = LoadTextureFromImage(onePlayerImage); 
    Texture2D twoPlayerButton = LoadTextureFromImage(twoPlayerImage); 
    Texture2D exitButton = LoadTextureFromImage(exitImage); 

    // game loop and updates
    while(!WindowShouldClose()) { 
        BeginDrawing();
            DrawText("pong", (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - SCREEN_HEIGHT) + 50, 55, WHITE);
            
            GUIObj.menu(onePlayerButton, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 40, "1P", true); // button for starting 1P game
            GUIObj.menu(twoPlayerButton, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 45, "2P", true); // button for starting 2P game
            int shouldBreakLoop = GUIObj.menu(exitButton, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + (exitImage.height / 3.7) + 45, "EXIT", false); // button for exiting game
        EndDrawing();

        if (shouldBreakLoop == 1) {
            break;
        }
    }

    // unload textures
    UnloadTexture(onePlayerButton);
    UnloadTexture(twoPlayerButton);
    UnloadTexture(exitButton);

    // deinitialization of program
    CloseWindow();

    return 0;
}