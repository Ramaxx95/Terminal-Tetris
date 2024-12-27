#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <chrono>
#include <thread>
#include <limits>
#include <ios>

#include "gameloop.h"

#define PLAY_GAME 1
#define SEE_HIGHSCORES 2
#define QUIT_GAME 3

// Clase principal del programa
class Game {

    private:
        bool is_running;

    public:
        Game();
        int start();
        ~Game();
}; 

#endif //GAME_H
