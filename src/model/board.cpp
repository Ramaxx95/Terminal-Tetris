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
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
                        {'1','1','1','0','0','1','1','1'},
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

    updatePlayerPiece();
    return 0;
}

int Board::movePiece(int interpreted_input){

    int x = 0, y = 0;
    this->player_piece.getPosition(x, y);

    if(interpreted_input != dont_move_piece){
        this->erasePlayerPiece();
        switch (interpreted_input)
        {
            case move_piece_left:
                if(!playerPieceIsTouchingLeft()){
                    this->player_piece.changePosition(x - 1, y);
                }
                break;

            case move_piece_right:
                if(!playerPieceIsTouchingRight()){
                    this->player_piece.changePosition(x + 1, y);
                }
                break;

            case move_piece_down:
                this->player_piece.changePosition(x, y + 1);
                break;
            
            // TODO: implementar rotar piezas
            // case move_piece_rotate:
            //     this->player_piece.rotate();
            //     break;
            
            default:
                break;
        }
        this->printPlayerPiece();
    }
    

    return 0;
}

int Board::clearLinesOfBlocks(int level, int& lines_cleared_total){

    int resulting_score = 0, lines_cleared = 0;

    size_t row_size = this->game_board.size();
    size_t column_size = this->game_board[0].size();
     
    for(size_t i = row_size - 1; i > 0; i--){
        for(size_t j = 0; j < column_size; j++){

            if(this->game_board[i][j] != '1'){
                break;
            }
            else if(j == column_size - 1){
                deleteFullRow(i);
                resulting_score += 100 * level;
                lines_cleared++;
                i++;
            }
        }
    }

    lines_cleared_total += lines_cleared;
    return resulting_score;
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

                if(this->player_piece.isAnyBlockCollidingBottom(pos_x, pos_y)){
                    if(i <= TOP){
                        this->top_reached = true;
                    }
                    return true;
                }
            }
            
        }
    }
    return false;
}

bool Board::playerReachedTop(){
   
    return this->top_reached;
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

std::vector<std::vector<char>> Board::getBoard() {
    return this->game_board;
}

int Board::deleteFullRow(size_t row){

    for(size_t i = 0; i < this->game_board[row].size(); i++){
        this->game_board[row][i] = '0';
        dropBlocks(row, i);
    }
    return 0;
}

int Board::updatePlayerPiece(){

    int x, y;
    this->player_piece.getPosition(x, y);

    erasePlayerPiece();

    this->player_piece.changePosition(x, y + 1);

    printPlayerPiece();

    return 0;
}

int Board::printPlayerPiece(){

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

bool Board::playerPieceIsTouchingLeft() {

    std::vector<int> x, y;
    int outmost_left_block = 0, left_limit = 0;
    std::vector<int> x_limit, y_limit; // guardamos los limites de los bloques izquierdos

    outmost_left_block = this->player_piece.getLeftMostBlockPosition();

    this->player_piece.getBlockPositionsThatMatch(outmost_left_block, x_limit, y_limit);

    // Choca con el limite izquierdo 
    if(outmost_left_block == left_limit){
        return true;
    }

    for(size_t i = 0; i < x_limit.size(); i++){
        if(this->game_board[y_limit[i]][x_limit[i] - 1] == '1'){
            return true;
        }
    }
    return false;
}

bool Board::playerPieceIsTouchingRight(){

    std::vector<int> x, y;
    int outmost_right_block = 0, right_limit = (int) this->game_board[0].size() - 1;
    std::vector<int> x_limit, y_limit; // guardamos los limites de los bloques derechos

    outmost_right_block = this->player_piece.getRightMostBlockPosition();

    this->player_piece.getBlockPositionsThatMatch(outmost_right_block, x_limit, y_limit);

    // Choca con el limite derecho 
    if(outmost_right_block == right_limit){
        return true;
    }

    for(size_t i = 0; i < x_limit.size(); i++){
        if(this->game_board[y_limit[i]][x_limit[i] + 1] == '1'){
            return true;
        }
    }
    return false;
}

Board::~Board() {}
