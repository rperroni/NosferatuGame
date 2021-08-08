#include "Identidentifier.h"

bool Identidentifier::isHuman(Object *obj) {
    return ((obj -> getId() >= 1) && (obj -> getId() <= 49) );
}

bool Identidentifier::isHumanTeam(Object* object) {
    return (object -> getId() >= 0 && object -> getId() <= 99);
}

bool Identidentifier::isMonsterTeam(Object *object) {
    return (object -> getId() >= 100 && object -> getId() <= 299);
}

bool Identidentifier::isHunter(Object *obj) {
    return ((obj -> getId() >= 50) && (obj -> getId() <= 99));
}

bool Identidentifier::isVanesa(Object *obj) {
    return (obj -> getId() == 0);
}

bool Identidentifier::isCross(Object *obj) {
    return ((obj -> getId() >= 320) && (obj -> getId() <= 339));
}

bool Identidentifier::isHolyWater(Object *obj) {
    return ((obj -> getId() >= 300) && (obj -> getId() <= 319));
}

bool Identidentifier::isShotgun(Object *obj) {
    return ((obj -> getId() >= 340) && (obj -> getId() <= 359));
}

bool Identidentifier::isStake(Object *obj) {
    return ((obj -> getId() >= 380) && (obj -> getId() <= 999));
}

bool Identidentifier::isBullet(Object *obj) {
    return (obj -> getId() >= 360 && obj -> getId() <= 379);
}

bool Identidentifier::isVampire(Object *obj) {
    return (obj -> getId() >= 202 && obj -> getId() <= 299);
}

bool Identidentifier::isVampirella(Object *obj) {
    return (obj -> getId() == 201);
}

bool Identidentifier::isNosferatu(Object *obj) {
    return (obj -> getId() == 200);
}

bool Identidentifier::isZombie(Object *obj) {
    return (obj -> getId() >= 100 && obj -> getId() <= 199);
}

bool Identidentifier::isHuman(int id) {
    return ((id >= 1) && (id <= 49));
}

bool Identidentifier::isHunter(int id) {
    return ((id >= 50) && (id <= 99));
}

bool Identidentifier::isVanesa(int id) {
    return ( id == 0 );
}

bool Identidentifier::isCross(int id) {
    return ((id >= 320) && (id <= 339));
}

bool Identidentifier::isHolyWater(int id) {
    return ((id >= 300) && (id <= 319));
}

bool Identidentifier::isShotgun(int id) {
    return ((id >= 340) && (id <= 359));
}

bool Identidentifier::isStake(int id) {
    return ((id >= 380) && (id <= 999));
}

bool Identidentifier::isBullet(int id) {
    return (id >= 360 && id <= 379);
}

bool Identidentifier::isVampire(int id) {
    return (id >= 202 && id <= 299);
}

bool Identidentifier::isVampirella(int id) {
    return (id == 201);
}

bool Identidentifier::isNosferatu(int id) {
    return (id == 200);
}

bool Identidentifier::isZombie(int id) {
    return (id >= 100 && id <= 199);
}

bool Identidentifier::isBeing(Object *object) {
    return (object -> getId() >= 0 && object -> getId() <= 299);
}

bool Identidentifier::isElement(Object *object) {
    return ( object ->getId() >= 300 && object -> getId() <= 999 );
}

bool Identidentifier::isHumanTeam(int id) {
    return (id >= 0 && id <= 99);
}

bool Identidentifier::isMonsterTeam(int id) {
    return (id >= 100 && id <= 299);
}

bool Identidentifier::isBeing(int id) {
    return (id >= 0 && id <= 299);
}

bool Identidentifier::isElement(int id) {
    return (id >= 300 && id <= 999);
}
