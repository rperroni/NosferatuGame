#ifndef GRAFOS_SIMULATIONMENU_H
#define GRAFOS_SIMULATIONMENU_H

#include "Printer.h"
#include "UserInput.h"
#include "constantsNames.h"
#include "Map.h"
#include "Dictionary.h"
#include "Simulation.h"

class SimulationMenu {
private:
    Printer printer;
    UserInput userInput;

public:

    SimulationMenu() = default;
    void showMenu(Map* map, Dictionary &dic);

private:
    void selectTeamToShow(Map* map);
    Simulation* selectTeam(Map * map);
};


#endif //GRAFOS_SIMULATIONMENU_H
