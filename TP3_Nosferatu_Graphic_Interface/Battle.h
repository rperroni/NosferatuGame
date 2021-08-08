#ifndef _BATTLE_H_
#define _BATTLE_H_

#include "ObjectIncludes.h"
#include "Map.h"
#include "Identidentifier.h"

class Battle {

private:
    Map* map;

    int targetRow;
    int targetCol;

    int selectedRow;
    int selectedCol;

    Being* selectedBeing;

    Identidentifier ident;

public:

    Battle();

    void loadMap(Map * map);

    void attack(int row, int col);

    void defend();

    void healOthers();

    void selectBeing(int row, int col);

    Element* selectWeapon();

    ~Battle();

//private:
    void showAttackRange(Element* weapon);

    void showHuntersAttackRange(Element* weapon);

    void showSquareRange(int range, const string background);

    void showCrossedRange(const string background);

    void showAttackRange();

    void selectTarget();

    void printAttackRange();
};


#endif //_BATTLE_H_
