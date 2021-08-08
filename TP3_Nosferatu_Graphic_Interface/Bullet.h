#ifndef UNTITLED5_BULLET_H
#define UNTITLED5_BULLET_H
#include "Element.h"

class Bullet : public Element{
private:
    //Atributos
    //Nombre del tipo de consumible
    std::string consumableName = "Bala";
//    int amount;

public:
    //Contructor
    //PRE: Ingresa una cantidad positiva
    //POST: El objeto adquiere la cantidad ingresada
    Bullet(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show ();

    //PRE: ---
    //POST: Retorta la cantidad del objeto
    int getAmount();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    void setAmount(int amount);
};




#endif //UNTITLED5_BULLET_H
