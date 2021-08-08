#ifndef GRAFOS_CONSTANTSNAMES_H
#define GRAFOS_CONSTANTSNAMES_H
#include "string"

const short int SELFHEAL = 1;
const short int HEALOTHERS = 2;

const short int MAX_ENERGY = 20;
const short int MIN_ENERGY = 0;

const std::string QUADRANT_NAMES[4] = {"NO", "NE", "SO", "SE"};

const std::string HUMAN_CAPITALIZED = "Humano";
const std::string HUNTER_CAPITALIZED = "Cazador";
const std::string VANESA_CAPITALIZED = "Vanesa";
const std::string ZOMBIE_CAPITALIZED = "Zombi";
const std::string VAMPIRE_CAPITALIZED = "Vampiro";
const std::string NOSFERATU_CAPITALIZED = "Nosferatu";
const std::string VAMPIRELLA_CAPITALIZED = "Vampirella";
const std::string HOLYWATER_CAPITALIZED = "Agua bendita";
const std::string STAKE_CAPITALIZED = "Estaca";
const std::string CROSS_CAPITALIZED = "Cruz";
const std::string SHOTGUN_CAPITALIZED = "Escopeta";
const std::string BULLET_CAPITALIZED = "Bala";

const std::string OBJECT_NAMES[12] ={
        HUMAN_CAPITALIZED, HUNTER_CAPITALIZED, VANESA_CAPITALIZED,
        ZOMBIE_CAPITALIZED, VAMPIRE_CAPITALIZED, NOSFERATU_CAPITALIZED,
        VAMPIRELLA_CAPITALIZED, HOLYWATER_CAPITALIZED, STAKE_CAPITALIZED,
        CROSS_CAPITALIZED, SHOTGUN_CAPITALIZED, BULLET_CAPITALIZED
};

const std::string PATH_ESTADO = "estado.txt";
const std::string VAMPIRE = "vampiro";
const std::string HUMAN = "humano";
const std::string HUNTER = "humano CV";
const std::string VANESA = "Vanesa";
const std::string VAMPIRELLA = "Vampirella";
const std::string NOSFERATU = "Nosferatu";
const std::string ZOMBIE = "zombie";
const std::string HOLYWATER = "agua";
const std::string CROSS = "cruz";
const std::string BULLET = "bala";
const std::string STAKE = "estaca";
const std::string SHOTGUN = "escopeta";

const std::string CLIFF = "P";
const std::string MOUNTAIN = "M";
const std::string THEVOID = "O";
const std::string ROAD = "C";
const std::string VOLCANO = "V";
const std::string LAKE = "L";

const std::string VAMPIREUPPER = "Vampiro";
const std::string HUMANUPPER = "Humano";
const std::string VAMPIREHUNTERUPPER = "Caza Vampiros";
const std::string ZOMBIEUPPER = "Zombi";
const std::string HOLYWATERUPPER = "Agua Bendita"; // CAMBIAR A b, para el INVENTARIO, sino rompe todo.
const std::string CROSSUPPER = "Cruz";
const std::string BULLETUPPER = "Bala";
const std::string STAKEUPPER = "Estaca";
const std::string SHOTGUNUPPER = "Escopeta";
const int maxNumberOfObjects = 8;

enum {START, END};

enum {
    optionHUMAN = 1, optionVAMPIREHUNTER, optionVANESA, optionZOMBIE,
    optionVAMPIRE, optionNOSFERATU, optionVAMPIRELLA};

enum {
    optionCROSS = 1,
    optionSTAKE, optionHOLYWATER, optionBULLET ,optionSHOTGUN
};

enum {
    HUMAN_COST,
    VAMPIRE_COST,
    HUNTER_COST,
    ZOMBIE_COST
};

const int ADD_OBJECT = 1;
const int REMOVE_OBJECT = 2;
const int SHOW_MAP = 3;
const int QUADRANT_SEARCH = 4;
const int ID_SEARCH = 5;
const int START_SIMULATION = 6;
const int MOVE_OBJECT = 7;
const int EXIT = 0;

const int INFINITO = 99;

enum Team {
    HUMANS = 1,
    MONSTERS
};

enum {
    SIMULATION_ID_SEARCH,
    SIMULATION_SHOW_MAP,
    SIMULATION_SHOW_INTEGRANTS,
    SIMULATION_SELECT_TEAM,
    SIMULATION_EXIT
};
#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#endif //GRAFOS_CONSTANTSNAMES_H
