#include "player.h"

Player::Player() : name(""), score(0) {

    std::cout << "Please enter a name: ";
    std::cin >> this->name;
    std::cout << "\n";

    std::system("clear");
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
