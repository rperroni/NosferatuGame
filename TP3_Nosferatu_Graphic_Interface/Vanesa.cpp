#include "Vanesa.h"

Vanesa::Vanesa() : Hunter() {
    sf::Texture texture;
    texture.loadFromFile("Vanesa.png");

    this -> texture = texture;


    this -> objectCharName = 'W';
    this -> objectName = VANESA_CAPITALIZED;
    this -> costType = HUNTER_COST;
    this -> team = HUMANS;
    this -> crossDefended = false;
}

void Vanesa::show() {
    std::cout << "Raza: " << characterType << std::endl;
    std::cout << "Tipo: " << humanType << std::endl;
    std::cout << "Nombre: " << vampireHunterName << std::endl;
}

void Vanesa::addTurnEnergy() {
    this -> energy += 10;
}

bool Vanesa::grabElement(Element *item) {
    this -> inventory -> addItem(item);

    return true;
}

void Vanesa::attack(Being *&target, Element *weapon) {
    Identidentifier ident;
    if ( ident.isZombie(target) && ! target -> isProtected() )
    {
        this -> attackZombie(target, weapon, 1.25, 0.25);
    }
    else if (ident.isVampire(target) || ident.isNosferatu(target))
    {
        this -> attackVampire(target, weapon);
    }
    else if ( ident.isVampirella(target) )
    {
        this -> attackVampirella(target, weapon);
    }

    this -> addEnergy(-6);
}

void Vanesa::attackVampire(Being *&target, Element *weapon) {
    Identidentifier ident;
    if (ident.isShotgun(weapon))
        target -> receiveDamage( (this -> strength) * 0.4);
    else if (ident.isStake(weapon))
        target -> killBeing();
    else
        //con agua bendita
        target -> receiveDamage( 20 );
}

void Vanesa::attackVampirella(Being *&target, Element *weapon) {
    Identidentifier ident;
    if (ident.isShotgun(weapon))
        target -> receiveDamage( (this -> strength) * 0.4);
    else if (ident.isStake(weapon) && ! target -> isProtected() )
        target -> killBeing();
    else if( ! target -> isProtected() )
        //con agua bendita
        target -> receiveDamage( 20 );
}

short int Vanesa::defense() {
    // Hay que preguntarle cual quiere usar, ver bien las condiciones
    short int option = 0;
    this -> addEnergy(-10);
    if( this -> inventory -> isInInventory(HOLYWATERUPPER) )
        option = HEALOTHERS;
    //preguntar si quiere hacer cada cosa
    if( this -> inventory -> isInInventory(CROSSUPPER) )
        this -> crossDefended = true;
    if( !( this -> inventory -> isInInventory(CROSSUPPER) && !this -> inventory -> isInInventory(HOLYWATERUPPER)) )
        this -> selfHeal();
    return option;
}

void Vanesa::selfHeal() {
    this -> addHealth(10);
}

bool Vanesa::isProtected() {
    return crossDefended;
}
