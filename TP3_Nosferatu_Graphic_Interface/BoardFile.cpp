#include "BoardFile.h"

void BoardFile::readFile(Map* &map) {
    int row = 0, column = 0;
    std::string trash;
    inputFile >> this->height;
    inputFile >> this->width;

    map = new Map(this->width, this->height);

    getline(inputFile, trash, '\n');
    while ( !inputFile.eof() ){
        setTerrain(map,row,column);
    }
}

void BoardFile::setTerrain(Map *&map, int &row, int &column) {
    std::string terrain;
    getline(inputFile, terrain, ',');
    map -> loadTerrain(row ,column ,  this -> objectCreator -> createTerrain(terrain));
    column++;
    if (column == width - 1){
        getline(inputFile, terrain, '\n');
        map -> loadTerrain(row, column, this -> objectCreator -> createTerrain(terrain));
        column = 0;
        row ++;
    }
}
