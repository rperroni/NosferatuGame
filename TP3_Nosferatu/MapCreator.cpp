#include "MapCreator.h"

MapCreator::MapCreator(Map *&map, Dictionary &dict) {
    savedGame = false;
    boardFile.openFile("tablero.txt");
    boardFile.readFile(map);
    boardFile.closeFile();
    savedGame = false;
    if ( saveGameFile.openFile("partida.txt") ) {
        this->savedGame = true;
        saveGameFile.closeFile();
    }
    else{
        objectFile.openFile("estado.txt");
        objectFile.readFile(map, dict);
        objectFile.closeFile();
    }
}

void MapCreator::createMap(Map *&map, Dictionary &dict) {
    boardFile.openFile("tablero.txt");
    boardFile.readFile(map);
    boardFile.closeFile();

    if ( saveGameFile.openFile("partida.txt") )
        this -> savedGame = true;
    else{
        objectFile.openFile("estado.txt");
        objectFile.readFile(map, dict);
        objectFile.closeFile();
    }
}

bool MapCreator::isSavedGame() {
    return savedGame;
}

void MapCreator::readSavedGame(Map *&map, Player *playerOne, Player *playerTwo){
    saveGameFile.readFile(map, playerOne, playerTwo);
    saveGameFile.closeFile();
}

MapCreator::~MapCreator() {

}
