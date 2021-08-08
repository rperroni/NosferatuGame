#include "Zombie.h"

Zombie::Zombie() {
    this -> objectCharName = 'z';
    this -> objectName = ZOMBIE_CAPITALIZED;
    this -> costType = ZOMBIE_COST;
    this -> isHidden = false;
    this -> team = MONSTERS;
}

void Zombie::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " <<characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " <<monsterType << std::endl;
}

void Zombie::addTurnEnergy() {
    this -> energy += 5;
    if(energy == 20)
        energy = 20;
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
    target -> transform();
    Printer printer;
    printer.showZombieAttackedHuman(target -> getObjectName(), target -> getRow(), target -> getCol());
}

short int Zombie::defense() {
    return SELFHEAL;
}

void Zombie::selfHeal() {
    this -> addEnergy(-2);

    this -> isHidden = true;

    Printer printer;
    printer.showZombiIsHidden();

    this -> addHealth(20);
    this -> startDefense(1);
}

bool Zombie::checkAttackEnergy(){
    return (this -> energy >= 5);
}

bool Zombie::checkDefenseEnergy() {
    return (this -> energy >= 2);
}

void Zombie::endDefense() {
    isHidden = false;
    startDefense(-1);
}
