#ifndef _BOARDFILE_H
#define _BOARDFILE_H

#include "FileManager.h"
#include "ObjectCreator.h"
#include "CostMatrices.h"
#include "constantsNames.h"

class BoardFile: public FileManager{

private:

    // ATRIBUTOS

    int width, height;

public:

    // METODOS

    // CONSTRUCTOR
    BoardFile() = default;

    // PRE: Ingresa el mapa
    // POST: Lee el archivo de carga de terrenos
    void readFile(Map* &map);

private:

    // PRE: Ingresa el mapa, la fila y columna
    // POST: Setea el terreno y lo guarda dentro del mapa
    void setTerrain(Map* &map,int &row, int &column);

};


#endif //GRAFOS_BOARDFILE_H
