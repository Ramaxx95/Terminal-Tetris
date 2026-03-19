#include "fileManager.h"

FileManager::FileManager(){}

std::unordered_map<std::string, int> FileManager::getScore(){

    FILE* f = fopen(FILE_NAME, "rb");

    std::unordered_map<std::string, int> scores;

    if(f == nullptr){
        return scores;
    }

    char buf[256] = {0};
    char c;
    int idx = 0;

    while(feof(f) != EOF){

        idx = 0;

        while((c = fgetc(f)) != ';'){
            buf[idx] = c;
            idx++;
        }

        std::string player_name(buf, idx);
        idx = 0;

        while((c = fgetc(f)) != ';'){
            buf[idx] = c;
            idx++;
        }

        std::string score_buf(buf, idx);
        int player_score = stoi(score_buf);

        scores[player_name] = player_score;
    }

    fclose(f);

    return scores;
    
}

FileManager::~FileManager(){}