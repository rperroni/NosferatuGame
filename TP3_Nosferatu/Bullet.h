#ifndef _BULLET_H
#define _BULLET_H
#include "Element.h"

class Bullet : public Element{
private:

    // ATRIBUTOS

    std::string consumableName = "Bala";

public:

    // METODOS

    // CONSTRUCTOR
    Bullet(int amount);

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Retorta la cantidad del objeto
    int getAmount();

    // PRE: ---
    // POST: Modifica la cantidad
    void setAmount(int amount);

};




#endif //UNTITLED5_BULLET_H
