#ifndef GRAFOS_MAPCREATOR_H
#define GRAFOS_MAPCREATOR_H

#include "Map.h"
#include "BoardFile.h"
#include "ObjectFile.h"
#include "CostMatrices.h"
#include "Dictionary.h"

class MapCreator {
private:
    BoardFile boardFile;
    ObjectFile objectFile;
public:
    //CONSTRUCTOR
    MapCreator(Map* &map, Dictionary &dict);

    //DESTRUCTOR
    ~MapCreator();
};


#endif //GRAFOS_MAPCREATOR_H
