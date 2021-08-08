#include "Game.h"

Game::Game() {
    option = 1;
    srand((unsigned int)time(NULL));

    simulationStarted = false;
    savedGameFound = false;
    MapCreator mapCreator(map, dictionary);
    if( mapCreator.isSavedGame() ) {
        simulationStarted = true;
        savedGameFound = true;
    }
    this -> userInput = UserInput();
}

void Game::play() {
    printer.mainWindow();
    printer.showIntro();
    std::cout << gotoxy.pos(41,5) << "\033[6;47;30;1m PRESIONE ENTER \033[0m";
    cin.get();

    while (!simulationStarted && option != 0){

        printer.mainWindow();
        printer.showMainMenu();
        option = userInput.validateRangeOption(0, 6);

        switch (option) {

            case ADD_OBJECT:
                menu.addObject(map, dictionary);
                break;

            case REMOVE_OBJECT:
                menu.removeObject(map,dictionary);
                break;

            case SHOW_MAP:
                printer.showMap(map -> getMatrix());
                printer.showBeingReferences();
                printer.showTerrainReferences();
                userInput.systemPause();
                break;

            case QUADRANT_SEARCH:
                menu.showQuadrantsMenu(map);
                break;

            case ID_SEARCH:
                userInput.showIdSearch(dictionary,map -> getMatrix());
                break;

            case START_SIMULATION:
                simulationStarted = true;
                break;

            case EXIT:
                break;

        }
    }

    if (simulationStarted) {
        SimulationMenu simulationMenu;
        simulationMenu.showMenu(map, dictionary, savedGameFound);
    }
}

Game::~Game() {
    delete (this -> map);
}

