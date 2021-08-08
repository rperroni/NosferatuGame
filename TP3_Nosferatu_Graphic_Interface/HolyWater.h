#ifndef UNTITLED5_HOLYWATER_H
#define UNTITLED5_HOLYWATER_H
#include "Element.h"

class HolyWater: public Element{
private:
    //Atributos
    std:: string consumableName = "Agua Bendita";
//    int amount;
public:
    //Contructor
    //PRE: Ingresa una cantidad positiva
    //POST: El objeto adquiere la cantidad ingresada
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

    void setAmount(int amount);
};


#endif //UNTITLED5_HOLYWATER_H
