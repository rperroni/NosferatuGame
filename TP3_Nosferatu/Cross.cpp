#include "Cross.h"

Cross::Cross(int amount) : Element(amount){
    this -> objectCharName = 'c';
    this -> objectName = CROSS_CAPITALIZED;
}

void Cross::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mTipo: " << objectType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mNombre: " << consumableName << std::endl;
}