#include "Human.h"

Human::Human() : Being() {
    sf::Texture texture;
    texture.loadFromFile("Human.png");

    this -> texture = texture;


    this -> bitten = false;
    this -> objectCharName = 'h';
    this -> objectName = HUMAN_CAPITALIZED;
    this -> costType = HUMAN_COST;
    this -> team = HUMANS;
}

void Human::show() {
    std::cout << "Raza:" << characterType << std::endl;

}

/*std::string Human::getObjectName() {
    return characterType;
}*/

void Human::attack(Being *&target) {
    Identidentifier ident;
    if( ident.isZombie(target) /*&& ! ((Zombie*) target) -> isHidden()*/)
    {
        target->receiveDamage( this -> strength );
    }
    else if(ident.isVampire(target) ||
            ident.isVampirella(target) ||
            ident.isNosferatu(target))
    {
        target->receiveDamage((this->strength) * 0.2);
    }
    this->addEnergy(-5);
}

void Human::addTurnEnergy(){
    this -> energy += 5;
}

bool Human::grabElement(Element * item) {
    this -> inventory -> addItem(item);

    return true;
}

void Human::pickItem() {
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
}

short Human::defense() {
    return SELFHEAL;
}

void Human::selfHeal() {
    short int healOption;
    if ( this -> inventory -> isInInventory(HOLYWATERUPPER)){
        std::cout << "¿Qué querés hacer?" << std::endl;
        std::cout << "\t[1] Usar agua bendita y regenerar toda tu energía" << std::endl;
        std::cout << "\t[2] No usar el agua bendita y ganar +1 armadura por 1 turno" << std::endl;
        std::cout << "\t>> ";
        std::cin >> healOption;
        if( healOption == 1 ){
            this -> inventory -> removeItem(HOLYWATERUPPER);
            this -> energy = MAX_ENERGY;
        }
        else
            // Que le dure hasta terminar el turno del otro jugador. Despues se resta
            this->addArmor(1);
    }
    else {
        this->addEnergy(3);
    }
}

bool Human::isProtected() {
    return false;
}

bool Human::isBitten() {
    return bitten;
}

void Human::transform() {
    this -> bitten = true;
}

//
//bool Human::hasHolyWater() {
//    bool holyWaterFound = false;
//    while(inventory->hasNext() && !holyWaterFound)
//    {
//        if(inventorygetNext() -> getData() -> getObjectName() == "agua" )
//            holyWaterFound = true;
//    }
//    return holyWaterFound;
//}
