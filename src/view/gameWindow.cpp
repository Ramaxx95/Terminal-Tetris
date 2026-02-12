#include "gameWindow.h"

GameWindow::GameWindow(Player& player) : player(player) {}

void GameWindow::showWindow(std::vector<std::vector<char>>& game_board, int game_level) {

    // Mostramos la info del jugador
    mvprintw(1, 22, "Player: %s", this->player.getName().c_str());
    mvprintw(2, 22, "Score:  %d", this->player.getScore());
    mvprintw(3, 22, "Level:  %d", game_level);

    size_t row_size = game_board.size();
    size_t column_size = game_board[0].size();
    
    // Mostramos la tabla del juego
    for(size_t i = row_size - 1; i > 0; i--){

        mvprintw(i, 0, "<|");

        for(size_t j = 1; j < column_size + 1; j++){

            if(game_board[i][j - 1] == '1'){
                mvprintw(i, j*2, "[]");
            }
            else {
                mvprintw(i, j*2, "..");
            }
        }

        mvprintw(i, 18, "|>");

    }
    mvprintw(row_size, 0, "====================");
}

void GameWindow::showEndGame(){

    clear();
    mvprintw(5, 5, "Game Over!");
    mvprintw(6, 5, "Player: %s", this->player.getName().c_str());
    mvprintw(7, 5, "Score:  %d", this->player.getScore());
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

GameWindow::~GameWindow() {}