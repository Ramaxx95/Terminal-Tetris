#include "fileManager.h"

FileManager::FileManager(){}

std::list<PlayerScore> FileManager::getScore(){

    FILE* f = fopen(FILE_NAME, "r");

    std::list<PlayerScore> scores;

    if(f == nullptr){
        return scores;
    }

    char buf[256] = {0};
    char c;
    int idx = 0;

    while((c = fgetc(f)) != EOF){

        idx = 0;
        buf[idx++] = c;

        while((c = fgetc(f)) != ';'){
            buf[idx] = c;
            idx++;
        }

        std::string player_name(buf, idx);
        idx = 0;

        while((c = fgetc(f)) != '\n'){
            buf[idx] = c;
            idx++;
        }

        std::string score_buf(buf, idx);

        PlayerScore p_score;
        p_score.name = player_name;
        p_score.score = stoi(score_buf);


        scores.push_back(p_score);

    }

    fclose(f);

    return scores;

}

void FileManager::addScore(std::string player_name, int score){

    // Preparamos la lista para luego escribirlo
    std::list<PlayerScore> scores = updateScore(player_name, score);

    // Reescribimos el archivo
    writeScores(scores);
}

// ### Private Funcions ###

std::list<PlayerScore> FileManager::updateScore(std::string player_name, int score){
    
    std::list<PlayerScore> scores = getScore();
    
    PlayerScore p_score;
    p_score.name = player_name;
    p_score.score = score;

    scores.push_back(p_score);

    // Funcion lambda para comparar puntuaciones
    auto compareByScoreDesc = [](const PlayerScore a, const PlayerScore& b) {
        return a.score > b.score;
    };

    scores.sort(compareByScoreDesc);

    // Maximo de 10 puntuaciones
    if(scores.size() > 10){
        scores.resize(10);
    }
    return scores;
}

void FileManager::writeScores(std::list<PlayerScore> scores){
    
    FILE* f = fopen(FILE_NAME, "w");

    char semi_colon = ';';
    char new_line = '\n';
    
    auto it = scores.begin();
    for(size_t i = 0; i < scores.size(); i++){

        if(i > 0){
            std::advance(it, 1);
        }
        
        std::string player_name = it->name;
        std::string player_score = std::to_string(it->score);

        fwrite(player_name.c_str(), player_name.length(), 1, f); // Escribo nombre
        fwrite(&semi_colon, sizeof(semi_colon), 1, f);
        fwrite(player_score.c_str(), player_score.length(), 1, f); // Escribo puntuacion
        fwrite(&new_line, sizeof(new_line), 1, f);
    }

    fputc(EOF, f);
    fclose(f);
}

FileManager::~FileManager(){}