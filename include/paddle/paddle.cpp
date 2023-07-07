#include "paddle.hpp"
#include "../raylib/raylib.h"

#include <iostream>
#include <string>

void DrawPaddle::drawPaddle(int posx, int posy) {
    paddle paddle;
    paddle.posx = 15;

    DrawRectangle(posx, posy, paddle.width, paddle.height, WHITE);
}

int Input::playerControls(std::string player, int posy) {
    paddle paddle;

    if (player == "playerone") {
        // if 'posy >= 0' is TRUE, then playerone can move up
        if (posy >= 0) { 
            if (IsKeyDown(KEY_W)) {
                // std::cout << posy << "\n";
                return (-7);
            }
        } 

        // if 'posy + paddle.height <= SCREEN_HEIGHT' is TRUE, then playerone can move down
        if (posy + paddle.height <= SCREEN_HEIGHT) {
            if (IsKeyDown(KEY_S)) {
                // std::cout << posy << "\n";
                return (7);
            }
        }
    }

    // if 'posy >= 0' is TRUE, then playertwo can move up
    if (player == "playertwo") {
        if (posy >= 0) { 
            if (IsKeyDown(KEY_UP)) {
                // std::cout << posy << "\n";
                return (-7);
            }
        } 

        // if 'posy + paddle.height <= SCREEN_HEIGHT' is TRUE, then playertwo can move down
        if (posy + paddle.height <= SCREEN_HEIGHT) {
            if (IsKeyDown(KEY_DOWN)) {
                // std::cout << posy << "\n";
                return (7);
            }
        }
    }

    // if nothing has happened, no position change (aka, 0 pixels);
    return 0;
}