#include "Printer.h"

void Printer::showTitle() {

    std::cout << gotoxy.pos(3,11) << "\033[31m  ███▄    █  ▒█████    ██████   █████▒▓█████  ██▀███   ▄▄▄     ▄▄▄█████▓ █    ██    \033[0m" << std::endl;
    std::cout << gotoxy.pos(4,11) << "\033[31m  ██ ▀█   █ ▒██▒  ██▒▒██    ▒ ▓██   ▒ ▓█   ▀ ▓██ ▒ ██▒▒████▄   ▓  ██▒ ▓▒ ██  ▓██▒   \033[0m" << std::endl;
    std::cout << gotoxy.pos(5,11) << "\033[31m ▓██  ▀█ ██▒▒██░  ██▒░ ▓██▄   ▒████ ░ ▒███   ▓██ ░▄█ ▒▒██  ▀█▄ ▒ ▓██░ ▒░▓██  ▒██░   \033[0m" << std::endl;
    std::cout << gotoxy.pos(6,11) << "\033[31m ▓██▒  ▐▌██▒▒██   ██░  ▒   ██▒░▓█▒  ░ ▒▓█  ▄ ▒██▀▀█▄  ░██▄▄▄▄██░ ▓██▓ ░ ▓▓█  ░██░   \033[0m" << std::endl;
    std::cout << gotoxy.pos(7,11) << "\033[31m ▒██░   ▓██░░ ████▓▒░▒██████▒▒░▒█░    ░▒████▒░██▓ ▒██▒ ▓█   ▓██▒ ▒██▒ ░ ▒▒█████▓    \033[0m" << std::endl;
    std::cout << gotoxy.pos(8,11) << "\033[31m ░ ▒░   ▒ ▒ ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░ ▒ ░    ░░ ▒░ ░░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ▒ ░░   ░▒▓▒ ▒ ▒    \033[0m" << std::endl;
    std::cout << gotoxy.pos(9,11) << "\033[31m    ░   ░ ░ ░ ░ ░ ▒  ░  ░  ░   ░ ░       ░     ░░   ░   ░   ▒    ░       ░░░ ░ ░    \033[0m" << std::endl;
    std::cout << gotoxy.pos(10,11) << "\033[31m          ░     ░ ░        ░             ░  ░   ░           ░  ░           ░        \033[0m" << std::endl;

}

