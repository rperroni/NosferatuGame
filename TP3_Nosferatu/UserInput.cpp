#include "UserInput.h"

int UserInput::validateRangeOption(int min, int max) {

    std::cout << gotoxy.pos(40,5) << "\033[47;30;1m----> "; std::cin >> option; std::cout << "\033[0m" << std::endl;

    if(option < min || option > max){
        std::cout << gotoxy.pos(40,10) << "\033[40m       \033[0m";
        std::cout << gotoxy.pos(43,5) << "\033[48;5;88m Fuera de rango. Tiene que ser entre: " << min << " y " << max << "\033[0m" <<  std::endl;
        return this -> validateRangeOption(min,max);
    }
    else{
        printer.optionClear();
        return option;
    }
}

void UserInput::validateRangeCoordinates(int* coordinateOne, int* coordinateTwo, int minCoordinateOne, int maxCoordinateOne, int minCoordinateTwo, int maxCoordinateTwo) {
    std::cout << gotoxy.pos(39,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m  COORDENADA Y: ";
    *coordinateOne = this -> validateRangeOption( minCoordinateOne, maxCoordinateOne);
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m  COORDENADA X: ";
    *coordinateTwo = this -> validateRangeOption( minCoordinateTwo, maxCoordinateTwo);

}

int UserInput::validateAmount() {
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m INGRESE LA CANTIDAD: ";
    return validateRangeOption(1,99);
}

void UserInput::systemPause() {

    std::cout << gotoxy.pos(41,5) << "\033[6;47;30;1m PRESIONE ENTER \033[0m";
    std::cin.get();
    std::cin.get();

}

int UserInput::validateReentry() {

    std::cout << gotoxy.pos(39,5) << "\033[48;5;88m INGRESO INVALIDO \033[0m";
    std::cout << gotoxy.pos(42,5) << "\033[47;30;1m [1] REINGRESAR  \033[0m";
    std::cout << gotoxy.pos(43,5) << "\033[47;30;1m [2] VOLVER ATRAS \033[0m";

    return validateRangeOption(1,2);
}

int UserInput::validateMovementRange(Being* current, Floyd &floyd, int &row, int &col) {
    int goBack = 1;
    cout << gotoxy.pos(35,31) << "\033[40m                                                                    \033[0m" << endl;
    cout << gotoxy.pos(36,31) << "\033[40m                                                                    \033[0m" << endl;
    cout << gotoxy.pos(37,31) << "\033[40m                                                                    \033[0m" << endl;
    cout << gotoxy.pos(38,31) << "\033[40m                                                                    \033[0m" << endl;
    cout << gotoxy.pos(39,31) << "\033[40m                                                                    \033[0m" << endl;
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m Seleccione la fila donde desea mover a " << current -> getObjectName() << END_COLOR;
    row = this -> validateRangeOption( 1, floyd.getHeight());
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m  Seleccione la columna donde desea mover a " << current -> getObjectName() << END_COLOR;
    col = this -> validateRangeOption( 1, floyd.getWidth());
    cout << gotoxy.pos(39,5) << "\033[40m                                                                        \033[0m" << endl;

    if(!floyd.checkMinimumPath(current->getCol(), current->getRow(), col - 1, row - 1 )){
        printer.optionClear();
        std::cout << gotoxy.pos(36,31) << "\033[40;1m" << TXT_RED_124 <<  "No es posible realizar el movimiento!" << END_COLOR << std::endl;
        std::cout << gotoxy.pos(37,31) << "\033[40;1m" << TXT_RED_124 <<  "No hay suficiente energía o el casillero esta ocupado por otro ser" << END_COLOR << std::endl;
        goBack = this -> simulationReEntry();
        if(goBack == 0)
            return goBack;
        else{
            cout << gotoxy.pos(41,5) << "\033[40m                                                                    \033[0m" << endl;
            return validateMovementRange(current, floyd, row, col);
        }
    }

    return goBack;
}

void UserInput::showIdSearch(Dictionary &dict, Matrix<Vertex*>* matrix) {

    std::cout << gotoxy.pos(39, 4) << "\033[47;30;1m INGRESE ID \033[0m" << std::endl;
    int id = this -> validateRangeOption(0, 999);
    std::cout << gotoxy.pos(39,4) << "\033[40m                                                 \033[0m";

    if (dict.search(id)) {
        printer.mainWindow();
        Object* current = dict.find(id);
        int row = current -> getRow();
        int column = current -> getCol();
        printer.showMap(matrix);
        std::cout << gotoxy.pos(19 + row*2, 32 + column*5) << matrix -> getData(row, column) -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";
        cout << gotoxy.pos(19 + row*2, 32 + column*5) << "\033[6m" << current -> getCharName() << END_COLOR << "\033[40m" << endl;
        std::cout << gotoxy.pos(36,41)  << "\033[40;1m" << TXT_GREEN_10 << " OBJETO ENCONTRADO " << END_COLOR << std::endl;
        current->show();
    }
    else
        std::cout << gotoxy.pos(39,4)  << "\033[40;1m" << TXT_RED_124 << "OBJETO NO ENCONTRADO";

    this -> systemPause();

}

Element *UserInput::validateSelectedWeapon(Being *being) {
    std::cout << gotoxy.pos(35,38) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(36,38) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(37,38) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(38,38) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(39,38) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m Seleccione el arma que desea usar: " << END_COLOR;
    std::cout << gotoxy.pos(39,45) << "\033[47;30;1m [1]    Escopeta    " << END_COLOR;
    std::cout << gotoxy.pos(39,70) << "\033[47;30;1m [2]     Estaca     " << END_COLOR;
    std::cout << gotoxy.pos(41,45) << "\033[47;30;1m [3]  Agua Bendita  " << END_COLOR;
    std::cout << gotoxy.pos(41,70) << "\033[47;30;1m [4]     Salir      " << END_COLOR;
    Element * weapon = nullptr;
    switch (validateRangeOption(1, 4)) {
        case 1:
            if(being-> getInventory() -> isShotgunUsable()){
                 weapon = new Shotgun(1);
                 weapon->setId(350);
            }
            break;
        case 2:
            if(being ->hasStake()){
                weapon = new Stake(1);
                weapon->setId(381);
            }
            break;
        case 3:
            if (being -> hasHolyWater()){
                weapon = new HolyWater(1);
                weapon->setId(319);
            }
            break;
        case 4:
            return weapon;
    }
    if(weapon)
        return weapon;
    else{
        std::cout << gotoxy.pos(41,4)  << "\033[40;1m" << TXT_RED_124 << "El personaje seleccionado no tiene el arma que desea usar";
        return validateSelectedWeapon(being);
    }
}

void UserInput::validateAttackPosition(Being *attacker, Element *weapon, int &row, int &col, Map *map) {
    Identifier ident;
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m Seleccione la fila donde desea atacar " << END_COLOR;
    row = this -> validateRangeOption(1, map -> getHeight());
    std::cout << gotoxy.pos(39,5) << "\033[47;30;1m Seleccione la columna donde desea atacar " << END_COLOR;
    col = this -> validateRangeOption(1, map -> getWidth());
    row--;
    col--;

    if(ident.isShotgun(weapon)){
        if(!(map->getMatrix() -> getData(row, col) -> getBeing()  &&
             map->getMatrix() -> getData(row, col) -> getBeing() -> getTeam() != attacker -> getTeam()) ||
             !((row >= attacker -> getRow() - 2 && row <= attacker -> getRow() + 2) &&
             (col >= attacker -> getCol() - 2 && col <= attacker -> getCol() + 2)) ){
            std::cout << gotoxy.pos(41,4)  << "\033[40;1m" << TXT_RED_124 << "La posicion seleccionada no es valida para atacar";
            if(this->simulationReEntry() != 0){
                validateAttackPosition(attacker, weapon, row, col, map);
            }else{
                row = -1;
                col = -1;
            }
        }
    } else if(ident.isHolyWater(weapon)){
        if(!(map->getMatrix()->getData(row, col)->getBeing()) ||
            !((row >= attacker->getRow() - 1 && row <= attacker->getRow() + 1) &&
            (col >= attacker->getCol() - 1 && col <= attacker->getCol() + 1)) ){
            std::cout << gotoxy.pos(41,4)  << "\033[40;1m" << TXT_RED_124 << "La posicion seleccionada no es valida para atacar";
            if(this->simulationReEntry() != 0){
                validateAttackPosition(attacker, weapon, row, col, map);
            } else{
                row = -1;
                col = -1;
            }
        }
    } else {
        if(!(map->getMatrix()->getData(row, col)->getBeing() &&
             map->getMatrix()->getData(row, col)->getBeing()->getTeam() != attacker->getTeam()) ||
            !((row == attacker->getRow() - 1 && col == attacker->getCol()) ||
            (row == attacker->getRow() + 1 && col == attacker->getCol()) ||
            (col == attacker->getCol() + 1 && row == attacker->getRow()) ||
            (col == attacker->getCol() - 1 && row == attacker->getRow()) ) ){
            std::cout << gotoxy.pos(41,4)  << "\033[40;1m" << TXT_RED_124 << "La posicion seleccionada no es valida para atacar";
            if(this->simulationReEntry() != 0){
                validateAttackPosition(attacker, weapon, row, col, map);
            } else{
                row = -1;
                col = -1;
            }
        }
    }
}

void UserInput::validateAttackPosition(Being *attacker, int &row, int &col, Map *map) {

    Identifier ident;
    if(ident.isZombie(attacker)){
        List<Being*>* list = new List<Being*>;
        List<Vertex*>* vertexList = map -> getMatrix() -> getData(attacker -> getRow(), attacker -> getCol()) -> getConnections();
        Being* target;
        while(vertexList -> hasNext()){
            target = vertexList -> getNext() -> getData() -> getBeing();
            if(target && ident.isHumanTeam(target) ){
                list -> insert(target);
            }
        }
        vertexList -> reset();
        if( !list -> isEmpty() ){
            int randomAttack = rand() % (list -> getLength()) + 1;
            target = list -> getData(randomAttack);
            row = target -> getRow();
            col = target -> getCol();
        }else{
            row = -1;
            col = -1;
        }


        delete list;
    }else {
        std::cout << gotoxy.pos(39, 5) << "\033[47;30;1m Seleccione la fila donde desea atacar " << END_COLOR;
        row = this->validateRangeOption(1, map->getHeight());
        std::cout << gotoxy.pos(39, 5) << "\033[47;30;1m Seleccione la columna donde desea atacar " << END_COLOR;
        col = this->validateRangeOption(1, map->getWidth());
        row--;
        col--;

        if (ident.isHuman(attacker)) {
            if (!(map->getMatrix()->getData(row, col)->getBeing() &&
                map->getMatrix()->getData(row, col)->getBeing()->getTeam() != attacker->getTeam()) ||
                !((row >= attacker->getRow() - 1 && row <= attacker->getRow() + 1) &&
                (col >= attacker->getCol() - 1 && col <= attacker->getCol() + 1)) ){
                std::cout << gotoxy.pos(41, 4) << "\033[40;1m" << TXT_RED_124
                          << "La posicion seleccionada no es valida para atacar";
                if(this->simulationReEntry() != 0) {
                    validateAttackPosition(attacker, row, col, map);
                } else{
                    row = -1;
                    col = -1;
                }
            }
        } else if (ident.isVampire(attacker) || ident.isVampirella(attacker)) {
            if (!(map->getMatrix()->getData(row, col)->getBeing() &&
                  map->getMatrix()->getData(row, col)->getBeing()->getTeam() != attacker->getTeam()) ||
                !((row == attacker->getRow() - 1 && col == attacker->getCol()) ||
                  (row == attacker->getRow() + 1 && col == attacker->getCol()) ||
                  (col == attacker->getCol() + 1 && row == attacker->getRow()) ||
                  (col == attacker->getCol() - 1 && row == attacker->getRow()))) {
                std::cout << gotoxy.pos(41, 4) << "\033[40;1m" << TXT_RED_124
                          << "La posicion seleccionada no es valida para atacar";
                if(this->simulationReEntry() != 0) {
                    validateAttackPosition(attacker, row, col, map);
                }
                else{
                    row = -1;
                    col = -1;
                }
            }
        } else {
            if (!(map->getMatrix()->getData(row, col)->getBeing() &&
                  map->getMatrix()->getData(row, col)->getBeing()->getTeam() != attacker->getTeam()) ||
                !((row >= attacker->getRow() - 2 && row <= attacker->getRow() + 2) &&
                (col >= attacker->getCol() - 2 && col <= attacker->getCol() + 2))) {
                std::cout << gotoxy.pos(41, 4) << "\033[40;1m" << TXT_RED_124
                          << "La posicion seleccionada no es valida para atacar";
                if(this->simulationReEntry() != 0) {
                    validateAttackPosition(attacker, row, col, map);
                }
                else{
                    row = -1;
                    col = -1;
                }
            }
        }
    }
}

int UserInput::askToSaveGame(int currentPlayerNumber) {
    printer.mainWindow();

    cout << gotoxy.pos(23,35) << "\033[6;47;30;1m         Jugador  " << currentPlayerNumber << "         \033[0m" << endl;
    cout << gotoxy.pos(24,35) << "\033[40m                            \033[0m" << endl;
    cout << gotoxy.pos(25,35) << "\033[40m                            \033[0m" << endl;
    cout << gotoxy.pos(26,35) << "\033[47;30;1m ¿Desea guardar la partida? \033[0m" << endl;
    cout << gotoxy.pos(28,35) << "\033[47;30;1m [1] Sí \033[0m" << endl;
    cout << gotoxy.pos(28,55) << "\033[47;30;1m [2] No \033[0m" << endl;
    return (this -> validateRangeOption(1, 2));
}

int UserInput::simulationReEntry() {

    std::cout << gotoxy.pos(42,5) << "\033[47;30;1m [1] CONTINUAR \033[0m";
    std::cout << gotoxy.pos(43,5) << "\033[47;30;1m [0] VOLVER ATRAS \033[0m";

    return  this->validateRangeOption(0,1);
}

int UserInput::vanesaDefenseOptions(bool defenseOptions[MAX_DEFENSE_OPTIONS]) {
    if(defenseOptions[VANESA_DEFENSE_HOLY_WATER] && defenseOptions[VANESA_DEFENSE_CROSS])
    {
        std::cout << gotoxy.pos(35,28) << "\033[47;30;1m ¿Cómo desea defenderse?                                 \033[0m";
        std::cout << gotoxy.pos(36,28) << "\033[47;30;1m [" << VANESA_DEFENSE_HOLY_WATER+1 << "] Usar agua bendita para salvar a sus aliados         \033[0m";
        std::cout << gotoxy.pos(37,28) << "\033[47;30;1m [" << VANESA_DEFENSE_CROSS+1 << "] Usar una cruz para defenderse de ataques vampíricos \033[0m";
        std::cout << gotoxy.pos(38,28) << "\033[47;30;1m [" << VANESA_DEFENSE_SELFHEAL+1 << "] Curarse con +10" << HEALTH_SYMBOL << "                                    \033[0m";
        std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";

        option = this ->validateRangeOption(VANESA_DEFENSE_HOLY_WATER+1, VANESA_DEFENSE_SELFHEAL+1);
        option--;
        if(option == VANESA_DEFENSE_SELFHEAL)
            option = SELFHEAL;
        else if(option == VANESA_DEFENSE_HOLY_WATER)
            option = HEALOTHERS;
        else
            option = CROSSPROTECTION;
    }
    else if(defenseOptions[VANESA_DEFENSE_HOLY_WATER] && !defenseOptions[VANESA_DEFENSE_CROSS])
    {
        std::cout << gotoxy.pos(35,28) << "\033[47;30;1m ¿Cómo desea defenderse?                         \033[0m";
        std::cout << gotoxy.pos(36,28) << "\033[47;30;1m [" << VANESA_DEFENSE_HOLY_WATER+1 << "] Usar agua bendita para salvar a sus aliados \033[0m";//48
        std::cout << gotoxy.pos(37,28) << "\033[47;30;1m [" << VANESA_DEFENSE_SELFHEAL << "] Curarse con +10" << HEALTH_SYMBOL << "                            \033[0m";
        std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
        std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
        option = this ->validateRangeOption(VANESA_DEFENSE_HOLY_WATER+1, VANESA_DEFENSE_SELFHEAL);
        if(option == VANESA_DEFENSE_SELFHEAL)
            option = SELFHEAL;
        else
            option = HEALOTHERS;
    }
    else if(!defenseOptions[VANESA_DEFENSE_HOLY_WATER] && defenseOptions[VANESA_DEFENSE_CROSS])
    {
        std::cout << gotoxy.pos(35,28) << "\033[47;30;1m ¿Cómo desea defenderse?                                 \033[0m";
        std::cout << gotoxy.pos(36,28) << "\033[47;30;1m [" << VANESA_DEFENSE_CROSS << "] Usar una cruz para defenderse de ataques vampíricos \033[0m";
        std::cout << gotoxy.pos(37,28) << "\033[47;30;1m [" << VANESA_DEFENSE_SELFHEAL << "] Curarse con +10" << HEALTH_SYMBOL << "                                    \033[0m";
        std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
        std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
        option = this ->validateRangeOption(VANESA_DEFENSE_CROSS, VANESA_DEFENSE_SELFHEAL+1);
        if(option == VANESA_DEFENSE_SELFHEAL)
            option = SELFHEAL;
        else
            option = CROSSPROTECTION;
    }
    else
    {
        std::cout << gotoxy.pos(35,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " Vanesa no tiene agua bendita ni cruz en su inventario \033[0m";
        std::cout << gotoxy.pos(36,28) << "\033[40m" << TXT_BOLD << TXT_GREEN_76 << " La defensa es: curarse con +10" << HEALTH_SYMBOL << "                       \033[0m";
        std::cout << gotoxy.pos(37,28) << "\033[40m                                                         \033[0m";
        std::cout << gotoxy.pos(38,28) << "\033[40m                                                         \033[0m";
        std::cout << gotoxy.pos(39,28) << "\033[40m                                                         \033[0m";
        option = SELFHEAL;
    }
    return option;
}

int UserInput::hunterDefenseOptions() {
    std::cout << gotoxy.pos(35,31) << "\033[47;30;1m ¿Cómo desea defenderse?            \033[0m";
    std::cout << gotoxy.pos(36,31) << "\033[47;30;1m [" << SELFHEAL << "] Curarte con +50" << HEALTH_SYMBOL <<  "               \033[0m";//48
    std::cout << gotoxy.pos(37,31) << "\033[47;30;1m [" << HEALOTHERS << "] Curar a tus aliados con +20" << HEALTH_SYMBOL << "   \033[0m";
    std::cout << gotoxy.pos(38,31) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,31) << "\033[40m                                                         \033[0m";

    return ( this ->validateRangeOption(SELFHEAL, HEALOTHERS) );
}

int UserInput::humanDefenseOptions() {
    std::cout << gotoxy.pos(35,31) << "\033[47;30;1m ¿Cómo desea defenderse?                            \033[0m";
    std::cout << gotoxy.pos(36,31) << "\033[47;30;1m [" << HUMAN_ENERGY_ADD << "] Usar el agua bendita para regenerar toda tu " << ENERGY_SYMBOL <<  " \033[0m";//48
    std::cout << gotoxy.pos(37,31) << "\033[47;30;1m [" << HUMAN_ARMOR_ADD << "] Obtener +1" << ARMOR_SYMBOL << "  por 1 turno                       \033[0m";
    std::cout << gotoxy.pos(38,31) << "\033[40m                                                         \033[0m";
    std::cout << gotoxy.pos(39,31) << "\033[40m                                                         \033[0m";

    return ( this ->validateRangeOption(HUMAN_ENERGY_ADD, HUMAN_ARMOR_ADD) );
}

void UserInput::nosferatuDefenseOptions(Being *nosferatu, Map *map, int &row, int &col, List<Being *> *vampires) {
    Identifier ident;
    printer.showSquareRange(map->getMatrix(), 2, BGND_LIGHT_BLUE_45, nosferatu -> getRow(), nosferatu -> getCol());
    printer.showHealths(vampires);
    std::cout << gotoxy.pos(39, 5) << "\033[47;30;1m Seleccione la fila del vampiro con el que desea intercambiar vida " << END_COLOR;
    row = this->validateRangeOption(1, map->getHeight());
    std::cout << gotoxy.pos(39, 5) << "\033[47;30;1m Seleccione la columna del vampiro con el que desea intercambiar vida " << END_COLOR;
    col = this->validateRangeOption(1, map->getWidth());
    row--;
    col--;
    if (!(map->getMatrix()->getData(row, col)->getBeing()) ||
        !((ident.isVampire(map->getMatrix()->getData(row, col)->getBeing())) ||
        (ident.isVampirella(map->getMatrix()->getData(row, col)->getBeing()))) ||
        !((row >= nosferatu->getRow() - 2 && row <= nosferatu->getRow() + 2) &&
          (col >= nosferatu->getCol() - 2 && col <= nosferatu->getCol() + 2))) {
        std::cout << gotoxy.pos(41, 4) << "\033[40;1m" << TXT_RED_124
                  << "La posicion seleccionada no es valida para intercambiar vida";
        if(this->simulationReEntry() != 0) {
            nosferatuDefenseOptions(nosferatu, map, row, col, vampires);
        }
        else{
            row = -1;
            col = -1;
        }
    }
    printer.clearCharacterStats();

}



