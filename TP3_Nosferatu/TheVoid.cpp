#include "TheVoid.h"

TheVoid::TheVoid() {
    this->type = "\033[48;5;5m ";
    this -> costs[HUMAN_COST] = 15;
    this -> costs[HUNTER_COST] = 15;
    this -> costs[ZOMBIE_COST] = 15;
    this -> costs[VAMPIRE_COST] = 15;
}

