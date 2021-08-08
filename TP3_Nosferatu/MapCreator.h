#ifndef GRAFOS_MAPCREATOR_H
#define GRAFOS_MAPCREATOR_H

#include "Map.h"
#include "BoardFile.h"
#include "ObjectFile.h"
#include "SaveGameFile.h"
#include "CostMatrices.h"
#include "Dictionary.h"
#include "Player.h"

class MapCreator {
private:
    BoardFile boardFile;
    ObjectFile objectFile;
    SaveGameFile saveGameFile;

    bool savedGame;
public:
    //CONSTRUCTOR
    MapCreator(Map *&map, Dictionary &dict);

    // PRE: Ingresa el mapa y el diccionario
    // POST: Crea el mapa con datos
    void createMap(Map* &map, Dictionary &dict);

    // PRE: --
    // POST: Devuelve true si se guardo el juego y false si no.
    bool isSavedGame();

    // PRE: Ingresa el mapa, el jugador 1 y jugador 2
    // POST: Lee el archivo guardado y lo setea
    void readSavedGame(Map *&map, Player *playerOne, Player *playerTwo);

    //DESTRUCTOR
    ~MapCreator();
};


#endif //GRAFOS_MAPCREATOR_H
