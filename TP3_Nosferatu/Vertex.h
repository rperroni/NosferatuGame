#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <string>
#include "Object.h"
#include "Cell.h"
#include "Being.h"
#include "Element.h"
#include "List.h"

const int UNINITIALIZED_POSITION = -12;

using namespace std;

class Vertex {
private:
    // ATRIBUTOS
    int index;
    int xPosition;
    int yPosition;
    bool isTaken;
    Cell * cell;
    Being * being;
    Element * element;
    List<Vertex*> * connections;

public:
    // METODOS

    // CONSTRUCTOR
    Vertex();

    //DESTRUCTOR
    ~Vertex();

    // PRE:
    // POST: Añade las conexiones a un vertice que esta en la esquina
    void addConnections(Vertex * connection1, Vertex * connection2);

    // PRE:
    // POST: Añade las conexiones a un vertice que esta en el borde
    void addConnections(Vertex * connection1, Vertex * connection2, Vertex * connection3);

    // PRE:
    // POST: Añade las conexiones a un vertice que esta en el medio
    void addConnections(Vertex * connection1, Vertex * connection2, Vertex * connection3, Vertex * connection4);

    // PRE:
    // POST: Devuelve las conexiones del vertice
    List<Vertex*> * getConnections();

    // PRE:
    // POST: Devuelve el casillero del vertice
    Cell * getCell();

    // PRE:
    // POST: Setea el casillero del vertice
    void setCell(Cell* cell);

    // PRE:
    // POST: Setea el ser del vertice
    void setBeing(Being* being);

    // PRE:
    // POST: Setea el elemento del vertice
    void setElement(Element* element);

    // PRE:
    // POST: Devuelve la coordenada X del vertice
    int getX();

    // PRE:
    // POST: Devuelve la coordenada Y del vertice
    int getY();

    // PRE:
    // POST: Devuelve el indice del vertice
    int getIndex();

    // PRE:
    // POST: Setea el indice del vertice
    void setIndex(int index);

    // PRE:
    // POST: Setea la posicion del vertice
    void setPosition(int xPos, int yPos);

    // PRE:
    // POST: Devuelve el ser que se encuentra en el vertice
    Being * getBeing();

    // PRE:
    // POST: Devuelve el elemento que se encuentra en el vertice
    Element * getElement();

    // PRE:
    // POST: Devuelve si hay un ser en el vertice o no
    bool isPositionTaken();

};


#endif //_VERTEX_H_