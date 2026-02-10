#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>

#include "block.h"

// Clase abstracta de Tetriminos
class Tetrimino{
      
    protected:
        // Posicion en el eje 'x' mas cercano al extremo izquierdo superior (no necesariamente es un bloque)
        int x;

        // Posicion en el eje 'y' mas cercano al extremo izquierdo superior (no necesariamente es un bloque)
        int y;

        // Ancho de la pieza
        int width;

        // Alto de la pieza
        int height;

        // Forma con la que empieza el tetrimino
        int initial_shape;

        // Forma actual
        int curr_shape;

        // Cantidad total de formas
        int max_shapes;

        // Bloques que componen el Tetrimino
        std::vector<Block> blocks;

        /*** METODOS ***/

    public:
        Tetrimino();

        Tetrimino(int x, int y, int w, int h, int initial_shape, int curr_shape, int max_shapes);

        virtual int rotate();

        bool isAnyBlockCollidingBottom(int x_thres, int y_thres);

        int getLeftMostBlockPosition();

        int getBlockPositionsThatMatch(int x, std::vector<int>& x_blocks, std::vector<int>& y_blocks);

        int getRightMostBlockPosition();

        int changePosition(int x, int y);

        int getPosition(int& x, int& y);

        int getBlockPositions(std::vector<int>& x, std::vector<int>& y);

        int getLowestBlockPosition();

        void resetShape();

        virtual ~Tetrimino();

};

#endif //TETRIMINO_H
