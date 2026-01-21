#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <ncurses.h>
#include <vector>
#include <chrono>
#include <thread>
#include "../model/player.h"

class GameWindow {
    private:
        Player& player;

    public:
        GameWindow(Player& player);
        void showWindow(std::vector<std::vector<char>>& game_board);
        void showEndGame();
        ~GameWindow();
};

#endif