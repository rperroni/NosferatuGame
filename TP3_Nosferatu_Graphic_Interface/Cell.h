#ifndef GRAFOS_CELL_H
#define GRAFOS_CELL_H

#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics.hpp"
#include "string"
#include "Object.h"
#include "constantsNames.h"

//using namespace sf; VES LO QUE PASA POR PONERLO EL INGLESSSSSSSSS.

const int MAX_COSTS = 4;

class Cell {
protected:

    std::string type;
    std::string boardName;
    int costs[MAX_COSTS];

    sf::Texture texture;
    sf::Texture greenBorder;
    sf::Texture redBorder;


public:
    // CONSTRUCTOR
    Cell();

    // PRE:
    // POST:
    std::string getType();

    // PRE:
    // POST:
    int* getCosts();

    sf::Texture getTexture();

    sf::Texture getGreenBorder();

    sf::Texture getRedBorder();



    std::string getBoardName();



    // DESTRUCTOR
    ~Cell();
};


#endif //GRAFOS_CELL_H
