#ifndef UNTITLED5_NOSFERATU_H
#define UNTITLED5_NOSFERATU_H
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

    void addTurnEnergy();

    void attack(Being* &target);

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();
};


#endif //UNTITLED5_NOSFERATU_H
