#ifndef TETRIMINO_FACTORY_H
#define TETRIMINO_FACTORY_H

#include <random>
#include <limits>
#include <algorithm>
#include <list>
#include "tetrimino/oPiece.h"
#include "tetrimino/sPiece.h"
#include "tetrimino/nPiece.h"
#include "tetrimino/iPiece.h"
#include "tetrimino/tPiece.h"
#include "tetrimino/lPiece.h"
#include "tetrimino/pPiece.h"

#define MAX_LAST_USED 4

// Fabrica para crear Tetriminos al azar
class TetriminoFactory {

    private:
        std::vector<Tetrimino*> tetrimino_list;
        std::list<int> last_used;

    public:
        TetriminoFactory();
        Tetrimino* generatePiece();
        ~TetriminoFactory();
}; 

#endif //TETRIMINO_FACTORY_H
