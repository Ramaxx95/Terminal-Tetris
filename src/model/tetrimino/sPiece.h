#ifndef S_PIECE_H
#define S_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'S'
class SPiece : public Tetrimino{

    public:
        SPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~SPiece() override;

};

#endif //S_PIECE_H