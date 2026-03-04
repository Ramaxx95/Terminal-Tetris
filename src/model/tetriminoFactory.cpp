#include "tetriminoFactory.h"

TetriminoFactory::TetriminoFactory() : last_used(0) {
    this->tetrimino_list.push_back(new OPiece(3,2));
    this->tetrimino_list.push_back(new SPiece(3,2));
    this->tetrimino_list.push_back(new NPiece(3,2));
    this->tetrimino_list.push_back(new IPiece(3,0));
    this->tetrimino_list.push_back(new TPiece(3,2));
    this->tetrimino_list.push_back(new LPiece(3,1));
    this->tetrimino_list.push_back(new PPiece(3,1));
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
    int n_random_piece_repeated = std::count(this->last_used.begin(), this->last_used.end(), random_piece);
    
    while(n_random_piece_repeated > 0){
        random_piece = distrib(gen);
        n_random_piece_repeated = std::count(this->last_used.begin(), this->last_used.end(), random_piece);
    }

    if(this->last_used.size() == MAX_LAST_USED){
        this->last_used.pop_front();
        this->last_used.push_back(random_piece);
    }
    else{
        this->last_used.push_back(random_piece);
    }

    Tetrimino* piece = this->tetrimino_list[random_piece];
    piece->resetPosition();
    piece->resetTo(1);

    return piece;
}

TetriminoFactory::~TetriminoFactory() {
    for (size_t i = 0; i < this->tetrimino_list.size(); i++){
        delete this->tetrimino_list[i];
    }
    this->tetrimino_list.clear();
}