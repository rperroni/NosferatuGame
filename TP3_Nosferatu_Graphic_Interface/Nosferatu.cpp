#include "Nosferatu.h"

Nosferatu::Nosferatu() {
    sf::Texture texture;
    texture.loadFromFile("Nosferatu.png");

    this -> texture = texture;


    this -> objectCharName = 'N';
    this -> objectName = NOSFERATU_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> team = MONSTERS;
}

void Nosferatu::show() {
    std::cout << "Raza: " << characterType << std::endl;
    std::cout << "Tipo: " << monsterType << std::endl;
    std::cout << "Nombre: " << vampireName << std::endl;
}

void Nosferatu::addTurnEnergy() {
    this -> energy += 10;
}
/*
std::string Nosferatu::getObjectName() {
    return vampireName;
}*/

short int Nosferatu::defense() {
    // Afuera de Nosferatu porque hay que leer el mapa.
    return SELFHEAL;
}

void Nosferatu::selfHeal() {
    this -> addEnergy(-10);
}

bool Nosferatu::isProtected() {
    return false;
}

void Nosferatu::attack(Being* &target) {
    Identidentifier ident;
    this->addEnergy(-6);
    if( !(ident.isVanesa(target) && target -> isProtected()) )
        target -> receiveDamage(this ->getStrength());
}