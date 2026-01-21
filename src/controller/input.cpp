#include "input.h"

Input::Input(bool &game_running) : 
    character_input(0), game_running(game_running) {
        initscr();
        cbreak();              // input inmediato
        noecho();              // no mostrar teclas
        // keypad(stdscr, TRUE);  // habilita flechas
        nodelay(stdscr, TRUE); // getch no bloqueante
        curs_set(0);    
    }

uint8_t Input::getInput() {

    this->character_input = getch();
    uint8_t action;

    switch (this->character_input) {
        case 'a':
            // mvprintw(1, 1, "LEFT ");
            action = MOVE_LEFT;
            break;
        case 'd':
            // mvprintw(1, 1, "RIGHT ");
            action = MOVE_RIGHT;
            break;
        case 's':
            // mvprintw(1, 1, "DOWN ");
            action = MOVE_DOWN;
            break;
        case ' ':
            // mvprintw(1, 1, "ROTATE ");
            action = ROTATE;
            break;
        case 'q':
            break;
        default:
            break;
    }

    refresh();
    return action;

}

Input::~Input(){
    endwin();
}