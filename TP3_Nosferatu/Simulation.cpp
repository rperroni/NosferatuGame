#include "Simulation.h"

Simulation::Simulation() {
    this -> turnCounter = 0;
    this -> exitSimulation = false;
    this -> savedPlayer = 0;
    this -> otherPlayer = 0;
}

void Simulation::loadGame(Map *map, Player* playerOne, Player* playerTwo) {
    this -> map = map;
    this -> battle.loadMap(map);
    this -> floyd.loadMap(map);
    this -> playerOne = playerOne;
    this -> playerTwo = playerTwo;
}

void Simulation::startSimulation(bool savedGameFound){
    if(savedGameFound)
    {
        this -> loadSavedGame();
        printer.mainWindow();
        printer.showSavedGameFound();
        cin.get();
    }
    else
        loadCharacters();

    while(!exitSimulation)
    {
        if(!exitSimulation && userInput.askToSaveGame(savedPlayer) == YES){
            this -> saveGame (savedPlayer);
            this -> exitSimulation = true;
        }
        else
            playerSelectOptions(savedPlayer);
        if(!exitSimulation && userInput.askToSaveGame(otherPlayer) == YES){
            this -> saveGame(otherPlayer);
            this -> exitSimulation = true;
        }
        else {
            if (!exitSimulation) {
                playerSelectOptions(otherPlayer);
            }
        }
        turnCounter++;
    }
}

void Simulation::setSavedPlayer(int playerNumber) {
    this -> savedPlayer = playerNumber;
    if(playerNumber == 1)
        this -> otherPlayer = 2;
    else
        this -> otherPlayer = 1;
}

void Simulation::loadCharacters() {
    for(int i = 0; i < map->getHeight(); i++){
        for (int j = 0; j < map->getWidth(); j++) {
            if(map ->getMatrix() -> getData(i, j) -> getBeing()){
                if (map -> getMatrix() -> getData(i, j) -> getBeing() -> getTeam() == playerOne -> getTeam())
                    playerOne->addCharacter(map ->getMatrix() ->getData(i, j) -> getBeing());
                else{
                    playerTwo->addCharacter(map ->getMatrix() ->getData(i, j) -> getBeing());
                }
            }
        }
    }
}


Simulation::~Simulation() {
    if(playerOne) {
        delete playerOne;
        playerOne = nullptr;
    }
    if(playerTwo) {
        delete playerTwo;
        playerTwo = nullptr;
    }
}

void Simulation::playerSelectOptions(int playerNumber) {

    exitSimulation = false;
    List<Being*> * characters;
    int otherPlayerNumber;

    if(playerNumber == 1){
        characters = playerOne -> getCharacters();
        otherPlayerNumber = 2;
    }
    else{
        characters = playerTwo -> getCharacters();
        otherPlayerNumber = 1;
    }

    bool reEntryOption;

    while(characters -> hasNext() && !exitSimulation){

        Being* current = characters -> getCurrent() -> getData();

        reEntryOption = true;
        exitSimulation = false;

        while(reEntryOption){
            printer.showSimulationMap(map -> getMatrix(),current);
            printer.showPlayerTurn(playerNumber);
            printer.showCharacterStats(current);
            printer.showActionMenu();

            switch (userInput.validateRangeOption(0, 4)) {
                case ATTACK_ACTION:
                    if (userInput.simulationReEntry() == 0) {
                        reEntryOption = true;
                    }
                    else {
                        reEntryOption = false;
                        playerAttack(current);
                    }
                    break;
                case DEFENSE_ACTION:
                    if (userInput.simulationReEntry() == 0) {
                        reEntryOption = true;
                    }
                    else {
                        reEntryOption = false;
                        playerDefend(current, playerNumber);
                    }
                    break;
                case MOVE_ACTION:
                    int row, col;
                    if (userInput.validateMovementRange(current, floyd, row, col) == 0) {
                        reEntryOption = true;
                    } else {
                        reEntryOption = false;
                        floyd.minimumPath(current->getCol(), current->getRow(), col - 1, row - 1);
                    }
                    break;
                case EXIT:
                    reEntryOption = false;
                    exitSimulation = true;
                    break;
                default:
                    reEntryOption = false;
                    break;

            }
        }
        if(!exitSimulation) {
            printer.showCharacterStats(current);
            userInput.systemPause();
            current -> addTurnEnergy();
            checkHealths(otherPlayerNumber);
            if(current -> isBitten()){
                current -> bittenCountDown();
            }
            if(current -> getDefenseDuration() == 0){
                current -> endDefense();
            }
            else if(current -> getDefenseDuration() > 0){
                current -> defenseCountdown();
            }
            characters -> getNext();
        }
        endGame();
    }

    characters -> reset();

    checkTransformations();

}

