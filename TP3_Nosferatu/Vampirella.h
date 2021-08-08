#ifndef _VAMPIRELLA_H
#define _VAMPIRELLA_H

#include "Vampire.h"

class Vampirella: public Vampire{

private:
    //Atributos
    std::string vampireName = "Vampirella";
    bool isBat;
public:

    //CONSTRUCTOR
    Vampirella();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: --
    //POST: Agrega la energia por defecto en cada turno
    void addTurnEnergy();

    //PRE: Ingresa un objetivo
    //POST: Realiza el ataque por defecto
    void attack(Being* &target);

    //PRE: Ingresa un objetivo y un arma
    //POST: Realiza el ataque con dicha arma
    void attack(Being* &target, Element* weapon){}

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    //PRE: --
    //POST: Realiza la auto defensa
    void selfHeal();

    //PRE: --
    //POST: Devuelve true en caso de estar en defensa
    bool isProtected();

    //PRE: --
    //POST: Devuelve true en caso de tener la energia suficiente para atacar
    bool checkAttackEnergy();

    // PRE: --
    //POST: Devuelve true en caso de tener la energia suficiente para la defensa
    bool checkDefenseEnergy();

    //PRE: --
    //POST: Finaliza la defensa
    void endDefense();

};


#endif //_VAMPIRELLA_H
