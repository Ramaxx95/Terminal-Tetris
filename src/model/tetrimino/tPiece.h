#ifndef T_PIECE_H
#define T_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'T'
class TPiece : public Tetrimino{

    public:
        TPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~TPiece() override;

};

#endif //T_PIECE_H