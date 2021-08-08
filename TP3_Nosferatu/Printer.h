#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <iostream>
#include "Map.h"
#include "Gotoxy.h"
#include "Matrix.h"
#include "colors.h"
#include "Dictionary.h"

#ifdef __linux__
    #define CLEAR "clear"
#endif
#ifdef _MINGW32__
    #define CLEAR "cls"
#endif

using namespace std;

class Printer {
private:

    Gotoxy gotoxy;

public:

    // CONSTRUCTOR
    // PRE:
    // POST:
    Printer() = default;

    // PRE:
    // POST: Muestra el titulo.
    void showTitle();

    // PRE:
    // POST: Muestra las opciones principales.
    void showMainMenu();

    // PRE:
    // POST: Muestra una intro de historica sobre Nosferatu y su guerra.
    void showIntro();

    // PRE: Recibe un puntero a objeto matriz.
    // POST: Muestra el mapa con colores.
    void showMap(Matrix<Vertex *> *matrix);

    // PRE: Recibe un int con el numero de filas y columnas.
    // POST: Muestra los numeros del mapa, de filas y columnas.
    void showMapLimit(int rows, int columns);

    // PRE: Recibe un puntero tiple a matriz, un puntero doblea
    //      vertices e int's respectivos a sus coordenadas de salida y llegada.
    // POST: Muestra un paso del recorrido de un ser.
    void showFloydPath(Vertex ***matrix, Vertex **vertices, int origin, int firstOrigin, int height, int width);

    // PRE: Recibe un string con el nombre del elemento.
    // POST: Muestra un mensaje con el objeto que sea agrego.
    void showGrabbedElement(std::string elementName);

    // PRE:
    // POST: Muestra las acciones que se pueden hacer en un turno.
    void showActionMenu();

    // PRE:
    // POST: Muestra el menu de la simulacion.
    void showSimulationMenu();

    // PRE:
    // POST: Muestra el area de juego.
    void showGameArea();

    // PRE:
    // POST: Lista y muestra todos los objetos posibles a agregar.
    void showObjectsMenu();

    // PRE:
    // POST: Lista y muestra todos los cuadrante posibles a elegir.
    void showQuadrantsMenu();

    // PRE:
    // POST: Muestra un flecha de input para el usuario.
    void showInputSpot();

    // PRE:
    // POST: Borra y muestra la ventana principal con el titulo y el area.
    void mainWindow();

    // PRE:
    // POST: muestra la cantidad de integrantes del equipo indicado
    void showTeamCharactersAmount(std::string teamName, int teamAmount);

    // PRE:
    // POST: muestra las opciones de equipos
    void showTeamsOptions();

    // PRE: Recibe el numero del jugador que va a jugar.
    // POST: Muestra un mensaje para avisarle a ese jugador.
    void showPlayerTurn(int playerNumber);

    // PRE: Recibe un puntero a ser.
    // POST: Lista y muestra las estadisticas del ser.
    void showCharacterStats(Being *being);

    // PRE:
    // POST: Libera el espacio que ocupaban las estadisticas del ser (pantalla).
    void clearCharacterStats();

    // PRE:
    // POST: Limpia la parte de las opciones del usuario en el turno (pantalla).
    void optionClear();

    // PRE: Recibe dos strings, uno con el nombre del cuadrante y otro con el nombre del objeto que se busca.
    // POST: Muestra mensaje de que se encontro.
    void showFoundMessage(std::string quadrant, std::string wantedName);

    // PRE: Recibe dos strings, uno con el nombre del cuadrante y otro con el nombre del objeto que se busca.
    // POST: Muestra mensaje de que no se encontro.
    void showNotFoundMessage(std::string quadrant, std::string wantedName);

    // POST: Recibe un puntero a objeto matriz y un puntero a ser.
    // PRE: Muestra el mapa de la simulacion.
    void showSimulationMap(Matrix<Vertex *> *matrix, Being *current);

