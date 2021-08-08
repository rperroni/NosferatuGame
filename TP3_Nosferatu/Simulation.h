#ifndef _SIMULATION_H
#define _SIMULATION_H
#include "Printer.h"
#include "Battle.h"
#include "ObjectIncludes.h"
#include "Player.h"
#include "Dictionary.h"
#include "UserInput.h"
#include "Floyd.h"
#include "SaveGameFile.h"
#include "MapCreator.h"

class Simulation {
private:
    //ATRIBUTOS
    Gotoxy gotoxy;
    Map * map;
    Battle battle;
    int turnCounter;
    Player* playerOne;
    Player* playerTwo;
    Printer printer;
    UserInput userInput;
    bool exitSimulation;
    Floyd floyd;

    int savedPlayer;
    int otherPlayer;

public:
    //CONSTRUCTOR
    Simulation();


    ~Simulation();

    //PRE: Ingresa el mapa y los jugadores
    //POST: Carga la partida
    void loadGame(Map * map, Player * playerOne, Player * playerTwo);

    //PRE: Ingresa si hay una partida guardada
    //POST: Comienza la simulacion
    void startSimulation(bool savedGameFound);

    //PRE: Ingresa el numero de un jugador
    //POST: Setea el jugador guardado
    void setSavedPlayer(int playerNumber);

    //PRE: --
    //POST: Carga los personajes
    void loadCharacters();

    //PRE: --
    //POST: Muestra el equipo a mostrar
    void selectTeamToShow();

    //PRE: Ingresa el numero de jugador
    //POST: Muestra las opciones a dicho jugador
    void playerSelectOptions(int playerNumber);

    //PRE: Ingresa un ser
    //POST: Realiza el ataque del jugador
    void playerAttack(Being* being);

    //PRE: Ingresa el numero de un jugador
    //POST: Revisa la salud de sus personajes
    void checkHealths(int playerNumber);

    //PRE: --
    //POST: Revisa las transformaciones
    void checkTransformations();

    //PRE: Ingresa un ser y un jugador
    //POST: Realiza la defensa de un personaje
    void playerDefend(Being *being, int playerNumber);

private:

    //PRE: --
    //POST: Finaliza la simulacion
    void endGame();

    //PRE: --
    //POST: Genera la lista de Inventario vacia
    void generateFreeItemsList(List<Element*>* freeItems);

    //PRE: Ingresa el numero de un jugador
    //POST: Guarda la partida con los datos de dicho jugador
    void saveGame(int playerNumber);

    //PRE: --
    //POST: Carga la partida guardada
    void loadSavedGame();

    //PRE: Ingresa el numero del equipo ganador
    //POST: Muestra la victoria del equipo ganador
    void showWinner(int winnerTeam);

};


#endif //_SIMULATION_H
