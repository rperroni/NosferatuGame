#include "TheVoid.h"

TheVoid::TheVoid() {
    sf::Texture terrain;
    terrain.loadFromFile("TheVoid.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("TheVoidMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("TheVoidMarkedRed.png");
    this -> redBorder = redBorder;


    this -> type = "\033[48;5;5m ";
    this -> boardName = "T";
    this -> costs[HUMAN_COST] = 15;
    this -> costs[HUNTER_COST] = 15;
    this -> costs[ZOMBIE_COST] = 15;
    this -> costs[VAMPIRE_COST] = 15;
}

