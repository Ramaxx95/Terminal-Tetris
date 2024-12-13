#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

#define TOP 3 // columna tope que el jugador puede ver

class Board {

    private:
        // '0' = celda vacio
        // '1' = celda lleno
        std::vector<std::vector<char>> game_board;
        bool top_reached;

        int deleteFullRow(size_t row);
        int dropBlocks(size_t row, size_t column);

    public:
        Board();
        int update();
        ~Board();
}; 

#endif //BOARD_H
