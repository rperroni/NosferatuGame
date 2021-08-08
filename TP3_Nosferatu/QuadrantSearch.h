#ifndef _QUADRANTSEARCH_H_
#define _QUADRANTSEARCH_H_

#include <iostream>
#include "Map.h"
#include "constantsNames.h"
#include "Gotoxy.h"
#include "UserInput.h"
#include "Printer.h"

class QuadrantSearch {
private:

    Printer printer;
    UserInput userInput;
    Gotoxy gotoxy;
    int height;
    int width;
    Vertex*** matrix;
    int rowLimits[2];
    int columnLimits[2];


public:
    //QuadrantSearch() = default;
    QuadrantSearch() = default;

    void loadMatrix(Map* graph);
    //PRE: Se ingresan los limites de busqueda y el mapa
    //POST: Se elige un cuadrante y respecto a ello se asignan los limites de busqueda para filas y columnas
    void chooseQuadrant(Map* matrix);

    //PRE: Se ingresan el nombre, el mapa y los limites de busqueda
    //POST: Retorna si dicho objeto se encuentra en ese cuadrante o no
    void searchForObject(std::string wantedObject);

    //PRE: Se ingresan los limites del cuadrante, el nombre y el mapa
    //POST: Se asignan los limites segun el cuadrante solicitado
    void assignLimits(std::string quadrantName);

    //PRE: Ingresa el nombre y las posiciones
    //POST:  Devuelve true en caso de estar ese nombre en dicha posicion
    bool isFound(std::string name, int row, int column);

    ~QuadrantSearch();
};


#endif //GRAFOS_QUADRANTSEARCH_H
