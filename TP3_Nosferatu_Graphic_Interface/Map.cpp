#include "Map.h"

Map::Map(int width, int height) {

    graph = new Matrix<Vertex*>(height, width);

    for( int i = 0; i < graph->getHeight(); i++){

        for( int j = 0; j < graph->getWidth(); j++){

            graph -> getMatrix()[i][j] = new Vertex;

        }
    }

    indexAmount = 0;

    this -> humanAmount = 0;
    this -> monsterAmount = 0;

    fillMap();
}

void Map::loadTerrain(int row, int col, Cell* cell) {
    graph -> getData(row,col) -> setCell(cell);
    graph -> getData(row,col) -> setIndex(indexAmount++);
    graph -> getData(row,col) -> setPosition(row,col);

}

void Map::loadBeing(int row, int col, Being* being) {
    this -> changeTeamAmount(being, 1);

    graph -> getData(row, col) -> setBeing(being);

}

void Map::changeTeamAmount(Being* being, int amount) {
    if ( teamIdentifier.isHumanTeam(being) )
        this -> humanAmount += amount;
    else
        this -> monsterAmount += amount;
}

void Map::loadElement(int row, int col, Element* element) {
    graph -> getData(row,col) -> setElement(element);
}

void Map::fillCenter() {

    for (int row = 1; row < graph -> getHeight() - 1; row++){

        for (int column = 1; column < graph -> getWidth() - 1; column++) {

            graph -> getData(row,column) -> addConnections(

                    graph -> getData(row, column + 1),
                    graph -> getData(row, column - 1),
                    graph -> getData(row + 1, column),
                    graph -> getData(row - 1, column));
        }
    }
}

void Map::fillCorners() {

    graph -> getData(0,0) -> addConnections(

            graph -> getData(1,0),
            graph -> getData(0,1));

    graph -> getData(graph -> getHeight() - 1 ,0) -> addConnections(

            graph -> getData(graph -> getHeight() - 2,0),
            graph -> getData(graph->getHeight()-1,1));

    graph -> getData(graph -> getHeight() - 1,graph -> getWidth() - 1) -> addConnections(

            graph -> getData(graph -> getHeight() - 2,graph -> getWidth() - 1),
            graph -> getData(graph -> getHeight() - 1,graph -> getWidth() - 2));

    graph -> getData(0,graph -> getWidth() - 1) -> addConnections(

            graph -> getData(0,graph -> getWidth() - 2),
            graph -> getData(1,graph -> getWidth() - 1));

}


void Map::fillEdges() {

    for (int row = 1; row < graph -> getHeight() - 1; row++) {
        graph -> getData(row,0) -> addConnections(

                graph -> getData(row - 1,0),
                graph -> getData(row + 1,0),
                graph -> getData(row,1));


        graph -> getData(row,graph -> getWidth() - 1) -> addConnections(

                graph -> getData(row-1,graph -> getWidth() - 1),
                graph -> getData(row+1,graph -> getWidth() - 1),
                graph -> getData(row,graph -> getWidth() - 2));

    }

    for (int column = 1; column < graph->getWidth() - 1; ++column) {


        graph -> getData(0,column) -> addConnections(

                graph -> getData(0,column - 1),
                graph -> getData(0,column + 1),
                graph -> getData(1,column));

        graph -> getData(graph -> getHeight() - 1,column) -> addConnections(

                graph -> getData(graph -> getHeight() - 1,column - 1),
                graph -> getData(graph -> getHeight() - 1,column + 1),
                graph -> getData(graph -> getHeight() - 2,column));

    }
}

void Map::fillMap() {
    fillCenter();
    fillCorners();
    fillEdges();
}

void Map::imprimir() {
    graph -> showMatrix();

}

Matrix<Vertex*>* Map::getMatrix() {
    return graph;
}

void Map::loadIndex(const int row, const int col, int index) {
    graph -> getData(row,col) -> setIndex(index);
}

int Map::getHeight() {
    return graph -> getHeight();
}

int Map::getWidth() {
    return graph -> getWidth();
}

int Map::getHumanAmount() {
    return this -> humanAmount;
}

int Map::getMonsterAmount() {
    return this -> monsterAmount;
}

Map::~Map() {
    for(int i = 0; i < graph->getHeight(); i++) {
        for (int j = 0; j < graph->getWidth(); j++) {
            if (graph->getMatrix()[i][j])
                delete graph->getMatrix()[i][j];
        }
    }

    delete graph;
}
