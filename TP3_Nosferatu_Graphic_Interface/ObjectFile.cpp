#include "ObjectFile.h"


void ObjectFile::readFile(Map* &map, Dictionary &dict) {
    getline(inputFile, trash);
    while(!inputFile.eof()) {
        separateString();
        loadObject(map, dict);
        if (!inputFile){
            kindObject = "";
        }
    }
}

void ObjectFile::separateString() {

    getline(inputFile, kindObject, ' ');
    getline(inputFile,amount,'(');
    if (amount == "CV "){
        kindObject = "humano CV";
        amount = "";
    }
    else if (amount == " " )
        amount = "";
    getline(inputFile, row, ',');
    getline(inputFile, column, ')');
    getline(inputFile,trash,' ');
    getline(inputFile,id,'\n');

}

void ObjectFile::loadObject(Map *&map, Dictionary &dict) {

    Identidentifier ident;
    if ( ident.isBeing(stoi(id)) ) {
        this ->loadBeing(map, dict);
    }
    else if( ident.isElement(stoi(id)) ){
        this -> loadElement(map, dict);
    }
}

void ObjectFile::loadBeing(Map *&map, Dictionary &dict) {
    Identidentifier ident;
    Being* being;

    if ( ident.isVanesa(stoi(id)) )
        being = this -> objectCreator -> createBeing<Vanesa>();

    else if( ident.isHuman(stoi(id)) )
        being = this -> objectCreator -> createBeing<Human>();

    else if( ident.isHunter(stoi(id)) )
        being = this -> objectCreator -> createBeing<Hunter>();

    else if( ident.isZombie(stoi(id)) )
        being = this -> objectCreator -> createBeing<Zombie>();

    else if( ident.isNosferatu(stoi(id)) )
        being = this -> objectCreator -> createBeing<Nosferatu>();

    else if( ident.isVampirella(stoi(id)) )
        being = this -> objectCreator -> createBeing<Vampirella>();

    else if( ident.isVampire(stoi(id)) )
        being = this -> objectCreator -> createBeing<Vampire>();

    being -> setId(stoi(id));
    map -> loadBeing(stoi(row), stoi(column), being);
    dict.insert(being);
}

void ObjectFile::loadElement(Map *&map, Dictionary &dict) {
    Identidentifier ident;
    Element* element;

    if ( ident.isHolyWater(stoi(id)) )
        element = this -> objectCreator -> createElement<HolyWater>(stoi(amount));

    else if( ident.isCross(stoi(id)) )
        element = this -> objectCreator -> createElement<Cross>(1);

    else if( ident.isShotgun(stoi(id)) )
        element = this -> objectCreator -> createElement<Shotgun>(1);

    else if( ident.isBullet(stoi(id)) )
        element = this -> objectCreator -> createElement<Bullet>(stoi(amount));

    else if( ident.isStake(stoi(id)) )
        element = this -> objectCreator -> createElement<Stake>(1);

    element -> setId(stoi(id));
    map -> loadElement(stoi(row), stoi(column), element);
    dict.insert(element);
}

