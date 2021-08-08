#ifndef GRAFOS_USERINPUT_H
#define GRAFOS_USERINPUT_H

#include "iostream"
#include "Gotoxy.h"
#include "Printer.h"
#include "SFML/Graphics.hpp"


class UserInput {

private:

    Gotoxy gotoxy;
    Printer printer;
    int option;

public:

    UserInput() = default;

    int validateRangeOption(int min, int max);

    void validateRangeCoordinates(int* row, int* column, int minRows, int maxRows, int minColumns, int maxColumns);

    int validateAmount();

    void systemPause();

    int validateReentry();

};


#endif //GRAFOS_USERINPUT_H