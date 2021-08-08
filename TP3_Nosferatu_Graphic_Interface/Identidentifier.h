#ifndef GRAFOS_IDENTIDENTIFIER_H
#define GRAFOS_IDENTIDENTIFIER_H

#include "Object.h"
#include "constantsNames.h"

class Identidentifier {
public:
    bool isHuman(Object* obj);
    bool isHunter(Object* obj);
    bool isVanesa(Object* obj);

    bool isCross(Object* obj);
    bool isHolyWater(Object* obj);
    bool isShotgun(Object* obj);
    bool isStake(Object* obj);
    bool isBullet(Object* obj);

    bool isVampire(Object* obj);
    bool isVampirella(Object* obj);
    bool isNosferatu(Object* obj);
    bool isZombie(Object* obj);

    bool isHuman(int id);
    bool isHunter(int id);
    bool isVanesa(int id);

    bool isCross(int id);
    bool isHolyWater(int id);
    bool isShotgun(int id);
    bool isStake(int id);
    bool isBullet(int id);

    bool isVampire(int id);
    bool isVampirella(int id);
    bool isNosferatu(int id);
    bool isZombie(int id);

    bool isHumanTeam(Object* object);
    bool isMonsterTeam(Object* object); // Parece que no lo vamos a usar. Con el isHumanTeam es suficiente.

    bool isBeing(Object* object);
    bool isElement(Object* object);

    bool isHumanTeam(int id);
    bool isMonsterTeam(int id); // Parece que no lo vamos a usar. Con el isHumanTeam es suficiente.
    bool isBeing(int id);
    bool isElement(int id);

};


#endif //GRAFOS_IDENTIDENTIFIER_H
