#ifndef _CONSTANTSNAMES_H
#define _CONSTANTSNAMES_H
#include "string"

//  OPCIONES
const int YES = 1;
const int NO = 2;

//  CURACIONES

const short int SELFHEAL = 1;
const short int HEALOTHERS = 2;
const short int CROSSPROTECTION = 5;

// ENERGIA

const short int MAX_ENERGY = 20;
const short int MIN_ENERGY = 0;

// CUADRANTES

const std::string QUADRANT_NAMES[4] = {"NO", "NE", "SO", "SE"};

// OBJETOS PRIMERA LETRA MAYUSCULA

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

// LISTA NOMBRES PRIMERA LETRA MAYUSCULA

const std::string OBJECT_NAMES[12] ={
        HUMAN_CAPITALIZED, HUNTER_CAPITALIZED, VANESA_CAPITALIZED,
        ZOMBIE_CAPITALIZED, VAMPIRE_CAPITALIZED, NOSFERATU_CAPITALIZED,
        VAMPIRELLA_CAPITALIZED, HOLYWATER_CAPITALIZED, STAKE_CAPITALIZED,
        CROSS_CAPITALIZED, SHOTGUN_CAPITALIZED, BULLET_CAPITALIZED
};

// ARCHIVOS DE TEXTO

const std::string PATH_ESTADO = "estado.txt";

// OBJETOS MINUSCULA

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

// TERRENOS

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

// LIMITE DE LOS CUADRANTES

enum {START, END};

// OBJETOS ENUMERADOS DEL 1 AL 12

enum {
    optionHUMAN = 1, optionVAMPIREHUNTER, optionVANESA, optionZOMBIE,
    optionVAMPIRE, optionNOSFERATU, optionVAMPIRELLA, optionHOLYWATER,
    optionSTAKE, optionCROSS, optionSHOTGUN, optionBULLET};

// COSTOS

enum {
    HUMAN_COST,
    VAMPIRE_COST,
    HUNTER_COST,
    ZOMBIE_COST
};

//  OPCIONES DEL MENU PRINCIPAL

const int ADD_OBJECT = 1;
const int REMOVE_OBJECT = 2;
const int SHOW_MAP = 3;
const int QUADRANT_SEARCH = 4;
const int ID_SEARCH = 5;
const int START_SIMULATION = 6;
const int EXIT = 0;

// OPCIONES DEL MENU DE ACCIONES

const int ATTACK_ACTION = 1;
const int DEFENSE_ACTION = 2;
const int MOVE_ACTION = 3;

// DEFENSA DE VANESA

const int VANESA_DEFENSE_HOLY_WATER = 0;
const int VANESA_DEFENSE_CROSS = 1;
const int VANESA_DEFENSE_SELFHEAL = 2;

const int MAX_DEFENSE_OPTIONS = 3;

//  DEFENSA DE HUMANO CON AGUA BENDITA
const int HUMAN_ENERGY_ADD = 1;
const int HUMAN_ARMOR_ADD = 2;

// INFINITO

const int INFINITO = 99;

// TEAMS

enum Team {
    HUMANS = 1,
    MONSTERS
};

const std::string teams[2] = {
        "humanos",
        "monstruos"
};

// OPCIONES DEL MENU DE SIMULACION

enum {
    SIMULATION_ID_SEARCH = 1,
    SIMULATION_SHOW_MAP,
    SIMULATION_SHOW_INTEGRANTS,
    SIMULATION_SELECT_TEAM,
    SIMULATION_EXIT
};

// ESTADISTICAS DEL PERSONAJE

const std::string HEALTH_SYMBOL = "\U00002764\U0000FE0F";
const std::string ENERGY_SYMBOL = "⚡";
const std::string ARMOR_SYMBOL = "\U0001F6E1";
const std::string STRENGTH_SYMBOL = "\U0001F4AA";

//  OTROS SIMBOLOS

const std::string RIGHT_ARROW_SYMBOL = "\U000021E8";

#endif //GRAFOS_CONSTANTSNAMES_H