void Simulation::checkTransformations() {
    List<Being*>* humanCharacters;
    List<Being*>* monsterCharacters;
    Being* currentBeing;
    int pos = 1;

    if( playerOne -> getTeam() == HUMANS ) {
        humanCharacters = playerOne -> getCharacters();
        monsterCharacters = playerTwo -> getCharacters();
    }
    else {
        humanCharacters = playerTwo -> getCharacters();
        monsterCharacters = playerOne -> getCharacters();
    }

    while ( humanCharacters -> hasNext() ) {

        currentBeing = humanCharacters -> getNext() -> getData();

        if (currentBeing->isZombieTransformed()) {

            Being *humanToZombie = new Zombie;

            humanToZombie -> setId(currentBeing -> getId());
            humanToZombie -> setRow(currentBeing -> getRow());
            humanToZombie -> setColumn(currentBeing -> getCol());
            humanToZombie -> setEnergy(currentBeing -> getEnergy());
            humanToZombie -> setArmor(currentBeing -> getArmor());
            humanToZombie -> setStrength(currentBeing -> getStrength());
            humanToZombie -> setHealth(currentBeing -> getHealth());
            ((Zombie *) humanToZombie) -> setTransformation();
            monsterCharacters -> insert(humanToZombie);
            humanCharacters -> erase(pos);
            delete currentBeing;
            map -> getMatrix() -> getData(humanToZombie -> getRow(), humanToZombie -> getCol()) -> setBeing(humanToZombie);
        } else if(currentBeing->isVampireTransformed()){
            Being* humanToVampire = new Vampire;
            humanToVampire -> setId(currentBeing -> getId());
            humanToVampire -> setRow(currentBeing -> getRow());
            humanToVampire -> setColumn(currentBeing -> getCol());
            humanToVampire -> setEnergy(currentBeing -> getEnergy());
            humanToVampire -> setArmor(currentBeing -> getArmor());
            humanToVampire -> setStrength(currentBeing -> getStrength());
            humanToVampire -> setHealth(currentBeing -> getHealth());

            humanToVampire -> vampireTransform();
            monsterCharacters->insert(humanToVampire);
            humanCharacters -> erase(pos);
            delete currentBeing;
            map -> getMatrix() -> getData(humanToVampire -> getRow(),humanToVampire -> getCol()) -> setBeing(humanToVampire);
        }
        pos++;
    }

    humanCharacters -> reset();
}

void Simulation::playerAttack(Being* being) {

    battle.selectBeing(being -> getRow(), being -> getCol());
    if( being->checkAttackEnergy() ){
        battle.attack();
    }
    else
        std::cout << gotoxy.pos(43, 4) << "\033[40;1m" << TXT_RED_124
                  << "No tiene suficiente energia para atacar" << END_COLOR;

}

void Simulation::checkHealths(int playerNumber) {

    List<Being*> * characters;
    playerNumber == 1 ? characters = playerOne->getCharacters() : characters = playerTwo->getCharacters();
    int counter = 1;
    while(characters -> hasNext()){
        Being * current = characters -> getNext() -> getData();
        int currentRow = current -> getRow();
        int currentCol = current -> getCol();
        if( current -> getHealth() <= 0) {
            characters -> erase(counter);
            delete current;
            map -> getMatrix() -> getData(currentRow, currentCol) -> setBeing(nullptr);
        }
        counter++;
    }
    characters -> reset();
}

void Simulation::playerDefend(Being *being, int playerNumber) {
    battle.selectBeing(being -> getRow(), being -> getCol());
    List<Being*>* auxCharacters = playerOne -> getCharacters();
    if(being -> checkDefenseEnergy()){
        if(playerNumber == 2)
            auxCharacters = playerTwo -> getCharacters();
        battle.defend(auxCharacters);
    }
    else{
        std::cout << gotoxy.pos(43, 4) << "\033[40;1m" << TXT_RED_124
                  << "No tiene suficiente energía para defender" << END_COLOR;
    }

}

void Simulation::generateFreeItemsList(List<Element*>* freeItems) {
    for( int i = 0; i < map->getHeight(); i++ ){
        for( int j = 0; j < map->getWidth(); j++ ){
            if ( map->getMatrix()->getData(i, j)->getElement()){
                freeItems -> insert(map->getMatrix()->getData(i, j)->getElement());
            }
        }
    }
    freeItems -> reset();
}

void Simulation::saveGame(int playerNumber) {

    List<Element*> *freeItems = new List<Element*> ;
    generateFreeItemsList(freeItems);

    SaveGameFile saveGameFile;

    saveGameFile.openOutputFile("partida.txt");
    playerOne->getCharacters()->reset();
    playerTwo->getCharacters()->reset();

    saveGameFile.writeGameStatus(playerNumber, playerOne, playerTwo, freeItems);
    saveGameFile.closeOutputFile();
    delete freeItems;
}

void Simulation::loadSavedGame() {
    SaveGameFile savedGameFile;
    savedGameFile.openFile("partida.txt");
    savedGameFile.readFile(map, playerOne, playerTwo);
    savedGameFile.closeFile();

    this ->setSavedPlayer( savedGameFile.getSavedPlayer() );

}

void Simulation::endGame() {

    if(playerOne -> getCharacters() -> isEmpty()){
        this -> showWinner(playerTwo -> getTeam());
        exitSimulation = true;
        remove("partida.txt");
    }
    else if(playerTwo -> getCharacters()-> isEmpty()){
        this -> showWinner(playerOne -> getTeam());
        exitSimulation = true;
        remove("partida.txt");
    }
}

void Simulation::showWinner(int winnerTeam) {
    printer.mainWindow();
    if( winnerTeam == HUMANS )
        printer.humanVictory();
    else
        printer.monsterVictory();
}



