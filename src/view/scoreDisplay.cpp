#include "scoreDisplay.h"

ScoreDisplay::ScoreDisplay(){}

void ScoreDisplay::showScore(){
    
    initscr();
    nodelay(stdscr, TRUE);
    curs_set(0);  

    if(has_colors()){
        start_color();
        use_default_colors(); 
        init_color(8, 1000, 843, 0); // gold
        init_color(9, 753, 753, 753); // silver
        init_color(10, 804, 498, 196); // bronze
        init_pair(1, 8, -1);
        init_pair(2, 9, -1);
        init_pair(3, 10, -1); 
        init_pair(4, COLOR_CYAN, -1); 
    }
    
    std::list<PlayerScore> scores = this->fileManager.getScore();
    
    if(scores.empty()){
        clear();
        mvprintw(1, 1, "No score has been set yet");
        mvprintw(2, 1, "Get back and play!");
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    else{
        clear();

        int num = 1;

        if(has_colors()){
            for(auto it = scores.begin(); it != scores.end(); it++){
                if(num < 10){
                    if(num == 1){
                        attron(COLOR_PAIR(1));
                    }
                    else if(num == 2){
                        attroff(COLOR_PAIR(1));
                        attron(COLOR_PAIR(2));
                    }
                    else if(num == 3){
                        attroff(COLOR_PAIR(2));
                        attron(COLOR_PAIR(3));
                    }
                    else{
                        attroff(COLOR_PAIR(3));
                        attron(COLOR_PAIR(4));
                    }
                    mvprintw(num, 1, " %d. %s - %d", num, it->name.c_str(), it->score);    
                }
                else{
                    mvprintw(num, 1, "%d. %s - %d", num, it->name.c_str(), it->score);
                }
                num++;
            }
        }
        
        
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }    
    endwin();
    
}

ScoreDisplay::~ScoreDisplay(){}