#include "Shotgun.h"

Shotgun::Shotgun(int amount) : Element(amount){
    sf::Texture texture;
    texture.loadFromFile("Shotgun.png");

    this -> texture = texture;


    this -> objectCharName = 'E';
    this -> objectName = SHOTGUN_CAPITALIZED;
}

void Shotgun::show() {
    std::cout << "Tipo: " << objectType << std::endl;
    std::cout << "Nombre: " << consumableName << std::endl;
}
/*
std::string Shotgun::getObjectName() {
    return consumableName;
}*/