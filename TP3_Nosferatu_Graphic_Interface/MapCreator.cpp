#include "MapCreator.h"

MapCreator::MapCreator(Map *&map, Dictionary &dict) {
    boardFile.openFile("tablero.txt");
    boardFile.readFile(map);
    objectFile.openFile("estado.txt");
    objectFile.readFile(map, dict);
}

MapCreator::~MapCreator() {
}
