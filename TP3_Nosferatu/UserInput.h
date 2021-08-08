#ifndef _USERINPUT_H
#define _USERINPUT_H

#include "iostream"
#include "Gotoxy.h"
#include "Printer.h"
#include "Floyd.h"
#include "ObjectIncludes.h"

class UserInput {

private:

    Gotoxy gotoxy;
    Printer printer;
    int option;

public:
    //CONSTRUCTOR
    UserInput() = default;

    //PRE: Ingresa el rango
    //POST: Devuelve la opcion elegida en dicho rango
    int validateRangeOption(int min, int max);

    //PRE: Ingresa el comienzo y el fin de coordenadas
    //POST: Modifica las coordenadas elegidas
    void validateRangeCoordinates(int* coordinateOne, int* coordinateTwo, int minCoordinateOne, int maxCoordinateOne, int minCoordinateTwo, int maxCoordinateTwo);

    //PRE: --
    //POST: Devuelve la cantidad elegida del elemento
    int validateAmount();

    //PRE: --
    //POST: Solicita un enter por pantalla
    void systemPause();

    //PRE: --
    //POST: Devuelve 1 en caso de querer reingresar o 2 en caso de volver al menu
    int validateReentry();

    //PRE: Ingresa el ser, floyd y la posicion de destino
    //POST: Valida si el movimiento es posible o no, en caso de ser posible devuelve 1
    int validateMovementRange(Being *current, Floyd &floyd, int &row, int &col);

    //PRE: Ingresa el ID y la matriz
    //POST: Muestra la busqueda por ID
    void showIdSearch(Dictionary &dict, Matrix<Vertex*>* matrix);

    //PRE: Ingresa un ser
    //POST: Devuelve el elemento que tenga ese ser
    Element* validateSelectedWeapon(Being * being);

    //PRE: Ingresa un ser, un arma, el mapa y la posicion de ataque
    //POST: Realiza el ataque con el arma y modifica los datos
    void validateAttackPosition(Being* attacker, Element* weapon, int &row, int &col, Map *map);

    //PRE: Ingresa un ser, el mapa y la posicion de ataque
    //POST: Realiza el ataque por defecto y modifica los datos
    void validateAttackPosition(Being* attacker, int &row, int &col, Map *map);

    //PRE: Ingresa el jugador actual
    //POST: Devuelve 1 si desea guardar la partida o 2 en caso de que no
    int askToSaveGame(int currentPlayerNumber);

    //PRE: --
    //POST: Devuelve 1 en caso de continuar o 2 en caso de volver atras
    int simulationReEntry();

    //PRE: Ingresa si eligio defenderse
    //POST: Devuelve que defensa usara Vanesa
    int vanesaDefenseOptions(bool *defenseOptions);

    //PRE: --
    //POST: Devuelve que defensa usara el cazador
    int hunterDefenseOptions();

    //PRE: --
    //POST: Devuelve que defensa usara el Humano
    int humanDefenseOptions();

    //PRE: Ingresa Nosferatu, el mapa, la posicion y sus aliados
    //POST: Realiza la defensa de Nosferatu, intercambiando su salud
    void nosferatuDefenseOptions(Being *nosferatu, Map *map, int &row, int &col, List<Being *> *allies);

};





#endif //_USERINPUT_H