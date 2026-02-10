#ifndef O_PIECE_H
#define O_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'O'
class OPiece : public Tetrimino{
    private:

        // Forma con la que empieza el tetrimino
        // (en este caso, hay una sola forma)
        int initial_shape;
        int curr_shape;

    public:
        OPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~OPiece() override;

};

#endif //O_PIECE_H
