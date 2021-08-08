#ifndef UNTITLED5_VANESA_H
#define UNTITLED5_VANESA_H
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

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    void attack(Being* &target, Element* weapon);
    void attack(Being* &target){}; // PREGUNTAR ANDY

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();

    void addTurnEnergy();

    //Vanesa usa el mismo pickItem() que Hunter

    bool grabElement(Element *item);

    bool isCrossDefended();

private:
    //metodos

    void attackVampire(Being* &target, Element* weapon);

    void attackVampirella(Being* &target, Element* weapon);
};


#endif //UNTITLED5_VANESA_H
