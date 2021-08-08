#include "Zombie.h"

Zombie::Zombie() {
    sf::Texture texture;
    texture.loadFromFile("Zombie.png");

    this -> texture = texture;


    this -> objectCharName = 'z';
    this -> objectName = ZOMBIE_CAPITALIZED;
    this -> costType = ZOMBIE_COST;
    this -> isHidden = false;
    this -> team = MONSTERS;
}

void Zombie::show() {
    std::cout << "Raza: " <<characterType << std::endl;
    std::cout << "Tipo: " <<monsterType << std::endl;
}

void Zombie::addTurnEnergy() {
    this -> energy += 5;
}

bool Zombie::grabElement(Element *item) {
    if (*(item) == HOLYWATERUPPER) {
        this -> inventory -> addItem(item);

        return true;
    }
    else
        return false;
}
bool Zombie::isProtected() {
    return isHidden;
}

void Zombie::attack(Being *&target) {
    this -> addEnergy(-5);
    //Falta ver como hacer la transformacion
}

short int Zombie::defense() {
    return SELFHEAL;
}

void Zombie::selfHeal() {
    this -> addEnergy(-2);

    //    por un turno esta escondido
    this -> isHidden = true;

    this -> addHealth(20);
}