#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>

#include "block.h"

// Clase abstracta de Tetriminos
class Tetrimino{
      

    public:
        // Posicion en el eje 'x' mas cercano al extremo izquierdo superior (no necesariamente es un bloque)
        int x;

        // Posicion en el eje 'y' mas cercano al extremo izquierdo superior (no necesariamente es un bloque)
        int y;

        // Ancho de la pieza
        int width;

        // Alto de la pieza
        int height;

        // Bloques que componen el Tetrimino
        std::vector<Block> blocks;

        /*** METODOS ***/

        Tetrimino();

        Tetrimino(int x, int y, int w, int h);

        virtual int rotate();

        bool isAnyBlockCollidingBottom(int x_thres, int y_thres);

        int getLeftMostBlockPosition();

        int getBlockPositionsThatMatch(int x, std::vector<int>& x_blocks, std::vector<int>& y_blocks);

        int getRightMostBlockPosition();

        int changePosition(int x, int y);

        int getPosition(int& x, int& y);

        int getBlockPositions(std::vector<int>& x, std::vector<int>& y);

        int getLowestBlockPosition();

        virtual ~Tetrimino();

};

#endif //TETRIMINO_H
