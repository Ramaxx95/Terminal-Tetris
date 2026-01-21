#include "game.h"

Game::Game() : is_running(true){}

int Game::start() {

    std::system("clear");
    
    // main loop
    while (this->is_running){
        
        std::cout << "Please select an option:\n"
                  << "1. Play\n"
                  << "2. Highscores\n"
                  << "3. Quit\n";

        int player_input;
        std::cin >> player_input;

        // Limpia el input en caso erroneo e ignora valores que no sean int
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::system("clear");

        switch (player_input){
            case PLAY_GAME:
                {
                    GameLoop gameloop = GameLoop();
                    gameloop.start();
                    break;
                }

            case SEE_HIGHSCORES:
                {
                    // Mostrar los highscores y volver al inicio
                    std::cout << "[DEBUG] Mostrando Highscores...\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    break;
                }

            case QUIT_GAME:
                this->is_running = false;
                break;     
            
            default:
                {
                    std::cout << "Wrong value entered. Please try again\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    break;
                }
        }

        // Limpiar pantalla
        std::system("clear");

    }
    
    return 0;
}

Game::~Game() {}
