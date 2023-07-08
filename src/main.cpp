//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <iostream>
#include <math.h>


#include "../include/paddle/paddle.hpp"
#include "gui/gui.hpp"

// raylib API
#include "../include/raylib/raylib.h"

using namespace std;

bool debugMode(Rectangle ball, int pong_speed_y, bool debugModeIsOn);
int resetPong(string whatToReturn);

int main() {
    // initialization of program
    const char* TITLE = "Pong";
    
    // paddle positions
    int playerone = (SCREEN_HEIGHT / 2);
    int playertwo = (SCREEN_HEIGHT / 2);

    int ballxpos = (SCREEN_WIDTH / 2);
    int ballypos = (SCREEN_HEIGHT / 2);
    int pong_speed_x = 9;
    int pong_speed_y = 0;
    Rectangle ball = { static_cast<float>(ballxpos), static_cast<float>(ballypos), 10, 10 };

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

        bool debug = debugMode(ball, pong_speed_y, true);

        ball.x += pong_speed_x;
        ball.y += pong_speed_y;
        
        DrawRectangleRec(ball, WHITE);

        DrawPaddleObj.drawPaddle(15, playerone, debug);
        playerone += InputObj.playerControls("playerone", playerone);

        if (CheckCollisionRecs(ball, paddleTop)) {
            pong_speed_y += GetRandomValue(1, 4);

            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        } else if (CheckCollisionRecs(ball, paddleBottom)) {
            pong_speed_y -= GetRandomValue(1, 4);

            if (pong_speed_y == 0) {
                pong_speed_y -= GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        }

        DrawPaddleObj.drawPaddle(SCREEN_WIDTH - 25, playertwo, debug);
        playertwo += InputObj.playerControls("playertwo", playertwo);
        
        if (CheckCollisionRecs(ball, paddleTop)) {
            pong_speed_y += GetRandomValue(1, 4);

            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        } else if (CheckCollisionRecs(ball, paddleBottom)) {
            pong_speed_y -= GetRandomValue(1, 4);

            if (pong_speed_y == 0) {
                pong_speed_y += GetRandomValue(4, 7);
            }

            pong_speed_x *= -1.0;
        }

        if (ball.y >= SCREEN_HEIGHT) {
            pong_speed_y *= -1;
        } else if (ball.y <= 0) {
            pong_speed_y *= -1;
        }

        if (ball.x >= SCREEN_WIDTH) {
            ball.x = resetPong("ball_xpos");
            ball.y = resetPong("ball_ypos");
            pong_speed_y = resetPong("0");

            playerone = (SCREEN_HEIGHT / 2) - 25;
            playertwo = (SCREEN_HEIGHT / 2) - 25;
        } else if (ball.x <= 0) {
            ball.x = resetPong("ball_xpos");
            ball.y = resetPong("ball_ypos");
            pong_speed_y = resetPong("0");

            playerone = (SCREEN_HEIGHT / 2);
            playertwo = (SCREEN_HEIGHT / 2);
        }

        EndDrawing();
    }

    // deinitialization of program
    CloseWindow();

    return 0;
}

int resetPong(string whatToReturn) {
    if (whatToReturn == "ball_ypos") {
        return SCREEN_HEIGHT / 2;
    } else if (whatToReturn == "ball_xpos") {
        return SCREEN_WIDTH / 2;
    }

    return 0;
}

bool debugMode(Rectangle ball, int pong_speed_y, bool debugModeIsOn) {
    if (debugModeIsOn) {
        // pong speed
        char pong_speed_text[16];
        sprintf(pong_speed_text, "%d", pong_speed_y);
        DrawText("Pong y speed: ", 5, SCREEN_HEIGHT - 75, 15, RED);
        DrawText(pong_speed_text, 110, SCREEN_HEIGHT - 75, 15, RED);        

        // pong x position
        char pong_x_pos[16];
        sprintf(pong_x_pos, "%f", ball.x);
        DrawText("Pong x position: ", 5, SCREEN_HEIGHT - 50, 15, RED);
        DrawText(pong_x_pos, 125, SCREEN_HEIGHT - 50, 15, RED);

        // pong y position
        char pong_y_pos[16];
        sprintf(pong_y_pos, "%f", ball.y);
        DrawText("Pong y position: ", 5, SCREEN_HEIGHT - 25, 15, RED);
        DrawText(pong_y_pos, 125, SCREEN_HEIGHT - 25, 15, RED);

        return true;
    }

    return false;
}