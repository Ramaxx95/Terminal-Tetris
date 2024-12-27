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
        Block* upper_side;
        Block* lower_side;
        Block* right_side;
        Block* left_side;

    public:
        Block();

        // Agrega un bloque al lado indicado por el flag
        //
        // Devuelve -1 en caso de error
        // Devuelve 0 en caso exitoso
        //
        // flag: lado del bloque a donde se quiere añadir otro
        // add_blk: puntero a bloque que se quiere añadir (no puede ser NULL)
        int addBlock(const AddFlag flag, Block* add_blk);
        ~Block();

};

#endif //BLOCK_H
