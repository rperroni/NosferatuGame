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

    // PRE::
    // POST:
    void addConnections(Vertex * connection1, Vertex * connection2);

    // PRE:
    // POST:
    void addConnections(Vertex * connection1, Vertex * connection2, Vertex * connection3);

    // PRE:
    // POST:
    void addConnections(Vertex * connection1, Vertex * connection2, Vertex * connection3, Vertex * connection4);

    // PRE:
    // POST:
    List<Vertex*> * getConnections();

    // PRE:
    // POST:
    Cell * getCell();

    // PRE:
    // POST:
    void setCell(Cell* cell);

    // PRE:
    // POST:
    void setBeing(Being* being);

    // PRE:
    // POST:
    void setElement(Element* element);

    // PRE:
    // POST:
    int getX();

    // PRE:
    // POST:
    int getY();

    // PRE:
    // POST:
    int getIndex();

    // PRE:
    // POST:
    void setIndex(int index);

    // PRE:
    // POST:
    void setPosition(int xPos, int yPos);

    // PRE:
    // POST:
    Being * getBeing();

    // PRE:
    // POST:
    Element * getElement();

    bool isPositionTaken();

};


#endif //_VERTEX_H_