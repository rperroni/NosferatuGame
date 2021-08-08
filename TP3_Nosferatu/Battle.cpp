#include "Battle.h"
#include "colors.h"

Battle::Battle() {
    this -> selectedBeing = nullptr;
}

void Battle::loadMap(Map* map) {
    this -> map = map;
}

void Battle::selectBeing(int row, int col) {
    this -> selectedBeing = map -> getMatrix() -> getData(row, col) -> getBeing();
    this -> selectedRow = row;
    this -> selectedCol = col;
}

void Battle::attack() {
    int row, col;
    Being* target;

    if( ident.isHunter(selectedBeing) || ident.isVanesa(selectedBeing)){

        Element* weapon = selectWeapon();

        if(weapon) {
            this -> showHuntersAttackRange(weapon);
            userInput.validateAttackPosition(selectedBeing, weapon, row, col, map);

            if(row != -1 && col != -1) {
                target = map -> getMatrix() -> getData(row, col) -> getBeing();
                selectedBeing -> attack(target, weapon);
            }
        }
        delete weapon;
    }
    else{

        this -> showAttackRange();
        userInput.validateAttackPosition(selectedBeing, row, col, map);

        if(row != -1 && col != -1){
            target = map -> getMatrix() -> getData(row, col) -> getBeing();
            selectedBeing -> attack(target);
        }

    }
}

void Battle::defend(List<Being*> *allies) {
    short int defenseOption = selectedBeing -> defense();

    if (defenseOption == SELFHEAL ) {

        if( ident.isNosferatu(selectedBeing) ){
            int row, col;
            userInput.nosferatuDefenseOptions(selectedBeing, map, row, col, allies);
            if(row != -1 && col != -1){
                exchangeHealths(map -> getMatrix() -> getData(row, col) -> getBeing());
            }
        }
        else
            selectedBeing -> selfHeal();
    }
    else if (defenseOption == HEALOTHERS)
        this -> healOthers(allies);
}

void Battle::healOthers(List<Being *> *allies) {

    int selectedId = selectedBeing -> getId();
    int length = allies -> getLength();
    int count = 0;
    int row, col;
    Being *current;

    if (ident.isHunter(selectedBeing)) {

        while (length != count) {
            current = allies -> getNext() -> getData();
            if (current -> getId() != selectedId)
                current -> addHealth(20);
            count++;
            if (!allies->hasNext())
                allies -> reset();
        }
        printer.showHuntersHealedOthers();
    }
    else { // VANESA

        while (length != count) {
            current = allies -> getNext() -> getData();
            row = current -> getRow();
            col = current -> getCol();
            if ((row >= selectedRow - 2 && row <= selectedRow + 2) &&
                (col >= selectedCol - 2 && col <= selectedCol + 2))
                current -> avoidTransformation();
            count++;
            if (!allies -> hasNext())
                allies -> reset();
        }
        printer.showVanesaAvoidedTransformation();
    }
}

void Battle::showAttackRange(Element* weapon) {

    int characterId = selectedBeing -> getId();

    if( ident.isVanesa(characterId) || ident.isHunter(characterId) )
        this -> showHuntersAttackRange(weapon);

}

Element* Battle::selectWeapon() {
    return userInput.validateSelectedWeapon(selectedBeing);
}

void Battle::showAttackRange() {

    if( ident.isHuman(selectedBeing) ) {
        printer.showSquareRange(map -> getMatrix(), 1, BGND_DARK_RED_1, selectedRow, selectedCol);
    }
    else if( ident.isZombie(selectedBeing) || ident.isVampire(selectedBeing) || ident.isVampirella(selectedBeing)){
        printer.showCrossedRange(map -> getMatrix(), BGND_DARK_RED_1, selectedRow, selectedCol);
    }
    else // NOSFERATU
        printer.showSquareRange(map -> getMatrix(), 2, BGND_DARK_RED_1, selectedRow, selectedCol);
}

void Battle::showHuntersAttackRange(Element *weapon) {

    if(ident.isShotgun(weapon))
        printer.showSquareRange(map -> getMatrix(), 2, BGND_ORANGE_202, selectedRow, selectedCol);

    else if (ident.isHolyWater(weapon))
        printer.showSquareRange(map -> getMatrix(), 1, BGND_LIGHT_BLUE_45, selectedRow, selectedCol);

    else // ESTACA
        printer.showCrossedRange(map -> getMatrix(), BGND_PURPLE_93, selectedRow, selectedCol);
}



void Battle::exchangeHealths(Being* target) {
    int selectedHealth = selectedBeing -> getHealth();
    selectedBeing -> setHealth(target -> getHealth());
    target -> setHealth(selectedHealth);
}



