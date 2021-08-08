#include "Volcano.h"

Volcano::Volcano() {
    sf::Texture terrain;
    terrain.loadFromFile("Volcano.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("VolcanoMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("VolcanoMarkedRed.png");
    this -> redBorder = redBorder;


    this -> type = "\033[48;5;160m ";
    this -> boardName = "V";
    this -> costs[HUMAN_COST] = 1;
    this -> costs[HUNTER_COST] = 1;
    this -> costs[ZOMBIE_COST] = 0;
    this -> costs[VAMPIRE_COST] = 2;
}