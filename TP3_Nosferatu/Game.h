#ifndef _GAME_H_
#define _GAME_H_

#include "Map.h"
#include "MapCreator.h"
#include "Floyd.h"
#include "CostMatrices.h"
#include "Dictionary.h"
#include "Printer.h"
#include "Menu.h"
#include "Battle.h"
#include "UserInput.h"
#include "constantsNames.h"
#include "SimulationMenu.h"
#include "Gotoxy.h"

class Game {

private:

    // ATRIBUTOS

    int option;
    Map* map;
    //SimulationMenu simulationMenu;
    Dictionary dictionary;
    Printer printer;
    UserInput userInput;
    Menu menu;

    Gotoxy gotoxy;

    bool simulationStarted;
    bool savedGameFound;

    MapCreator* mapCreator;

public:

    // METODOS

    // CONSTRUCTOR
    Game();

    // PRE: --
    // POST: Comienza toda la simulacion
    void play();

    // DESTRUCTOR
    ~Game();
};


#endif //_GAME_H_
