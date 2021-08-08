#include "Volcano.h"

Volcano::Volcano() {
    this -> type = "\033[48;5;160m ";
    this -> costs[HUMAN_COST] = 1;
    this -> costs[HUNTER_COST] = 1;
    this -> costs[ZOMBIE_COST] = 0;
    this -> costs[VAMPIRE_COST] = 2;
}