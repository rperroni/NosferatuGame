#include "SimulationMenu.h"


SimulationMenu::SimulationMenu() {
    playerOne = new Player;
    playerTwo = new Player;
    simulation = new Simulation;
}

void SimulationMenu::showMenu(Map* map, Dictionary &dic, bool savedGameFound) {
    bool finish = false;
    while (!finish) {

        printer.mainWindow();
        if(!savedGameFound){
            printer.showSimulationMenu();

            switch (userInput.validateRangeOption(1, 5)) {
                case SIMULATION_ID_SEARCH:
                    userInput.showIdSearch(dic, map->getMatrix());
                    break;
                case SIMULATION_SHOW_MAP:
                    printer.showMap(map->getMatrix());
                    printer.showBeingReferences();
                    printer.showTerrainReferences();
                    userInput.systemPause();
                    break;
                case SIMULATION_SHOW_INTEGRANTS:
                    this->selectTeamToShow(map);
                    break;
                case SIMULATION_SELECT_TEAM:
                    simulation = selectTeam(map);
                    simulation->startSimulation(savedGameFound);
                    finish = true;
                    break;
                case SIMULATION_EXIT:
                    finish = true;
                    break;
            }

        }
        else {
            simulation -> loadGame(map, playerOne, playerTwo);
            simulation -> startSimulation(savedGameFound);
            finish = true;
        }
    }
}

void SimulationMenu::selectTeamToShow(Map* map) {
    printer.mainWindow();
    printer.showTeamsOptions();
    int teamToShow = userInput.validateRangeOption(HUMANS,MONSTERS);

    if ( teamToShow == HUMANS )
        printer.showTeamCharactersAmount("humanos", map -> getHumanAmount());
    else
        printer.showTeamCharactersAmount("monstruos" , map -> getMonsterAmount());

    userInput.systemPause();
}

Simulation* SimulationMenu::selectTeam(Map * map) {
    printer.mainWindow();
    int firstToChoose = rand() % 2 + 1;

    cout  << gotoxy.pos(22,34) << "\033[47;30;1m    Jugador " << firstToChoose << " elige primero    \033[0m" << endl;
    cout << gotoxy.pos(25,38) <<  "\033[47;30;1m[" << HUMANS << "] Equipo humanos     \033[0m" << endl;
    cout << gotoxy.pos(28,38) << "\033[47;30;1m[" << MONSTERS << "] Equipo monstruos   \033[0m" << endl;

    int chosenTeam = userInput.validateRangeOption(HUMANS, MONSTERS);
    int otherTeam = HUMANS;

    if(chosenTeam == HUMANS)
        otherTeam = MONSTERS;
    if(firstToChoose == 1){
        playerOne -> setTeam(chosenTeam);
        playerTwo -> setTeam(otherTeam);
    }else{
        playerTwo -> setTeam(chosenTeam);
        playerOne -> setTeam(otherTeam);
    }


    simulation -> loadGame(map, playerOne, playerTwo);
    simulation -> setSavedPlayer(firstToChoose);
    return simulation;
}

SimulationMenu::~SimulationMenu() {
    delete simulation;
}

