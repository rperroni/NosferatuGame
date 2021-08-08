#ifndef GRAFOS_PRINTER_H
#define GRAFOS_PRINTER_H

#include <iostream>
#include "constantsGraphicalInterface.h"
#include "Map.h"
#include "Gotoxy.h"
#include "Matrix.h"
#include "colors.h"
#include "SFML/Graphics.hpp"
#include "string"


#ifdef __linux__
#define CLEAR "clear"
#endif
#ifdef _MINGW32__
#define CLEAR "cls"

#endif

using namespace std;

class Printer {
private:

    sf::Font font;
    sf::Text text;
    //sf::Texture terrainTexture[6];
    //sf::Texture beingTextures[7];
    //sf::Texture elementTextures[5];
    Gotoxy gotoxy;

public:

    // CONSTRUCTOR
    // PRE:
    // POST:
    Printer();

    // PRE:
    // POST:
    void showTitle();

    // PRE:
    // POST:
    void showMainMenu();

    // PRE:
    // POST:
    void showIntro();

    // PRE:
    // POST:
    void showMap(Map* map);

    // PRE:
    // POST:
    void showMap(Matrix<Vertex*>* matrix,sf::RenderWindow &window);
    void showMap(Matrix<Vertex*>* matrix);

    void showMap(Vertex*** graph, sf::RenderWindow &window);

    // PRE:
    // POST:
    void showSavedGame();

    // PRE:
    // POST:
    void showActionMenu();

    // PRE:
    // POST:
    void showSimulationMenu();

    // PRE:
    // POST:
    void showGameArea();

    void showPreparationMenu();

    // PRE:
    // POST:
    void showObjectsMenu();

    // PRE:
    // POST:
    void showQuadrantsMenu();

    // PRE:
    // POST:
    void showInputSpot();

    // PRE:
    // POST:
    void mainWindow();

    // PRE:
    // POST:
    void showIdMenu();

    // PRE:
    // POST:
    void voidReferences();

    void showNotAbleToMove(int originX, int originY, sf::RenderWindow &window);

    void optionClear();

    void showFoundMessage(std::string quadrant, std::string wantedName);

    void showNotFoundMessage(std::string quadrant, std::string wantedName);

    void showAddObject(Matrix<Vertex*>* matrix,sf::RenderWindow &window);

private:
    void showBeings(sf::RenderWindow &window);
    void showElements(sf::RenderWindow &window);
    void setFont();
    void showTerrainReferences();
    void showBeingReferences();
    void setTextures();
    string validateEntry(sf::RenderWindow &window);
    void showObject(sf::RenderWindow &window, Object* item);
    void showCoordinateInput(sf::RenderWindow &window,Matrix<Vertex*>* matrix, string* row, string* col);
};


#endif //GRAFOS_PRINTER_H
