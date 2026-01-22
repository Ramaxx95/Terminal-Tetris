#include "inputManager.h"

InputManager::InputManager() {}

int InputManager::interpretInput(uint8_t input_received){
    
    int input_interpreted = 0;

    switch (input_received)
    {
        case MOVE_LEFT:
            input_interpreted = -1;
            break;

        case MOVE_RIGHT:
            input_interpreted = 1;
            break;
            
        case MOVE_DOWN:
            input_interpreted = 2;
            break;

        case ROTATE:
            input_interpreted = 3;
            break;
        
        default:
            break;
    }

    return input_interpreted;
}

InputManager::~InputManager() {}