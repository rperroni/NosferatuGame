#include "Bullet.h"

Bullet::Bullet(int amount) : Element(amount) {
    this -> objectName = BULLET_CAPITALIZED;
    this -> objectCharName = 'b';
}

void Bullet::show() {
    std::cout << gotoxy.pos(38,43) << "\033[40;1mTipo: " << objectType << std::endl;
    std::cout << gotoxy.pos(40,43) << "\033[40;1mNombre: " << consumableName << std::endl;
    std::cout << gotoxy.pos(42,43) << "\033[40;1mCantidad: " << amount << std::endl;
}

int Bullet::getAmount() {
    return amount;
}

void Bullet::setAmount(int amount) {
    this -> amount = amount;
}
