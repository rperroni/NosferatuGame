#ifndef GRAFOS_FILEMANAGER_H
#define GRAFOS_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "Map.h"
#include "ObjectCreator.h"

class FileManager {
protected:
    std::ifstream inputFile;
    ObjectCreator* objectCreator;

public:
    FileManager() {

        this -> objectCreator = new ObjectCreator;

    }

    bool openFile(std::string fileName);
    void closeFile();

    virtual void readFile();
    virtual ~FileManager() {

        delete objectCreator;
    };
};


#endif //GRAFOS_FILEMANAGER_H
