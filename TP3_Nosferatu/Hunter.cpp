#include "Hunter.h"

#include "UserInput.h"
Hunter::Hunter() : Human() {
    this -> objectName = HUNTER_CAPITALIZED;
    this -> objectCharName = 'H';
    this -> costType = HUNTER_COST;
    this -> team = HUMANS;
}

void Hunter::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mRaza: " << characterType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mTipo: " << humanType << std::endl;
}

void Hunter::addTurnEnergy() {
    this -> energy += 8;
    if(energy > 20)
        energy = 20;
}

bool Hunter::grabElement(Element *item) {
    this -> inventory -> addItem(item);
    return true;
}

void Hunter::attack(Being *&target, Element *weapon) {

    Identifier ident;
    Printer printer;
    int aux = target -> getHealth();

    if (ident.isZombie(target) && ! target -> isProtected()) {
        this->attackZombie(target, weapon, (float) 1.05, (float) 0.2);
        printer.showHunterAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());
    }
    else if(ident.isZombie(target) && target -> isProtected())
        printer.showCantAttackHiddenZombie();
    else if (ident.isVampire(target) || ident.isNosferatu(target)) {
        this->attackVampire(target, weapon);
        printer.showHunterAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());

    }
    else if (ident.isVampirella(target)) {
        this -> attackVampirella(target, weapon);
        printer.showHunterAttacked(target -> getObjectName(), target -> getRow(), target -> getCol(), aux, target -> getHealth(), weapon -> getObjectName());

    }

    this -> addEnergy(-6);
}

void Hunter::attackZombie(Being *&target, Element *weapon, float withShotgun, float withStake) {

    Identifier ident;

    if (ident.isShotgun(weapon)) {
        target -> receiveDamage((float)(this -> strength) * withShotgun);
        this -> inventory -> useItem(BULLETUPPER, 2);
    }

    else if (ident.isStake(weapon))
        target -> receiveDamage((float)(this -> strength) * withStake);

}

void Hunter::attackVampire(Being *&target, Element *weapon) {

    Identifier ident;

    if (ident.isShotgun(weapon)) {
        target -> receiveDamage((float)(this -> strength) * (float) 0.3);
        this -> inventory -> useItem(BULLETUPPER, 2);
    }

    else if (ident.isStake(weapon))
        target -> receiveDamage(60);

    else {
        target -> receiveDamage(10);
        this -> inventory -> useItem(HOLYWATERUPPER, 1);
    }
}

void Hunter::attackVampirella(Being *&target, Element *weapon) {

    Identifier ident;
    Printer printer;

    if (ident.isShotgun(weapon)) {
        target -> receiveDamage((float)(this -> strength) * (float)0.3);
        this -> inventory -> useItem(BULLETUPPER, 2);
    }

    else if (ident.isStake(weapon) && ! target -> isProtected())
        target -> receiveDamage(60);

    else if (! target -> isProtected()) {
        target -> receiveDamage(10);
        this -> inventory -> useItem(HOLYWATERUPPER, 1);
    }
    else
        printer.showCantAttackBatVampirella();

}

short int Hunter::defense() {
    UserInput userInput;
    this -> addEnergy(-5);

    return ((short) userInput.hunterDefenseOptions() );
}

void Hunter::selfHeal() {
    this -> addHealth(50);
}

bool Hunter::isProtected(){
    return false;
}

bool Hunter::checkAttackEnergy() {
    return (this -> energy >= 6);
}

bool Hunter::checkDefenseEnergy() {
    return (this -> energy >= 5);
}
