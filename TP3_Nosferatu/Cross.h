#ifndef _CROSS_H
#define _CROSS_H
#include "Element.h"

class Cross: public Element{
private:
    // ATRIBUTOS

    std::string consumableName = "cruz";
public:

    // METODOS

    //CONSTRUCTOR
    Cross(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

};


#endif //UNTITLED5_CROSS_H
