#include "Shotgun.h"

Shotgun::Shotgun(int amount) : Element(amount){
    this -> objectCharName = 'E';
    this -> objectName = SHOTGUN_CAPITALIZED;
}

void Shotgun::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mTipo: " << objectType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mNombre: " << consumableName << std::endl;
}
