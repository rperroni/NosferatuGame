#include "Stake.h"

Stake::Stake(int amount) : Element(amount) {
    this -> objectCharName = 'e';
    this -> objectName = STAKE_CAPITALIZED;
}

void Stake::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mTipo: " << objectType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mNombre: " << consumableName << std::endl;
}
