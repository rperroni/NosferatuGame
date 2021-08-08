#ifndef UNTITLED5_STAKE_H
#define UNTITLED5_STAKE_H
#include "Element.h"

class Stake:public Element{
private:
    //Atributos
    std:: string consumableName = "estaca";
public:

    //CONSTRUCTOR
    Stake(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();
};


#endif //UNTITLED5_STAKE_H
