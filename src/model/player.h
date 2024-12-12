#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {

    private:
        std::string name;
        unsigned int score;
        // Tetrimino curr_tetris;

    public:
        Player();
        int updateScore(unsigned int add_score);
        // int rotatePiece();
        ~Player();
}; 

#endif //PLAYER_H
