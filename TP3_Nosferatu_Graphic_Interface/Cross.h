#ifndef UNTITLED5_CROSS_H
#define UNTITLED5_CROSS_H
#include "Element.h"

class Cross: public Element{
private:
    //Atributos
    std::string consumableName = "cruz";
public:

    //CONSTRUCTOR
    Cross(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

};


#endif //UNTITLED5_CROSS_H
