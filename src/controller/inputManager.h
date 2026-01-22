#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "input.h"

class InputManager {
    private:

    public:
        InputManager();
        int interpretInput(uint8_t input_received);
        ~InputManager();
};

#endif 