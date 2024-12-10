#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "tmp/print.h"

#define BLANK ".."
#define SQUARE "[]"

// Compilacion por ahora:  g++ main.cpp -o tetris

int main(int argc, char* argv[]){

    print_msg();
    // bool running = true;
    // int counter = 0;

    // std::vector<std::vector<std::string>> matrix = {{"<|", SQUARE, BLANK, BLANK, BLANK, "|>"},
    //                                                 {"<|", BLANK, SQUARE, BLANK, BLANK, "|>"},
    //                                                 {"<|", BLANK, BLANK, SQUARE, BLANK, "|>"},
    //                                                 {"<|", BLANK, BLANK, BLANK, SQUARE, "|>"}};

    // while(running){

    //     for(int i = 0; i < 4; i++){
    //         for (int j = 0; j < 6; j++){
    //             std::cout << matrix.at(i).at(j);
    //         }

    //         // Actualizo la fila actual de la matriz
    //         for (int j = 0; j < 6; j++){
    //             if(j > 0){
    //                 if(matrix.at(i).at(j - 1) == SQUARE && j != 5){
    //                     matrix.at(i).at(j - 1) = BLANK;
    //                     matrix.at(i).at(j) = SQUARE;
    //                     break;
    //                 } else if(matrix.at(i).at(j) == SQUARE && j == 4){
    //                     matrix.at(i).at(j) = BLANK;
    //                     matrix.at(i).at(1) = SQUARE;
    //                     break;
    //                 }
    //             }
                
    //         }
    //         std::cout << std::endl;
            
    //     }

    //     // Muevo el cursor hacia arriba y al principio
    //     std::cout << "\x1b[4A\r";

    //     std::this_thread::sleep_for(std::chrono::milliseconds(150));
        
    //     if(counter == 52){
    //         running = false;
    //     }
    //     counter++;
    // }

    // std::cout << "\n\n\n\n";
    return 0;
}