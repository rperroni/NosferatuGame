#include "Cliff.h"

Cliff::Cliff() {
    this -> type = "\033[48;5;31m ";
    this -> costs[HUMAN_COST] = 2;
    this -> costs[HUNTER_COST] = 2;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 0;
}