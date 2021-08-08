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

void Battle::attack(int row, int col) {

    // esto es solo para probar
    Being* target = map->getMatrix()->getData(row, col)->getBeing();

    // restar 2 balas cuando ataca con escopeta
    // restar 1 agua bendita cuando ataca con agua bendita
    // no restamos estaca?? Rta: No, la estaca es infinita
    selectedBeing -> attack(target);
}

void Battle::defend() {
    if (selectedBeing->defense() == SELFHEAL )
        selectedBeing -> selfHeal();
    else
        this -> healOthers();
}

void Battle::healOthers() {
    std::cout << "Cura a otros... despues vemos" << std::endl;
}

void Battle::showAttackRange(Element* weapon) {
    int characterId = selectedBeing -> getId();

    if( ident.isVanesa(characterId) || ident.isHunter(characterId) )
        this ->showHuntersAttackRange(weapon);

}
//short int HEALALL = 1
//        SELFHEAL = 2
//being   short int heal ¿queres curarte o a todos?  -->  selfHeal
//battle defend --> being->defend --> healAll

void Battle::selectTarget() {

}

Element* Battle::selectWeapon() {
    return nullptr;
}

void Battle::showAttackRange() {
    if( ident.isHuman(selectedBeing) ) {
        this ->showSquareRange(1, BGND_DARK_RED_52);
    }
    else if( ident.isZombie(selectedBeing) || ident.isVampire(selectedBeing) || ident.isVampirella(selectedBeing)){
        this->showCrossedRange(BGND_DARK_RED_52);
    }
    else
        showSquareRange(2, BGND_DARK_RED_52);
}

void Battle::showHuntersAttackRange(Element *weapon) {
    if(ident.isShotgun(weapon))
        this -> showSquareRange(2, BGND_DARK_RED_52);

    else if (ident.isHolyWater(weapon))
        this->showSquareRange(1, BGND_BLUE_20);

    else
        this->showCrossedRange(BGND_DARK_RED_52);
}

void Battle::showSquareRange(int range, const string background ) {
    for (int i = 0; i < map->getHeight(); i++) {
        for (int j = 0; j < map->getWidth(); j++) {
            if ((i >= selectedRow - range && i <= selectedRow + range) && (j >= selectedCol - range && j <= selectedCol + range)) {
                cout << background;
                if (map->getMatrix()->getData(i, j)->getBeing()) {
                    if ((i != selectedRow || j != selectedCol))
                        cout << " " << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " ";
                    else
                        cout << BGND_DARK_GREEN_22 << " "
                             << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " ";
                } else if (map->getMatrix()->getData(i, j)->getElement())
                    cout << " " << map->getMatrix()->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << " * ";
                cout << END_COLOR;
            } else {
                if (map->getMatrix()->getData(i, j)->getBeing())
                    cout << " " << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " ";
                else if (map->getMatrix()->getData(i, j)->getElement())
                    cout << " " << map->getMatrix()->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << " * ";
            }
        }
        cout << endl;
    }
}


void Battle::showCrossedRange(const string background) {
    for (int i = 0; i < map->getHeight(); i++) {
        for (int j = 0; j < map->getWidth(); j++) {
            if ((i == selectedRow && j == selectedCol))
                cout << BGND_DARK_GREEN_22 << " " << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " " << END_COLOR;

            else if ((i == selectedRow - 1 && j == selectedCol) ||
                (i == selectedRow + 1 && j == selectedCol) ||
                (j == selectedCol + 1 && i == selectedRow) ||
                (j == selectedCol - 1 && i == selectedRow) ){
                cout << background;
                if (map->getMatrix()->getData(i, j)->getBeing()) {
                    cout << " " << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " ";
                } else if (map->getMatrix()->getData(i, j)->getElement())
                    cout << " " << map->getMatrix()->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << " * ";
                cout << END_COLOR;
            } else {
                if (map->getMatrix()->getData(i, j)->getBeing())
                    cout << " " << map->getMatrix()->getData(i, j)->getBeing()->getCharName() << " ";
                else if (map->getMatrix()->getData(i, j)->getElement())
                    cout << " " << map->getMatrix()->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << " * ";
            }
        }
        cout << endl;
    }
}

Battle::~Battle() {

}



