#include "Road.h"

Road::Road() {
    sf::Texture terrain;
    terrain.loadFromFile("Road.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("RoadMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("RoadMarkedRed.png");
    this -> redBorder = redBorder;


    this -> type = "\033[48;5;247m ";
    this -> boardName = "R";
    this -> costs[HUMAN_COST] = 1;
    this -> costs[HUNTER_COST] = 1;
    this -> costs[ZOMBIE_COST] = 1;
    this -> costs[VAMPIRE_COST] = 1;
}