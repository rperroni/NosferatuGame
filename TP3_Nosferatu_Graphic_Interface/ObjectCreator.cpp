#include "ObjectCreator.h"

Cell * ObjectCreator::createTerrain(std::string name) {

    Cell* boardCell;

//    sf::Texture texture;
//    cout << name << endl;

    if ( name == MOUNTAIN ) {
//        texture -> loadFromFile("Mountain2.png");
        boardCell = new Mountain();
    }

    else if ( name == LAKE ) {
//        texture -> loadFromFile("lake.png");
        boardCell = new Lake();

    }

    else if ( name == THEVOID ) {
//        texture -> loadFromFile("TheVoid.png");
        boardCell = new TheVoid();
    }

    else if ( name == VOLCANO ) {
//        texture->loadFromFile("volcano2.png");
        boardCell = new Volcano();
    }

    else if ( name == ROAD ) {
//        texture -> loadFromFile("road.png");
        boardCell = new Road();
    }

    else if ( name == CLIFF ) {
//        texture -> loadFromFile("cliff.png");
        boardCell = new Cliff();
    }


    return boardCell;

}