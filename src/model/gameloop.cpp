#include "gameloop.h"

GameLoop::GameLoop() : is_running(true) {}

int GameLoop::start(){

    // Setear Player

    // Setear GameWindow

    // Setear Board

    while (this->is_running) {
        /* code */
        this->is_running = false;
    }
    
    return 0;
}

void GameLoop::determineEndGame(){

    // if(this->game_board.noSpaceLeft()){
    //     this->is_running = false;
    // }
}

GameLoop::~GameLoop() {}
