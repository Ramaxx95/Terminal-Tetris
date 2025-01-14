#include "board.h"

Board::Board() : top_reached(false) {
    this->game_board = {{'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'0','0','0','0','0','0','0','0'},
                        {'1','1','1','0','0','1','1','1'}};
}

int Board::update(){

    size_t row_size = this->game_board.size();
    size_t column_size = this->game_board[0].size();

    // updatePlayerPiece();
     
    for(size_t i = row_size; i > 0; i--){
        for(size_t j = 0; j < column_size; j++){

            if(this->game_board[i][j] != '1'){
                continue;
            }
            else if(j == column_size - 1){
                deleteFullRow(i);
            }
        }
    }
    return 0;
}

void Board::showBoard(){

    for(size_t i = 0; i < this->game_board.size(); i++){
        for(size_t j = 0; j < this->game_board[i].size(); j++){

            std::cout << this->game_board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Board::deleteFullRow(size_t row){

    for(size_t i = 0; i < this->game_board[row].size(); i++){
        this->game_board[row][i] = '0';
        dropBlocks(row, i);
    }
    return 0;
}

int Board::dropBlocks(size_t row, size_t column){

    size_t curr_row = row;

    while (curr_row > TOP){
        if(this->game_board[curr_row - 1][column] == '1'){
            this->game_board[curr_row][column] = '1';
            this->game_board[curr_row - 1][column] = '0';
            curr_row--;
        }
        else{
            break;
        }
    }
    
    return 0;
}

Board::~Board() {}
