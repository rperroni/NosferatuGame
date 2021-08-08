#include "Vampirella.h"
#include "Printer.h"

Vampirella::Vampirella() {
    this -> objectCharName = 'V';
    this -> objectName = VAMPIRELLA_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> isBat = false;
    this -> team = MONSTERS;
}

void Vampirella::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " << characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " << monsterType << std::endl;
    std::cout << gotoxy.pos(42,43) << "\033[40;1mNombre: " << vampireName << std::endl;
}

void Vampirella::addTurnEnergy() {
    this -> energy += 6;
    if(energy > 20)
        energy = 20;
}


bool Vampirella::isProtected() {
    return this -> isBat;
}

void Vampirella::attack(Being *&target) {
    Identifier ident;
    Printer printer;
    this->addEnergy(-4);
    int aux = target -> getHealth();
    if( !(ident.isVanesa(target) && target->isProtected() )) {
        target->receiveDamage((float) this->getStrength());
        printer.showVampirellaAttackedHuman(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth());
    }
    else
        printer.showVanesaIsCrossedProtectedMsg();
}

short int Vampirella::defense() {
    return SELFHEAL;
}

void Vampirella::selfHeal() {
    Printer printer;
    this -> addEnergy(-5);
    printer.showVampirellaIsBat();
    this -> isBat = true;
    this -> startDefense(1);
}

bool Vampirella::checkAttackEnergy() {
    return (this -> energy >= 4);
}

bool Vampirella::checkDefenseEnergy() {
    return (this -> energy >= 5);
}

void Vampirella::endDefense() {
    isBat = false;
    startDefense(-1);
}
