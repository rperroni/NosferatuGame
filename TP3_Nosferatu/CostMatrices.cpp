#include "CostMatrices.h"


CostMatrices::CostMatrices(Map * map) {
    this -> height = map -> getMatrix() -> getHeight();
    this -> width = map -> getMatrix() -> getWidth();
    this -> vertexAmount = (this -> height) * (this -> width);
    this -> vertexCount = 0;
    this -> createMatrices();
    this -> loadCostMatrices(map);
}


void CostMatrices::createMatrices() {
    this -> humanCost = new Matrix<int>(vertexAmount,vertexAmount);
    this -> hunterCosts = new Matrix<int>(vertexAmount,vertexAmount);
    this -> vampireCosts = new Matrix<int>(vertexAmount,vertexAmount);
    this -> zombieCosts = new Matrix<int>(vertexAmount,vertexAmount);
    this -> initCostMatrices();
}

void CostMatrices::loadCostMatrices(Map * map) {
    for(int row = 0; row < this -> height; row++){
        for(int column = 0; column < this -> width; column++)
            this -> loadCosts(map, row, column);
    }
}

void CostMatrices::loadCosts(Map* &map, int row, int col) {

    List<Vertex*>* vertexList = map -> getMatrix() -> getData(row, col) -> getConnections();

    while (vertexList -> hasNext()) {
        Vertex * actualVertex = vertexList -> getNext() -> getData();
        int index = actualVertex -> getIndex();
        loadCellCosts(actualVertex, index);
    }

    vertexList -> reset();
    vertexCount++;
}

int *** CostMatrices::getCostMatrices() {

    int *** matrixArray = new int**[MAX_COSTS];
    matrixArray[HUMAN_COST] = this -> humanCost -> getMatrix();
    matrixArray[HUNTER_COST] = this -> hunterCosts -> getMatrix();
    matrixArray[VAMPIRE_COST] = this -> vampireCosts -> getMatrix();
    matrixArray[ZOMBIE_COST] = this -> zombieCosts -> getMatrix();

    return matrixArray;
}

void CostMatrices::loadCellCosts(Vertex* actual, int index) {
    this -> humanCost -> getMatrix()[vertexCount][index] = actual -> getCell() -> getCosts()[HUMAN_COST];
    this -> hunterCosts -> getMatrix()[vertexCount][index] = actual -> getCell() -> getCosts()[HUNTER_COST];
    this -> vampireCosts -> getMatrix()[vertexCount][index] = actual -> getCell() -> getCosts()[VAMPIRE_COST];
    this -> zombieCosts -> getMatrix()[vertexCount][index] = actual -> getCell() -> getCosts()[ZOMBIE_COST];
}

void CostMatrices::initCostMatrices() {

    for(int i = 0; i < vertexAmount; i++){
        for(int j = 0; j < vertexAmount; j++){

            if (i == j) {
                this -> humanCost -> getMatrix()[i][j] = 0;
                this -> hunterCosts -> getMatrix()[i][j] = 0;
                this -> zombieCosts -> getMatrix()[i][j] = 0;
                this -> vampireCosts -> getMatrix()[i][j] = 0;
            }
            else {
                this -> humanCost -> getMatrix()[i][j] = INFINITO;
                this -> hunterCosts -> getMatrix()[i][j] = INFINITO;
                this -> zombieCosts -> getMatrix()[i][j] = INFINITO;
                this -> vampireCosts -> getMatrix()[i][j] = INFINITO;
            }

        }
    }
}

CostMatrices::~CostMatrices() {
    delete humanCost;
    delete hunterCosts;
    delete vampireCosts;
    delete zombieCosts;
}
