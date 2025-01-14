#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>

#include "block.h"

// Clase abstracta de Tetriminos
class Tetrimino{
      

    public:
        // Posicion en el eje 'x' del bloque mas cercano al extremo izquierdo superior
        int x;

        // Posicion en el eje 'y' del bloque mas cercano al extremo izquierdo superior
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

        bool isAnyBlockColliding(int x_thres, int y_thres);

        int changePosition(int x, int y);

        int getPosition(int& x, int& y);

        int getBlockPositions(std::vector<int>& x, std::vector<int>& y);

        virtual ~Tetrimino();

};

#endif //TETRIMINO_H
