#ifndef TETRIMINO_FACTORY_H
#define TETRIMINO_FACTORY_H

#include <random>
#include <limits>
#include "tetrimino/oPiece.h"
#include "tetrimino/sPiece.h"
#include "tetrimino/nPiece.h"
//#include "tetrimino/restoPiezas.h"

// TODO: si al agregar mas piezas ralentiza mucho el juego, capaz convenga usar esta factory
//       en un thread aparte

// Fabrica para crear Tetriminos al azar
class TetriminoFactory {

    private:
        std::vector<Tetrimino*> tetrimino_list;
        int last_used;

    public:
        TetriminoFactory();
        Tetrimino* generatePiece();
        ~TetriminoFactory();
}; 

#endif //TETRIMINO_FACTORY_H
