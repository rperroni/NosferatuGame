#include "Cross.h"

Cross::Cross(int amount) : Element(amount){
    sf::Texture texture;
    texture.loadFromFile("Cross.png");

    this -> texture = texture;


    objectCharName = 'c';
    this -> objectName = CROSS_CAPITALIZED;
}

void Cross::show() {
    std::cout << "Tipo: " << objectType << std::endl;
    std::cout << "Nombre: " << consumableName << std::endl;
}
/*
std::string Cross::getObjectName() {
    return consumableName;
}*/