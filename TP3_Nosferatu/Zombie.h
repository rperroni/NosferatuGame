#ifndef _ZOMBIE_H
#define _ZOMBIE_H
#include "Monster.h"
#include "Human.h"
#include "Printer.h"

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

    // PRE:
    // POST: Agrega la energia correspondiente al turno jugado.
    void addTurnEnergy();

    // PRE: Recibe una referencia a puntero de objeto a ser.
    // POST: Ataca a sus enemigos.
    void attack(Being* &target);

    // PRE:
    // POST: Metodo vacio.
    void attack(Being* &target, Element* weapon){}

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    // PRE:
    // POST: Se cura a si mismo.
    void selfHeal();

    // PRE:
    // POST: Devuelve si esta protegido o no.
    bool isProtected();

    // PRE:
    // POST: Devuelve si tiene suficiente energia para atacar o no
    bool checkAttackEnergy();

    // PRE:
    // POST: Devuelve si tiene suficiente energia para defender o no
    bool checkDefenseEnergy();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    bool grabElement(Element* item);

    // PRE:
    // POST: Termina con la defensa del zombie.
    void endDefense();



};


#endif //_ZOMBIE_H
