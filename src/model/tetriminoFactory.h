#ifndef TETRIMINO_FACTORY_H
#define TETRIMINO_FACTORY_H

#include <random>
#include <limits>
#include "tetrimino/oPiece.h"
#include "tetrimino/sPiece.h"
#include "tetrimino/nPiece.h"
#include "tetrimino/iPiece.h"
//#include "tetrimino/restoPiezas.h"

// TODO: si al agregar mas piezas ralentiza mucho el juego, capaz convenga usar esta factory
//       en un thread aparte

// Fabrica para crear Tetriminos al azar
class TetriminoFactory {

    private:
        std::vector<Tetrimino*> tetrimino_list;
        int last_used; // TODO: por ahi conviene tener mas de una pieza guardada -> para que no
                       //       repita mucho (tal vez con 3 sea suficiente)

    public:
        TetriminoFactory();
        Tetrimino* generatePiece();
        ~TetriminoFactory();
}; 

#endif //TETRIMINO_FACTORY_H
