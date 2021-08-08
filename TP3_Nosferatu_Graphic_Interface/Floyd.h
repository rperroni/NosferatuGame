#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H

#include "Vertex.h"
#include "Map.h"
#include "Matrix.h"
#include "constantsNames.h"
#include "CostMatrices.h"
#include "Printer.h"

class Floyd {

private:

    int vertexAmount;
    int height;
    int width;

    Vertex *** graph;
    Vertex ** vertices;

    int *** costMatrices;
    int *** pathMatrices;

    CostMatrices * costs;

public:

    //PRE:
    //POST:
    Floyd(Map * map);

    //PRE:
    //POST:
    void minimumPath(int originX, int originY, int destinationX, int destinationY, sf::RenderWindow &window);

    //PRE:
    //POST:
    ~Floyd();


private:

    int ** createPathMatrix();

    void showPath(int origin, int firstOrigin, sf::RenderWindow &window);

    void moveBeing(int origin, int destination);

    void setIndexes();

    void initVertices();

    void showPathMatrix(int typeCost);

    void showCostMatrix(int typeCost);

    void createCostMatrixArray(Map * map);

    void calculateMatrices(int typeCost);

    void createMatrixArray();

    void deletePathMatrices();

};


#endif //GRAFOS_FLOYD_H
