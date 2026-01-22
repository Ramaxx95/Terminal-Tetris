#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <iostream>
// DEBUG
#include <chrono>
#include <thread>
// DEBUG

#include "player.h"
#include "board.h"

#define BASE_LEVEL_COUNTER 25000
#define MAX_LEVEL_COUNTER 10000

// Clase encargada del loop de juego
class GameLoop {

    private:
        bool is_running;
        Player player; 
        int counter;
        int level;
        int lines_cleared;
        Board game_board;

        void determineEndGame();

    public:
        GameLoop();
        int start();
        ~GameLoop();
}; 

#endif //GAMELOOP_H
