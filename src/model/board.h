#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>

#include "tetrimino/tetrimino.h"
#include "tetriminoFactory.h"

#define TOP 3 // fila tope que el jugador puede ver
const int move_piece_left =  -1;
const int dont_move_piece =  0;
const int move_piece_right =  1;
const int move_piece_down =  2;
const int move_piece_rotate =  3;

// Clase encargada de la logica del tablero
class Board {

    private:
        // '0' = celda vacio
        // '1' = celda lleno
        std::vector<std::vector<char>> game_board;
        bool top_reached;
        Tetrimino* player_piece;
        TetriminoFactory factory;

        int deleteFullRow(size_t row);
        int dropBlocks(size_t row, size_t column);
        int updatePlayerPiece();
        int printPlayerPiece();
        int erasePlayerPiece();
        bool playerPieceIsCollisioning();

    public:
        Board();
        int generateNewPiece();
        int update();
        int movePiece(int interpreted_input);
        int clearLinesOfBlocks(int level, int& lines_cleared_total);
        bool playerPieceReachedBottom();
        bool playerPieceStopped();
        bool playerReachedTop();
        std::vector<std::vector<char>> getBoard();
        ~Board();
}; 

#endif //BOARD_H
