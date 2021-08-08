#ifndef _OBJECTFILE_H
#define _OBJECTFILE_H
#include "FileManager.h"
#include "ObjectCreator.h"
#include "Object.h"
#include "constantsNames.h"
#include "Dictionary.h"



class ObjectFile : public FileManager {

private:

    std::string kindObject, row, column, amount, id, trash;

public:
    //CONSTRUCTOR
    ObjectFile() = default;

    //PRE: Ingresa el mapa y el diccionario
    //POST: Lee el archivo y agrega los seres
    void readFile(Map* &map, Dictionary &dict);

private:

    //PRE: --
    //POST: Separa el string
    void separateString();

    //PRE: Ingresa el mapa y el diccionario
    //POST: Carga el objeto en ambos
    void loadObject(Map* &map, Dictionary &dict);

    //PRE: Ingresa el mapa y el diccionario
    //POST: Carga el ser en ambos
    void loadBeing(Map* &map, Dictionary &dict);

    //PRE: Ingresa el mapa y el diccionario
    //POST: Carga el elemento en ambos
    void loadElement(Map* &map, Dictionary &dict);
};


#endif //GRAFOS_OBJECTFILE_H
