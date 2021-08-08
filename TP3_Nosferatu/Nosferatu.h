#ifndef _NOSFERATU_H
#define _NOSFERATU_H
#include "Vampire.h"

class Nosferatu: public Vampire{
private:
    //ATRIBUTOS
    std::string vampireName = "Nosferatu";
public:

    //CONTRUCTOR
    Nosferatu();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    //PRE: ---
    //POST: Adhiere la energia al comienzo del turno
    void addTurnEnergy();

    //PRE: Ingresa el ser
    //POST: Realiza el ataque
    void attack(Being* &target);

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    //PRE: Ingresa el objetivo y el arma a usar
    //POST: Realiza el ataque
    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    // PRE: --
    // POST: Se cura a si mismo
    void selfHeal();

    // PRE: --
    // POST: Devuelve true en caso de estar protegido
    bool isProtected();

    //PRE: --
    //POST: Devuelve true en caso de tener la energia suficiente para atacar
    bool checkAttackEnergy();

    // PRE: --
    // POST: Devuelve true en caso de tener la energia suficiente para defenderse
    bool checkDefenseEnergy();

    // PRE: --
    // POST: Finaliza la defensa
    void endDefense(){};
};


#endif //UNTITLED5_NOSFERATU_H
