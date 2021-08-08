#include "Simulation.h"

Simulation::Simulation() {
    this -> turnCounter = 0;
}

void Simulation::loadGame(Map *map, Player* playerOne, Player* playerTwo) {
    this -> map = map;
    this -> battle.loadMap(map);
    this -> playerOne = playerOne;
    this -> playerTwo = playerTwo;
}

void Simulation::startSimulation() {
    loadCharacters();
    //cout << "PAS0" << endl;
    cout << endl;
    playerOne->showCharacters();
    cout << endl;
    playerTwo->showCharacters();
    cout << endl;



}



void Simulation::loadCharacters() {
    for(int i = 0; i < map->getHeight(); i++){
        for (int j = 0; j < map->getWidth(); j++) {
            if(map ->getMatrix() ->getData(i, j) -> getBeing()){
                if (map ->getMatrix() ->getData(i, j) -> getBeing() -> getTeam() == playerOne->getTeam())
                    playerOne->addCharacter(map ->getMatrix() ->getData(i, j) -> getBeing());
                else{
                    playerTwo->addCharacter(map ->getMatrix() ->getData(i, j) -> getBeing());
                }
            }
        }
    }
}


Simulation::~Simulation() {
    delete  playerOne;
    delete  playerTwo;
}