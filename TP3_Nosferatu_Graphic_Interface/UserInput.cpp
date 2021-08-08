#include "UserInput.h"

int UserInput::validateRangeOption(int min, int max) {

    std::cout << gotoxy.pos(40,5) << "\033[47;30;1m----> ";
    std::cin >> option;
    std::cout << "\033[0m" << std::endl;

    if(option < min || option > max){
        std::cout << gotoxy.pos(40,10) << "\033[40m       \033[0m";
        std::cout << gotoxy.pos(43,5) << "\033[48;5;88m Fuera de rango. Tiene que ser entre: " << min << " y " << max << "\033[0m" <<  std::endl;
        return this -> validateRangeOption(min,max);
    }
    else{
        printer.optionClear();
        return option;
    }
}

void UserInput::validateRangeCoordinates(int* row, int* column, int minRows, int maxRows, int minColumns, int maxColumns) {
    std::cout << gotoxy.pos(39,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m  COORDENADA Y: ";
    *row = this -> validateRangeOption(minRows, maxRows);
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m  COORDENADA X: ";
    *column = this -> validateRangeOption(minColumns, maxColumns);

}

int UserInput::validateAmount() {
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m INGRESE LA CANTIDAD: ";
    return validateRangeOption(1,99);
}

void UserInput::systemPause() {

    std::cout << gotoxy.pos(41,5) << "\033[6;47;30;1m PRESIONE ENTER \033[0m";
    std::cin.get();
    std::cin.get();

}

int UserInput::validateReentry() {

    std::cout << gotoxy.pos(39,5) << "\033[48;5;88m INGRESO INVALIDO \033[0m";
    std::cout << gotoxy.pos(42,5) << "\033[47;30;1m [1] REINGRESAR  \033[0m";
    std::cout << gotoxy.pos(43,5) << "\033[47;30;1m [2] VOLVER ATRAS \033[0m";

    return validateRangeOption(1,2);
}

