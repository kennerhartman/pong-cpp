//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#ifndef _PADDLE_HPP

#include <string>
#include "../raylib/raylib.h"
#include "../../src/gui/gui.hpp"

extern Rectangle paddleTop;
extern Rectangle paddleBottom;

struct paddle {
    int posx;
    int posy;
    float height = 27.5;
    int width = 10;
};

class DrawPaddle {
    public:
        // draw a paddle based on a x position and y position.  
        void drawPaddle(int posx, int posy, bool debugMode);
};

class Input {
    public:
        // player movement for players one and two
        int playerControls(std::string player, int posy);
};


#endif