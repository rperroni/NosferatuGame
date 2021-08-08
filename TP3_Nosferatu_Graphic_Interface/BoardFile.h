#ifndef GRAFOS_BOARDFILE_H
#define GRAFOS_BOARDFILE_H

#include "FileManager.h"
#include "ObjectCreator.h"
#include "CostMatrices.h"
#include "constantsNames.h"

class BoardFile: public FileManager{

private:

    int width, height;

public:

    BoardFile() = default;

    void readFile(Map* &map);

private:

    void setTerrain(Map* &map,int &row, int &column);

};


#endif //GRAFOS_BOARDFILE_H
