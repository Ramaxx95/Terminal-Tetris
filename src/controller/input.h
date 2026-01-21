#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>

#define MOVE_RIGHT '\x10'
#define MOVE_LEFT '\x11'
#define MOVE_DOWN '\x13'
#define NO_INPUT '\x14'
#define ROTATE '\x15'

class Input {
    private:
        int character_input;
        bool& game_running;

    public:
        Input(bool& game_running);
        uint8_t getInput();
        ~Input();
};

#endif