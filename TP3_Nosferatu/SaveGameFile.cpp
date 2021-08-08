#include "SaveGameFile.h"

int SaveGameFile::getSavedPlayer() {
    return this -> savedPlayer;
}

bool SaveGameFile::openOutputFile(std::string fileName) {
    outputFile.open(fileName, std::ios::out);
    return (outputFile.is_open());
}

void SaveGameFile::closeOutputFile() {
    outputFile.close();
}

void SaveGameFile::writeGameStatus(int playerNumber, Player *playerOne, Player *playerTwo, List<Element*>* items) {
    outputFile << playerNumber << endl;
    this -> writePlayerStatus(playerOne);
    this -> writePlayerStatus(playerTwo);
    this -> writeItems(items);
}

void SaveGameFile::writePlayerStatus(Player *player) {
    outputFile << teams[player->getTeam()-1] << " " << player->getCharacters()->getLength() << endl;
    while( player->getCharacters()->hasNext() )
    {
        this -> writeCharacterInfo( player->getCharacters()->getNext()->getData() );
    }

}

void SaveGameFile::writeCharacterInfo(Being *character) {
    outputFile << character -> getObjectName() << " ";
    outputFile << character -> getId() << " ";
    outputFile << character -> getArmor() << " ";
    outputFile << character -> getStrength() << " ";
    outputFile << character -> getHealth() << " ";
    outputFile << character -> getEnergy() << " ";
    outputFile << character -> getRow() << " ";
    outputFile << character -> getCol() << " ";

    this -> writeInventoryInfo( character -> getInventory() );
    outputFile << endl;
}

void SaveGameFile::writeInventoryInfo(Inventory* inventory)
{
    Element* item;
    int itemAmount;
    Identifier ident;

    int holyWaterAmount = 0, crossAmount = 0, stakeAmount = 0, shotgunAmount = 0, bulletAmount = 0;

    while (inventory -> getItems() -> hasNext() )
    {
        item = inventory -> getItems() -> getNext() -> getData();
        itemAmount = item -> getAmount();
        if( ident.isHolyWater(item) )
            holyWaterAmount = itemAmount;
        else if ( ident.isCross(item) )
            crossAmount = itemAmount;
        else if ( ident.isStake(item) )
            stakeAmount = itemAmount;
        else if ( ident.isShotgun(item) )
            shotgunAmount = itemAmount;
        else // is bullet
            bulletAmount = itemAmount;
    }

    outputFile << holyWaterAmount << " ";
    outputFile << crossAmount << " ";
    outputFile << stakeAmount << " ";
    outputFile << shotgunAmount << " ";
    outputFile << bulletAmount << " ";
}

void SaveGameFile::writeItems(List<Element *> *items) {
    outputFile << "Items " << items -> getLength();
    Element* item;
    while( items->hasNext() )
    {
        outputFile << endl;
        item = items -> getNext() -> getData();
        outputFile << item -> getObjectName() << " ";
        outputFile << item -> getId() << " ";
        outputFile << item -> getAmount() << " ";
        outputFile << item -> getRow() << " ";
        outputFile << item -> getCol();
    }
}

void SaveGameFile::readFile(Map *&map, Player *&playerOne, Player *&playerTwo) {
    while( !inputFile.eof() )
    {
        inputFile >> savedPlayer;
        this -> readPlayerStatus(map, playerOne);
        this -> readPlayerStatus(map, playerTwo);
        this ->readFreeItems(map);
    }

}

void SaveGameFile::readPlayerStatus(Map *&map, Player *&player) {
    getline(inputFile, team, ' ');
    getline(inputFile, charactersAmount, '\n');

    int playerTeam;
    if( team == teams[HUMANS-1] )
        playerTeam = HUMANS;
    else
        playerTeam = MONSTERS;

    player -> setTeam(playerTeam);

    for( int i = 0; i < stoi(charactersAmount); i++)
    {
        getline(inputFile, characterName, ' ');
        getline(inputFile, characterId, ' ');
        getline(inputFile, characterArmor, ' ');
        getline(inputFile, characterStrength, ' ');
        getline(inputFile, characterHealth, ' ');
        getline(inputFile, characterEnergy, ' ');
        getline(inputFile, characterRow, ' ');
        getline(inputFile, characterCol, ' ');
        getline(inputFile, holyWaterAmount, ' ');
        getline(inputFile, crossAmount, ' ');
        getline(inputFile, stakeAmount, ' ');
        getline(inputFile, shotgunAmount, ' ');
        getline(inputFile, bulletAmount, '\n');

        this -> loadSavedBeing(map, player);
    }
}

