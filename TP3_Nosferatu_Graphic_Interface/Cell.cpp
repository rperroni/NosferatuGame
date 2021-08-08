#include "Cell.h"
#include "colors.h"

Cell::Cell() {
//    this -> terrain = sf::Sprite();
 //   terrain -> setTexture(*texture);
}

std::string Cell::getType() {
    return type;
}

int* Cell::getCosts() {
    return this -> costs;
}

std::string Cell::getBoardName() {
    return boardName;
}

sf::Texture Cell::getTexture() {
    return this -> texture;
}

sf::Texture Cell::getGreenBorder() {
    return this -> greenBorder;
}

sf::Texture Cell::getRedBorder() {
    return this -> redBorder;
}

Cell::~Cell() {

}