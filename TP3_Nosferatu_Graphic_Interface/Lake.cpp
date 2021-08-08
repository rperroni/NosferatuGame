#include "Lake.h"

Lake::Lake() {
    sf::Texture terrain;
    terrain.loadFromFile("Lake.png");
    this -> texture = terrain;

    sf::Texture greenBorder;
    greenBorder.loadFromFile("LakeMarkedGreen.png");
    this -> greenBorder = greenBorder;

    sf::Texture redBorder;
    redBorder.loadFromFile("LakeMarkedRed.png");
    this -> redBorder = redBorder;


    this -> type = "\033[48;5;51m ";
    this -> boardName = "L";
    this -> costs[HUMAN_COST] = 0;
    this -> costs[HUNTER_COST] = 0;
    this -> costs[ZOMBIE_COST] = 2;
    this -> costs[VAMPIRE_COST] = 1;


}