#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>

#include "tetrimino/tetrimino.h"
#include "tetriminoFactory.h"

#define TOP 3 // columna tope que el jugador puede ver

// Clase encargada de la logica del tablero
class Board {

    private:
        // '0' = celda vacio
        // '1' = celda lleno
        std::vector<std::vector<char>> game_board;
        bool top_reached;
        Tetrimino player_piece;

        int deleteFullRow(size_t row);
        int dropBlocks(size_t row, size_t column);
        int updatePlayerPiece();
        int printPlayerPiece();
        int erasePlayerPiece();

    public:
        Board();
        int generateNewPiece();
        int update();
        bool playerPieceReachedBottom();
        bool playerPieceStopped();
        void showBoard();
        ~Board();
}; 

#endif //BOARD_H
