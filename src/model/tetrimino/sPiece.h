#ifndef S_PIECE_H
#define S_PIECE_H

#include "tetrimino.h"

// Clase para la pieza 'S'
class SPiece : public Tetrimino{
    private:

        // Forma con la que empieza el tetrimino
        // (en este caso, hay dos formas)
        int initial_shape;
        int curr_shape;
        int max_shapes;

    public:
        SPiece(int pos_x, int pos_y);

        int rotate() override;

        virtual ~SPiece() override;

};

#endif //S_PIECE_H