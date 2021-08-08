#ifndef GRAFOS_OBJECTFILE_H
#define GRAFOS_OBJECTFILE_H
#include "FileManager.h"
#include "ObjectCreator.h"
#include "Object.h"
#include "constantsNames.h"
#include "Dictionary.h"



class ObjectFile : public FileManager {

private:

    std::string kindObject, row, column, amount, id, trash;

public:
    ObjectFile() = default;
    void readFile(Map* &map, Dictionary &dict);

private:
    void separateString();
    void loadObject(Map* &map, Dictionary &dict);
    void loadBeing(Map* &map, Dictionary &dict);
    void loadElement(Map* &map, Dictionary &dict);
};


#endif //GRAFOS_OBJECTFILE_H
