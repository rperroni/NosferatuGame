#ifndef _VAMPIRE_H
#define _VAMPIRE_H
#include "Monster.h"

class Vampire: public Monster {
protected:
    //Atributos
    std::string monsterType = "Vampiro";

public:

    //CONSTRUCTOR
    Vampire();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    void addTurnEnergy();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    //PRE: Ingresa un elemento
    //POST: Devuelve true en caso de haber agarrado el item
    bool grabElement(Element* item);

    //PRE: Ingresa un elemento
    //POST: Destruye dicho elemento
    void destroyElement(Element* item);

    //PRE: Ingresa un ser de objetivo
    //POST: Realiza el ataque a dicho objetivo
    void attack(Being* &target);

    //PRE: Ingresa un ser de objetivo y un arma
    //POST: Realiza el ataque a dicho objetivo con el arma ingresada
    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    //PRE: --
    //POST: Realiza la autodefensa
    void selfHeal();

    //PRE: --
    //POST: Devuelve true en caso de tener defensa activa
    bool isProtected();

    //PRE: --
    //POST: Devuelve true en caso de tener energia disponible para atacar
    bool checkAttackEnergy();

    //PRE: --
    //POST: Devuelve true en caso de tener energia disponible para defenderse
    bool checkDefenseEnergy();

    //PRE: --
    //POST: Finaliza al defensa actual
    void endDefense();
};


#endif //_VAMPIRE_H
