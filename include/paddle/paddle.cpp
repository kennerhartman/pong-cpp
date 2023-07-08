//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include "paddle.hpp"
#include "../../src/gui/gui.hpp"
#include "../raylib/raylib.h"

#include <iostream>
#include <string>

paddle paddleRec;
Rectangle paddleTop = {
    paddleRec.posx / 1.0f,
    paddleRec.posy / 1.0f,
    paddleRec.width / 1.0f,
    paddleRec.height / 1.0f
};

Rectangle paddleBottom = {
    paddleRec.posx / 1.0f,
    paddleRec.posy / 1.0f,
    paddleRec.width / 1.0f,
    paddleRec.height / 1.0f
};

void DrawPaddle::drawPaddle(int posx, int posy, bool debugMode) {
    paddle paddle;
    paddleTop.x = posx;
    paddleTop.y = posy;

    paddleBottom.x = posx;
    paddleBottom.y = posy - 29.5;

    DrawRectangleRec(paddleTop, WHITE);

    if (debugMode) {
        DrawRectangleRec(paddleBottom, RED);
    } else {
        DrawRectangleRec(paddleBottom, WHITE);
    }

}

int Input::playerControls(std::string player, int posy) {
    paddle paddle;

    if (player == "playerone") {
        // if 'posy >= BORDER_HEIGHT * 3.8 (38px)' is TRUE, then playerone can move up
        if (posy >= BORDER_HEIGHT * 3.8) {  // hardcoded the "collision" because this is a simple game
            if (IsKeyDown(KEY_W)) {
                // std::cout << posy << "\n";
                return (-9);
            }
        } 

        // if 'posy + paddle.height <= SCREEN_HEIGHT' is TRUE, then playerone can move down
        if (posy + paddle.height <= SCREEN_HEIGHT - BORDER_HEIGHT) {
            if (IsKeyDown(KEY_S)) {
                // std::cout << posy << "\n";
                return (9);
            }
        }
    }

    // if 'posy >= BORDER_HEIGHT * 3.8 (38px)' is TRUE, then playerone can move up
    if (player == "playertwo") {
        if (posy >= BORDER_HEIGHT * 3.8) { // hardcoded the "collision" because this is a simple game
            if (IsKeyDown(KEY_UP)) {
                // std::cout << posy << "\n";
                return (-9);
            }
        } 

        // if 'posy + paddle.height <= SCREEN_HEIGHT' is TRUE, then playertwo can move down
        if (posy + paddle.height <= SCREEN_HEIGHT - BORDER_HEIGHT) {
            if (IsKeyDown(KEY_DOWN)) {
                // std::cout << posy << "\n";
                return (9);
            }
        }
    }

    // if nothing has happened, no position change (aka, 0 pixels);
    return 0;
}