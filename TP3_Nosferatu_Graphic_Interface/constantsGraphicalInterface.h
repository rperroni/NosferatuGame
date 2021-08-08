#ifndef UNTITLED5_CONSTANTSGRAPHICALINTERFACE_H
#define UNTITLED5_CONSTANTSGRAPHICALINTERFACE_H

const int MAX_NUMBER_OF_ITEMS = 8;
const std::string INSTRUCTIONALMESSAGES[3]=
        {"Presione -espacio- para comenzar","Presione 'enter' para ingresar\nPara navegar use las \nflechas direccionales",
           " "};

const std::string OPTIONNAMES[MAX_NUMBER_OF_ITEMS] = {"Agregar objeto","Eliminar objeto","Mostrar mapa",
                                                      "Buscar por cuadrante","Busqueda por ID","Comenzar simulacion","Mover objeto", "Salir"};

const std::string OPTIONNAMES2[MAX_NUMBER_OF_ITEMS] = {"$ Agregar objeto","# Eliminar objeto","$ Mostrar mapa",
                                                       "# Buscar por cuadrante","$ Busqueda por ID","# Comenzar simulacion","$ Mover objeto", "# Salir"};

const std::string HYPHENATED_TERRAIN_NAMES[6] = {"- Lago", "- Volcan", "- Camino", "- Precipicio", "- Montana", "- Vacio"};
const std::string HYPHENATED_BEING_NAMES[7] = {"- Humano","- Cazador", "- Vanesa","- Zombie", "- Vampiro", "- Vampirella", "- Nosferatu",};
const std::string HYPHENATED_ELEMENT_NAMES[5] = {"- Cruz","- Estaca", "- Agua","- Bala", "- Escopeta"};

const std::string LISTED_BEING_NAMES[7] = {"1 - Humano","2 - Cazador", "3 - Vanesa","4 - Zombie", "5 - Vampiro", "6 - Vampirella", "7 - Nosferatu",};
const std::string LISTED_ELEMENT_NAMES[5] = {"1 - Cruz","2 - Estaca", "3 - Agua","4 - Bala", "5 - Escopeta"};


const std::string BEING_NAMES[7] ={
        "Humano", "Cazador", "Vanesa",
        "Zombi", "Vampiro", "Vampirella",
        "Nosferatu"
};

const std::string ELEMENT_NAMES[5]= {
        "Cruz", "Estaca",
        "Agua bendita", "Bala", "Escopeta"
};

const std::string BEING_NAMES2[7] ={
        "humano", "humano CV", "Vanesa",
        "zombi", "vampiro", "Vampirella",
        "Nosferatu"
};

const std::string ELEMENT_NAMES2[5]= {
        "cruz", "estaca",
        "agua", "bala", "escopeta"
};

const std::string FILESNAMES[2] = {"bloodBackGround2.png","bloodBackGround2.png"};

const int WIDHT = 850;

#endif //UNTITLED5_CONSTANTSGRAPHICALINTERFACE_H
