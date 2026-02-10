#include "sPiece.h"

SPiece::SPiece(int pos_x, int pos_y) : Tetrimino(pos_x, pos_y, 2, 3, 1, 1, 2) {

    // Creo cada bloque de la pieza
    this->blocks.push_back(Block(pos_x, pos_y + 1));
    this->blocks.push_back(Block(pos_x + 1, pos_y + 1));
    this->blocks.push_back(Block(pos_x + 1, pos_y));
    this->blocks.push_back(Block(pos_x + 2, pos_y));

    // Linkeo cada bloque
    this->blocks[0].addBlock(RIGHT_SIDE, &this->blocks[1]);
    this->blocks[1].addBlock(LEFT_SIDE, &this->blocks[0]);
    this->blocks[1].addBlock(UPPER_SIDE, &this->blocks[2]);
    this->blocks[2].addBlock(LOWER_SIDE, &this->blocks[1]);
    this->blocks[2].addBlock(RIGHT_SIDE, &this->blocks[3]);
    this->blocks[3].addBlock(LEFT_SIDE, &this->blocks[2]);
}

int SPiece::rotate(){

    this->curr_shape++;
    if(this->curr_shape > this->max_shapes){
        this->curr_shape = 1;
    }

    for(size_t i = 0; i < this->blocks.size(); i++){
        this->blocks[i].removeBlocks();
    }

    if(this->curr_shape == 1){
        // Notar como el extremo superior izquierdo de esta pieza no lo ocupa ningun bloque
        this->blocks[0].changePosition(this->x, this->y + 1);
        this->blocks[1].changePosition(this->x + 1, this->y + 1);
        this->blocks[2].changePosition(this->x + 1, this->y);
        this->blocks[3].changePosition(this->x + 2, this->y);

        this->blocks[0].addBlock(RIGHT_SIDE, &this->blocks[1]);
        this->blocks[1].addBlock(LEFT_SIDE, &this->blocks[0]);
        this->blocks[1].addBlock(UPPER_SIDE, &this->blocks[2]);
        this->blocks[2].addBlock(LOWER_SIDE, &this->blocks[1]);
        this->blocks[2].addBlock(RIGHT_SIDE, &this->blocks[3]);
        this->blocks[3].addBlock(LEFT_SIDE, &this->blocks[2]);
    }
    else if (this->curr_shape == 2){
        // Notar como ahora el bloque "3" se encuentra en el extremo superior izquierdo de esta pieza
        this->blocks[0].changePosition(this->x + 1, this->y + 2);
        this->blocks[1].changePosition(this->x + 1, this->y + 1);
        this->blocks[2].changePosition(this->x, this->y + 1);
        this->blocks[3].changePosition(this->x, this->y);

        this->blocks[0].addBlock(UPPER_SIDE, &this->blocks[1]);
        this->blocks[1].addBlock(LOWER_SIDE, &this->blocks[0]);
        this->blocks[1].addBlock(LEFT_SIDE, &this->blocks[2]);
        this->blocks[2].addBlock(RIGHT_SIDE, &this->blocks[1]);
        this->blocks[2].addBlock(UPPER_SIDE, &this->blocks[3]);
        this->blocks[3].addBlock(LOWER_SIDE, &this->blocks[2]);
    }

    return 0;
}

SPiece::~SPiece() {
    this->blocks.clear();
}