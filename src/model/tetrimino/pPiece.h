#ifndef P_PIECE_H
#define P_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'L'
class PPiece : public Tetrimino{

    public:
        PPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~PPiece() override;

};

#endif //P_PIECE_H