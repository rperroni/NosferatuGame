#include "Game.h"

Game::Game() {

    option = 1;
    srand(time(NULL));
    MapCreator mapCreator(map, dictionary);
    this -> userInput = UserInput();
//    this -> printer = Printer();

}


void Game::play() {
    bool simulationStarted = false;

    while (!simulationStarted && option != 0){

        printer.mainWindow();
        printer.showMainMenu();
        option = userInput.validateRangeOption(0, 6);

        switch (option) {

            case ADD_OBJECT: //MESSIRVE
                menu.addObject(map, dictionary);
                break;
            case REMOVE_OBJECT: //MESSIRVE
                menu.removeObject(map,dictionary);
                break;
            case SHOW_MAP: //MESSIRVE
                printer.showMap(map->getMatrix());
                userInput.systemPause();
                break;
            case QUADRANT_SEARCH:
                menu.showQuadrantsMenu(map);
                break;
            case ID_SEARCH:
                printer.showIdMenu();
                break;
            case START_SIMULATION:
                simulationStarted = true;
                break;
            case EXIT:
                break;

        }

        //this -> simulationMenu.showMenu(map, dictionary);
    }
    if (simulationStarted ) this -> simulationMenu.showMenu(map, dictionary);
}

Game::~Game() {
    delete (this -> map);
}

Map *Game::mapa() {
    return map;
}

bool Game::selectOption(int option, sf::RenderWindow &window) {
    bool endGame = false;
    system(CLR_SCREEN);

    switch (option) {

        case ADD_OBJECT: {
            graphicOptions.addObject(window, map, &dictionary);
            break;
        }

        case REMOVE_OBJECT: {
            //graphicOptions.moveObject(window, map);
            graphicOptions.removeObject(window, map, &dictionary);
            break;
        }

        case SHOW_MAP: {
            //printer.showMap(map->getMatrix(), window);
            //graphicOptions = GraphicOptions();
            graphicOptions.showMap(window, map);
            break;
        }

        case QUADRANT_SEARCH: {
            //printer.showAddObject(map->getMatrix(), window);
            graphicOptions.quadrantSearch(window,map);
            break;
        }

        case ID_SEARCH: graphicOptions.idSearch(window,map,&dictionary);break;
        case START_SIMULATION: simulationMenu.showMenu(map, dictionary);break;

        case MOVE_OBJECT: {
            graphicOptions.moveObject(window, map);
            break;
        }

        case 8: endGame = true;break;
        default: std::cout << "La opcion ingresada no es valida\n\n\n\n" << std::endl;
    }
    return endGame;
}
bool Game::playVideo(int chosenOption, sf::RenderWindow &window) {
    return selectOption(chosenOption, window);
}
