#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <exception>
#include <map>
#include <string>
#include <vector>

#define FILE_NAME "../Tetris/player_score.csv"

// Clase encargada de lectura y escritura de puntuaciones
class FileManager {

    private:
        std::map<std::string, int> updateScore(std::string player_name, int score);
        void writeScores(std::map<std::string, int> scores);
        std::vector<std::string> getKeys(std::map<std::string, int> scores);

    public:
        FileManager();
        std::map<std::string, int> getScore();
        void addScore(std::string player_name, int score);
        ~FileManager();
}; 

#endif //FILE_MANAGER_H
