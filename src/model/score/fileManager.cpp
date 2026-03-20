#include "fileManager.h"

FileManager::FileManager(){}

std::map<std::string, int> FileManager::getScore(){

    FILE* f = fopen(FILE_NAME, "r");

    std::map<std::string, int> scores;

    if(f == nullptr){
        return scores;
    }

    char buf[256] = {0};
    char c;
    int idx = 0;

    while(c != EOF){

        idx = 0;

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
        int player_score = stoi(score_buf);

        scores[player_name] = player_score;

        c = fgetc(f);
    }

    fclose(f);

    return scores;

}

void FileManager::addScore(std::string player_name, int score){

    // Preparamos el map para luego escribirlo
    std::map<std::string, int> scores = updateScore(player_name, score);

    // Reescribimos el archivo
    writeScores(scores);
}

// ### Private Funcions ###

std::map<std::string, int> FileManager::updateScore(std::string player_name, int score){
    
    std::map<std::string, int> scores = getScore();
    
    if(scores.empty()){
        scores[player_name] = score;
    }
    else{
        std::vector<std::string> keys = getKeys(scores);

        std::string player_name_tmp;
        int score_tmp;

        for(size_t i = scores.size() - 1; i > 0; i--){
            player_name_tmp = keys[i];
            score_tmp = scores[player_name_tmp];

            if(score >= score_tmp){
                auto player_replace = scores.extract(player_name_tmp);

                player_name_tmp = keys[i - 1];
                score_tmp = scores[player_name_tmp];
                
                player_replace.key() = player_name_tmp;
                scores.insert(std::move(player_replace));
                scores[player_name_tmp] = score_tmp;

                // La puntuacion agregada es la mas alta
                if(i == 1){
                    player_name_tmp = keys[0];
                    auto player_replace = scores.extract(player_name_tmp);
                    player_replace.key() = player_name;
                    scores.insert(std::move(player_replace));
                    scores[player_name] = score;
                }
            }
            else if((score < score_tmp) && (i < (scores.size() - 1))){
                auto player_replace = scores.extract(player_name_tmp);
                player_replace.key() = player_name;
                scores.insert(std::move(player_replace));
                scores[player_name] = score;
            }
            else{
                break;
            }
        }

    }

    return scores;
}

void FileManager::writeScores(std::map<std::string, int> scores){
    
    FILE* f = fopen(FILE_NAME, "w");

    std::vector<std::string> keys = getKeys(scores);

    char semi_colon = ';';
    char new_line = '\n';
    for(size_t i = 0; i < scores.size(); i++){

        std::string player_name = keys[i];
        std::string player_score = std::to_string(scores[player_name]);

        fwrite(player_name.c_str(), player_name.length(), 1, f); // Escribo nombre
        fwrite(&semi_colon, sizeof(semi_colon), 1, f);
        fwrite(player_score.c_str(), player_score.length(), 1, f); // Escribo puntuacion
        fwrite(&new_line, sizeof(new_line), 1, f);
    }

    fputc(EOF, f);
    fclose(f);
}

std::vector<std::string> FileManager::getKeys(std::map<std::string, int> scores){
    std::vector<std::string> keys;
    for(auto const& [key, val] : scores) {
        keys.push_back(key);
    }
    return keys;
}

FileManager::~FileManager(){}