    // PRE:
    // POST: Muestra las referencias de los casilleros.
    void showTerrainReferences();

    // PRE:
    // POST: Muestra las referencias de los seres y elementos.
    void showBeingReferences();

    // PRE: Recibe un puntero a objeto matriz, el rango, el string de fondo, la fila y la columna.
    // POST: Muestra el rango cuadrado de ataque o defensa.
    void showSquareRange(Matrix<Vertex*>* matrix, int range, const string background, int row, int column);

    // PRE: Recibe un puntero a objeto matriz, el fondo, la fila y la columna.
    // POST: Muestra el rango cruzado de ataque.
    void showCrossedRange(Matrix<Vertex*>* matrix, const string background, int row, int column);

    // PRE: Recibe un puntero a lista con los personajes del bando monstruos.
    // POST: Muestra los vampiros con los que Nosferatu puede cambiar su vida.
    void showHealths(List<Being*>* characters);

    // PRE:
    // POST: Muestra el simbolo de curacion y su mensaje.
    void showHuntersHealedOthers();

    // PRE:
    // POST: Muestra el mensaje de Vanesa protegiendo a sus aliados.
    void showVanesaAvoidedTransformation();

    // PRE: Recibe el nombre del mordido y las posicion en la que fue mordido.
    // POST: Muestra un mensje informando quien fue mordido y donde lo mordieron.
    void showZombieAttackedHuman(std::string targetName, int row, int col);

    // PRE: Recibe el nombre, la fila, columna, vieja y nueva vida del atacado.
    // POST: Da un informe del ataque; mostrando la vieja vida y la nueva.
    void showVampireAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth);

    // PRE: Recibe el nombre, la fila, columna, vieja y nueva vida del atacado.
    // POST: Da un informe del ataque; mostrando la vieja vida y la nueva.
    void showVampirellaAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth);

    // PRE: Recibe el nombre, la fila, columna, vieja y nueva vida del atacado.
    // POST: Da un informe del ataque; mostrando la vieja vida y la nueva.
    void showNosferatuAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth);

    void showVanesaAttacked(std::string targetName, int row, int col, int oldHealth, int newHealth, std::string weapon);

    void showHunterAttacked(std::string targetName, int row, int col, int oldHealth, int newHealth, std::string weapon);

    // PRE: Recibe el nombre, la fila, columna, vieja y nueva vida del atacado.
    // POST: Da un informe del ataque; mostrando la vieja vida y la nueva.
    void showNosferatuTransformedHuman(std::string targetName, int row, int col);

    // PRE:
    // POST: Avisa que Vanesa esta protegida con la cruz.
    void showVanesaIsCrossedProtectedMsg();

    // PRE:
    // POST: Avisa que el humano eligió reponer toda su energía.
    void showHumanGotMaxEnergy();

    // PRE:
    // POST: Avisa que el humano eligió sumar 1 de armadura por 1 turno.
    void showHumanGotArmor();

    // PRE:
    // POST: Avisa que el humano no tiene agua bendita así que suma energía.
    void showHumanGotDefaultEnergy();

    // PRE:
    // POST: avisa que el objeto no puede agregarse.
    void couldntAddObject(std::string objectName);

    // PRE:
    // POST: avisa que el objeto puedo agregarse.
    void objectAddedSuccessfully(std::string objectName);

    // PRE:
    // POST: Avisa que el humano no tiene agua bendita así que suma energía.
    void showVampirellaIsBat();

    void showZombiIsHidden();

    void showVampireIsHidden();

    void showCantAttackHiddenZombie();

    void showCantAttackBatVampirella();

    void showSavedGameFound();

    // PRE:
    // POST: Muestra un mensaje de victoria para humanos.
    void humanVictory();

    // PRE:
    // POST: Muestra un mensaje de victoria para monstruos.
    void monsterVictory();

};


#endif //_PRINTER_H
