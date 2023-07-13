//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#ifndef _GAME_HPP
#define _GAME_HPP

#include <string>

class Games {
    public:
        void twoPlayerPong(bool debugMode);
        void onePlayerPong(bool debugMode);
        int resetPong(std::string whatToReturn);
};

#endif