#include "Menu.h"

Menu::Menu() {
    option = 0;
}

int Menu::showMainMenu() {
    printer.mainWindow();
    return userInput.validateRangeOption(1,6);
}

void Menu::quadrantSearch() {
    printer.mainWindow();
    printer.showMainMenu();

}

void Menu::showQuadrantsMenu(Map* graph) {

    quadrantSearcher.loadMatrix(graph);

    printer.mainWindow();
    printer.showQuadrantsMenu();

    std::string quadrantName = QUADRANT_NAMES[userInput.validateRangeOption(1,4) - 1];
    quadrantSearcher.assignLimits(quadrantName);

    printer.mainWindow();
    printer.showObjectsMenu();

    std::string objectName = OBJECT_NAMES[userInput.validateRangeOption(1,12) - 1];

    if (quadrantSearcher.searchForObject(objectName)){
        printer.showFoundMessage(quadrantName, objectName);
        userInput.systemPause();
    }

    else {
        printer.showNotFoundMessage(quadrantName, objectName);
        userInput.systemPause();
    }
}

int Menu::showObjectsMenu() {

    printer.mainWindow();
    printer.showObjectsMenu();
    return userInput.validateRangeOption(1,12);

}

int Menu::showSimulationMenu() {

    printer.mainWindow();
    printer.showSimulationMenu();
    return userInput.validateRangeOption(0,4);
}

int Menu::showActionsMenu() {

    printer.mainWindow();
    printer.showActionMenu();
    return userInput.validateRangeOption(1,4);

}

void Menu::addObject(Map* &map, Dictionary &dict) {
/*
    switch(this -> showObjectsMenu()){
        case optionHUMAN:
            objectAdder.beingAdd<Human>(map,dict,1,49);
            break;
        case optionVAMPIREHUNTER:
            objectAdder.beingAdd<Hunter>(map,dict,50,99);
            break;
        case optionVANESA:
            objectAdder.beingAdd<Vanesa>(map,dict,0,0);
            break;
        case optionZOMBIE:
            objectAdder.beingAdd<Zombie>(map,dict,100,199);
            break;
        case optionVAMPIRE:
            objectAdder.beingAdd<Vampire>(map,dict,202,299);
            break;
        case optionNOSFERATU:
            objectAdder.beingAdd<Nosferatu>(map,dict,200,200);
            break;
        case optionVAMPIRELLA:
            objectAdder.beingAdd<Vampirella>(map,dict,201,201);
            break;
        case optionHOLYWATER:
            objectAdder.elementAdd<HolyWater>(map,dict,300,319,userInput.validateAmount());
            break;
        case optionSTAKE:
            objectAdder.elementAdd<Stake>(map,dict,380,999,1);
            break;
        case optionCROSS:
            objectAdder.elementAdd<Cross>(map,dict,320,339,1);
            break;
        case optionSHOTGUN:
            objectAdder.elementAdd<Shotgun>(map,dict,340,359,1);
            break;
        case optionBULLET:
            objectAdder.elementAdd<Bullet>(map,dict,360,379,userInput.validateAmount());
            break;
    }
    */
}

void Menu::showBoardMenu() {

}

void Menu::removeObject(Map* &map, Dictionary &dic) {

    printer.mainWindow();
    printer.showMap(map -> getMatrix());

    int coordY, coordX;

    userInput.validateRangeCoordinates(&coordY, &coordX, 1, map->getHeight(), 1, map->getWidth());

    if (map -> getMatrix() -> getData((coordY) - 1,(coordX) - 1) -> getBeing()) {
        Being* removing_being = map -> getMatrix() -> getData((coordY) - 1,(coordX) - 1) -> getBeing();

        map -> changeTeamAmount(removing_being, -1);
        dic.remove(removing_being -> getId());

        delete removing_being;

        map -> getMatrix() -> getData((coordY) - 1,(coordX) - 1) -> setBeing(nullptr);
    }

    else if (map -> getMatrix()-> getData(coordY - 1,coordX - 1) -> getElement()) {
        Element* removing_element = map -> getMatrix()-> getData(coordY - 1,coordX - 1) -> getElement();

        dic.remove(removing_element -> getId());

        delete removing_element;

        map -> getMatrix() -> getData((coordY) - 1,(coordX) - 1) -> setElement(nullptr);
    }

    else{
        switch(userInput.validateReentry()){
            case 1:
                removeObject(map,dic);
                break;
        }
    }
}
