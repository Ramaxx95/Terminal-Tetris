#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <iostream>
// DEBUG
#include <chrono>
#include <thread>
// DEBUG

#include "player.h"
#include "board.h"

class GameLoop {

    private:
        bool is_running;
        Player player; 
        // GameWindow window;
        Board game_board;

        void determineEndGame();

    public:
        GameLoop();
        int start();
        ~GameLoop();
}; 

#endif //GAMELOOP_H
