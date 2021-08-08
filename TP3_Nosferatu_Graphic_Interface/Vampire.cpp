#include "Vampire.h"

Vampire::Vampire() {
    sf::Texture texture;
    texture.loadFromFile("Vampire.png");

    this -> texture = texture;

    this -> objectCharName = 'v';
    this -> objectName = VAMPIRE_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> team = MONSTERS;
}

void Vampire::show() {
    std::cout << "Raza: " << characterType << std::endl;
    std::cout << "Tipo: " << monsterType << std::endl;
}
/*
std::string Vampire::getObjectName() {
    return monsterType;
}*/

void Vampire::addTurnEnergy() {
    this -> energy += 4;
}

bool Vampire::grabElement(Element *item) {
    if (*(item) == STAKEUPPER) {
        this -> destroyElement(item);

        return true;
    }

    else {
        return false;
    }
}

void Vampire::destroyElement(Element *item) {
    delete item;

    std::cout << "He destruido la estaca. Muajaja." << std::endl;
}

void Vampire::attack(Being *&target) {
    Identidentifier ident;
    this->addEnergy(-2);
    if( !(ident.isVanesa(target) && target -> isProtected()) )
        target -> receiveDamage(this ->getStrength());
}

short Vampire::defense() {
    return SELFHEAL;
}

void Vampire::selfHeal() {
    this -> addEnergy(-4);

    // Que le dure hasta terminar el turno del otro jugador.
    this -> addArmor(1);
}

bool Vampire::isProtected(){
    return false;
}