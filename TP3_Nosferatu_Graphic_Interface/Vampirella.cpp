#include "Vampirella.h"

Vampirella::Vampirella() {
    sf::Texture texture;
    texture.loadFromFile("Vampirella.png");

    this -> texture = texture;


    this -> objectCharName = 'V';
    this -> objectName = VAMPIRELLA_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> isBat = false;
    this -> team = MONSTERS;
}

void Vampirella::show() {
    std::cout << "Raza: " << characterType << std::endl;
    std::cout << "Tipo: " << monsterType << std::endl;
    std::cout << "Nombre: " << vampireName << std::endl;
}

void Vampirella::addTurnEnergy() {
    this -> energy += 6;
}

//std::string Vampirella::getObjectName() {
//    return vampireName;
//}

bool Vampirella::isProtected() {
    return this -> isBat;
}

void Vampirella::attack(Being *&target) {
    Identidentifier ident;
    this->addEnergy(-4);
    if( !(ident.isVanesa(target) && target->isProtected() ))
        target -> receiveDamage(this ->getStrength());
}

short int Vampirella::defense() {
    return SELFHEAL;
}

void Vampirella::selfHeal() {
    this -> addEnergy(-5);

    this -> isBat = true;
}