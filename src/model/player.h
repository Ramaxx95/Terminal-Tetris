#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

// Clase encargada de la logica del Jugador
class Player {

    private:
        std::string name;
        unsigned int score;
        // Tetrimino curr_tetris;

    public:
        Player();
        int updateScore(unsigned int add_score);
        // int rotatePiece();

        std::string getName();
        unsigned int getScore();
        ~Player();
}; 

#endif //PLAYER_H
