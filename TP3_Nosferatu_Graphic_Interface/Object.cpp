#include "Object.h"

Object::Object() {
}

int Object::getAmount() {
    return 1;
}

int Object::getId() {
    return id;
}

void Object::setId(int id) {
    this ->  id = id;
}

void Object::showObjectCharacter()
{
    std::cout << this -> objectCharName << " ";
}

char Object::getCharName() {
    return objectCharName;
}

std::string Object::getObjectName() {
    return this -> objectName;
}

sf::Texture Object::getTexture() {
    return this -> texture;
}