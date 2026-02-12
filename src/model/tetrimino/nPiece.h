#ifndef N_PIECE_H
#define N_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'N'
class NPiece : public Tetrimino{

    public:
        NPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~NPiece() override;

};

#endif //N_PIECE_H