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

    // ATRIBUTOS

    int vertexAmount;
    int height;
    int width;
    int *** costMatrices;
    int *** pathMatrices;
    Vertex *** graph;
    Vertex ** vertices;
    CostMatrices * costs;
    Printer printer;

public:

    // CONSTRUCTOR
    Floyd() {
        pathMatrices = nullptr;
        vertices = nullptr;
        costs = nullptr;
        costMatrices = nullptr;
    };

    // PRE: Ingresa el mapa
    // POST: Carga los atributos con los datos del mapa
    void loadMap(Map * map);

    // PRE: Ingresa las coordenadas de origen y las de destino
    // POST: Realiza el camino minimo
    void minimumPath(int originX, int originY, int destinationX, int destinationY);

    // PRE: Ingresa las coordenadas de origen y las de destino
    // POST: Devuelve true en caso de tener la energia suficiente para realizar el camino minimo
    bool checkMinimumPath(int originX, int originY, int destinationX, int destinationY);

    // PRE: --
    // POST: Devuelve el ancho
    int getWidth();

    // PRE: --
    // POST: Devuelve el alto
    int getHeight();

    // DESTRUCTOR
    ~Floyd();


private:

    // METODOS PRIVADOS

    // PRE: --
    // POST: Crea la matriz de caminos
    int ** createPathMatrix();

    // PRE: Ingresa el origen y el index del vectice de origen
    // POST: Muestra el camino
    void showPath(int origen, int firstOrigin);

    // PRE: Ingresa el ogiten y el destino
    // POST: Mueve el personaje
    void moveBeing(int origin, int destination);

    // PRE: --
    // POST: Setea los index
    void setIndexes();

    // PRE: --
    // POST: Inicia vertice
    void initVertices();

    // PRE: --
    // POST: Muestra la matriz de caminos
    void showPathMatrix(int typeCost);

    // PRE: --
    // POST: Muestra las matrices de costo
    void showCostMatrix(int typeCost);

    // PRE: Ingresa el mapa
    // POST: Crea un array de matrices de costo
    void createCostMatrixArray(Map * map);

    // PRE: Ingresa un costo
    // POST: Calcula la matriz
    void calculateMatrices(int typeCost);

    // PRE: --
    // POST: Crea el array de matrices
    void createMatrixArray();

    // PRE: --
    // POST: Borra las matrices de camino
    void deletePathMatrices();

    // PRE: Ingresan las coordenadas de ambos objetos
    // POST: El elemento es agarrado por el ser
    void grabElement(int y, int x, int originY, int originX);

};


#endif //GRAFOS_FLOYD_H
