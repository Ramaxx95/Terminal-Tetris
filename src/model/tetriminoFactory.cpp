#include "tetriminoFactory.h"

TetriminoFactory::TetriminoFactory() : last_used(0) {
    this->tetrimino_list.push_back(new OPiece(3,0));
    this->tetrimino_list.push_back(new SPiece(3,0));
    this->tetrimino_list.push_back(new NPiece(3,0));
    this->tetrimino_list.push_back(new IPiece(3,0));
    this->tetrimino_list.push_back(new TPiece(3,0));
    this->tetrimino_list.push_back(new LPiece(3,0));
    this->tetrimino_list.push_back(new PPiece(3,0));
}

Tetrimino* TetriminoFactory::generatePiece(){

    std::random_device rd;

    // Seed
    std::mt19937 gen(rd());

    // Limits
    int min_val = 0;
    int max_val = this->tetrimino_list.size() - 1;
    std::uniform_int_distribution<int> distrib(min_val, max_val);

    int random_piece = distrib(gen);
    while(random_piece == this->last_used){
        random_piece = distrib(gen);
    }
    this->last_used = random_piece;

    Tetrimino* piece = this->tetrimino_list[random_piece];
    piece->changePosition(3, 0);
    piece->resetShape();

    return piece;
}

TetriminoFactory::~TetriminoFactory() {
    for (size_t i = 0; i < this->tetrimino_list.size(); i++){
        delete this->tetrimino_list[i];
    }
    this->tetrimino_list.clear();
}