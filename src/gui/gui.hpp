//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#ifndef _GUI_HPP

#include <string>

extern int SCREEN_HEIGHT; // screen height
extern int SCREEN_WIDTH; // screen width
extern int BORDER_WIDTH; // border width
extern int BORDER_HEIGHT; // border height

extern int PLAYER_ONE_SCORE; // left side player
extern int PLAYER_TWO_SCORE; // right side player

class GUI {
    public:
        // strictly-GUI related functions

        void board();
        void score(std::string player);
        void displayScore();

        // menu and debug GUI functions

        int menu(struct Texture button, int x_pos, int y_pos, std::string action, bool debugMode);
        bool debugMode(struct Rectangle pong, int pong_speed_y, bool debugModeIsOn);
    
    private:
        void border();
        int SCORE_TEXT_SIZE = 55;
};

#endif