void SaveGameFile::loadSavedBeing(Map *&map, Player *&player) {
    Identifier ident;
    Being* being;

    if (ident.isVanesa(stoi(characterId))) {
        if (characterName != ZOMBIE_CAPITALIZED && characterName != VAMPIRE_CAPITALIZED)
            being = this->objectCreator->createBeing<Vanesa>();
        else if (characterName == ZOMBIE_CAPITALIZED)
            being = this->objectCreator->createBeing<Zombie>();
        else
            being = this->objectCreator->createBeing<Vampire>();
    }
    else if (ident.isHuman(stoi(characterId))){
        if(characterName != ZOMBIE_CAPITALIZED && characterName != VAMPIRE_CAPITALIZED)
            being = this->objectCreator->createBeing<Human>();
        else if (characterName == ZOMBIE_CAPITALIZED)
            being = this->objectCreator->createBeing<Zombie>();
        else
            being = this->objectCreator->createBeing<Vampire>();
    }

    else if (ident.isHunter(stoi(characterId))){
        if(characterName != ZOMBIE_CAPITALIZED && characterName != VAMPIRE_CAPITALIZED)
            being = this->objectCreator->createBeing<Hunter>();
        else if (characterName == ZOMBIE_CAPITALIZED)
            being = this->objectCreator->createBeing<Zombie>();
        else
            being = this->objectCreator->createBeing<Vampire>();
    }

    else if( ident.isZombie(stoi(characterId)) )
        being = this -> objectCreator -> createBeing<Zombie>();

    else if( ident.isNosferatu(stoi(characterId)) )
        being = this -> objectCreator -> createBeing<Nosferatu>();

    else if( ident.isVampirella(stoi(characterId)) )
        being = this -> objectCreator -> createBeing<Vampirella>();

    else if( ident.isVampire(stoi(characterId)) )
        being = this -> objectCreator -> createBeing<Vampire>();


    being -> setId(stoi(characterId));
    being -> setArmor(stoi(characterArmor));
    being -> setStrength(stoi(characterStrength));
    being -> setHealth(stoi(characterHealth));
    being -> setEnergy(stoi(characterEnergy));
    being -> setRow(stoi(characterRow));
    being -> setColumn(stoi(characterCol));

    this -> loadBeingInventory(being);

    map -> loadBeing(stoi(characterRow), stoi(characterCol), being);

    player -> addCharacter(being);
}

void SaveGameFile::loadBeingInventory(Being *&being) {
    Element* element;

    if ( stoi(holyWaterAmount) != 0) {
        element = this -> objectCreator -> createElement<HolyWater>(stoi(holyWaterAmount));
        being -> getInventory() -> addItem(element);
    }
    if( stoi(crossAmount) != 0 ) {
        element = this -> objectCreator -> createElement<Cross>(stoi(crossAmount));
        being -> getInventory() -> addItem(element);
    }
    if( stoi(shotgunAmount) != 0 ) {
        element = this -> objectCreator -> createElement<Shotgun>(stoi(shotgunAmount));
        being -> getInventory() -> addItem(element);
    }
    if( stoi(bulletAmount) != 0 ){
        element = this -> objectCreator -> createElement<Bullet>(stoi(bulletAmount));
        being -> getInventory() -> addItem(element);
    }

    if(stoi(stakeAmount) != 0) {
        element = this -> objectCreator -> createElement<Stake>(stoi(stakeAmount));
        being -> getInventory() -> addItem(element);
    }

}

void SaveGameFile::readFreeItems(Map *&map){
    getline(inputFile, aux, ' ');
    getline(inputFile, itemsAmount, '\n');

    for(int i = 0; i < stoi(itemsAmount); i++){
        getline(inputFile, itemName, ' ');
        if( itemName == "Agua" ) {
            getline(inputFile, aux, ' ');
        }
        getline(inputFile, itemId, ' ');
        getline(inputFile, itemAmount, ' ');
        getline(inputFile, itemRow, ' ');
        getline(inputFile, itemCol, '\n');

        this -> loadElement(map);
    }
}

void SaveGameFile::loadElement(Map *&map) {
    Identifier ident;
    Element* element;

    if ( ident.isHolyWater(stoi(itemId)) )
        element = this -> objectCreator -> createElement<HolyWater>(stoi(itemAmount));

    else if( ident.isCross(stoi(itemId)) )
        element = this -> objectCreator -> createElement<Cross>(1);

    else if( ident.isShotgun(stoi(itemId)) )
        element = this -> objectCreator -> createElement<Shotgun>(1);

    else if( ident.isBullet(stoi(itemId)) )
        element = this -> objectCreator -> createElement<Bullet>(stoi(itemAmount));

    else if( ident.isStake(stoi(itemId)) )
        element = this -> objectCreator -> createElement<Stake>(1);

    element -> setId(stoi(itemId));
    element -> setRow(stoi(itemRow));
    element -> setColumn(stoi(itemCol));

    map -> loadElement(stoi(itemRow), stoi(itemCol), element);
}
