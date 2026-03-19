#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <exception>
#include <unordered_map>
#include <string>

#define FILE_NAME "player_score.csv"

// Clase encargada de lectura y escritura de puntuaciones
class FileManager {

    public:
        FileManager();
        std::unordered_map<std::string, int> getScore();
        ~FileManager();
}; 

#endif //FILE_MANAGER_H
