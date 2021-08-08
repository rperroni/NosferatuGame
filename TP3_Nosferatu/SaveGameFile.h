#ifndef _SAVEGAMEFILE_H_
#define _SAVEGAMEFILE_H_
#include "FileManager.h"
#include "Player.h"
#include "Dictionary.h"
#include "ObjectCreator.h"

class SaveGameFile: public FileManager{
private:
    std::ofstream outputFile;
    int savedPlayer;

    //lo que va leyendo del archivo
    std::string aux;
    std::string team, charactersAmount;
    // de cada jugador
    std::string characterName, characterId, characterArmor, characterStrength, characterHealth, characterEnergy;
    std::string characterRow, characterCol, holyWaterAmount, crossAmount, stakeAmount, shotgunAmount, bulletAmount;
    // de los items
    std::string itemsAmount;
    std::string itemName, itemId, itemAmount, itemRow, itemCol;

public:
    SaveGameFile() = default;

    // PRE: fileName debe ser un nombre de archivo válido donde guarda la partida ("partida.txt)
    // POST: devuelve true si el archivo existe. De lo contrario devuelve false.
    bool openOutputFile(std::string fileName);

    //PRE: el archivo outputFile debe estar abierto
    //POST: cierra outputFile
    void closeOutputFile();

    //PRE: recibe un Map y dos Player por referencia. Debe abrirse inputFile previamente
    //POST: lee el archivo "partida.txt" y carga la informacion necesaria para la simulación
    void readFile(Map *&map, Player *&playerOne, Player *&playerTwo);

    //PRE: -
    //POST: devuelve el número del jugador que guardó el juego.
    int getSavedPlayer();

    // PRE: recibe el numero del jugador que guardó la partida, dos Players (que tienen su team y lista de
    //      personajes y una lista de items libres en el tablero. Esta lista debe ser generada antes de llamar
    //      a este método.
    // POST: guarda el estado del juego con los datos recibidos en un archivo "partida.txt"
    void writeGameStatus(int playerNumber, Player *playerOne, Player *playerTwo, List<Element*>* items);

private:

    //escritura
    void writePlayerStatus(Player *player);

    void writeCharacterInfo(Being* character);

    void writeInventoryInfo(Inventory* inventory);

    void writeItems(List<Element*>* items);

    // lectura
    void readPlayerStatus(Map* &map, Player *&player);

    void loadSavedBeing(Map* &map, Player *&player);

    void loadBeingInventory(Being *&being);

    void readFreeItems(Map* &map);

    void loadElement(Map *&map);
};


#endif //_SAVEGAMEFILE_H_
