#ifndef GRAFOS_OBJECTADDER_H
#define GRAFOS_OBJECTADDER_H

#include <iostream>
#include "Printer.h"
#include "Map.h"
#include "Dictionary.h"
#include "ObjectIncludes.h"
#include "ObjectCreator.h"
#include "UserInput.h"


class ObjectAdder {

private:

    ObjectCreator objectCreator;
    UserInput userInput;
    Printer printer;
    Being* being;
    Element* element;

public:

    ObjectAdder() = default;

    template<typename type>

    bool beingAdd(Map* &map, Dictionary &dict, int startId, int endId, int row, int column);

    template<typename type>

    bool elementAdd(Map* &map, Dictionary &dict, int startId, int endId, int amount, int row, int column);


    int searchId(Dictionary &dict, int startId, int endId);

};


template<typename type>

bool ObjectAdder::beingAdd(Map *&map, Dictionary &dict, int startId, int endId, int row, int column){

    being = objectCreator.createBeing<type>();
    being -> setId(searchId(dict, startId, endId));
    bool finishLoad = false;
    //int coordY, coordX;
    printer.showMap(map -> getMatrix());
    //userInput.validateRangeCoordinates(&coordY,&coordX,1, map -> getHeight() - 1,1,map -> getWidth() -1 );
    if (being->getId() != -1)
        if(!map -> getMatrix() -> getData(row - 1,column - 1) -> isPositionTaken()
          && !map->getMatrix()->getData(row - 1, column -1 )->getElement())
        {
            finishLoad = true;
            map->loadBeing(row - 1, column - 1, being);
            dict.insert(being);
        }
    /*
    else {
        this -> template beingAdd<type>(map, dict, startId, endId, row, column);
        }
        */
    return finishLoad;
}

template<typename type>

bool ObjectAdder::elementAdd(Map* &map, Dictionary &dict, int startId, int endId, int amount, int row, int column) {

    element = objectCreator.createElement<type>(amount);
    element -> setId(searchId(dict, startId, endId));
    bool finishLoad = false;

    //int coordY, coordX;
    //printer.showMap(map -> getMatrix());
    //userInput.validateRangeCoordinates(&coordY,&coordX,1, map -> getHeight(),1,map -> getWidth());
    if (element->getId() != -1)
        if(!map -> getMatrix() -> getData(row - 1,column - 1) -> isPositionTaken()
           && !map->getMatrix()->getData(row - 1, column -1 )->getElement())
        {
            finishLoad = true;
            map -> loadElement(row - 1, column - 1, element);
            dict.insert(element);
        }
    /*
    else {
        switch(userInput.validateReentry()){
            case 1:
                this -> template elementAdd<type>(map, dict, startId, endId, amount, row, column);
                break;
            case 2:
                break;
        }
    }
*/
    return finishLoad;
}


#endif //GRAFOS_OBJECTADDER_H
