#ifndef _VANESA_H
#define _VANESA_H

#include "Hunter.h"


class Vanesa: public Hunter{
private:
    //Atributos
    std::string vampireHunterName = "Vanesa";
    bool crossDefended;
public:

    //CONSTRUCTOR
    Vanesa();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: target debe ser un ser valido y weapon un elemento valido
    //POST: Ataca a target con el arma weapon
    void attack(Being* &target, Element* weapon);
    void attack(Being* &target){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    //PRE:
    //POST: Ejecuta la auto defensa
    void selfHeal();

    //PRE:
    //POST: Devuelve si esta protegido o no
    bool isProtected();

    //PRE:
    //POST: Devuelve si tiene energia para atacar o no
    bool checkAttackEnergy();

    // PRE:
    // POST: Devuelve si tiene energia para defender o no
    bool checkDefenseEnergy();

    //PRE:
    //POST: Suma la energia de turno
    void addTurnEnergy();

    //PRE: item debe ser un elemento valido
    //POST: Agrega item en el inventario
    bool grabElement(Element *item);

    //PRE:
    //POST: Termina la defensa
    void endDefense();

private:
    //metodos

    void attackVampire(Being* &target, Element* weapon);

    void attackVampirella(Being* &target, Element* weapon);
};


#endif //_VANESA_H
