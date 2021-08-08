#ifndef _BEING_H_
#define _BEING_H_

#include <ctime>
#include <cstdlib>

#include "Inventory.h" //inventory incluye list, element y constNames
#include "Identidentifier.h" //incluye Objects
#include "constantsNames.h"

class Being : public Object {
protected:
    int energy;
    int health;
    int armor;
    int strength;
    Inventory* inventory;
    int costType;
    int team;

public:

    Being();

    // PRE: Recibe un daño
    // POST: Modifica la vida en función del daño recibido
    void receiveDamage(int damage);

    // PRE:
    // POST:
    void killBeing();

    // PRE:
    // POST:
    virtual void attack(Being* &target, Element* weapon) = 0;

    // PRE:
    // POST:
    virtual void attack(Being* &target) = 0;

    // PRE: El jugador debe haber elegido la accion de Defenderse
    // POST: Ejecuta las acciones de defensa correspondientes
    virtual short int defense() = 0;

    // PRE:
    // POST:
    virtual void selfHeal() = 0;

    // PRE:
    // POST:
    virtual bool isProtected() = 0;

    // PRE: debe ser llamado al inicio del turno
    // POST: agrega la energía de inicio de turno a cada ser
    virtual void addTurnEnergy() = 0;


    // PRE: recibe un puntero a un elemento
    // POST: si el ser puede agarrar ese objeto, lo agrega a su inventario y devuelve true. De lo contrario
    //       devuelve false.
    virtual bool grabElement(Element *item) = 0;

    //virtual void pickItem() = 0;

    // PRE:
    // POST:
    int getEnergy();

    // PRE:
    // POST:
    int getArmor();

    // PRE:
    // POST:
    int getHealth();

    // PRE:
    // POST:
    int getStrength();

    // PRE:
    // POST:
    void addEnergy(int energy);

    void addStrength(int strength);

    void addArmor(int armor);

    void addHealth(int health);

    // PRE: -
    // POST: devuelve true si el ser tiene más de 0 de vida, si no devuelve false
    bool isAlive();

    // PRE:
    // POST:
    bool hasCross();

    // PRE:
    // POST:
    int getCostType();

    // PRE:
    // POST:
    void setRandomStats();

    // PRE:
    // POST:
    Inventory* getInventory();

    int getTeam();

    ~Being();

private:
    //virtual void showAttackRange() = 0;
   //virtual Being* selectTarget() = 0;
};


#endif //_BEING_H_
