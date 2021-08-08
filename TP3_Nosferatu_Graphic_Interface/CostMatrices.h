#ifndef GRAFOS_COSTMATRICES_H
#define GRAFOS_COSTMATRICES_H

#include "Cell.h"
#include "Vertex.h"
#include "Matrix.h"
#include "Map.h"
#include "constantsNames.h"

class CostMatrices {
private:

    Matrix<int>* humanCost;
    Matrix<int>* zombieCosts;
    Matrix<int>* hunterCosts;
    Matrix<int>* vampireCosts;
    int vertexAmount;
    int vertexCount;
    int height;
    int width;

public:

    // CONSTRUCTOR
    // PRE:
    // POST:
    CostMatrices(Map * map);

    // DESTRUCTOR
    // PRE:
    // POST:
    ~CostMatrices();

    // PRE:
    // POST:
    void createMatrices();

    // PRE:
    // POST:
    void loadCosts(Map* &map, int row, int col);

    // PRE:
    // POST:
    int *** getCostMatrices();

    // PRE:
    // POST:
    int ** getHumanCosts();

    // PRE:
    // POST:
    void loadCostMatrices(Map * map);

    // PRE:
    // POST:
    void show_matrixs();

private:

    // PRE:
    // POST:
    void loadCellCosts(Vertex* actualVertex, int index);

    // PRE:
    // POST:
    void initCostMatrices();

};


#endif //GRAFOS_COSTMATRICES_H
