#include "HolyWater.h"

HolyWater::HolyWater(int amount) : Element(amount){
    this -> amount = amount;
    this -> objectName = HOLYWATER_CAPITALIZED;
    this -> objectCharName = 'a';
}

void HolyWater::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mTipo: " << objectType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mNombre: " << consumableName << std::endl;
    std::cout << gotoxy.pos(42,43) << "\033[40;1mCantidad: " << amount << std::endl;
}

int HolyWater::getAmount() {
    return amount;
}

void HolyWater::setAmount(int amount) {
    this->amount = amount;
}
