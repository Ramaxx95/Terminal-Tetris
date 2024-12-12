#include "game.h"

Game::Game() : is_running(true){}

int Game::start() {

    // main loop
    while (this->is_running){
        
        std::cout << "Please select an option:\n"
                  << "1. Play\n"
                  << "2. Highscores\n"
                  << "3. Quit\n";

        int player_input = 0;
        std::cin >> player_input;
        
        switch (player_input){
            case PLAY_GAME:
                // Generar entorno de juego (nuevo thread?)
                break;

            case SEE_HIGHSCORES:
                // Mostrar los highscores y volver al inicio
                break;

            case QUIT_GAME:
                this->is_running = false;
                break;     
            
            default:
                std::system("clear");
                std::cerr << "Wrong value entered. Please try again\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
        }

        // Limpiar pantalla
        std::system("clear");

    }
    
    return 0;
}

Game::~Game() {}
