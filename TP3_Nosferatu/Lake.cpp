#include "Lake.h"

Lake::Lake() {

    this -> type = "\033[48;5;51m ";
    this -> costs[HUMAN_COST] = 0;
    this -> costs[HUNTER_COST] = 0;
    this -> costs[ZOMBIE_COST] = 2;
    this -> costs[VAMPIRE_COST] = 1;


}