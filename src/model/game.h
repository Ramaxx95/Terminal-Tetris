#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <chrono>
#include <thread>

#include "gameloop.h"

#define PLAY_GAME 1
#define SEE_HIGHSCORES 2
#define QUIT_GAME 3

class Game {

    private:
        bool is_running;

    public:
        Game();
        int start();
        ~Game();
}; 

#endif //GAME_H
