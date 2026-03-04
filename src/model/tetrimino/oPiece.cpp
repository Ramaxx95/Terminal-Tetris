#include "oPiece.h"

OPiece::OPiece(int pos_x, int pos_y) : Tetrimino(pos_x, pos_y, 2, 2, 1, 1, 1){

    // Creo cada bloque de la pieza
    this->blocks.emplace_back(Block(pos_x, pos_y));
    this->blocks.emplace_back(Block(pos_x + 1, pos_y));
    this->blocks.emplace_back(Block(pos_x + 1, pos_y + 1));
    this->blocks.emplace_back(Block(pos_x, pos_y + 1));

    // Linkeo cada bloque
    this->blocks[0].addBlock(RIGHT_SIDE, &this->blocks[1]);
    this->blocks[0].addBlock(LOWER_SIDE, &this->blocks[3]);
    this->blocks[1].addBlock(LOWER_SIDE, &this->blocks[2]);
    this->blocks[1].addBlock(LEFT_SIDE, &this->blocks[0]);
    this->blocks[2].addBlock(LEFT_SIDE, &this->blocks[3]);
    this->blocks[2].addBlock(UPPER_SIDE, &this->blocks[1]);
    this->blocks[3].addBlock(RIGHT_SIDE, &this->blocks[2]);
    this->blocks[3].addBlock(UPPER_SIDE, &this->blocks[0]);
}

int OPiece::rotate(){

    // Para esta pieza, rotarla da el mismo resultado siempre
    return 0;
}

OPiece::~OPiece() {
    this->blocks.clear();
}
