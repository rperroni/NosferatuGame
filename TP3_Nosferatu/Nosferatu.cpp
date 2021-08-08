#include "Nosferatu.h"
#include "Printer.h"

Nosferatu::Nosferatu() {
    this -> objectCharName = 'N';
    this -> objectName = NOSFERATU_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> team = MONSTERS;
}

void Nosferatu::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " << characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " << monsterType << std::endl;
    std::cout << gotoxy.pos(42,43) << "\033[40;1mNombre: " << vampireName << std::endl;
}

void Nosferatu::addTurnEnergy() {
    this -> energy += 10;
    if(energy > 20)
        energy = 20;
}

short int Nosferatu::defense() {
    return SELFHEAL;
}

void Nosferatu::selfHeal() {
    this -> addEnergy(-10);
}

bool Nosferatu::isProtected() {
    return false;
}

bool Nosferatu::checkAttackEnergy() {
    return (this -> energy >= 6);
}

bool Nosferatu::checkDefenseEnergy() {
    return (this -> energy >= 10);
}

void Nosferatu::attack(Being* &target) {
    Identifier ident;
    Printer printer;
    int aux = target -> getHealth();

    this -> addEnergy(-6);

    if( !(ident.isVanesa(target) && target -> isProtected()) && target -> getHealth() > 30) {
        target->receiveDamage((float) this -> getStrength());
        printer.showNosferatuAttackedHuman(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth());
    }

    else if(!target->isProtected() && target -> getHealth() <= 30) {
        target->vampireTransform();
        printer.showNosferatuTransformedHuman(target -> getObjectName(), target -> getRow(), target -> getCol());
    }

}