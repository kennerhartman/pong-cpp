//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <string>
#include "gui.hpp"
#include "../../include/raylib/raylib.h"

// set screen dimensions
int SCREEN_HEIGHT = 525;
int SCREEN_WIDTH = 858;
int BORDER_HEIGHT = 10;
int BORDER_WIDTH = 8;

// player scores
int PLAYER_ONE_SCORE = 0;
int PLAYER_TWO_SCORE = 0;

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

void GUI::score(std::string player) {
    if(player == "one") { // player on left side of the screen
        ++PLAYER_ONE_SCORE;
    } else if (player == "two") {
        ++PLAYER_TWO_SCORE;
    }
}

void GUI::displayScore() {
    if (PLAYER_ONE_SCORE < 10) {
        char score_text[8];
        sprintf(score_text, "%i", PLAYER_ONE_SCORE);
        DrawText("0", (SCREEN_WIDTH / 5), (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
        DrawText(score_text, (SCREEN_WIDTH / 5) + 35, (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
    } else {
        char score_text[8];
        sprintf(score_text, "%i", PLAYER_ONE_SCORE);
        DrawText(score_text, (SCREEN_WIDTH / 5), (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
    }

    if (PLAYER_TWO_SCORE < 10) {
        char score_text[8];
        sprintf(score_text, "%i", PLAYER_TWO_SCORE);
        DrawText("0", (SCREEN_WIDTH / 1.35), (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
        DrawText(score_text, (SCREEN_WIDTH / 1.35) + 35, (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
    } else {
        char score_text[8];
        sprintf(score_text, "%i", PLAYER_TWO_SCORE);
        DrawText(score_text, (SCREEN_WIDTH / 1.35), (SCREEN_HEIGHT - SCREEN_HEIGHT) + 25, SCORE_TEXT_SIZE, WHITE);
    }
}

/* 
    TODO: 
    
    score board

    extern scoreForPlayerOne in gui.hpp
    extern scoreForPlayerTwo in gui.hpp
*/
