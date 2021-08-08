#ifndef _OBJECTCREATOR_H
#define _OBJECTCREATOR_H

#include "ObjectIncludes.h"
#include "Map.h"
#include "Being.h"


class ObjectCreator {

public:

    // COSNTRUCTOR.

    ObjectCreator() = default;

    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de terreno en el vertice de la posicion indicada

    Cell* createTerrain(const std::string name);

    template <typename type>
    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de ser en el vertice de la posicion indicada
    Being* createBeing();

    template <typename type>
    // PRE: Recibe una posicion con row, col y un string
    // POST: Crea el tipo de elemento en el vertice de la posicion indicada
    Element* createElement(int amount);

};

template <typename type>
Being* ObjectCreator::createBeing() {

    Being* boardBeing = new type;
    return boardBeing;

}

template <typename type>

Element* ObjectCreator::createElement(int amount) {

    Element* boardElement = new type(amount);
    return boardElement;

}



#endif //GRAFOS_OBJECTCREATOR_H
