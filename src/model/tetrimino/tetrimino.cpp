#include "tetrimino.h"

Tetrimino::Tetrimino() : x(0), y(0), width(0), height(0){}

Tetrimino::Tetrimino(int x, int y, int w, int h) : x(x), y(y), width(w), height(h){}

int Tetrimino::rotate(){
    // Para la clase base, no hace nada
    return 0;
}

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

Tetrimino::~Tetrimino(){}
