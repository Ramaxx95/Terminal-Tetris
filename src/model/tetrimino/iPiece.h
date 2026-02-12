#ifndef I_PIECE_H
#define I_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'I'
class IPiece : public Tetrimino{

    public:
        IPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~IPiece() override;

};

#endif //I_PIECE_H