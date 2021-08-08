#ifndef _HUNTER_H_
#define _HUNTER_H_

#include "Human.h"

class Hunter : public Human{

protected:

    // ATRIBUTOS

    std::string humanType = "Cazador";

public:

    // METODOS

    //CONSTRUCTOR
    Hunter();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto.
    void show();

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    // PRE: --
    // POST: Se cura a si mismo
    void selfHeal();

    // PRE: --
    // POST: Devuelve true en caso de estar protegido
    bool isProtected();

    // PRE: --
    // POST: Devuelve true en caso de tener la energia suficiente para atacar
    bool checkAttackEnergy();

    // PRE: --
    // POST:Devuelve true en caso de tener la energia suficiente para defenderse
    bool checkDefenseEnergy();

    // PRE: --
    // POST: Agrega la energia correspondiente al comienzo del turno
    void addTurnEnergy();

    // PRE: Ingresa el ser que sera el objetivo y el arma a usar
    // POST: Realiza el ataque con sus respectivas modificaciones
    void attack(Being* &target, Element* weapon);

    // PRE: Ingresa el personaje objetivo
    // POST: Realiza el ataque por defecto
    void attack(Being* &target){};

    // PRE: Ingresa un elemento
    // POST: Devuelve true en caso de poder agarrarlo
    bool grabElement(Element *item);

    // PRE: --
    // POST: Finaliza la defensa
    void endDefense(){};

protected:

    // PRE: Ingresa el objetivo, el arma y con que arma se realizara el ataque
    // POST: Realiza el ataque y realiza las modificaciones de stats
    void attackZombie(Being *&target, Element *weapon, float withShotgun, float withStake);

private:

    // PRE: Ingresa el objetivo y el arma
    // POST: Realiza el ataque y realiza las modificaciones de stats
    void attackVampire(Being* &target, Element* weapon);

    // PRE: Ingresa el objetivo y el arma
    // POST: Realiza el ataque y realiza las modificaciones de stats
    void attackVampirella(Being* &target, Element* weapon);

};


#endif //_HUNTER_H_
