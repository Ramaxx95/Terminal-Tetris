#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <iostream>
#include <chrono>
#include <thread>

#include "player.h"
#include "board.h"

#define BASE_LEVEL_COUNTER 40
#define MAX_LEVEL_COUNTER 10

// Clase encargada del loop de juego
class GameLoop {

    private:
        bool is_running;
        Player player; 
        int counter;
        int level;
        int lines_cleared;
        Board game_board;

    public:
        GameLoop();
        int start();
        ~GameLoop();
}; 

#endif //GAMELOOP_H
