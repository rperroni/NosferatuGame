#ifndef _CELL_H
#define _CELL_H
#include "string"
#include "Object.h"
#include "constantsNames.h"

// CONSTANTES

const int MAX_COSTS = 4;

class Cell {
protected:

    // ATRIBUTOS

    std::string type;
    int costs[MAX_COSTS];

public:

    // METODOS

    // CONSTRUCTOR
    Cell();

    // PRE: --
    // POST: Devuelve el tipo de celda que es
    std::string getType();

    // PRE: --
    // POST: Devuelve el costo de la casilla
    int* getCosts();

    // DESTRUCTOR
    ~Cell();

};


#endif //GRAFOS_CELL_H
