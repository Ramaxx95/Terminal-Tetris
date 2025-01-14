#ifndef TETRIMINO_FACTORY_H
#define TETRIMINO_FACTORY_H

#include "tetrimino/oPiece.h"
//#include "tetrimino/restoPiezas.h"

// Fabrica para crear Tetriminos al azar
class TetriminoFactory {

    public:
        TetriminoFactory() = delete;
        static Tetrimino generatePiece();
}; 

#endif //TETRIMINO_FACTORY_H
