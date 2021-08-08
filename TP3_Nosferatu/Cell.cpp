#include "Cell.h"
#include "colors.h"

Cell::Cell() {}

std::string Cell::getType() {
    return type;
}

int* Cell::getCosts() {
    return this -> costs;
}

Cell::~Cell() {}