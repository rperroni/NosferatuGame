#ifndef GRAFOS_GRAPHICOPTIONS_H
#define GRAFOS_GRAPHICOPTIONS_H

#include "SFML/Graphics.hpp"
#include "Map.h"
#include "constantsGraphicalInterface.h"
#include "Dictionary.h"
#include "Menu.h"
#include "ObjectAdder.h"
#include "UserInput.h"
#include <unistd.h>
#include "Floyd.h"
#include "Background.h"

const int MAX_BEING_NAMES = 7;

const int MAX_ELEMENT_NAMES = 5;

const int MAX_TERRAIN_NAMES = 6;

class GraphicOptions {
private:

    int rowLimits[2];
    int columnLimits[2];

    Background background;
    sf::Font graphicFont;
    sf::Text graphicText;
    sf::Sprite graphicSprite;
    sf::Texture terrainTexture[6];
    sf::Texture beingTextures[7];
    sf::Texture elementTextures[5];

    UserInput userInput;
    ObjectAdder objectAdder;

public:
    GraphicOptions();

    void addObject(sf::RenderWindow &window, Map* map, Dictionary* dic);

    void removeObject(sf::RenderWindow &window, Map* map, Dictionary* dic);

    void showMap(sf::RenderWindow &window, Map* map);

    void quadrantSearch(sf::RenderWindow &window, Map* map);

    void idSearch(sf::RenderWindow &window, Map* map, Dictionary* dic);

    void moveObject(sf::RenderWindow &window, Map* map);

private:

    bool addBeing(Map *&map, Dictionary &dict, int userInput, int row, int column);

    bool addElement(Map *&map, Dictionary &dict, int userInput, int amount, int row, int column);

    void showBoard(sf::RenderWindow &window, Map* map);

    void loadTerrainTextures();
    void loadBeingTextures();
    void loadElementTextures();

    void setFont(std:: string fontName);

    void editCustomText(int row, int column, const string &text);
    void showMapReferences(sf::RenderWindow &window);
    void showTerrainReferences(sf::RenderWindow &window, int xPosition, int yPosition);

    void showBeingTextures(sf::RenderWindow &window, int xPosition, int yPosition);
    void showBeingTexts(sf::RenderWindow &window, const std::string* names, int xPosition, int yPosition);

    void showElementTextures(sf::RenderWindow &window, int xPosition, int yPosition);
    void showElementTexts(sf::RenderWindow &window, const std::string* names, int xPosition, int yPosition);

    void awaitingInteraction(sf::RenderWindow &window);

    void showObject(sf::RenderWindow &window, Object* object);

    string validateEntry(sf::RenderWindow &window);

    string showCoordinateInput(sf::RenderWindow &window, int max);

    void showRemoveMap(sf::RenderWindow &window, Map* map, int row, int column);
    void showAddMap(sf::RenderWindow &window, Map* map, int row, int column);

    void showQuadrantReferences(sf::RenderWindow &window);

    void assingQuadrantLimits(string quadrantName, int height, int width);

    bool showQuadrant(sf::RenderWindow &window, Map* map, string object);
};


#endif //GRAFOS_GRAPHICOPTIONS_H
