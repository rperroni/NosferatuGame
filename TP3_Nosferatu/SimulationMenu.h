#ifndef _SIMULATIONMENU_H
#define _SIMULATIONMENU_H

#include "Printer.h"
#include "UserInput.h"
#include "constantsNames.h"
#include "Map.h"
#include "Dictionary.h"
#include "Simulation.h"
#include "Gotoxy.h"

class SimulationMenu {
private:

    Gotoxy gotoxy;
    Printer printer;
    UserInput userInput;

    Player* playerOne;
    Player* playerTwo;

    Simulation* simulation;

public:
    //CONSTRUCTOR
    SimulationMenu();

    ~SimulationMenu();

    //PRE: Ingresa el mapa, diccionario y en caso de haber partida guardada
    //POST: Muestra el menu de simulacion
    void showMenu(Map* map, Dictionary &dic, bool savedGameFound);

private:

    //PRE: Ingresa el mapa
    //POST: Selecciona el equipo a mostrar
    void selectTeamToShow(Map* map);

    //PRE: Ingresa el mapa y selecciona los equipos
    //POST: Devuelve la simulacion para poder comenzarla
    Simulation* selectTeam(Map * map);
};


#endif //_SIMULATIONMENU_H
