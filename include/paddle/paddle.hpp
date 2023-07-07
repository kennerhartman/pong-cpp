#ifndef _PADDLE_HPP

#include <string>
#include "../raylib/raylib.h"
#include "../../src/gui/gui.hpp"

struct paddle {
    int height = 55;
    int width = 10;
    int posx;
};

class DrawPaddle {
    public:
        // draw a paddle based on a x position and y position.  
        void drawPaddle(int posx, int posy);
};

class Input {
    public:
        // player movement for players one and two
        int playerControls(std::string player, int posy);
};


#endif