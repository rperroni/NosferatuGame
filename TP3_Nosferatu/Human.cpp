#include "Human.h"
#include "UserInput.h"

Human::Human() : Being() {
    this -> bitten = false;
    this -> bittenCount = -1;
    this -> objectCharName = 'h';
    this -> objectName = HUMAN_CAPITALIZED;
    this -> costType = HUMAN_COST;
    this -> team = HUMANS;
    this -> vampireBitten = false;
}

void Human::show() {
    std::cout << gotoxy.pos(41,5) << "Raza:" << characterType << std::endl;
    std::cout << gotoxy.pos(42,5) << "Tipo:" << objectName << std::endl;
}

void Human::attack(Being *&target) {

    Identifier ident;

    if(this -> inventory -> isShotgunUsable()) {

        if (ident.isZombie(target) && !target -> isProtected())
            target -> receiveDamage((float)(this -> strength));

        else if (ident.isVampire(target) ||
                 ident.isVampirella(target) ||
                 ident.isNosferatu(target))
            target -> receiveDamage((float)(this -> strength) * (float)0.2);

        this -> addEnergy(-5);
        this -> inventory -> useItem(BULLETUPPER, 2);

    }
    else {
        std::cout << gotoxy.pos(41, 4) << "\033[40;1m"
                  << TXT_RED_124 << "El humano seleccionado no puede usar la escopeta";
    }
}

void Human::addTurnEnergy(){
    this -> energy += 5;
    if(energy > 20)
        energy = 20;
}

bool Human::grabElement(Element * item) {
    this -> inventory -> addItem(item);
    return true;
}

short Human::defense() {
    return SELFHEAL;
}

void Human::selfHeal() {

    short int healOption;
    UserInput userInput;
    Printer printer;

    if ( this -> inventory -> isInInventory(HOLYWATER_CAPITALIZED)){

        healOption = (short)userInput.humanDefenseOptions();

        if( healOption == HUMAN_ENERGY_ADD ) {
            this -> inventory -> removeItem(HOLYWATER_CAPITALIZED);
            this -> energy = MAX_ENERGY;
            printer.showHumanGotMaxEnergy();
        }
        else {
            this -> addArmor(1);
            this -> startDefense(1);
            printer.showHumanGotArmor();
        }
    }
    else {
        this -> addEnergy(3);
        printer.showHumanGotDefaultEnergy();
    }
}

bool Human::isProtected() {
    return false;
}

bool Human::checkAttackEnergy() {
    return (this -> energy >= 5);
}

bool Human::checkDefenseEnergy() {
    return (this -> energy >= 0);
}

bool Human::isBitten() {
    return bitten;
}

void Human::transform() {
    this -> bitten = true;
    bittenCount = 2;
}

void Human::bittenCountDown() {
    bittenCount--;
}

bool Human::isZombieTransformed() {
    return (bittenCount == 0);
}

bool Human::isVampireTransformed() {
    return vampireBitten;
}

void Human::avoidTransformation() {
    bitten = false;
    bittenCount = -1;
}

void Human::endDefense() {
    this -> armor--;
    startDefense(-1);
}

void Human::vampireTransform() {
    vampireBitten = true;
}

