//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include "gui.hpp"
#include "../../include/raylib/raylib.h"

// set screen dimensions
int SCREEN_HEIGHT = 525;
int SCREEN_WIDTH = 858;
int BORDER_HEIGHT = 10;
int BORDER_WIDTH = 8;

// functions for drawing the GUI

void GUI::board() {
    for (int i = 19; i < SCREEN_HEIGHT; i += 21) {
        DrawRectangle(SCREEN_WIDTH / 2, SCREEN_HEIGHT - i, 8, 14, WHITE);
    }

    GUI GUIObj;
    GUIObj.border();
}

void GUI::border() {
    DrawRectangle(0, SCREEN_HEIGHT - (BORDER_HEIGHT / 2), SCREEN_WIDTH, BORDER_HEIGHT, WHITE);
    DrawRectangle(0, SCREEN_HEIGHT - SCREEN_HEIGHT - (BORDER_HEIGHT / 2), SCREEN_WIDTH, 10, WHITE);
}

/* 
    TODO: 
    
    score board

    extern scoreForPlayerOne in gui.hpp
    extern scoreForPlayerTwo in gui.hpp
*/
