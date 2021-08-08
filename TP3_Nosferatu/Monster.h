#ifndef _MONSTER_H
#define _MONSTER_H
#include "Being.h"

class Monster: public Being{
protected:
    //ATRIBUTOS
    std:: string characterType = "Monstruo";
    bool transformedHuman;
    bool tranformedVampire;

public:
    //CONSTRUCTOR
    Monster();

    //PRE: -
    //POST: Devuelve true en caso de estar transformado en zombie NO SE USA
    bool isZombieTransformed();

    //PRE: -
    //POST: Devuelve true en caso de estar transformado en vampiro NO SE USA
    bool isVampireTransformed();

    //PRE: -
    //POST: Setea la transformacion
    void setTransformation();

    //PRE: -
    //POST: Se transforma NO SE USA
    void transform(){};

    //PRE: -
    //POST: Devuelve true en caso de haber sido mordido NO SE USA
    bool isBitten();

    //PRE: -
    //POST: Inicia el contador del tiempo de transformacion NO SE USA
    void bittenCountDown(){};

    //PRE: -
    //POST: Evade la transformacion
    void avoidTransformation(){};

    //PRE: -
    //POST: Finaliza la defensa
    virtual void endDefense() = 0;

    //PRE: -
    //POST: Se transforma en vampiro
    void vampireTransform();

};


#endif //UNTITLED5_MONSTER_H

