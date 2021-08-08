#ifndef GRAFOS_MAP_H
#define GRAFOS_MAP_H

#include "Element.h"
#include "Being.h"
#include "Cell.h"
#include "Matrix.h"
#include "Object.h"
#include "Vertex.h"
#include "Gotoxy.h"
#include "Identifier.h"

class Map {

private:

    int indexAmount;
    Matrix<Vertex*>*  graph;

    int humanAmount;
    int monsterAmount;

    Identifier teamIdentifier;

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

    //METODO VACIO
    void imprimir();

    // PRE:
    // POST: No implementado.
    void loadCost(int row, int col, int cost);

    //PRE:
    //POST:
    void loadIndex(int row, int col, int index);

    // PRE:
    // POST: No implementado.
    void printCosts();

    // PRE: --
    // POST: Devuelve la cantidad de humanos
    int getHumanAmount();

    // PRE: --
    // POST: Devuelve la cantidad de monstruos
    int getMonsterAmount();

    // PRE: Ingresa un ser y la cantidad
    // POST: Modifica la cantidad de cada equipo
    void changeTeamAmount(Being* being, int amount);

    // PRE: --
    // POST: Devuelve un puntero a matriz de vertices.
    Matrix<Vertex*>* getMatrix();

    // PRE: --
    // POST: Devuelve el alto del mapa
    int getHeight();

    // PRE: --
    // POST: Devuelve el ancho del mapa.
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
