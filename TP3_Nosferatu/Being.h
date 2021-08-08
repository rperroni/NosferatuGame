#ifndef _BEING_H_
#define _BEING_H_

#include <ctime>
#include <cstdlib>
#include "Inventory.h" //inventory incluye list, element y constNames
#include "Identifier.h"
#include "constantsNames.h"

class Being : public Object {
protected:

    // ATRIBUTOS
    int energy;
    int health;
    int armor;
    int strength;
    Inventory* inventory;
    int costType;
    int team;
    int defenseDuration;

public:

    // METODOS

    // CONSTRUCTOR
    Being();

    // PRE: Recibe un daño
    // POST: Modifica la vida en función del daño recibido
    void receiveDamage(float damage);

    // PRE: --
    // POST: Baja los puntos de vida del personaje a 0
    void killBeing();

    // PRE: --
    // POST: Devuelve los puntos de energia del ser
    int getEnergy();

    // PRE: --
    // POST: Devuelve los puntos de armadura del ser
    int getArmor();

    // PRE: --
    // POST: Devuelve los puntos de vida del ser
    int getHealth();

    // PRE: --
    // POST: Devuelve los puntos de fuerza del ser
    int getStrength();

    // PRE: Ingresa los puntos de energia
    // POST: Modifica los puntos de energia del ser
    void setEnergy(int energy);

    // PRE: Ingresa los puntos de armadura
    // POST: Modifica los puntos de armadura del ser
    void setArmor(int armor);

    // PRE: Ingresa los puntos de vida
    // POST: Modifica los puntos de vida del ser
    void setHealth(int health);

    // PRE: Ingresa los puntos de fuerza
    // POST: Modifica los puntos de fuerza del ser
    void setStrength(int strength);

    // PRE: Ingresa los puntos de energia
    // POST: Suma los puntos de energia al ser
    void addEnergy(int energy);

    // PRE: Ingresa los puntos de fuerza
    // POST: Suma los puntos de fuerza al ser
    void addStrength(int strength);

    // PRE: Ingresa los puntos de armadura
    // POST: Suma los puntos de armadura del ser
    void addArmor(int armor);

    // PRE: Ingresa los puntos de vida
    // POST: Suma los puntos de vida del ser
    void addHealth(int health);

    // PRE: --
    // POST: Devuelve true si el ser tiene más de 0 de vida, si no devuelve false
    bool isAlive();

    // PRE: --
    // POST: Devuelve true en caso de tener una cruz en el inventario
    bool hasCross();

    // PRE: --
    // POST: Devuelve true en caso de tener una escopeta
    bool hasShotgun();

    // PRE: --
    // POST: Devuelve true en caso de tener balas
    bool hasBullets();

    // PRE: --
    // POST: Devuelve true en caso de tener estaca
    bool hasStake();

    // PRE: --
    // POST: Devuelve true en caso de tener agua bendita
    bool hasHolyWater();

    // PRE: --
    // POST: Devuelve el tipo de costo de cada casillero
    int getCostType();

    // PRE: --
    // POST: Setea las estadisticas aleatorias del ser
    void setRandomStats();

    // PRE: --
    // POST: Devuelve el inventario del personaje
    Inventory* getInventory();

    // PRE: --
    // POST: Devuelve el numero del equipo en el que se encuentra
    int getTeam();

    // PRE: --
    // POST: Baja un turno de la defensa
    void defenseCountdown();

    // PRE: --
    // POST: Devuelve la duracion de defensa que queda
    int getDefenseDuration();

    // PRE: Ingresa los turnos
    // POST: Inicia la duracion de la defensa
    void startDefense(int turns);

    //  VIRTUALES
    // PRE: Recibe el objetivo y el arma
    // POST: Realiza el ataque correspondiente
    virtual void attack(Being* &target, Element* weapon) = 0;

    // PRE: Ingresa el objetivo
    // POST: Realiza el ataque correspondiente
    virtual void attack(Being* &target) = 0;

    // PRE: El jugador debe haber elegido la accion de Defenderse.
    // POST: Ejecuta las acciones de defensa correspondientes.
    virtual short int defense() = 0;

    // PRE: --
    // POST: Se cura a si mismo
    virtual void selfHeal() = 0;

    // PRE: --
    // POST: Devuelve true en caso de estar protegido
    virtual bool isProtected() = 0;

    // PRE: --
    // POST: Devuelve true en caso de tener energia disponible para realizar el ataque
    virtual bool checkAttackEnergy() = 0;

    // PRE: --
    // POST: Devuelve true en caso de tener energia disponible para defender
    virtual bool checkDefenseEnergy() = 0;

    // PRE: Debe ser llamado al inicio del turno
    // POST: Agrega la energía de inicio de turno a cada ser
    virtual void addTurnEnergy() = 0;

    // PRE: Recibe un puntero a un elemento
    // POST: Si el ser puede agarrar ese objeto, lo agrega a su inventario y devuelve true. De lo contrario devuelve false.
    virtual bool grabElement(Element *item) = 0;

    // PRE: --
    // POST: Se transforma en zombie
    virtual void transform() = 0;

    // PRE: --
    // POST: Devuelve true en caso de haber sido mordido
    virtual bool isBitten() = 0;

    // PRE: --
    // POST: Devuelve true en caso de ser un zombie transformado
    virtual bool isZombieTransformed() = 0;

    // PRE: --
    // POST: Devuelve true en caso de ser un vampiro transformado
    virtual bool isVampireTransformed() = 0;

    // PRE: --
    // POST: Comienza la cuenta regresiva de la mordida
    virtual void bittenCountDown() = 0;

    // PRE: --
    // POST: Evita la transformacion
    virtual void avoidTransformation() = 0;

    // PRE: --
    // POST: Finaliza la duracion de la defensa
    virtual void endDefense() = 0;

    // PRE: --
    // POST: Se transforma en vampiro
    virtual void vampireTransform() = 0;

    // DESTRUCTOR
    ~Being();

private:
    //virtual void showAttackRange() = 0;
   //virtual Being* selectTarget() = 0;
};


#endif //_BEING_H_
