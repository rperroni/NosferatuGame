#ifndef _SHOTGUN_H
#define _SHOTGUN_H
#include "Element.h"

class Shotgun: public Element{
private:

    //Atributos
    std::string consumableName = "escopeta";
public:

    //CONSTRUCTOR
    Shotgun(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();
};
#endif //_SHOTGUN_H
