#include "player.h"

Player::Player() : name(""), score(0) {

    std::cout << "Please enter a name: ";
    std::cin >> this->name;
    std::cout << "\n";

    int result = std::system("clear");
    
    if(result != 0){
    	std::cerr << "Error: couldn't clear screen\n";
    	exit(1);
    }	
}

int Player::updateScore(unsigned int add_score){

    this->score += add_score;
    return 0;
}

std::string Player::getName() {

    return this->name;
}

unsigned int Player::getScore() {

    return this->score;
}

Player::~Player() {}
