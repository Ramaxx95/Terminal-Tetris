#include "gameloop.h"
#include "../controller/input.h"

GameLoop::GameLoop() : is_running(true), player(Player()), game_board(Board()) {}

int GameLoop::start(){

    // Setear GameWindow

    /*** DEBUG ***/
    int counter = 0;
    /*** DEBUG ***/

    // pieza con la que arranca el jugador
    this->game_board.generateNewPiece();

    // byte que guarda el input recibido (para DEBUG nada mas)
    uint8_t input_received = 0;

    // Inicializo el input del jugador
    Input player_input = Input(this->is_running);

    while (this->is_running) {
        
        std::cout << "[DEBUG] Jugador: " << this->player.getName()
                  << " Score: " << this->player.getScore() << std::endl;

        input_received = player_input.getInput();
        if(input_received){
            std::cout << "[DEBUG] Input recibido: " << (int) input_received << std::endl;
        }

        if(this->game_board.playerReachedTop()){
            std::system("clear");
            std::cout << "\t\tFin del juego!" << std::endl 
                      << "\t\tJugador: " << this->player.getName() << std::endl
                      << "\t\tScore:   " << this->player.getScore() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));

            this->is_running = false;
            continue;
        }
        
        if(this->game_board.playerPieceReachedBottom() || this->game_board.playerPieceStopped()){
            int score_achieved = this->game_board.clearLinesOfBlocks();
            this->player.updateScore(score_achieved);
            this->game_board.generateNewPiece();
        }

        this->game_board.update();
        this->game_board.showBoard();
        counter++;
        
        //TODO: reemplazar el 'sleep' por el 'counter' de arriba -> una vez que el counter llega
        //      a un umbral dado por el 'level' actual, que se actualice la pantalla, score, etc.
        //      Mientras NO se haya llegado al umbral, el jugador puede mover y rotar su pieza.
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
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
