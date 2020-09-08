#ifndef GAME_H
#define GAME_H

#include "MacDonald.h"
#include "TimeManager.h"
#include <sstream>

class Game {
    private:
    MacDonald player;
    TimeManager timeGame;
    public:
    Game();
    void handleUserInput( std::string input );
    void update();

    void run();
};

#endif