#include "Player.h"

Player::Player() {
    this -> characters = new List<Being*>;
}

void Player::setTeam(int team) {
    this -> team = team;
}

void Player::addCharacter(Being *character) {
    this -> characters -> insert(character);
}

void Player::removeCharacter(int id) {
    int counter = 1;
    bool found = false;
    while (!found && characters -> hasNext()){
        if (characters -> getNext() -> getData() -> getId() == id){
            characters -> erase(counter);
            found = true;
        }
        counter++;
    }
}


int Player::getTeam() {
    return this -> team;
}

void Player::showCharacters() {
    while(characters->hasNext()){
        std::cout << characters->getNext()->getData()->getObjectName() << std::endl;
    }
    characters->reset();
}

Player::~Player() {
    delete characters;
}

void Player::selectOptions() {

}

List<Being*>* Player::getCharacters() {
    return characters;
}
