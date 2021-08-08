#ifndef GRAFOS_MAP_H
#define GRAFOS_MAP_H

#include "Element.h"
#include "Being.h"
#include "Cell.h"
#include "Matrix.h"
#include "Object.h"
#include "Vertex.h"
#include "Gotoxy.h"
#include "Identidentifier.h"

class Map {

private:

    int indexAmount;
    Matrix<Vertex*>*  graph;

    int humanAmount;
    int monsterAmount;

    Identidentifier teamIdentifier;

public:

    // CONSTRUCTOR
    // PRE: Recibe el ancho y alto de la matriz
    // POST: Crea el grafo de tamaño width y height con todas sus conexione
    Map(int width, int height);

    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de terreno en el vertice de la posicion indicada
    void loadTerrain(int row, int col, Cell* cell);

    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de ser en el vertice de la posicion indicada
    void loadBeing(int row, int col, Being* being);

    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de elemento en el vertice de la poscion indicada
    void loadElement(int row, int col, Element* element);

    void imprimir();

    void loadCost(int row, int col, int cost);

    void loadIndex(int row, int col, int index);

    void printCosts();

    int getHumanAmount();

    int getMonsterAmount();

    void changeTeamAmount(Being* being, int amount);

    Matrix<Vertex*>* getMatrix();

    int getHeight();

    int getWidth();

    // DESTRUCTOR
    ~Map();

private:

    // PRE: -
    // POST: Crea las conexiones de los vertices centrales
    void fillCenter();

    // PRE: -
    // POST: Crea las conexiones de los vertices de las esquinas de la matriz
    void fillCorners();

    // PRE: -
    // POST: Crea las conexiones de los vertices de los bordes de la matriz
    void fillEdges();

    // PRE: -
    // POST: Crea todas las conexiones de los vertices del mapa
    void fillMap();

};


#endif //GRAFOS_MAP_H
