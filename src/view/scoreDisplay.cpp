#include "scoreDisplay.h"

ScoreDisplay::ScoreDisplay(){}

void ScoreDisplay::showScore(){
    
    initscr();
    nodelay(stdscr, TRUE);
    curs_set(0);  
    
    std::unordered_map<std::string, int> scores = this->fileManager.getScore();
    
    if(scores.empty()){
        clear();
        mvprintw(1, 1, "No score has been set yet");
        mvprintw(2, 1, "Get back and play!");
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    else{
        clear();
        
        std::vector<std::string> keys;
        for (auto const& [key, val] : scores) {
            keys.push_back(key);
        }

        for(size_t i = 0; i < scores.size(); i++){
            int num = i + 1;
            std::string player_name = keys.at((int) i);
            mvprintw(num, 1, "%d. %s - %d", num, player_name.c_str(), scores.at(player_name));
        }
        
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }    
    endwin();
    
}

ScoreDisplay::~ScoreDisplay(){}