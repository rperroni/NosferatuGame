#include "SimulationMenu.h"

void SimulationMenu::showMenu(Map* map, Dictionary &dic) {
    printer.showSimulationMenu();
    int id;
    Simulation* simulation;
    bool finish = false;
    while (!finish) {
        switch (userInput.validateRangeOption(1, 5)) {
            //MAURO CHEQUEA LA PARTE DEL DIC
            case SIMULATION_ID_SEARCH:
                id = userInput.validateRangeOption(0, 999);
                if (dic.search(id)) {
                    cout << "Se encontro el objeto" << endl;
                    dic.find(id) -> show();
                } else
                    cout << "No existe un objeto con ese ID" << endl;
                userInput.systemPause();
                break;
            case SIMULATION_SHOW_MAP:
                printer.showMap(map);
                userInput.systemPause();
                break;
            case SIMULATION_SHOW_INTEGRANTS:
                this -> selectTeamToShow(map);
                cout << " AAA " << endl;
                break;
            case SIMULATION_SELECT_TEAM:
                simulation = selectTeam(map);
                simulation->startSimulation();
                delete simulation;
                finish = true;
                break;
            case SIMULATION_EXIT:
                cout << "BUSCAR POR ID" << endl;
                finish = true;
                break;

        }
    }
}

void SimulationMenu::selectTeamToShow(Map* map) {
    int teamToShow = userInput.validateRangeOption(HUMANS,MONSTERS);

    if ( teamToShow == HUMANS )
        std::cout << "La cantidad de integrantes en el bando de humanos es: " << map -> getHumanAmount() << std::endl;
    else
        std::cout << "La cantidad de integrantes en el bando de monstruos es: " << map -> getMonsterAmount() << std::endl;


}

Simulation* SimulationMenu::selectTeam(Map * map) {
    int firstToChoose = rand() % 2 + 1;
    Player *playerOne = new Player;
    Player *playerTwo = new Player;

    cout << "Jugador " << firstToChoose << " elige primero" << endl;
    cout << "[" << HUMANS << "] Equipo humanos" << endl;
    cout << "[" << MONSTERS << "] Equipo monstruos" << endl;

    int chosenTeam = userInput.validateRangeOption(HUMANS, MONSTERS);
    int otherTeam = HUMANS;

    if(chosenTeam == HUMANS)
        otherTeam = MONSTERS;
    if(firstToChoose == 1){
        playerOne->setTeam(chosenTeam);
        playerTwo->setTeam(otherTeam);
    }else{
        playerTwo->setTeam(chosenTeam);
        playerOne->setTeam(otherTeam);
    }


    Simulation * simulation = new Simulation;
    simulation->loadGame(map, playerOne, playerTwo);
    return simulation;
}
