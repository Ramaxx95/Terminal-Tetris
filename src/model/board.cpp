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
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'}};
}

int Board::generateNewPiece(){
    
    this->player_piece = TetriminoFactory::generatePiece();
    printPlayerPiece();
    return 0;
}

int Board::update(){

    //TODO: refactorizar esta funcion cuando haya movilidad y rotacion por
    //      parte del input del jugador
    updatePlayerPiece();
    return 0;
}

int Board::clearLinesOfBlocks(){
    
    size_t row_size = this->game_board.size();
    size_t column_size = this->game_board[0].size();
     
    for(size_t i = row_size - 1; i > 0; i--){
        for(size_t j = 0; j < column_size; j++){

            if(this->game_board[i][j] != '1'){
                break;
            }
            else if(j == column_size - 1){
                deleteFullRow(i);
                i++;
            }
        }
    }

    return 0;
}

bool Board::playerPieceReachedBottom(){
    int piece_floor = this->player_piece.getLowestBlockPosition();
    return piece_floor >= (int) (this->game_board.size() - 1);
}

bool Board::playerPieceStopped(){
    int pos_x, pos_y = 0;
    size_t row_size = this->game_board.size();
    size_t column_size = this->game_board[0].size();

    for(size_t i = row_size - 1; i > 0; i--){
        for(size_t j = 0; j < column_size; j++){
            if(this->game_board[i][j] == '1'){
                pos_x = j;
                pos_y = i;

                if(this->player_piece.isAnyBlockColliding(pos_x, pos_y)){
                    return true;
                }
            }
            
        }
    }
    return false;
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

int Board::updatePlayerPiece(){

    // Cuando haya Player Input -> tiene que ser argumento para donde
    // mover la pieza

    int x, y;
    this->player_piece.getPosition(x, y);

    erasePlayerPiece();

    // TODO: verificar que la pieza se pose encima del pilon o
    //       haya llegado al fin del tablero -> eliminar pieza
    //       y spawnear otra
    this->player_piece.changePosition(x, y + 1);

    printPlayerPiece();

    return 0;
}

int Board::printPlayerPiece(){

    // TODO: primero, convertir en '0' la posicion actual

    std::vector<int> x, y;

    this->player_piece.getBlockPositions(x, y);
    size_t vector_size = x.size();

    for(size_t i = 0; i < vector_size; i++){
        this->game_board[y.at(i)][x.at(i)] = '1';
    }
    
    return 0;
}

int Board::erasePlayerPiece(){

    std::vector<int> x, y;

    this->player_piece.getBlockPositions(x, y);
    size_t vector_size = x.size();

    for(size_t i = 0; i < vector_size; i++){
        this->game_board[y.at(i)][x.at(i)] = '0';
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
