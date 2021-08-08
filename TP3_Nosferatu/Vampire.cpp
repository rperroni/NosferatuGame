#include "Vampire.h"
#include <unistd.h>
#include "colors.h"
#include "Printer.h"

Vampire::Vampire() {
    this -> objectCharName = 'v';
    this -> objectName = VAMPIRE_CAPITALIZED;
    this -> costType = VAMPIRE_COST;
    this -> team = MONSTERS;
}

void Vampire::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " << characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " << monsterType << std::endl;
}

void Vampire::addTurnEnergy() {
    this -> energy += 4;
    if(energy > 20)
        energy = 20;
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

    std::cout << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " El vampiro ha destruido la estaca. Muajajaja! \033[0m" << std::endl;
    usleep(500000);
}

void Vampire::attack(Being *&target) {
    Identifier ident;
    this->addEnergy(-2);
    Printer printer;
    int aux = target -> getHealth();
    if( !(ident.isVanesa(target) && target -> isProtected()) ) {
        target->receiveDamage((float) this->getStrength());
        printer.showVampireAttackedHuman(target -> getObjectName(), target -> getRow(), target -> getCol(),
                                         aux, target -> getHealth());
    }
    else
        printer.showVanesaIsCrossedProtectedMsg();
}

short Vampire::defense() {
    return SELFHEAL;
}

void Vampire::selfHeal() {
    this -> addEnergy(-4);

    Printer printer;
    printer.showVampireIsHidden();

    this -> addArmor(1);
    this -> startDefense(1);
}

bool Vampire::isProtected(){
    return false;
}

bool Vampire::checkAttackEnergy() {
    return (this -> energy >= 2);
}

bool Vampire::checkDefenseEnergy() {
    return (this -> energy >= 4);
}

void Vampire::endDefense() {
    this -> armor--;
    startDefense(-1);
}


