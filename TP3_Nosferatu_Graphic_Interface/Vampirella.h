#ifndef UNTITLED5_VAMPIRELLA_H
#define UNTITLED5_VAMPIRELLA_H

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
};


#endif //UNTITLED5_VAMPIRELLA_H
