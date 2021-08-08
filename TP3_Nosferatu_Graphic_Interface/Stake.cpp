#include "Stake.h"

Stake::Stake(int amount) : Element(amount) {
    sf::Texture texture;
    texture.loadFromFile("Stake.png");

    this -> texture = texture;


    this -> objectCharName = 'e';
    this -> objectName = STAKE_CAPITALIZED;
}

void Stake::show() {
    std::cout << "Tipo: " << objectType << std::endl;
    std::cout << "Nombre: " << consumableName << std::endl;
}
//std::string Stake::getObjectName() {
//    return consumableName;
//}