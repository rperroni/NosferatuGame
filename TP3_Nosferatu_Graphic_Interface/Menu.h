#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include "Printer.h"
#include "Map.h"
#include "Dictionary.h"
#include "ObjectIncludes.h"
#include "ObjectCreator.h"
#include "ObjectAdder.h"
#include "UserInput.h"
#include "ObjectAdder.h"
#include "QuadrantSearch.h"

using namespace std;

class Menu {

private:
    Gotoxy gotoxy;
    ObjectAdder objectAdder;
    UserInput userInput;
    Printer printer;
    QuadrantSearch quadrantSearcher;
    int option;

public:


    Menu();

    // PRE:
    // POST:
    int showMainMenu();

    // PRE:
    // POST:
    void showBoardMenu();

    // PRE:
    // POST:
    void showQuadrantsMenu(Map* matrix);

    // PRE:
    // POST:
    int showObjectsMenu();

    // PRE:
    // POST:
    int showSimulationMenu();

    // PRE:
    // POST:
    int showActionsMenu();

    void quadrantSearch();


    void addObject(Map* &map, Dictionary &dic);

    void removeObject(Map* &map, Dictionary &dic);


};



#endif //_MENU_H_