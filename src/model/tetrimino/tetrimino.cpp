#include "tetrimino.h"

Tetrimino::Tetrimino() : x(0), y(0), width(0), height(0){}

Tetrimino::Tetrimino(int x, int y, int w, int h) : x(x), y(y), width(w), height(h){}

bool Tetrimino::isAnyBlockColliding(int x_thres, int y_thres){

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

Tetrimino::~Tetrimino(){}
