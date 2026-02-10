#include "tetriminoFactory.h"

TetriminoFactory::TetriminoFactory() : last_used(0) {
    this->tetrimino_list.push_back(OPiece(3,0));
}

Tetrimino TetriminoFactory::generatePiece(){

    std::random_device rd; 

    // Seed
    std::mt19937 gen(rd()); 

    // Limits
    int min_val = 0;
    int max_val = this->tetrimino_list.size() - 1;
    std::uniform_int_distribution<int> distrib(min_val, max_val);

    int random_piece = distrib(gen);
    // while(random_piece == this->last_used){
    //     random_piece = distrib(gen);
    // }
    this->last_used = random_piece;

    return this->tetrimino_list[random_piece];
}