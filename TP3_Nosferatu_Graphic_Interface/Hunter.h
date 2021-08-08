#ifndef _HUNTER_H_
#define _HUNTER_H_
#include "Human.h"

class Hunter : public Human{
protected:
    //Atributos
    std::string humanType = "Cazador";
public:

    //CONSTRUCTOR
    Hunter();

    //PRE: ---
    //POST: Muestra por pantalla las caracteristicas del objeto.
    void show();

    //PRE: ---
    //POST: Retorna el nombre del objeto
    //std::string getObjectName();

    // PRE: el jugador debe haber elegido la accion de Defenderse
    // POST: ejecuta las acciones de defensa correspondientes
    short int defense();

    void selfHeal();

    bool isProtected();

    void addTurnEnergy();

    void attack(Being* &target, Element* weapon);
    void attack(Being* &target){};

    // PRE:
    // POST:
    void pickItem();

    bool grabElement(Element *item);

protected:
    //metodos
    void attackZombie(Being *&target, Element *weapon, float withShotgun, float withStake);

private:
    void attackVampire(Being* &target, Element* weapon);

    void attackVampirella(Being* &target, Element* weapon);


//pocentaje daño zombi escopeta
//porcentaje daño zombi estaca
//pocentaje daño vampiro escopeta
// daño vampiro estaca
// daño vampiro agua bendita
};


#endif //_HUNTER_H_
