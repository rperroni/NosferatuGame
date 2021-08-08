#include "Vertex.h"

Vertex::Vertex() {
    xPosition = UNINITIALIZED_POSITION;
    yPosition = UNINITIALIZED_POSITION;

    connections = new List<Vertex *>;
    being = nullptr;
    element = nullptr;
    cell = nullptr;
    isTaken = false;
}

List<Vertex *> *Vertex::getConnections() {
    return connections;
}

Cell * Vertex::getCell() {
    return cell;
}

void Vertex::setCell(Cell* cell) {
    this -> cell = cell;
}

void Vertex::setBeing(Being *being) {
    this -> being = being;
    if (!being)
        isTaken = false;
    else
        isTaken = true;
}

void Vertex::setElement(Element *element) {
    this -> element = element;
}

void Vertex::addConnections(Vertex *connection, Vertex *connection2) {
    connections->insert(connection);
    connections->insert(connection2);
}

void Vertex::addConnections(Vertex *connection, Vertex *connection2, Vertex *connection3) {
    connections->insert(connection);
    connections->insert(connection2);
    connections->insert(connection3);
}

void Vertex::addConnections(Vertex *connection, Vertex *connection2, Vertex *connection3, Vertex *connection4) {
    connections->insert(connection);
    connections->insert(connection2);
    connections->insert(connection3);
    connections->insert(connection4);
}

int Vertex::getX() {
    return xPosition;
}

int Vertex::getY() {
    return yPosition;
}

void Vertex::setPosition(int xPos, int yPos) {
    xPosition = xPos;
    yPosition = yPos;
}

int Vertex::getIndex() {
    return this -> index;
}

void Vertex::setIndex(int index) {
    this -> index = index;
}

Being * Vertex::getBeing() {
    return being;
}

Element * Vertex::getElement() {
    return element;
}

bool Vertex:: isPositionTaken(){
    return this -> isTaken;
}

Vertex::~Vertex() {
    delete cell;
    if(being){
        cout << being->getObjectName();
        delete being;
        cout << " \nEliminado\n";
    }
    if(element)
        delete element;

    delete connections;
}