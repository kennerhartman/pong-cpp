//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <string>
#include <iostream>
#include "gui.hpp"
#include "../game/game.hpp"
#include "../../include/raylib/raylib.h"

// set screen dimensions
int SCREEN_HEIGHT = 525;
int SCREEN_WIDTH = 858;
int BORDER_HEIGHT = 10;
int BORDER_WIDTH = 8;

// player scores
int PLAYER_ONE_SCORE = 0;
int PLAYER_TWO_SCORE = 0;

#define NUM_FRAMES 3

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

int GUI::menu(struct Texture button, int x_pos, int y_pos, std::string action, bool debugMode) {
    // loads Games class which stores all of our Pong game types
    Games GamesObj;

    // create button texture, frames, and bounds
    float frameHeight = (float)button.height / NUM_FRAMES;
    Rectangle rectangleFrame = { 0, 0, (float)button.width, frameHeight };
    
    Rectangle btnBounds = { 
        x_pos - button.width / 2.0f, 
        (y_pos - button.height / NUM_FRAMES / 2.0f), 
        (float)button.width, 
        frameHeight - 22
    };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction;                 // An action to be taken if true

    Vector2 mousePoint = { 0.0f, 0.0f };
    
    mousePoint = GetMousePosition();
    btnAction = false;

    // Check button state
    if (CheckCollisionPointRec(mousePoint, btnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
    }
    else btnState = 0;

    // button actions
    if (btnAction && action == "2P") {
        GamesObj.twoPlayerPong(debugMode);
    } else if (btnAction && action == "EXIT") {
        return 1; // break the game loop in main.cpp
    }

    // Calculate button frame rectangle to draw depending on button state
    rectangleFrame.y = btnState * frameHeight;

    DrawTextureRec(button, rectangleFrame, (Vector2){ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
    return 0;
}

bool GUI::debugMode(Rectangle pong, int pong_speed_y, bool debugModeIsOn) {
    if (debugModeIsOn) {
        // pong speed
        char pong_speed_text[16];
        sprintf(pong_speed_text, "%d", pong_speed_y);
        DrawText("Pong y speed: ", 5, SCREEN_HEIGHT - 75, 15, RED);
        DrawText(pong_speed_text, 110, SCREEN_HEIGHT - 75, 15, RED);        

        // pong x position
        char pong_x_pos[16];
        sprintf(pong_x_pos, "%f", pong.x);
        DrawText("Pong x position: ", 5, SCREEN_HEIGHT - 50, 15, RED);
        DrawText(pong_x_pos, 125, SCREEN_HEIGHT - 50, 15, RED);

        // pong y position
        char pong_y_pos[16];
        sprintf(pong_y_pos, "%f", pong.y);
        DrawText("Pong y position: ", 5, SCREEN_HEIGHT - 25, 15, RED);
        DrawText(pong_y_pos, 125, SCREEN_HEIGHT - 25, 15, RED);

        // frame time   
        DrawFPS(SCREEN_WIDTH - 77, SCREEN_HEIGHT - 25, WHITE);

        return true;
    }

    return false;
}