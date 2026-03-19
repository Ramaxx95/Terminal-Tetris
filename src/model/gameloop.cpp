#include "gameloop.h"
#include "../controller/input.h"
#include "../controller/inputManager.h"
#include "../view/gameWindow.h"

GameLoop::GameLoop() : 
    is_running(true), 
    player(Player()), 
    counter(0), 
    level(1), 
    lines_cleared(0), 
    game_board(Board()), 
    fileManager(FileManager()) {}

int GameLoop::start(){

    int curr_level_counter = BASE_LEVEL_COUNTER;

    // pieza con la que arranca el jugador
    this->game_board.generateNewPiece();

    // byte que guarda el input recibido (para DEBUG nada mas)
    uint8_t input_received = 0;
    InputManager inputManager = InputManager();

    // Inicializo el input del jugador (ahora hay que usar ncurses)
    Input player_input = Input(this->is_running);

    // Inicializo la pantalla de juego
    GameWindow window = GameWindow(this->player);
    std::vector<std::vector<char>> board; 

    while (this->is_running) {

        input_received = player_input.getInput();

        if(this->counter >= curr_level_counter){
            
            if(this->game_board.playerReachedTop()){
                fileManager.addScore(this->player.getName(), this->player.getScore());
                window.showEndGame();
                this->is_running = false;
                continue;
            }
            
            if(this->game_board.playerPieceReachedBottom() || this->game_board.playerPieceStopped()){
                int score_achieved = this->game_board.clearLinesOfBlocks(this->level, this->lines_cleared);
                this->player.updateScore(score_achieved);
                if(this->lines_cleared >= 10) {
                    this->level++;
                    this->lines_cleared = 0;
                    if(curr_level_counter > MAX_LEVEL_COUNTER){
                        curr_level_counter -= 5;
                    }
                    else {
                        curr_level_counter = MAX_LEVEL_COUNTER;
                    }
                }
                this->game_board.generateNewPiece();
            }
            
            this->game_board.update();
            this->counter = 0;
        }
        else {
            game_board.movePiece(inputManager.interpretInput(input_received));
        }

        this->counter++;

        // DEBUG
        // int x = 0, y = 0, height = 0;
        // this->game_board.getPlayerPosition(x, y, height); 
        // mvprintw(5, 22, "Pieza actual: (%d, %d) ", x, y); 
        // mvprintw(6, 22, "Posicion mas baja: %d ", height + y);
        // mvprintw(7, 22, "Counter: %d ", counter);
        // END DEBUG

        board = this->game_board.getBoard();
        window.showWindow(board, this->level);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
       
    }

    return 0;
}

GameLoop::~GameLoop() {}
