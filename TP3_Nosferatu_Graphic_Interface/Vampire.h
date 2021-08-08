#ifndef UNTITLED5_VAMPIRE_H
#define UNTITLED5_VAMPIRE_H
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

    bool grabElement(Element* item);

    void destroyElement(Element* item);

    void attack(Being* &target);

    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();

};


#endif //UNTITLED5_VAMPIRE_H
