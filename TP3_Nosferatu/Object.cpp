#include "Object.h"

Object::Object() {
    currentRow = -1;
    currentCol = -1;
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

void Object::setRow(int row) {
    currentRow = row;
}

void Object::setColumn(int col) {
    currentCol = col;
}

int Object::getRow() {
    return currentRow;
}

int Object::getCol() {
    return currentCol;
}
