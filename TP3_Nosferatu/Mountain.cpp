#include "Mountain.h"

Mountain::Mountain() {

    this->type = "\033[48;5;94m ";
    this -> costs[HUMAN_COST] = 2;
    this -> costs[HUNTER_COST] = 0;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 1;

}