#include <unistd.h>
#include "Floyd.h"
#include "CostMatrices.h"

void Floyd::loadMap(Map* map){
    this -> graph = map -> getMatrix() -> getMatrix();
    this -> height = map -> getMatrix() -> getHeight();
    this -> width = map -> getMatrix() -> getWidth();
    this -> vertexAmount = this -> height * this -> width;
    this -> vertices = new Vertex*[vertexAmount];
    createCostMatrixArray(map);
    this -> pathMatrices = nullptr;
    initVertices();
    createMatrixArray();
}

void Floyd::createCostMatrixArray(Map * map) {
    this -> costs = new CostMatrices(map);
    this -> costMatrices = costs -> getCostMatrices();
}

int ** Floyd::createPathMatrix(){
    int ** pathMatrix = new int*[vertexAmount];

    for(int i = 0; i < vertexAmount; i++){
        pathMatrix[i] = new int[vertexAmount];
    }

    for(int i = 0; i < vertexAmount; i++){
        for(int j = 0; j < vertexAmount; j++) {
            pathMatrix[i][j] = j;
        }
    }

    return pathMatrix;
}


void Floyd::createMatrixArray() {

    this -> pathMatrices = new int ** [MAX_COSTS];
    int ** actualPathMatrix;

    for (int i = 0; i < MAX_COSTS; i++) {
        actualPathMatrix = this -> createPathMatrix();
        this -> pathMatrices[i] = actualPathMatrix;
        this -> calculateMatrices(i);
    }

}

void Floyd::calculateMatrices(int typeCost) {

    int ** costMatrix = this -> costMatrices[typeCost];
    int ** pathMatrix = this -> pathMatrices[typeCost];
    int cost;

    for (int intermediateVertex = 0; intermediateVertex < vertexAmount; intermediateVertex++) {

        for (int origin = 0; origin < vertexAmount; origin++) {

            for (int destination = 0; destination < vertexAmount; destination++) {

                cost = costMatrix[origin][intermediateVertex] + costMatrix[intermediateVertex][destination];

                if (cost < costMatrix[origin][destination]) {
                    costMatrix[origin][destination] = cost;
                    pathMatrix[origin][destination] = pathMatrix[origin][intermediateVertex];
                }
            }
        }
    }
}


void Floyd::showPath(int origin, int firstOrigin) {

    for (int i = 0; i < this -> height; ++i) {

        for (int j = 0; j < this -> width; ++j) {

            if (i == vertices[origin] -> getX() && j == vertices[origin] -> getY())
                vertices[firstOrigin] -> getBeing() -> showObjectCharacter();

            else if (graph[i][j] -> getElement())
                graph[i][j] -> getElement() -> showObjectCharacter();

            else
                cout << "*" << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;

}


void Floyd::minimumPath(int originX, int originY, int destinationX, int destinationY) {

    int index, originIndex, destinationIndex;
    this -> setIndexes();
    originIndex = graph[originY][originX] -> getIndex();
    destinationIndex = graph[destinationY][destinationX] -> getIndex();
    int auxOrigin = originIndex;
    int typeCost = this -> graph[originY][originX] -> getBeing() -> getCostType();
    int x = 0;
    int y = 0;

    do {
        x = vertices[originIndex] -> getY();
        y = vertices[originIndex] -> getX();

        printer.showFloydPath(graph, vertices, originIndex, auxOrigin, height, width);
        this -> grabElement(y, x, originY, originX);
        usleep(500000);

        index = this -> pathMatrices[typeCost][originIndex][destinationIndex];
        originIndex = index;

    } while (index != destinationIndex);

    x = vertices[originIndex] -> getY();
    y = vertices[originIndex] -> getX();


    printer.showFloydPath(graph, vertices, originIndex, auxOrigin, height, width);

    this ->grabElement(y, x, originY, originX);

    moveBeing(auxOrigin, destinationIndex);
    Being * moved = vertices[destinationIndex] -> getBeing();
    moved -> addEnergy((-1) * costMatrices[moved -> getCostType()][auxOrigin][destinationIndex]);

    usleep(500000);
}

void Floyd::grabElement(int y, int x, int originY, int originX) {
    std::string itemName;
    Identifier ident;
    if (graph[y][x] -> getElement()) {
        itemName = graph[y][x] -> getElement() -> getObjectName();
        if ( graph[originY][originX] -> getBeing() -> grabElement(graph[y][x] -> getElement()) ) {
            if( ident.isHumanTeam(graph[originY][originX] -> getBeing()) ){
                std::cout << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << TXT_ITALIC << itemName << "\033[0m";
                std::cout << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << ", añadido al inventario\033[0m" << std::endl;
                usleep(500000);
            }
            graph[y][x] -> setElement(nullptr);
        }
    }
}

void Floyd::moveBeing(int origin, int destination) {
    vertices[destination] -> setBeing(vertices[origin] -> getBeing());
    vertices[origin] -> setBeing(nullptr);
    Being * moved = vertices[destination] -> getBeing();
    moved -> setRow(vertices[destination] -> getX());
    moved -> setColumn(vertices[destination] -> getY());
}

void Floyd::setIndexes() {
    int countIndex = 0;

    for(int i = 0; i < this -> height; i++) {

        for(int j = 0; j < this -> width; j++) {

            vertices[countIndex] = graph[i][j];
            graph[i][j] -> setIndex(countIndex++);
            graph[i][j] -> setPosition(i, j);
        }
    }
}

void Floyd::deletePathMatrices() {

    if(pathMatrices){
        for(int i = 0; i < MAX_COSTS; i++){
            for(int j = 0; j < vertexAmount; j++){
                delete [] pathMatrices[i][j];
            }
            delete [] pathMatrices[i];
        }
        delete [] pathMatrices;
    }

}

void Floyd::initVertices() {
    for(int i = 0; i < vertexAmount; i++)
        vertices[i] = nullptr;
}

bool Floyd::checkMinimumPath(int originX, int originY, int destinationX, int destinationY) {
    Vertex * origin = graph[originY][originX];
    Vertex * destination = graph[destinationY][destinationX];
    return costMatrices[origin->getBeing()->getCostType()][origin->getIndex()][destination->getIndex()] <= origin ->getBeing()->getEnergy()
           && graph[destinationY][destinationX]->getBeing() == nullptr;
}

int Floyd::getWidth() {
    return this -> width;
}

int Floyd::getHeight() {
    return this -> height;
}

Floyd::~Floyd() {
    deletePathMatrices();
    if(vertices)
        delete [] vertices;
    if(costMatrices)
        delete [] costMatrices;
    if(costs)
        delete costs;
}
