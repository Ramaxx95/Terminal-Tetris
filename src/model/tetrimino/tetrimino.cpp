#include "tetrimino.h"

Tetrimino::Tetrimino() : x(0), y(0), width(0), height(0), initial_shape(1), curr_shape(1), max_shapes(1){}

Tetrimino::Tetrimino(
    int x,
    int y, 
    int w, 
    int h, 
    int initial_shape, 
    int curr_shape, 
    int max_shapes) : x(x), y(y), width(w), height(h), initial_shape(initial_shape), curr_shape(curr_shape), max_shapes(max_shapes){}

int Tetrimino::rotate(){
    // Para la clase base, no hace nada
    return 0;
}

bool Tetrimino::isAnyBlockCollidingBottom(int x_thres, int y_thres){

    int pos_x, pos_y = 0;
    for(size_t i = 0; i < this->blocks.size(); i++){
        if(this->blocks[i].lowerSideOccupied()){
            continue;
        }

        this->blocks[i].getPosition(pos_x, pos_y);
        if(pos_x == x_thres && 
           pos_y == y_thres - 1){
            return true;
        }
    }
    return false;
}

int Tetrimino::getLeftMostBlockPosition(){

    int pos_x = 0, pos_y = 0, left_most_pos = 0;
    this->blocks[0].getPosition(pos_x, pos_y);
    left_most_pos = pos_x;

    for(size_t i = 0; i < this->blocks.size(); i++){
            
        this->blocks[i].getPosition(pos_x, pos_y);
        if(pos_x < left_most_pos){
            left_most_pos = pos_x;
        }
    }

    return left_most_pos;
}

int Tetrimino::getBlockPositionsThatMatch(int x, std::vector<int>& x_blocks, std::vector<int>& y_blocks){

    int pos_x = 0, pos_y = 0;

    for(size_t i = 0; i < this->blocks.size(); i++){
            
        this->blocks[i].getPosition(pos_x, pos_y);

        if(pos_x == x){
            x_blocks.push_back(pos_x);
            y_blocks.push_back(pos_y);
        }
    }

    return 0;
}

int Tetrimino::getRightMostBlockPosition(){

    int pos_x = 0, pos_y = 0, right_most_pos = 0;
    this->blocks[0].getPosition(pos_x, pos_y);
    right_most_pos = pos_x;

    for(size_t i = 0; i < this->blocks.size(); i++){
            
        this->blocks[i].getPosition(pos_x, pos_y);
        if(pos_x > right_most_pos){
            right_most_pos = pos_x;
        }
    }

    return right_most_pos;
}

int Tetrimino::changePosition(int x, int y){

    // Guardo como cambia la posicion
    int x_off, y_off;
    x_off = x - this->x;
    y_off = y - this->y;

    // Actualizo la posicion
    this->x = x;
    this->y = y;

    // Actualizo cada bloque
    int blk_x, blk_y;
    for(size_t i = 0; i < this->blocks.size(); i++){
        this->blocks.at(i).getPosition(blk_x, blk_y);
        this->blocks.at(i).changePosition(blk_x + x_off, blk_y + y_off);
    }

    return 0;
}

int Tetrimino::getPosition(int& x, int& y){

    x = this->x;
    y = this->y;

    return 0;
}

int Tetrimino::getBlockPositions(std::vector<int>& x, std::vector<int>& y){

    int blk_x, blk_y;

    for(size_t i = 0; i < this->blocks.size(); i++){
        this->blocks.at(i).getPosition(blk_x, blk_y);
        x.push_back(blk_x);
        y.push_back(blk_y);
    }
    return 0;
}

int Tetrimino::getLowestBlockPosition(){

    int tmp_x, tmp_y, floor = 0;
    this->blocks[0].getPosition(tmp_x, floor);

    for(size_t i = 1; i < this->blocks.size(); i++){

        this->blocks[i].getPosition(tmp_x, tmp_y);
        if(tmp_y > floor){
            floor = tmp_y;
        }

    }

    return floor;
}

void Tetrimino::resetShape(){
    this->curr_shape = this->max_shapes;
    rotate();
}

Tetrimino::~Tetrimino(){}
