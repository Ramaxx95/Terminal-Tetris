#include "gameloop.h"

GameLoop::GameLoop() : is_running(true), player(Player()) {}

int GameLoop::start(){

    // Setear GameWindow

    // Setear Board

    while (this->is_running) {
        /* code */
        std::cout << "[DEBUG] El juego esta corriendo...\n";
        std::cout << "[DEBUG] Jugador: " << this->player.getName()
                  << " Score: " << this->player.getScore() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
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
