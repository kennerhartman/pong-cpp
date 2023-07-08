//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#ifndef _GUI_HPP

extern int SCREEN_HEIGHT; // screen height
extern int SCREEN_WIDTH; // screen width
extern int BORDER_WIDTH; // border width
extern int BORDER_HEIGHT; // border height

class GUI {
    public:
        void board();
    
    private:
        void border();
};

#endif