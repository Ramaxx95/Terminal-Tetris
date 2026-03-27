#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <exception>
#include <map>
#include <string>
#include <list>

#define FILE_NAME "../Tetris/player_score.csv"

// Entidad que se encarga de mantener la data de cada jugador
struct PlayerScore{
    std::string name;
    int score;
};

// Clase encargada de lectura y escritura de puntuaciones
class FileManager {

    private:
        std::list<PlayerScore> updateScore(std::string player_name, int score);
        void writeScores(std::list<PlayerScore> scores);

    public:
        FileManager();
        std::list<PlayerScore> getScore();
        void addScore(std::string player_name, int score);
        ~FileManager();
}; 

#endif //FILE_MANAGER_H
