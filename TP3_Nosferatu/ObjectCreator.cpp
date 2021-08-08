#include "ObjectCreator.h"

Cell * ObjectCreator::createTerrain(std::string name) {

    Cell* boardCell;

    if ( name == MOUNTAIN )
        boardCell = new Mountain;

    else if ( name == LAKE )
        boardCell = new Lake;

    else if ( name == THEVOID )
        boardCell = new TheVoid;

    else if ( name == VOLCANO )
        boardCell = new Volcano;

    else if ( name == ROAD )
        boardCell = new Road;

    else if ( name == CLIFF )
        boardCell = new Cliff;

    return boardCell;

}