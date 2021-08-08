#include "Road.h"

Road::Road() {
    this -> type = "\033[48;5;247m ";
    this -> costs[HUMAN_COST] = 1;
    this -> costs[HUNTER_COST] = 1;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 1;
}