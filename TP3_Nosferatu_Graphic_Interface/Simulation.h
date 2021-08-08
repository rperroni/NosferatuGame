#ifndef GRAFOS_SIMULATION_H
#define GRAFOS_SIMULATION_H
#include "Printer.h"
#include "Battle.h"
#include "ObjectIncludes.h"
#include "Player.h"
#include "Dictionary.h"
#include "UserInput.h"

class Simulation {
private:
    Map * map;
    Battle battle;
    int turnCounter;
    Player* playerOne;
    Player* playerTwo;

    UserInput userInput;



public:
    Simulation();

    ~Simulation();

    void loadGame(Map * map, Player * playerOne, Player * playerTwo);

    void startSimulation();

    void loadCharacters();

    void selectTeamToShow();

};


#endif //GRAFOS_SIMULATION_H
