#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include "Printer.h"
#include "Map.h"
#include "Dictionary.h"
#include "ObjectIncludes.h"
#include "ObjectCreator.h"
#include "ObjectAdder.h"
#include "UserInput.h"
#include "ObjectAdder.h"
#include "QuadrantSearch.h"

using namespace std;

class Menu {

private:
    Gotoxy gotoxy;
    ObjectAdder objectAdder;
    UserInput userInput;
    Printer printer;
    QuadrantSearch quadrantSearcher;
    int option;

public:

    //CONSTRUCTOR
    Menu();

    // PRE: --
    // POST: Devuelve la opcion elegida del menu
    int showMainMenu();

    // PRE: --
    // POST: METODO VACIO
    void showBoardMenu();

    // PRE: Ingresa el mapa
    // POST: Muestra la opcion de busqueda por cuadrante
    void showQuadrantsMenu(Map* matrix);

    // PRE: --
    // POST: Muestra la opcion de agregar objetos
    int showObjectsMenu();

    // PRE: --
    // POST: Inicia el menu de simulacion
    int showSimulationMenu();

    // PRE: --
    // POST: Muestra el menu de acciones
    int showActionsMenu();


    // PRE: --
    // POST: Realiza la busqueda del cuadrante
    void quadrantSearch();

    //PRE: Ingresa el mapa y el diccionario
    //POST:  Agrega el objeto al mapa y el diccionario
    void addObject(Map* &map, Dictionary &dic);

    //PRE: Ingresa el mapa y el diccionario
    //POST: Elimina el objeto del mapa y el diccionario
    void removeObject(Map* &map, Dictionary &dic);
};



#endif //_MENU_H_