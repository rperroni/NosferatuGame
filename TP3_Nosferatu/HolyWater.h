#ifndef _HOLYWATER_H
#define _HOLYWATER_H

#include "Element.h"

class HolyWater: public Element{

private:

    // ATRIBUTOS

    std:: string consumableName = "Agua Bendita";

public:

    // METODOS

    // CONSTRUCTOR
    HolyWater(int quantity);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Retorta la cantidad del objeto
    //std::string getObjectName();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    int getAmount();

    // PRE: Ingresa la cantidad
    // POST: Devuelve la cantidad del elemento
    void setAmount(int amount);

};


#endif //UNTITLED5_HOLYWATER_H
