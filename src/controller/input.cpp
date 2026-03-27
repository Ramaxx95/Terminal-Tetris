#include "input.h"

Input::Input(bool &game_running) : 
    character_input(0), game_running(game_running) {
        initscr();
        cbreak();              // input inmediato
        noecho();              // no mostrar teclas
        nodelay(stdscr, TRUE); // getch no bloqueante
        curs_set(0);    
    }

uint8_t Input::getInput() {

    this->character_input = getch();
    uint8_t action;

    switch (this->character_input) {
        case 'a':
            action = MOVE_LEFT;
            break;
        case 'd':
            action = MOVE_RIGHT;
            break;
        case 's':
            action = MOVE_DOWN;
            break;
        case ' ':
            action = ROTATE;
            break;
        case 'q':
            break;
        default:
            action = NO_INPUT;
            break;
    }

    refresh();
    return action;

}

Input::~Input(){
    flushinp();
    endwin();
}