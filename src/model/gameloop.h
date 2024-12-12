#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <iostream>

class GameLoop {

    private:
        bool is_running;
        // Player player; -> {score, tetrimino, name}
        // GameWindow window;
        // Board game_board;

        void determineEndGame();

    public:
        GameLoop();
        int start();
        ~GameLoop();
}; 

#endif //GAMELOOP_H
