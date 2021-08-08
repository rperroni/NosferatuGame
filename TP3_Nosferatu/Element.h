#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include "Object.h"
#include "constantsNames.h"

class Element: public Object{

protected:

    // ATRIBUTOS

    int amount;
    std::string objectType = "Consumible";

public:

    // METODOS

    //CONSTRUCTOR
    Element(int amount);

    // PRE: Ingresa una cantidad
    // POST: Setea la cantidad del elemento
    virtual void setAmount(int amount);

    // PRE: --
    // POST: Muestra datos del elemento
    virtual void show() = 0;

    // PRE: --
    // POST: Devuelve valor por defecto (NO SE USA)
    bool isZombieTransformed(){return false;};

    // PRE: --
    // POST: Devuelve valor por defecto (NO SE USA)
    bool isVampireTransformed(){return false;};

    // PRE: Ingresa un elemento
    // POST: Suma la cantidad del otro item al elemento
    void operator+=(Element * item);

    // PRE: Ingresa un elemento
    // POST: Devuelve true en caso de ser el mismo tipo de objeto
    bool operator==(Element * item);

    // PRE: Ingresa un nombre
    // POST: Devuelve true en caso de ser ese tipo de elemento
    bool operator==(std::string name);

    // PRE: Ingresa la cantidad
    // POST: Devuelve true en caso de no ser esa cantidad
    bool operator!=(int amount);

};



#endif //_ELEMENT_H
