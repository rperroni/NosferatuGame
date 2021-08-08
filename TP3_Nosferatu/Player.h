#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "List.h"
#include "Being.h"
#include "constantsNames.h"

class Player {
private:

    //ATRIBUTO
    List<Being *> *characters;
    int team;

public:
    //CONSTRUCTORES
    Player();

    //PRE: Ingresa el numero del equipo
    //POST: Setea al jugador en dicho equipo
    void setTeam(int team);

    //PRE: Ingresa un ser
    //POST: Agrega el personaje a su bando
    void addCharacter(Being *character);

    //PRE: Ingresa un ID
    //POST: Elimina el personaje con dicho ID del bando
    void removeCharacter(int id);

    //PRE: --
    //POST: Devuelve a que equipo corresponde
    int getTeam();

    //PRE: --
    //POST: Muestra los personajes
    void showCharacters();

    //PRE: --
    //POST: NO SE USA
    void selectOptions();

    //PRE: --
    //POST: Devuelve la lista de personajes del bando
    List<Being*> * getCharacters();

    //DESTRUCTOR
    ~Player();
};


#endif //GRAFOS_PLAYER_H
