#include "Vanesa.h"
#include "UserInput.h"
#include "Printer.h"

Vanesa::Vanesa() : Hunter() {
    this -> objectCharName = 'W';
    this -> objectName = VANESA_CAPITALIZED;
    this -> costType = HUNTER_COST;
    this -> team = HUMANS;
    this -> crossDefended = false;
}

void Vanesa::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " << characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " << humanType << std::endl;
    std::cout << gotoxy.pos(42,43) << "\033[40;1mNombre: " << vampireHunterName << std::endl;
}

void Vanesa::addTurnEnergy() {
    this -> energy += 10;
    if (energy > 20)
        energy = 20;
}

bool Vanesa::grabElement(Element *item) {
    this -> inventory -> addItem(item);

    return true;
}

void Vanesa::attack(Being *&target, Element *weapon) {
    Identifier ident;
    Printer printer;
    int aux = target -> getHealth();
    if ( ident.isZombie(target) && ! target -> isProtected() )
    {
        this -> attackZombie(target, weapon, 1.25, 0.25);
        printer.showVanesaAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());
    }
    else if (ident.isVampire(target) || ident.isNosferatu(target))
    {
        this -> attackVampire(target, weapon);
        printer.showVanesaAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());
    }
    else if ( ident.isVampirella(target) )
    {
        this -> attackVampirella(target, weapon);
        printer.showVanesaAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());
    }

    this -> addEnergy(-6);
}

void Vanesa::attackVampire(Being *&target, Element *weapon) {
    Identifier ident;
    if (ident.isShotgun(weapon)) {
        target->receiveDamage((float)(this->strength) * (float)0.4);
        this->inventory->useItem(BULLETUPPER, 2);
    }
    else if (ident.isStake(weapon))
        target -> killBeing();
    else {
        target->receiveDamage(20);
        this -> inventory -> useItem(HOLYWATERUPPER, 1);
    }
}

void Vanesa::attackVampirella(Being *&target, Element *weapon) {
    Identifier ident;
    Printer printer;
    if (ident.isShotgun(weapon)) {
        target->receiveDamage((float) (this->strength) * (float) 0.4);
        this->inventory->useItem(BULLETUPPER, 2);
    }
    else if (ident.isStake(weapon) && ! target -> isProtected() )
        target -> killBeing();
    else if( ! target -> isProtected() ) {
        target->receiveDamage(20);
        this -> inventory -> useItem(HOLYWATERUPPER, 1);
    }
    else
        printer.showCantAttackBatVampirella();
}

short int Vanesa::defense() {
    UserInput userInput;
    short int option = 0;

    bool defenseOptions[MAX_DEFENSE_OPTIONS] = {false, false, false};

    defenseOptions[VANESA_DEFENSE_HOLY_WATER] = this -> inventory -> isInInventory(HOLYWATER_CAPITALIZED);

    defenseOptions[VANESA_DEFENSE_CROSS] = this -> inventory -> isInInventory(CROSS_CAPITALIZED);

    defenseOptions[VANESA_DEFENSE_SELFHEAL] = ( !this -> inventory -> isInInventory(CROSS_CAPITALIZED) &&
                                                !this -> inventory -> isInInventory(HOLYWATER_CAPITALIZED) );

    option = (short) userInput.vanesaDefenseOptions(defenseOptions);
    Printer printer;
    this -> addEnergy(-10);
    if(option == CROSSPROTECTION) {
        this -> crossDefended = true;
        this -> defenseDuration = 1;
        printer.showVanesaIsCrossedProtectedMsg();
    }
    return option;
}


void Vanesa::selfHeal() {
    this -> addHealth(10);
}

bool Vanesa::isProtected() {
    return crossDefended;
}

bool Vanesa::checkAttackEnergy() {
    return (this -> energy >= 8);
}

bool Vanesa::checkDefenseEnergy() {
    return (this -> energy >= 10);
}

void Vanesa::endDefense() {
    crossDefended = false;
}

