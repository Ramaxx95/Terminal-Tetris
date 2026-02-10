#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <iostream>

#define LOWER_FLAG_CHECK 0
#define HIGHER_FLAG_CHECK 3

// Flags para especificar en donde añadir un bloque
enum AddFlag{
    UPPER_SIDE,
    LOWER_SIDE,
    RIGHT_SIDE,
    LEFT_SIDE
};

// Clase para los bloques que componen el tetrimino
class Block{

    private:
        int x;
        int y;
        Block* upper_side;
        Block* lower_side;
        Block* right_side;
        Block* left_side;

    public:
        Block(int x, int y);

        // Agrega un bloque al lado indicado por el flag, mientras que el bloque agregado
        // se ocupa de agregar al que invoca este metodo
        //
        // Devuelve -1 en caso de error
        // Devuelve 0 en caso exitoso
        //
        // flag: lado del bloque a donde se quiere añadir otro
        // add_blk: puntero a bloque que se quiere añadir (no puede ser NULL)
        int addBlock(const AddFlag flag, Block* add_blk);

        // Desvincula todo aquel bloque que estaba enganchado con este bloque
        void removeBlocks();

        // Devuelve si el lado de abajo contiene un bloque
        bool lowerSideOccupied();

        // Guarda la posicion del bloque en los argumentos
        // 'pos_x' y 'pos_y'
        int getPosition(int& pos_x, int& pos_y);

        // Cambiar la posicion del bloque
        int changePosition(int x, int y);
        ~Block();

};

#endif //BLOCK_H
