#ifndef UNTITLED5_HUMAN_H
#define UNTITLED5_HUMAN_H
#include "Being.h"

class Human: public Being{
protected:
    std::string characterType = "Humano";
protected:
    bool bitten;
public:

    Human();

    void show();

    // PRE:
    // POST:
    //std::string getObjectName();

    void attack(Being* &target);
    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();

    // PRE: debe ser llamado al inicio del turno
    // POST: agrega la energía de inicio de turno a cada ser
    void addTurnEnergy();

    // PRE: recibe un puntero a un elemento
    // POST: si el ser puede agarrar ese objeto, lo agrega a su inventario y devuelve true. De lo contrario
    //       devuelve false.
    bool grabElement(Element *item);

    // PRE:
    // POST:
    virtual void pickItem();

    // PRE:
    // POST:
    bool isBitten();

    // PRE:
    // POST:
    void transform();

protected:
    bool hasHolyWater();
};


#endif //UNTITLED5_HUMAN_H