void Printer::showMainMenu() {

    std::cout << gotoxy.pos(16,24) << "\033[47;30;1m       SELECCIONE UNA OPCION (Ingrese un numero)       \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,30) << "\033[47;30;1m[1]  AGREGAR UN NUEVO OBJETO AL MAPA.      \033[0m" << std::endl;
    std::cout << gotoxy.pos(22,30) << "\033[47;30;1m[2]    ELIMINAR UN OBJETO DEL MAPA.        \033[0m" << std::endl;
    std::cout << gotoxy.pos(25,30) << "\033[47;30;1m[3]         MOSTRAR EL MAPA.               \033[0m" << std::endl;
    std::cout << gotoxy.pos(28,30) << "\033[47;30;1m[4]  BUSCAR POR CUADRANTE EN EL MAPA.      \033[0m" << std::endl;
    std::cout << gotoxy.pos(31,30) << "\033[47;30;1m[5]  BUSCAR POR ID DETALLES DE OBJETO.     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,30) << "\033[47;30;1m[6]        COMENZAR SIMULACION.            \033[0m" << std::endl;
    std::cout << gotoxy.pos(37,30) << "\033[47;30;1m[0]               SALIR.                   \033[0m" << std::endl;

}

void Printer::showIntro() {

    cout << gotoxy.pos(21,8) << TXT_BOLD << "\033[40m         .-\"\"\"\".                                                                     \033[0m" << endl;
    cout << gotoxy.pos(22,8) << TXT_BOLD << "\033[40m        ╱       ╲                                                                        \033[0m" << endl;
    cout << gotoxy.pos(23,8) << TXT_BOLD << "\033[40m    __ ╱   .-.  .╲                                                                       \033[0m" << endl;
    cout << gotoxy.pos(24,8) << TXT_BOLD << "\033[40m   ╱  `╲  ╱   ╲╱  ╲                                                                      \033[0m" << endl;
    cout << gotoxy.pos(25,8) << TXT_BOLD << "\033[40m   ▏  _ ╲╱   .◞◝.◞◝.                                                                     \033[0m" << endl;
    cout << gotoxy.pos(26,8) << TXT_BOLD << "\033[40m   ▏ (   ╲  ╱____╲__╲              Nosferatu renació de las cenizas luego de varios      \033[0m" << endl;
    cout << gotoxy.pos(27,8) << TXT_BOLD << "\033[40m    ╲ ╲      (_●) (_●)             años de letargo, sorprendiendo a los vampirólogos     \033[0m" << endl;
    cout << gotoxy.pos(28,8) << TXT_BOLD << "\033[40m     ╲ ╲            '‒‒‒._         que habían desechado la posibilidad de su regreso.    \033[0m" << endl;
    cout << gotoxy.pos(29,8) << TXT_BOLD << "\033[40m      ╲                   ╲_       Esta vez vuelve más poderoso: creó una alianza con    \033[0m" << endl;
    cout << gotoxy.pos(30,8) << TXT_BOLD << "\033[40m   ╱╲ ▕`       (__)________╱       Vampirella y un ejército de zombis con la finalidad   \033[0m" << endl;
    cout << gotoxy.pos(31,8) << TXT_BOLD << "\033[40m  ╱  ╲▕     ╱╲___╱                 de dominar el mundo.                                  \033[0m" << endl;
    cout << gotoxy.pos(32,8) << TXT_BOLD << "\033[40m ▕    ╲     ╲||▼▼                                                                        \033[0m" << endl;
    cout << gotoxy.pos(33,8) << TXT_BOLD << "\033[40m ▕     ╲     ╲|\"\"\"\",                                                                 \033[0m" << endl;
    cout << gotoxy.pos(34,8) << TXT_BOLD << "\033[40m ▕      ╲     ______)              Bienvenidos al juego...                               \033[0m" << endl;
    cout << gotoxy.pos(35,8) << TXT_BOLD << "\033[40m  ╲      ╲  ╱`                                                                           \033[0m" << endl;
    cout << gotoxy.pos(36,8) << TXT_BOLD << "\033[40m          ╲(                                                                             \033[0m" << endl;
}

void Printer::showMap(Matrix<Vertex*>* matrix) {

    mainWindow();
    int coordY = 20;

    std::cout << gotoxy.pos(coordY - 1 ,31);

    for (int i = 0; i < matrix->getHeight() ; ++i) {
        for (int j = 0; j < matrix->getWidth() ; ++j) {

            std::cout << matrix -> getData(i,j) -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";

            if ( matrix -> getData(i,j) -> getBeing())
                cout << matrix -> getData(i ,j) -> getBeing() -> getCharName() << " ";

            else if (matrix -> getData(i,j) -> getElement() )
                cout << matrix -> getData(i,j) -> getElement() -> getCharName() << " ";

            else
                cout << "  ";
            cout << END_COLOR << "\033[40m  \033[0m";
            cout << END_COLOR;
        }
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i,31);
    }

    this->showMapLimit(matrix -> getHeight(),matrix -> getWidth());

}

void Printer::showActionMenu() {

    cout << gotoxy.pos(35,40) << "\033[47;30;1m [1]   Atacar      \033[0m" << endl;
    cout << gotoxy.pos(36,40) << "\033[47;30;1m [2]   Defenderse  \033[0m" << endl;
    cout << gotoxy.pos(37,40) << "\033[47;30;1m [3]   Moverse     \033[0m" << endl;
    cout << gotoxy.pos(38,40) << "\033[47;30;1m [4]   Pasar       \033[0m" << endl;
    cout << gotoxy.pos(39,40) << "\033[47;30;1m [0]   Salir       \033[0m" << endl;
}

void Printer::showGameArea() {

    std::cout << gotoxy.pos(12,1) << "█" << std::endl;
    std::cout << gotoxy.pos(12,100) << "█" << std::endl;

    for(int i = 2; i <= 99; i++){
        std::cout << gotoxy.pos(12, i) << "█" << std::endl;
    }
    for(int i = 13; i <= 45; i++){

        std::cout << gotoxy.pos(i, 1) << "█" << std::endl;
        std::cout << gotoxy.pos(i, 100) << "█" << std::endl;

    }
    for(int i = 2; i <= 99; i++){
        std::cout << gotoxy.pos(45, i) << "█" << std::endl;
    }

    std::cout << gotoxy.pos(45,1) << "█" << std::endl;
    std::cout << gotoxy.pos(45,100) << "█" << std::endl;


    for(int i = 2; i <= 99; i++){
        for(int j = 13; j <= 44; j++){
            std::cout << gotoxy.pos(j, i) << "\033[40m \033[0m" << std::endl;
        }
    }

}

void Printer::showObjectsMenu() {

    std::cout << gotoxy.pos(15,33) << "\033[47;30;1m     SELECCIONE EL TIPO DE OBJETO     \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,10) << "\033[47;30;1m[1]    HUMANO      \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,42) << "\033[47;30;1m[2]    CAZADOR     \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,75) << "\033[47;30;1m[3]    VANESA      \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,10) << "\033[47;30;1m[4]    ZOMBIE      \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,42) << "\033[47;30;1m[5]    VAMPIRO     \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,75) << "\033[47;30;1m[6]   NOSFERATU    \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,10) << "\033[47;30;1m[7]   VAMPIRELLA   \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,42) << "\033[47;30;1m[8]      AGUA      \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,75) << "\033[47;30;1m[9]     ESTACA     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,10) << "\033[47;30;1m[10]    CRUCES     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,42) << "\033[47;30;1m[11]   ESCOPETA    \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,75) << "\033[47;30;1m[12]     BALA      \033[0m" << std::endl;

}

void Printer::showQuadrantsMenu() {

    std::cout << gotoxy.pos(20,36) << "\033[47;30;1m    SELECCIONE EL CUADRANTE    \033[0m" << std::endl;
    std::cout << gotoxy.pos(23,45) << "\033[47;30;1m[1]    NO    \033[0m" << std::endl;
    std::cout << gotoxy.pos(26,45) << "\033[47;30;1m[2]    NE    \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,45) << "\033[47;30;1m[3]    SO    \033[0m" << std::endl;
    std::cout << gotoxy.pos(32,45) << "\033[47;30;1m[4]    SE    \033[0m" << std::endl;

}

void Printer::showSimulationMenu() {

    cout << gotoxy.pos(20,38) << "\033[47;30;1m [1] Buscar por ID        \033[0m" << endl;
    cout << gotoxy.pos(23,38) << "\033[47;30;1m [2] Mostrar tablero      \033[0m" << endl;
    cout << gotoxy.pos(26,38) << "\033[47;30;1m [3] Mostrar integrantes  \033[0m" << endl;
    cout << gotoxy.pos(29,38) << "\033[47;30;1m [4] Seleccionar bando    \033[0m" << endl;
    cout << gotoxy.pos(32,38) << "\033[47;30;1m [5] Salir                \033[0m" << endl;

}

void Printer::showInputSpot() {
    std::cout << gotoxy.pos(35, 4) << "\033[47;30;1m----> \033[0m" << "  ";

}

void Printer::mainWindow() {
    system(CLEAR);
    showTitle();
    showGameArea();
}

void Printer::showTeamCharactersAmount(std::string teamName, int teamAmount) {
    cout << gotoxy.pos(33,38) << "\033[40m" << TXT_BOLD << TXT_LIGHT_BLUE_14 << "Equipo: " << teamName << "                          \033[0m" << endl;
    cout << gotoxy.pos(36,38) << "\033[40m" << TXT_BOLD << TXT_LIGHT_BLUE_14 << "Cantidad de integrantes: " << teamAmount << "        \033[0m" << endl;
}

void Printer::showTeamsOptions() {
    cout << gotoxy.pos(23,38) << "\033[47;30;1m Elija equipo              \033[0m" << endl;
    cout << gotoxy.pos(26,38) << "\033[47;30;1m [" << HUMANS << "] Equipo humanos        \033[0m" << endl;
    cout << gotoxy.pos(29,38) << "\033[47;30;1m [" << MONSTERS << "] Equipo monstruos      \033[0m" << endl;
}

void Printer::showTerrainReferences() {
    cout << gotoxy.pos(21,74) << "\033[40;1m» LAGO       " << "\033[48;5;51m  " << END_COLOR;
    cout << gotoxy.pos(23,74) << "\033[40;1m» VOLCAN     " << "\033[48;5;160m  "<< END_COLOR;
    cout << gotoxy.pos(25,74) << "\033[40;1m» PRECIPICIO " << "\033[48;5;31m  "<< END_COLOR;
    cout << gotoxy.pos(27,74) << "\033[40;1m» MONTAÑA    " << "\033[48;5;94m  "<< END_COLOR;
    cout << gotoxy.pos(29,74) << "\033[40;1m» CAMINO     " << "\033[48;5;247m  "<< END_COLOR;
    cout << gotoxy.pos(31,74) << "\033[40;1m» VACIO      " << "\033[48;5;5m  " << END_COLOR;
}

void Printer::showBeingReferences() {
    cout << gotoxy.pos(15,11) << "\033[40;1mW  VANESA       "  << END_COLOR;
    cout << gotoxy.pos(17,11) << "\033[40;1mh  HUMANO      "  << END_COLOR;
    cout << gotoxy.pos(19,11) << "\033[40;1mC  CAZADOR     " << END_COLOR;
    cout << gotoxy.pos(21,11) << "\033[40;1mz  ZOMBI       " << END_COLOR;
    cout << gotoxy.pos(23,11) << "\033[40;1mN  NOSFERATU   " << END_COLOR;
    cout << gotoxy.pos(25,11) << "\033[40;1mV  VAMPIRELLA  " << END_COLOR;
    cout << gotoxy.pos(27,11) << "\033[40;1mv  VAMPIRO     " << END_COLOR;
    cout << gotoxy.pos(29,11) << "\033[40;1ma  AGUA        " << END_COLOR;
    cout << gotoxy.pos(31,11) << "\033[40;1mc  CRUZ        " << END_COLOR;
    cout << gotoxy.pos(33,11) << "\033[40;1me  ESTACA      " << END_COLOR;
    cout << gotoxy.pos(35,11) << "\033[40;1mE  ESCOPETA    " << END_COLOR;
    cout << gotoxy.pos(37,11) << "\033[40;1mb  BALA        "  << END_COLOR;

}

void Printer::optionClear(){
    std::cout << gotoxy.pos(40,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(41,5) << "\033[40m                                                  \033[0m";
    std::cout << gotoxy.pos(42,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(43,5) << "\033[40m                                                  \033[0m";
}

void Printer::showFoundMessage(std::string quadrant, std::string wantedName){
    std::cout << gotoxy.pos(41,30) << "\033[47;30;1m El objeto: " << wantedName <<", se encuentra en el cuadrante: " << quadrant << END_COLOR << std::endl;



}

void Printer::showNotFoundMessage(std::string quadrant, std::string wantedName){
    std::cout << gotoxy.pos(41,30) << "El objeto: " << wantedName <<", no se encuentra en el cuadrante: " << quadrant << END_COLOR << std::endl;
}

void Printer::showFloydPath(Vertex*** graph, Vertex **vertices, int origin, int firstOrigin, int height, int width) {

    mainWindow();
    int coordY = 20;
    std::cout << gotoxy.pos(coordY - 1, 31);
    Being *current = vertices[firstOrigin] -> getBeing();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << graph[i][j] -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";

            if (i == vertices[origin] -> getX() && j == vertices[origin] -> getY()) {
                cout << current->getCharName() << " ";
            } else if (graph[i][j] -> getElement())
                cout << graph[i][j] -> getElement() -> getCharName() << " ";

            else
                cout << "  ";
            cout << END_COLOR << "\033[40m  \033[0m";
            cout << END_COLOR;
        }
        this -> showBeingReferences();
        this -> showCharacterStats(current);
        this -> showMapLimit(height, width);
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i, 31);
    }
}

void Printer::showGrabbedElement(std::string elementName) {
    cout << gotoxy.pos(32, 73)  << "\033[40m " << TXT_GREEN_76 << TXT_BOLD << elementName << ", " << END_COLOR;
    cout << gotoxy.pos(33, 73)  << "\033[40m " << TXT_GREEN_76 << TXT_BOLD << TXT_ITALIC << "añadido al inventario." << END_COLOR;

}

void Printer::showPlayerTurn(int playerNumber) {

    cout << gotoxy.pos(15, 41) << "\033[47;30;1m Turno: jugador " << playerNumber << " " << END_COLOR;
}

void Printer::showCharacterStats(Being * being) {

    cout << gotoxy.pos(19, 74) << "\033[40;1m Personaje: " << being->getObjectName() << END_COLOR;
    cout << gotoxy.pos(21, 75) <<  "\033[40;1m"<< HEALTH_SYMBOL + "  " << being -> getHealth()  << END_COLOR;
    cout << gotoxy.pos(23, 75)  << "\033[40;1m"<< ENERGY_SYMBOL + " " << being -> getEnergy() << END_COLOR;
    cout << gotoxy.pos(25, 75) << "\033[40;1m"<< ARMOR_SYMBOL + "  " << being -> getArmor() << END_COLOR;
    cout << gotoxy.pos(27, 75)  << "\033[40;1m"<< STRENGTH_SYMBOL + " " << being -> getStrength() << END_COLOR;

    being -> getInventory() -> showInventory();

}

void Printer::clearCharacterStats() {
    cout << gotoxy.pos(21, 74) << "\033[40m                    " << END_COLOR;
    cout << gotoxy.pos(23, 75) << "\033[40m                    " << END_COLOR;
    cout << gotoxy.pos(25, 75) << "\033[40m                    " << END_COLOR;
    cout << gotoxy.pos(27, 75) << "\033[40m                    " << END_COLOR;
    cout << gotoxy.pos(29, 75) << "\033[40m                    " << END_COLOR;
    cout << gotoxy.pos(31, 75) << "\033[40m                    " << END_COLOR;

}

void Printer::showSimulationMap(Matrix<Vertex*>* matrix, Being* current) {

    this -> showMap(matrix);
    this -> showBeingReferences();
    int row = current -> getRow();
    int column = current -> getCol();
    std::cout << gotoxy.pos(19 + row*2, 32 + column*5) << matrix -> getData(row, column) -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";
    cout << gotoxy.pos(19 + row*2, 32 + column*5) << "\033[6m" << current -> getCharName() << END_COLOR << "\033[40m" << endl;

}

void Printer::showSquareRange(Matrix<Vertex*>* matrix, int range, const string background, int row, int column) {

    mainWindow();
    this->showMapLimit(matrix->getHeight(),matrix->getWidth());
    int coordY = 20;
    std::cout << gotoxy.pos(coordY - 1, 31);
    for (int i = 0; i < matrix -> getHeight(); i++) {
        for (int j = 0; j < matrix -> getWidth(); j++) {
            if ((i >= row - range && i <= row + range) && (j >= column - range && j <= column + range))
            {
                cout << background;
                if (matrix -> getData(i, j) -> getBeing()) {
                    if ((i != row || j != column))
                        cout << TXT_DARK_GRAY_234 << TXT_BOLD << " " << matrix->getData(i, j) -> getBeing() -> getCharName() << " ";
                    else
                        cout << TXT_DARK_GRAY_234 << TXT_BOLD << BGND_GREEN_76 << " " << matrix -> getData(i, j) -> getBeing() -> getCharName() << " ";
                } else if (matrix->getData(i, j)->getElement())
                    cout << TXT_DARK_GRAY_234 << TXT_BOLD << " " << matrix->getData(i, j) -> getElement() -> getCharName() << " ";
                else
                    cout << background << "   ";
                cout << END_COLOR;
                cout << "\033[40m  ";
                cout << END_COLOR;
            } else {
                if (matrix -> getData(i, j) -> getBeing())
                    cout << "\033[47;30;1m" << " " << matrix -> getData(i, j) -> getBeing() -> getCharName() << " ";
                else if (matrix->getData(i, j)->getElement())
                    cout << "\033[47;30;1m" << " " << matrix -> getData(i, j) -> getElement() -> getCharName() << " ";
                else
                    cout << BGND_WHITE_254 << "   ";

                cout << END_COLOR;
                cout << "\033[40m  ";
                cout << END_COLOR;
            }
        }
        cout << endl;
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i, 31);
    }
    this ->showMapLimit(matrix -> getHeight(),matrix -> getWidth());
}

void Printer::showCrossedRange(Matrix<Vertex*>* matrix, const string background, int row, int column) {
    mainWindow();
    this->showMapLimit(matrix->getHeight(),matrix->getWidth());
    int coordY = 20;
    std::cout << gotoxy.pos(coordY - 1, 31);
    for (int i = 0; i < matrix->getHeight(); i++) {
        for (int j = 0; j < matrix->getWidth(); j++) {
            if ((i == row && j == column)) {
                cout << TXT_DARK_GRAY_234 << TXT_BOLD << BGND_GREEN_76 << " " << matrix->getData(i, j)->getBeing()->getCharName() << " " << END_COLOR;
                cout << END_COLOR;
                cout << "\033[40m  ";
                cout << END_COLOR;
            }
            else if ((i == row - 1 && j == column) ||
                     (i == row + 1 && j == column) ||
                     (j == column + 1 && i == row) ||
                     (j == column - 1 && i == row) )
            {
                cout << background;
                if (matrix->getData(i, j)->getBeing()) {
                    cout << TXT_DARK_GRAY_234 << TXT_BOLD << " " << matrix->getData(i, j)->getBeing()->getCharName() << " ";
                } else if (matrix->getData(i, j)->getElement())
                    cout << TXT_DARK_GRAY_234 << TXT_BOLD << " " << matrix->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << background << "   ";
                cout << END_COLOR;
                cout << "\033[40m  ";
                cout << END_COLOR;
            }
            else
            {
                if (matrix->getData(i, j)->getBeing())
                    cout << "\033[47;30;1m" << " " << matrix->getData(i, j)->getBeing()->getCharName() << " ";
                else if (matrix->getData(i, j)->getElement())
                    cout << "\033[47;30;1m" << " " << matrix->getData(i, j)->getElement()->getCharName() << " ";
                else
                    cout << "\033[47;30;1m" << "   ";

                cout << END_COLOR;
                cout << "\033[40m  ";
                cout << END_COLOR;
            }
        }
        cout << endl;
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i, 31);
    }
    this ->showMapLimit(matrix -> getHeight(),matrix -> getWidth());
}

void Printer::showMapLimit(int rows, int columns) {

    for(int i = 0; i < rows; i++){

        cout << gotoxy.pos(17, 32 + (i*5)) << "\033[40;1m" <<  i+1 << END_COLOR << endl;

    }

    for(int j = 0; j < columns; j++){

        cout << gotoxy.pos(19 + j*2 , 28) << "\033[40;1m" <<  j+1 << END_COLOR << endl;

    }

}

void Printer::showHealths(List<Being*>* characters) {
    clearCharacterStats();
    Identifier ident;
    int y = 19;
    int length = characters -> getLength();
    int count = 0;
    Being * being;
    while(length != count){
        being = characters -> getNext() -> getData();
        if(! ident.isZombie(being)){
            cout << gotoxy.pos(y, 74) << "\033[40m " << being->getObjectName() << " (" << being -> getRow() + 1 << ", " << being -> getCol() + 1 << ")" << END_COLOR;
            cout << gotoxy.pos(y + 2, 75) <<  "\033[40m"<< HEALTH_SYMBOL + "  " << being -> getHealth()  << END_COLOR;
            y += 4;
        }

        if (!characters->hasNext())
            characters -> reset();

        count++;
    }
}

void Printer::humanVictory() {
    cout << gotoxy.pos(20,16) << "\033[40m   ██░ ██  █    ██  ███▄ ▄███▓ ▄▄▄       ███▄    █  ▒█████    ██████  " << END_COLOR;
    cout << gotoxy.pos(21,16) << "\033[40m  ▓██░ ██▒ ██  ▓██▒▓██▒▀█▀ ██▒▒████▄     ██ ▀█   █ ▒██▒  ██▒▒██    ▒ "  << END_COLOR;
    cout << gotoxy.pos(22,16) << "\033[40m  ▒██▀▀██░▓██  ▒██░▓██    ▓██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██░  ██▒░ ▓██▄   "  << END_COLOR;
    cout << gotoxy.pos(23,16) << "\033[40m  ░▓█ ░██ ▓▓█  ░██░▒██    ▒██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒▒██   ██░  ▒   ██▒"  << END_COLOR;
    cout << gotoxy.pos(24,16) << "\033[40m  ░▓█▒░██▓▒▒█████▓ ▒██▒   ░██▒ ▓█   ▓██▒▒██░   ▓██░░ ████▓▒░▒██████▒▒"  << END_COLOR;
    cout << gotoxy.pos(25,16) << "\033[40m  ▒ ░░▒░▒░▒▓▒ ▒ ▒ ░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒░   ▒ ▒ ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░ "  << END_COLOR;
    cout << gotoxy.pos(26,16) << "\033[40m  ▒ ░▒░ ░░░▒░ ░ ░ ░  ░      ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░ ▒ ▒░ ░ ░▒  ░ ░ "  << END_COLOR;
    cout << gotoxy.pos(27,16) << "\033[40m  ░  ░░ ░ ░░░ ░ ░ ░      ░     ░   ▒      ░   ░ ░ ░ ░ ░ ▒  ░  ░  ░   "  << END_COLOR;
    cout << gotoxy.pos(28,16) << "\033[40m ░  ░  ░   ░            ░         ░  ░         ░     ░ ░        ░    "  << END_COLOR;

    cout << gotoxy.pos(30,26) << "\033[40m    ▄████  ▄▄▄       ███▄    █  ▄▄▄       ███▄    █   " << END_COLOR;
    cout << gotoxy.pos(31,26) << "\033[40m   ██▒ ▀█▒▒████▄     ██ ▀█   █ ▒████▄     ██ ▀█   █  "  << END_COLOR;
    cout << gotoxy.pos(32,26) << "\033[40m  ▒██░▄▄▄░▒██  ▀█▄  ▓██  ▀█ ██▒▒██  ▀█▄  ▓██  ▀█ ██▒"   << END_COLOR;
    cout << gotoxy.pos(33,26) << "\033[40m  ░▓█  ██▓░██▄▄▄▄██ ▓██▒  ▐▌██▒░██▄▄▄▄██ ▓██▒  ▐▌██▒"   << END_COLOR;
    cout << gotoxy.pos(34,26) << "\033[40m  ░▒▓███▀▒ ▓█   ▓██▒▒██░   ▓██░ ▓█   ▓██▒▒██░   ▓██░"   << END_COLOR;
    cout << gotoxy.pos(35,26) << "\033[40m  ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░   ▒ ▒  "   << END_COLOR;
    cout << gotoxy.pos(36,26) << "\033[40m ░   ░   ▒   ▒▒ ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░   "   << END_COLOR;
    cout << gotoxy.pos(37,26) << "\033[40m  ░ ░   ░   ░   ▒      ░   ░ ░   ░   ▒      ░   ░ ░ "   << END_COLOR;
    cout << gotoxy.pos(38,26) << "\033[40m  ░       ░  ░         ░       ░  ░         ░       "   << END_COLOR;

}

void Printer::monsterVictory() {


    cout << gotoxy.pos(20,8) << "\033[40m ███▄ ▄███▓  ▒█████   ███▄    █   ██████ ▄▄▄█████▓ ██▀███   █    ██  ▒█████    ██████"  << END_COLOR;
    cout << gotoxy.pos(21,8) << "\033[40m ▓██▒▀█▀ ██▒▒██▒  ██▒ ██ ▀█   █ ▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒ ██  ▓██▒▒██▒  ██▒▒██    ▒"  << END_COLOR;
    cout << gotoxy.pos(22,8) << "\033[40m ▓██    ▓██░▒██░  ██▒▓██  ▀█ ██▒░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▓██  ▒██░▒██░  ██▒░ ▓██▄"    << END_COLOR;
    cout << gotoxy.pos(23,8) << "\033[40m ▒██    ▒██ ▒██   ██░▓██▒  ▐▌██▒  ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ▓▓█  ░██░▒██   ██░  ▒   ██▒" << END_COLOR;
    cout << gotoxy.pos(24,8) << "\033[40m ▒██▒   ░██▒░ ████▓▒░▒██░   ▓██░▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒▒▒█████▓ ░ ████▓▒░▒██████▒▒" << END_COLOR;
    cout << gotoxy.pos(25,8) << "\033[40m ░ ▒░   ░  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒▓ ░▒▓░░▒▓▒ ▒ ▒ ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░" << END_COLOR;
    cout << gotoxy.pos(26,8) << "\033[40m ░  ░      ░  ░ ▒ ▒░ ░ ░░   ░ ▒░░ ░▒  ░ ░    ░      ░▒ ░ ▒░░░▒░ ░ ░   ░ ▒ ▒░ ░ ░▒  ░ ░" << END_COLOR;
    cout << gotoxy.pos(27,8) << "\033[40m ░      ░   ░ ░ ░ ▒     ░   ░ ░ ░  ░  ░    ░        ░░   ░  ░░░ ░ ░ ░ ░ ░ ▒  ░  ░  ░"   << END_COLOR;
    cout << gotoxy.pos(28,8) << "\033[40m ░       ░ ░           ░       ░              ░        ░         ░ ░        ░"          << END_COLOR;

    cout << gotoxy.pos(30,24) << "\033[40m    ▄████  ▄▄▄       ███▄    █  ▄▄▄       ███▄    █   " << END_COLOR;
    cout << gotoxy.pos(31,24) << "\033[40m   ██▒ ▀█▒▒████▄     ██ ▀█   █ ▒████▄     ██ ▀█   █  "  << END_COLOR;
    cout << gotoxy.pos(32,24) << "\033[40m  ▒██░▄▄▄░▒██  ▀█▄  ▓██  ▀█ ██▒▒██  ▀█▄  ▓██  ▀█ ██▒"   << END_COLOR;
    cout << gotoxy.pos(33,24) << "\033[40m  ░▓█  ██▓░██▄▄▄▄██ ▓██▒  ▐▌██▒░██▄▄▄▄██ ▓██▒  ▐▌██▒"   << END_COLOR;
    cout << gotoxy.pos(34,24) << "\033[40m  ░▒▓███▀▒ ▓█   ▓██▒▒██░   ▓██░ ▓█   ▓██▒▒██░   ▓██░"   << END_COLOR;
    cout << gotoxy.pos(35,24) << "\033[40m  ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░   ▒ ▒  "   << END_COLOR;
    cout << gotoxy.pos(36,24) << "\033[40m ░   ░   ▒   ▒▒ ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░   "   << END_COLOR;
    cout << gotoxy.pos(37,24) << "\033[40m  ░ ░   ░   ░   ▒      ░   ░ ░   ░   ▒      ░   ░ ░ "   << END_COLOR;
    cout << gotoxy.pos(38,24) << "\033[40m  ░       ░  ░         ░       ░  ░         ░       "   << END_COLOR;


}

void Printer::showHuntersHealedOthers() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " El cazador ha curado a todos sus aliados con +20"<< HEALTH_SYMBOL << "   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVanesaAvoidedTransformation() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Vanesa ha evitado que sus aliados cercanos se transformen en zombies   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showZombieAttackedHuman(std::string targetName, int row, int col) {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " El zombi ha mordido a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ")   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVampireAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth) {
    if(newHealth < 0)
        newHealth = 0;
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " El vampiro ha mordido a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ")  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << targetName << ": " << HEALTH_SYMBOL << "  " << oldHealth   << " " << RIGHT_ARROW_SYMBOL << " " << HEALTH_SYMBOL << "  " << newHealth  << "  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVampirellaAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth) {
    if(newHealth < 0)
        newHealth = 0;
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " Vampirella ha mordido a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ")  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << targetName << ": " << HEALTH_SYMBOL << "  " << oldHealth   << " " << RIGHT_ARROW_SYMBOL << " " << HEALTH_SYMBOL << "  " << newHealth  << "  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showNosferatuAttackedHuman(std::string targetName, int row, int col, int oldHealth, int newHealth) {
    if(newHealth < 0)
        newHealth = 0;
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " Nosferatu ha mordido a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ")  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << targetName << ": " << HEALTH_SYMBOL << "  " << oldHealth   << " " << RIGHT_ARROW_SYMBOL << " " << HEALTH_SYMBOL << "  " << newHealth  << "  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVanesaAttacked(std::string targetName, int row, int col, int oldHealth, int newHealth, std::string weapon) {
    if(newHealth < 0)
        newHealth = 0;
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " Vanesa ha atacado a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ") con " << weapon << "  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << targetName << ": " << HEALTH_SYMBOL << "  " << oldHealth   << " " << RIGHT_ARROW_SYMBOL << " " << HEALTH_SYMBOL << "  " << newHealth  << "  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showHunterAttacked(std::string targetName, int row, int col, int oldHealth, int newHealth,
                                 std::string weapon) {
    if(newHealth < 0)
        newHealth = 0;
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " Cazador ha atacado a " << targetName << " en la posición (" << row+1 << ", " << col+1 << ") con " << weapon << "  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << targetName << ": " << HEALTH_SYMBOL << "  " << oldHealth   << " " << RIGHT_ARROW_SYMBOL << " " << HEALTH_SYMBOL << "  " << newHealth  << "  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showNosferatuTransformedHuman(std::string targetName, int row, int col) {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " Nosferatu transformará " << targetName << " en la posición (" << row+1 << ", " << col+1 << ") en vampiro  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVanesaIsCrossedProtectedMsg() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Vanesa está protegida contra ataques vampíricos con una cruz!  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showHumanGotMaxEnergy() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " El humano ha repuesto toda su energía con el agua bendita  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showHumanGotArmor() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " El humano adquirió +1" << ARMOR_SYMBOL << " por un turno  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showHumanGotDefaultEnergy() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " El humano no tiene agua bendita, así que adquirió +3" << ENERGY_SYMBOL << "  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::couldntAddObject(std::string objectName) {
    std::cout << gotoxy.pos(37,28) << "\033[40m" << TXT_BOLD << TXT_LIGHT_RED_9 << " " << objectName << " ya existe. No se puede agregar otro!  \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(40,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(41,28) << "\033[40m                                                         \033[0m";
}

void Printer::objectAddedSuccessfully(std::string objectName) {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " " << objectName << " añadido correctamente!  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVampirellaIsBat() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Vampirella se ha transformado en murciélago!   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showZombiIsHidden() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Zombi se ha escondido por 1 turno   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showCantAttackHiddenZombie() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << TXT_ITALIC << " No se puede atacar al zombi porque está escondido   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showCantAttackBatVampirella() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << TXT_ITALIC << " Vampirela es un murciélago y no puede ser atacada por la estaca.  \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showVampireIsHidden() {
    std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Vampiro ha adquirido +1" << ARMOR_SYMBOL << " por un turno   \033[0m";
    std::cout << gotoxy.pos(36,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
}

void Printer::showSavedGameFound() {
    cout << gotoxy.pos(28,8) << TXT_BOLD << TXT_GREEN_76 << "\033[40m    SE HA ENCONTRADO UNA PARTIDA GUARDADA!    \033[0m";
}