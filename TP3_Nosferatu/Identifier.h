#ifndef _IDENTIFIER_H
#define _IDENTIFIER_H

#include "Object.h"
#include "constantsNames.h"

class Identifier {

public:

    // METODOS

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser humano
    bool isHuman(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser un cazador
    bool isHunter(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser Vanesa
    bool isVanesa(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser una Cruz
    bool isCross(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser agua bendita
    bool isHolyWater(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser una escopeta
    bool isShotgun(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser una estaca
    bool isStake(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser una bala
    bool isBullet(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser un vampiro
    bool isVampire(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser Vampirella
    bool isVampirella(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser Nosferatu
    bool isNosferatu(Object* obj);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser un Zombie
    bool isZombie(Object* obj);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser humano
    bool isHuman(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser un cazador
    bool isHunter(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser Vanesa
    bool isVanesa(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser Cruz
    bool isCross(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser agua
    bool isHolyWater(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser escopeta
    bool isShotgun(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser estaca
    bool isStake(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser bala
    bool isBullet(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser vampiro
    bool isVampire(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser Vampirella
    bool isVampirella(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser Nosferatu
    bool isNosferatu(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser zombie
    bool isZombie(int id);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser del equipo Humano
    bool isHumanTeam(Object* object);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser del equipo Monstruo
    bool isMonsterTeam(Object* object); // Parece que no lo vamos a usar. Con el isHumanTeam es suficiente.

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser un ser
    bool isBeing(Object* object);

    // PRE: Ingresa un objeto
    // POST: Devuelve true en caso de ser un Elemento
    bool isElement(Object* object);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser del equipo humano
    bool isHumanTeam(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser del equipo Monstruo
    bool isMonsterTeam(int id); // Parece que no lo vamos a usar. Con el isHumanTeam es suficiente.

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser de tipo SER
    bool isBeing(int id);

    // PRE: Ingresa un ID
    // POST: Devuelve true en caso de ser de tipo Elemento
    bool isElement(int id);

};


#endif //GRAFOS_IDENTIFIER_H
