#ifndef _OBJECTADDER_H
#define _OBJECTADDER_H

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

    //PRE: Ingresa el mapa, el diccionario y los limites de ID
    //POST: Crea y agrega el ser al mapa y al diccionario
    template<typename type>

    void beingAdd(Map* &map, Dictionary &dict, int startId, int endId);

    //PRE: Ingresa el mapa, el diccionario y los limites de ID
    //POST:  Crea y agrega el elemento al mapa y al diccionario
    template<typename type>

    void elementAdd(Map* &map, Dictionary &dict, int startId, int endId, int amount);

    //PRE: Ingresa el diccionario y los limites de id
    //POST: Devuelve un ID en caso de tener un ID libre, en caso contrario un -1
    int searchId(Dictionary &dict, int startId, int endId);

};


template<typename type>

void ObjectAdder::beingAdd(Map *&map, Dictionary &dict, int startId, int endId){

    being = objectCreator.createBeing<type>();
    int id = searchId(dict, startId, endId);
    if(id == -1) {
        printer.couldntAddObject(being -> getObjectName());
        userInput.systemPause();
        delete being;
    }
    else
    {
        being->setId(id);
        int coordY, coordX;
        printer.showMap(map->getMatrix());
        userInput.validateRangeCoordinates(&coordY, &coordX, 1, map->getHeight(), 1, map->getWidth());
        if (!map->getMatrix()->getData(coordY - 1, coordX - 1)->isPositionTaken() &&
            !map->getMatrix()->getData(coordY - 1, coordX - 1)->getElement()) {
            map->loadBeing(coordY - 1, coordX - 1, being);
            dict.insert(being);
        } else {
            switch (userInput.validateReentry()) {
                case 1:
                    this->template beingAdd<type>(map, dict, startId, endId);
                    break;
                case 2:
                    break;
            }
        }
        printer.objectAddedSuccessfully(being -> getObjectName());
        userInput.systemPause();
    }
}

template<typename type>

void ObjectAdder::elementAdd(Map* &map, Dictionary &dict, int startId, int endId, int amount) {

    element = objectCreator.createElement<type>(amount);
    element -> setId(searchId(dict, startId, endId));
    int coordY, coordX;
    printer.showMap(map -> getMatrix());
    userInput.validateRangeCoordinates(&coordY,&coordX,1, map -> getHeight(),1,map -> getWidth());
    if(!map -> getMatrix() -> getData(coordY - 1,coordX - 1) -> isPositionTaken()
       && !map->getMatrix()->getData(coordY - 1, coordX -1 )->getElement())
    {
        map -> loadElement(coordY - 1, coordX - 1, element);
        dict.insert(element);
    }
    else {
        switch(userInput.validateReentry()){
            case 1:
                this -> template elementAdd<type>(map,dict,startId,endId,amount);
                break;
            case 2:
                break;
        }
    }

}


#endif //_OBJECTADDER_H
