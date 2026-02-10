#ifndef TETRIMINO_FACTORY_H
#define TETRIMINO_FACTORY_H

#include <random>
#include <limits>
#include "tetrimino/oPiece.h"
//#include "tetrimino/restoPiezas.h"

// Fabrica para crear Tetriminos al azar
class TetriminoFactory {

    private:
        std::vector<Tetrimino> tetrimino_list;
        int last_used;

    public:
        TetriminoFactory();
        Tetrimino generatePiece();
}; 

#endif //TETRIMINO_FACTORY_H
