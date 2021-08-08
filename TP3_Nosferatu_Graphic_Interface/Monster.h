#ifndef UNTITLED5_MONSTER_H
#define UNTITLED5_MONSTER_H
#include "Being.h"

class Monster: public Being{
protected:
    //ATRIBUTOS
    std:: string characterType = "Monstruo";

public:
    Monster() = default;
};


#endif //UNTITLED5_MONSTER_H
