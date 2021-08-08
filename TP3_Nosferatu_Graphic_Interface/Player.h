#ifndef GRAFOS_PLAYER_H
#define GRAFOS_PLAYER_H

#include "List.h"
#include "Being.h"
#include "constantsNames.h"

class Player {
private:

    List<Being*> * characters;
    int team;

public:
    Player();

    void setTeam(int team);

    void addCharacter(Being* character);

    void removeCharacter(int id);

    int getTeam();

    void showCharacters();

    ~Player();
};


#endif //GRAFOS_PLAYER_H
