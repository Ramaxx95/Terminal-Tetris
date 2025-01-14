#include "gameloop.h"

GameLoop::GameLoop() : is_running(true), player(Player()), game_board(Board()) {}

int GameLoop::start(){

    // Setear GameWindow

    this->game_board.showBoard();

    /*** DEBUG ***/
    int counter = 0;
    /*** DEBUG ***/

    // pieza con la que arranca el jugador
    this->game_board.generateNewPiece();

    while (this->is_running) {
        /* code */
        std::cout << "[DEBUG] El juego esta corriendo...\n";
        std::cout << "[DEBUG] Jugador: " << this->player.getName()
                  << " Score: " << this->player.getScore() << std::endl;

        if(counter == 5){
            this->is_running = false;
        }
        else {
            this->game_board.update();
            this->game_board.showBoard();
            counter++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::system("clear");
    }
    
    return 0;
}

void GameLoop::determineEndGame(){

    // if(this->game_board.noSpaceLeft()){
    //     this->is_running = false;
    // }
}

GameLoop::~GameLoop() {}
