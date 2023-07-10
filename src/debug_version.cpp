//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

// my API 
#include "../include/paddle/paddle.hpp"
#include "gui/gui.hpp"

// raylib API
#include "../include/raylib/raylib.h"

using namespace std;

bool debugMode(Rectangle pong, int pong_speed_y, bool debugModeIsOn);
int resetPong(string whatToReturn);
void twoPlayerPong();

int main() {
    // initialization of program
    const char* TITLE = "Pong C++";

    // initialization of program
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);
    
    // TODO: Main menu and single-player

    // this function handles the logic of the two-player game, as well as game loop and updates
    twoPlayerPong();

    // deinitialization of program
    CloseWindow();

    return 0;
}

void twoPlayerPong() {
    // paddle positions
    int playerone = (SCREEN_HEIGHT / 2);
    int playertwo = (SCREEN_HEIGHT / 2);

    // create pong, set pong positions and speed
    int pong_xpos = (SCREEN_WIDTH / 2);
    int pong_ypos = (SCREEN_HEIGHT / 2);
    int pong_speed_x = -9; // ball goes to the left of the screen (paddle of player one)
    int pong_speed_y = 0;
    Rectangle pong = { static_cast<float>(pong_xpos), static_cast<float>(pong_ypos), 10, 10 };

    // objects for internal API methods
    DrawPaddle DrawPaddleObj;
    GUI GUIObj;
    Input InputObj;

    // game loop and updates for this function
    while (true) {
        // begin drawing the "canvus"
        BeginDrawing();
        ClearBackground(BLACK);
        
        // draw GUI
        GUIObj.board();

        // to turn on debug mode, change 'false' to 'true'
        bool debug = debugMode(pong, pong_speed_y, true);

        // draw pong and initiate speed 
        DrawRectangleRec(pong, WHITE);
        pong.x += pong_speed_x;
        pong.y += pong_speed_y;

        // player one paddle creationg and movement 
        DrawPaddleObj.drawPaddle(15, playerone, debug);
        playerone += InputObj.playerControls("playerone", playerone);

        // player one paddle collisions with pong
        if (CheckCollisionRecs(pong, paddleTop)) {
            pong_speed_y += GetRandomValue(1, 4);

            // stop the pong from having a speed of 0
            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        } else if (CheckCollisionRecs(pong, paddleBottom)) {
            pong_speed_y -= GetRandomValue(1, 4);

            // stop the pong from having a speed of 0
            if (pong_speed_y == 0) {
                pong_speed_y -= GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        }

        // player two paddle creationg and movement 
        DrawPaddleObj.drawPaddle(SCREEN_WIDTH - 25, playertwo, debug);
        playertwo += InputObj.playerControls("playertwo", playertwo);
        
        // player two paddle collisions with pong 
        if (CheckCollisionRecs(pong, paddleTop)) {
            pong_speed_y += GetRandomValue(1, 4);

            // stop the pong from having a speed of 0
            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        } else if (CheckCollisionRecs(pong, paddleBottom)) {
            pong_speed_y -= GetRandomValue(1, 4);

            // stop the pong from having a speed of 0
            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        }

        // pong collision checks with bottom and top of screen
        if (pong.y >= SCREEN_HEIGHT - BORDER_HEIGHT) {
            pong_speed_y *= -1;
        } else if (pong.y <= BORDER_HEIGHT) {
            pong_speed_y *= -1;
        }

        // reset pong on score
        if (pong.x >= SCREEN_WIDTH) { // left side of the screen, right side scores
            pong.x = resetPong("pong_xpos");
            pong.y = resetPong("pong_ypos");
            pong_speed_y = resetPong("0");
            GUIObj.score("one");

            playerone = (SCREEN_HEIGHT / 2);
            playertwo = (SCREEN_HEIGHT / 2);
        } 
        else if (pong.x <= 0) { // right side of the screen, left side scores
            pong.x = resetPong("pong_xpos");
            pong.y = resetPong("pong_ypos");
            pong_speed_y = resetPong("0");
            GUIObj.score("two");

            playerone = (SCREEN_HEIGHT / 2);
            playertwo = (SCREEN_HEIGHT / 2);
        }

        GUIObj.displayScore();

        EndDrawing();

        if (IsKeyDown(KEY_ESCAPE)) { // exit loop which will then close window
            break;
        }
    }
}

int resetPong(string whatToReturn) {
    if (whatToReturn == "pong_ypos") {
        return SCREEN_HEIGHT / 2;
    } else if (whatToReturn == "pong_xpos") {
        return SCREEN_WIDTH / 2;
    }

    return 0;
}

bool debugMode(Rectangle pong, int pong_speed_y, bool debugModeIsOn) {
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

        return true;
    }

    return false;
}