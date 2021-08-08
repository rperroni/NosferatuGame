#include "Bullet.h"

Bullet::Bullet(int amount) : Element(amount) {
    sf::Texture texture;
    texture.loadFromFile("Bullet.png");

    this -> texture = texture;

    this -> objectName = BULLET_CAPITALIZED;

}

void Bullet::show() {
    std::cout << "Tipo: " << objectType << std::endl;
    std::cout << "Nombre: " << consumableName << std::endl;
    std::cout << "Cantidad: " << amount << std::endl;
}
/*
std::string Bullet::getObjectName() {
    return consumableName;
}*/

int Bullet::getAmount() {
    return amount;
}

void Bullet::setAmount(int amount) {
    this->amount = amount;
}
