#ifndef UNTITLED5_GRAPHICMENU_H
#define UNTITLED5_GRAPHICMENU_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Game.h"
#include "constantsGraphicalInterface.h"
#include "GraphicOptions.h"

class GraphicMenu
{
private:
    //ATRIBUTOS
    Game gameCycle; //Parte principal del TP
    Background gameBackgrounds;
    int selectedItemIndex;
    bool allowActions = true;
    sf::Font font;
    sf::Font font2;

    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text instructionalText[3];
    sf::Text title;

public:
    //CONSTRUCTOR
    //PRE: ---
    //POST: Inicializa los atributos dandole los textos correspondientes
    GraphicMenu();

    //PRE: Ingresa que tipo de movimiento es (1 para mover hacia abajo, o -1 para arriba)
    //POST: En el caso de ser el final de la lista de navegacion, vuelve al comienzo, y en viceversa
    void MoveSelector(int move);

    //PRE: Ingresa la ventidad donde se realizaran los cambios
    //POST: Inicia la pantalla de la interfaz grafica
    void startGame (sf::RenderWindow &window);

    //PRE: ---
    //POST: Setea el texto de inicio
    void setStartText();

    //PRE: ---
    //POST: Setea el texto del menu de navegacion
    void setMenuText();

    //PRE: ---
    //POST: Setea el texto de instruccion del menu de navegacion
    void setInstructionalText();

    //PRE: ---
    //POST: Retorta que opcion de eligio
    int returnChosenOption ();

    //PRE: ---
    //POST: Setea el texto de pantalla de espera
    void setStandbyText();

    //PRE: Ingresa el movimiento y la ventana
    //POST: En el caso de tener los movimientos permitidos, realizara el cambio de opcion por pantalla
    void changeOptionSelector(sf::RenderWindow &window, int move);

    //PRE: Ingresa la ventana donde se realizaran los cambios
    //POST: Setea y muestra por pantalla el menu de inicio completo
    void drawInitialMenu(sf::RenderWindow &window);

    //PRE: Ingresa la ventana donde se realizaran los cambios
    //POST: Muestra la pantalla de espera entre opciones
    void drawStandbyScreen(sf::RenderWindow &window);

    //Destructor
    ~GraphicMenu();
private:
    //PRE: Ingresa que tipo de movimiento es (1 para mover hacia abajo, o -1 para arriba)
    //POST: Ejecuta el movimiento por pantalla y realiza los cambios en el menu
    void defaultMove(int move);

    //PRE: Ingresa la ventana donde se realizara el cambio
    //POST: Dibuja el menu de navegacion de opciones
    void drawMenu(sf::RenderWindow &window);
};
#endif //UNTITLED5_GRAPHICMENU_H