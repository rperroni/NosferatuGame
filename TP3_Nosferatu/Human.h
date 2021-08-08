#ifndef _HUMAN_H
#define _HUMAN_H

#include "Being.h"
#include "colors.h"

class Human: public Being{

protected:

    // ATRIBUTOS

    std::string characterType = "Humano";
    bool bitten;
    bool vampireBitten;
    int bittenCount;

public:

    // METODOS

    // CONSTRUCTOR
    Human();

    // PRE:
    // POST:
    void show();

    // PRE:
    // POST:
    void attack(Being* &target);

    // PRE:
    // POST:
    void attack(Being* &target, Element* weapon){};

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    // PRE: --
    // POST: Se cura a si mismo
    void selfHeal();

    // PRE: --
    // POST: Devuelve true si esta protegido
    bool isProtected();

    // PRE: --
    // POST: Devuelve true en caso de tener energia suficiente para atacar
    bool checkAttackEnergy();

    // PRE: --
    // POST: Devuelve false en caso de tener energia suficiente para atacar
    bool checkDefenseEnergy();

    // PRE: debe ser llamado al inicio del turno
    // POST: agrega la energía de inicio de turno a cada ser
    void addTurnEnergy();

    // PRE: recibe un puntero a un elemento
    // POST: si el ser puede agarrar ese objeto, lo agrega a su inventario y devuelve true. De lo contrario
    //       devuelve false.
    bool grabElement(Element *item);

    // PRE: --
    // POST: Devuelve true en caso de haber sido mordido
    bool isBitten();

    // PRE: --
    // POST: El ser se transforma
    void transform();

    // PRE: --
    // POST: El ser se transforma en vampiro
    void vampireTransform();

    // PRE: --
    // POST: Disminuye el contador de turnos de mordida
    void bittenCountDown();

    // PRE: --
    // POST: Devuelve true en caso de ser un humano transformado en zombie
    bool isZombieTransformed();

    // PRE: --
    // POST: Devuelve true en caso de ser un humano transformado en vampiro
    bool isVampireTransformed();

    // PRE: --
    // POST: Evita la transformacion
    void avoidTransformation();

    // PRE: --
    // POST: Finaliza la defensa
    void endDefense();

};


#endif //UNTITLED5_HUMAN_H
