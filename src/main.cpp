#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "model/game.h"

int main(int argc, char* argv[]){

    Game main_game = Game();

    main_game.start();
    
    return 0;
}