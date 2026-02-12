#ifndef L_PIECE_H
#define L_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'L'
class LPiece : public Tetrimino{

    public:
        LPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~LPiece() override;

};

#endif //L_PIECE_H