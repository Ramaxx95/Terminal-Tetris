#ifndef O_PIECE_H
#define O_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'O'
class OPiece : public Tetrimino{

    public:
        OPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~OPiece() override;

};

#endif //O_PIECE_H
