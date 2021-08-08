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
#include "SFML/Graphics.hpp"
#include "GraphicOptions.h"

class Game {
    /*
private:
    int option;
    Map* map;
    Dictionary dictionary;
    Printer textPrinter;
    Menu menu;
    //CostMatrices* costMatrices;

public:
    Game();
    void play();
    ~Game();
    void principalWindow();
*/
private:
    int option;
    Map* map;
    SimulationMenu simulationMenu;
    Dictionary dictionary;
    Printer printer;
    GraphicOptions graphicOptions;
    UserInput userInput;
    Menu menu;

public:

    Game();
    void play();
    Map* mapa();
    bool selectOption(int option, sf::RenderWindow &window);
    bool playVideo(int chosenOption, sf::RenderWindow &window);
    ~Game();
};


#endif //_GAME_H_
