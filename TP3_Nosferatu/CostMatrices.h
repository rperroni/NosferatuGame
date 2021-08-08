#ifndef _COSTMATRICES_H
#define _COSTMATRICES_H

#include "Cell.h"
#include "Vertex.h"
#include "Matrix.h"
#include "Map.h"
#include "constantsNames.h"

class CostMatrices {
private:

    // ATRIBUTOS

    Matrix<int>* humanCost;
    Matrix<int>* zombieCosts;
    Matrix<int>* hunterCosts;
    Matrix<int>* vampireCosts;
    int vertexAmount;
    int vertexCount;
    int height;
    int width;

public:

    // METODOS

    // CONSTRUCTOR
    CostMatrices(Map * map);

    // PRE: --
    // POST: Crea las matrices de costo
    void createMatrices();

    // PRE: --
    // POST: Carga los costos correspondientes
    void loadCosts(Map* &map, int row, int col);

    // PRE: --
    // POST: Devuelve las matrices de costo
    int *** getCostMatrices();

    // PRE: Ingresa el mapa
    // POST: Carga las matrices de costo
    void loadCostMatrices(Map * map);

    // DESTRUCTOR
    ~CostMatrices();


private:

    // PRE:
    // POST:
    void loadCellCosts(Vertex* actualVertex, int index);

    // PRE:
    // POST:
    void initCostMatrices();

};


#endif //GRAFOS_COSTMATRICES_H
