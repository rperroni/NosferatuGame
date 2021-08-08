#include "Cliff.h"

Cliff::Cliff() {
    sf::Texture terrain;
    terrain.loadFromFile("Cliff.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("CliffMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("CliffMarkedRed.png");
    this -> redBorder = redBorder;


    this -> type = "\033[48;5;31m ";
    this -> boardName = "C";
    this -> costs[HUMAN_COST] = 2;
    this -> costs[HUNTER_COST] = 2;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 0;
}