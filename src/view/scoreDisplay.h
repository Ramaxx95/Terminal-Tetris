#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include <ncurses.h>
#include <chrono>
#include <thread>
#include <vector>

#include "../model/score/fileManager.h"

// Clase encargada de la vista de puntuaciones
class ScoreDisplay {

    private:
        FileManager fileManager;

    public:
        ScoreDisplay();
        void showScore();
        ~ScoreDisplay();
}; 

#endif //SCORE_DISPLAY_H
