#ifndef GRAFOS_FILEMANAGER_H
#define GRAFOS_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "Map.h"
#include "ObjectCreator.h"

class FileManager {

protected:

    // ATRIBUTOS

    std::ifstream inputFile;
    ObjectCreator* objectCreator;

public:

    // METODOS

    // CONSTRUCTOR
    FileManager();

    // PRE: Ingresa el nombre del archivo
    // POST: Devuelve true en caso de existir
    bool openFile(std::string fileName);

    // PRE: --
    // POST: Cierra el archivo
    void closeFile();

    // PRE: --
    // POST: Lee el archivo
    virtual void readFile();

    // DESTRUCTOR
    virtual ~FileManager();
};


#endif //GRAFOS_FILEMANAGER_H
