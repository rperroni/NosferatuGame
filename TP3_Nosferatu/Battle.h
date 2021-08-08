#ifndef _BATTLE_H_
#define _BATTLE_H_

#include "ObjectIncludes.h"
#include "Map.h"
#include "Identifier.h"
#include "Printer.h"
#include "UserInput.h"

class Battle {

private:

    // ATRIBUTOS

    Map* map;
    Printer printer;
    UserInput userInput;
    int targetRow;
    int targetCol;
    int selectedRow;
    int selectedCol;
    Being* selectedBeing;
    Identifier ident;

public:

    // METODOS

    // CONSTRUCTOR
    Battle();

    // PRE: Ingresa el mapa de juego
    // POST: Lo apunta desde el atributo para poder ingresar a sus datos
    void loadMap(Map * map);

    // PRE: --
    // POST: Realiza los ataques de la simulacion
    void attack();

    // PRE: Ingresa la lista de aliados
    // POST: Selecciona a que personaje aliado desea defender
    void defend(List<Being*>* allies);

    // PRE: Ingresa la lista de aliados
    // POST: Selecciona a que aliado desea curar
    void healOthers(List<Being *> *allies);

    // PRE: Ingresa la posicion del mapa
    // POST: Selecciona el ser que este en esa posicion
    void selectBeing(int row, int col);

    // PRE: --
    // POST: Selecciona y devuelve un arma
    Element* selectWeapon();

    // PRE: Ingresa un arma
    // POST: Muestra el rango de ataque del mismo
    void showAttackRange(Element* weapon);

    // PRE: Ingresa un arma
    // POST: Muestra el rango de ataque de los cazadores con dicha arma
    void showHuntersAttackRange(Element* weapon);

    // PRE: --
    // POST: Muestra el rango de ataque
    void showAttackRange();

    // PRE: Ingresa el objetivo
    // POST: Intercambia sus puntos de vida
    void exchangeHealths(Being* target);

    // DESTRUCTOR
    ~Battle() = default;
};


#endif //_BATTLE_H_
