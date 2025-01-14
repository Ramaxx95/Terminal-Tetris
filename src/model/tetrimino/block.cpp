#include "block.h"

Block::Block(int x, int y) : x(x),
                             y(y),
                             upper_side(nullptr),
                             lower_side(nullptr),
                             right_side(nullptr),
                             left_side(nullptr) {}

int Block::addBlock(const AddFlag flag, Block* add_blk){

    if(static_cast<int>(flag) < LOWER_FLAG_CHECK || 
       static_cast<int>(flag) > HIGHER_FLAG_CHECK){
        std::cerr << "ERROR: flag introducido es erroneo\n";
        return -1;
    }
    if(add_blk == nullptr){
        std::cerr << "ERROR: el bloque dado es nulo\n";
        return -1;
    }

    switch (flag){
        case UPPER_SIDE:
            this->upper_side = add_blk;
            add_blk->lower_side = this;
            break;

        case LOWER_SIDE:
            this->lower_side = add_blk;
            add_blk->upper_side = this;
            break;

        case RIGHT_SIDE:
            this->right_side = add_blk;
            add_blk->left_side = this;
            break;

        case LEFT_SIDE:
            this->left_side = add_blk;
            add_blk->right_side = this;
            break;
    
        default:
            break;
    }
    return 0;
}

bool Block::lowerSideOccupied(){

    if(this->lower_side){
        return true;
    }
    return false;
}

int Block::getPosition(int& pos_x, int& pos_y){

    pos_x = this->x;
    pos_y = this->y;
    return 0;
}

int Block::changePosition(int x, int y){

    this->x = x;
    this->y = y;
    return 0;
}

Block::~Block(){
    this->upper_side = nullptr;
    this->lower_side = nullptr;
    this->right_side = nullptr;
    this->left_side = nullptr;
}
