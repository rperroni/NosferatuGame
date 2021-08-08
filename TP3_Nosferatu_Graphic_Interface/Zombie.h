#ifndef UNTITLED5_ZOMBIE_H
#define UNTITLED5_ZOMBIE_H
#include "Monster.h"

class Zombie: public Monster{
private:

    //Atributos
    std:: string monsterType = "Zombi";
    bool isHidden;
public:

    //CONSTRUCTOR
    Zombie();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto
    void show();

    void addTurnEnergy();

    void attack(Being* &target);

    void attack(Being* &target, Element* weapon){}

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    bool grabElement(Element* item);

};


#endif //UNTITLED5_ZOMBIE_H
