#include "Hunter.h"

Hunter::Hunter() : Human() {
    sf::Texture texture;
    texture.loadFromFile("Hunter.png");

    this -> texture = texture;


    this -> objectName = HUNTER_CAPITALIZED;
    this -> objectCharName = 'H';
    this -> costType = HUNTER_COST;
    this -> team = HUMANS;
}

void Hunter::show() {
    std::cout << "Raza: " << characterType << std::endl;
    std::cout << "Tipo: " << humanType << std::endl;
}

void Hunter::addTurnEnergy() {
    this -> energy += 8;
}
/*
std::string Hunter::getObjectName() {
    return humanType;
}*/

bool Hunter::grabElement(Element *item) {
    this -> inventory -> addItem(item);

    return true;
}

void Hunter::pickItem() {
    // QUITAR INGRESO DE OPTION USAR CLASE VALIDATIONS.

    int pickedOption = 0;

    this -> inventory -> showInventory();

    std::cout << "Ingrese una opcion del 1 al " << this -> inventory -> getItems() -> getLength() << std::endl;
    std::cin >> pickedOption;
    if (*(this -> inventory -> getItems() -> getData(pickedOption)) == SHOTGUNUPPER) {
        if (this -> inventory -> isShotgunUsable()) {
            std::cout << "Podes usar la escopeta pa" << std::endl; // QUITAR PA.
        }
    }

    else {
        std::cout << "Podes usar: " << this -> inventory -> getItems() -> getData(pickedOption) -> getObjectName() << std::endl;
    }
}

void Hunter::attack(Being *&target, Element *weapon) {
    Identidentifier ident;
    if ( ident.isZombie(target) && ! target -> isProtected())
    {
        this->attackZombie(target, weapon, 1.05, 0.2);
    }
    else if (ident.isVampire(target) || ident.isNosferatu(target))
    {
        this ->attackVampire(target, weapon);
    }
    else if ( ident.isVampirella(target) )
    {
        this -> attackVampirella(target, weapon);
    }

    this -> addEnergy(-6);
}

void Hunter::attackZombie(Being *&target, Element *weapon, float withShotgun, float withStake) {
    Identidentifier ident;
    if (ident.isShotgun(weapon))
        target->receiveDamage( (this -> strength) * withShotgun );
    else if (ident.isStake(weapon))
        target->receiveDamage((this->strength) * withStake);
}

void Hunter::attackVampire(Being *&target, Element *weapon) {
    Identidentifier ident;
    if (ident.isShotgun(weapon))
        target -> receiveDamage( (this -> strength)*0.3 );
    else if (ident.isStake(weapon))
        target -> receiveDamage(60);
    else
        //con agua bendita
        target -> receiveDamage( 10 );
}

void Hunter::attackVampirella(Being *&target, Element *weapon) {
    Identidentifier ident;
    if (ident.isShotgun(weapon))
        target -> receiveDamage( (this -> strength)*0.3 );
    else if (ident.isStake(weapon) && ! target -> isProtected())
        target -> receiveDamage(60);

    else if ( ! target -> isProtected())
        //con agua bendita
        target -> receiveDamage( 10 );
}

short int Hunter::defense() {
    this -> addEnergy(-5);

    short int option;

    std::cout << "¿Qué querés hacer?" << std::endl;
    std::cout << "\t["<< SELFHEAL <<"] Curarte a ti mismo con +50 vida" << std::endl;
    std::cout << "\t[" << HEALOTHERS << "] Curar a tus aliados con +20 vida" << std::endl;
    std::cout << "\t>> ";
    std::cin >> option;

    return option;
}

void Hunter::selfHeal() {
    this -> addHealth(50);
}

bool Hunter::isProtected(){
    return false;
}