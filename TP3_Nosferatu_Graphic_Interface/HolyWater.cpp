#include "HolyWater.h"

HolyWater::HolyWater(int amount) : Element(amount){
    sf::Texture texture;
    texture.loadFromFile("Holywater.png");

    this -> texture = texture;


    this -> amount = amount;
    this -> objectName = HOLYWATER_CAPITALIZED;
    this -> objectCharName = 'a';
}

void HolyWater::show() {
//    std::cout << "Tipo: " << objectType << std::endl;
    std::cout << "Nombre: " << consumableName << std::endl;
    std::cout << "Cantidad: " << amount << std::endl;
}
/*
std::string HolyWater::getObjectName() {
    return consumableName;
}*/

int HolyWater::getAmount() {
    return amount;
}

void HolyWater::setAmount(int amount) {
    this->amount = amount;
}
