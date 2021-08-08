#include "Identifier.h"

bool Identifier::isHuman(Object *obj) {
    return ( ((obj -> getId() >= 1) && (obj -> getId() <= 49)) && ((!obj->isZombieTransformed()) && (!obj->isVampireTransformed())));
}

bool Identifier::isHumanTeam(Object* object) {
    return ( ((object -> getId() >= 0) && (object -> getId() <= 99)) && (!object->isZombieTransformed()) && (!object->isVampireTransformed()));
}

bool Identifier::isMonsterTeam(Object *object) {
    return ( ((object -> getId() >= 100 && object -> getId() <= 299)) || (object->isZombieTransformed()) || (object->isVampireTransformed()));
}

bool Identifier::isHunter(Object *obj) {
    return ( ((obj -> getId() >= 50) && (obj -> getId() <= 99)) && ((!obj->isZombieTransformed()) && (!obj->isVampireTransformed())) );
}

bool Identifier::isVanesa(Object *obj) {
    return ( (obj -> getId() == 0) && ((!obj->isZombieTransformed()) && (!obj->isVampireTransformed())) );
}

bool Identifier::isCross(Object *obj) {
    return ( (obj -> getId() >= 320) && (obj -> getId() <= 339) );
}

bool Identifier::isHolyWater(Object *obj) {
    return ((obj -> getId() >= 300) && (obj -> getId() <= 319));
}

bool Identifier::isShotgun(Object *obj) {
    return ( (obj -> getId() >= 340) && (obj -> getId() <= 359) );
}

bool Identifier::isStake(Object *obj) {
    return ( (obj -> getId() >= 380) && (obj -> getId() <= 999) );
}

bool Identifier::isBullet(Object *obj) {
    return ( (obj -> getId() >= 360) && (obj -> getId() <= 379) );
}

bool Identifier::isVampire(Object *obj) {
    return ((obj -> getId() >= 202 && obj -> getId() <= 299) || obj->isVampireTransformed());
}

bool Identifier::isVampirella(Object *obj) {
    return (obj -> getId() == 201);
}

bool Identifier::isNosferatu(Object *obj) {
    return (obj -> getId() == 200);
}

bool Identifier::isZombie(Object *obj) {
    return ( (obj -> getId() >= 100 && obj -> getId() <= 199)  ||  (obj->isZombieTransformed()) );
}

bool Identifier::isHuman(int id) {
    return ((id >= 1) && (id <= 49));
}

bool Identifier::isHunter(int id) {
    return ((id >= 50) && (id <= 99));
}

bool Identifier::isVanesa(int id) {
    return ( id == 0 );
}

bool Identifier::isCross(int id) {
    return ((id >= 320) && (id <= 339));
}

bool Identifier::isHolyWater(int id) {
    return ((id >= 300) && (id <= 319));
}

bool Identifier::isShotgun(int id) {
    return ((id >= 340) && (id <= 359));
}

bool Identifier::isStake(int id) {
    return ((id >= 380) && (id <= 999));
}

bool Identifier::isBullet(int id) {
    return (id >= 360 && id <= 379);
}

bool Identifier::isVampire(int id) {
    return (id >= 202 && id <= 299);
}

bool Identifier::isVampirella(int id) {
    return (id == 201);
}

bool Identifier::isNosferatu(int id) {
    return (id == 200);
}

bool Identifier::isZombie(int id) {
    return (id >= 100 && id <= 199);
}

bool Identifier::isBeing(Object *object) {
    return (object -> getId() >= 0 && object -> getId() <= 299);
}

bool Identifier::isElement(Object *object) {
    return ( object ->getId() >= 300 && object -> getId() <= 999 );
}

bool Identifier::isHumanTeam(int id) {
    return (id >= 0 && id <= 99);
}

bool Identifier::isMonsterTeam(int id) {
    return (id >= 100 && id <= 299);
}

bool Identifier::isBeing(int id) {
    return (id >= 0 && id <= 299);
}

bool Identifier::isElement(int id) {
    return (id >= 300 && id <= 999);
}
