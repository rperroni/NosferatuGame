#include "Mountain.h"

Mountain::Mountain() {
    sf::Texture terrain;
    terrain.loadFromFile("Mountain.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("MountainMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("MountainMarkedRed.png");
    this -> redBorder = redBorder;


    this->type = "\033[48;5;94m ";
    this -> boardName = "M";
    this -> costs[HUMAN_COST] = 2;
    this -> costs[HUNTER_COST] = 0;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 1;

}