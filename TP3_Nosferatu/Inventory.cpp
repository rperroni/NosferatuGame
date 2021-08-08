#include "Inventory.h"
#include "HolyWater.h"
Inventory::Inventory() {
    this -> items = new List<Element*>;
    this -> itemAmount = 0;
}

void Inventory::addItem(Element* item) {

    if (isInInventory(item)) {
        *(this -> items -> getCurrent() -> getData()) += item;
        delete item;
    }

    else
        this -> items -> insert(item);

    this -> items -> reset();
    this -> itemAmount++;
}

void Inventory::showInventory() {

    std::cout << gotoxy.pos(29,75) << "\033[40;1m" << " ~ INVENTARIO ~ " << std::endl;
    int indexNumber = 1;

    while (items -> hasNext()) {

        Element* currentItem = items -> getNext() -> getData();
        std::string currentName = currentItem -> getObjectName();
        std::cout << gotoxy.pos(29 + indexNumber*2,75) << "\033[40;1m" << "[" << indexNumber << "] " << currentName << std::endl;

        if (currentName ==  HOLYWATER_CAPITALIZED)
            std::cout << gotoxy.pos(29 + indexNumber*2,93) << "\033[40;1m" << currentItem -> getAmount() << std::endl;
        else if(currentName == BULLET_CAPITALIZED)
            std::cout << gotoxy.pos(29 + indexNumber*2,85) << "\033[40;1m" << currentItem -> getAmount() << std::endl;

        std::cout << std::endl;
        indexNumber++;
    }

    items -> reset();

}

bool Inventory::isShotgunUsable() {
    return ( (this -> isInInventory(SHOTGUNUPPER)) && (this -> findBullets() >= 2) );
}

void Inventory::removeItemAmount(Element * currentItem, std::string name, int itemCounter) {

    if (name == HOLYWATERUPPER && currentItem -> getAmount() != 1)
        currentItem -> setAmount(currentItem -> getAmount() - 1);

    else if (name == BULLETUPPER && currentItem -> getAmount() != 2)
        currentItem -> setAmount(currentItem -> getAmount() - 2);

    else {
        delete currentItem;
        items -> erase(itemCounter);
    }

    items -> reset();
}

void Inventory::removeItem(std::string name) {

    int itemCounter = 1;
    bool isFound = false;

    while (!isFound && items -> hasNext()) {

        Element * currentItem = items -> getNext() -> getData();

        if (currentItem -> getObjectName() == name) {

            if (name == HOLYWATERUPPER || name == BULLETUPPER)
                removeItemAmount(currentItem, name, itemCounter);

            else {
                delete currentItem;
                items -> erase(itemCounter);
            }
            isFound = true;
        }
        else
            itemCounter++;
    }
    items -> reset();
}

bool Inventory::isInInventory(Element *item) {

    bool inInventory = false;
    while ( !inInventory && items -> hasNext()) {

        if (*(items -> getCurrent() -> getData())  == item)
            inInventory = true;

        else
            items -> getNext();
    }
    items->reset();
    return inInventory;
}

bool Inventory::isInInventory(std::string itemName) {
    bool inInventory = false;
    while ( !inInventory && items -> hasNext()) {

        if (*(items -> getCurrent() -> getData()) == itemName)
            inInventory = true;

        else
            items -> getNext();
    }
    items->reset();
    return inInventory;
}

List<Element *> *Inventory::getItems(){
    return items;
}

int Inventory::findBullets() {
    bool isBullet = false;
    int bulletAmount;
    while ( !isBullet && this -> items -> hasNext() ) {

        Element* currentItem = this -> items -> getNext() -> getData();

        if ( *(currentItem) == BULLETUPPER) {
            bulletAmount = currentItem -> getAmount();
            isBullet = true;
        }
    }
    items -> reset();
    return bulletAmount;
}

Inventory::~Inventory() {
    items -> reset();

    while (this -> itemAmount != 0 && items -> hasNext()) {
        delete (this -> items -> getNext() -> getData());
        itemAmount--;
    }

    delete items;
}

void Inventory::useBullets() {
    bool isBullet = false;
    int auxAmount;
    while ( !isBullet && this -> items -> hasNext() ) {

        Element* currentItem = this -> items -> getNext() -> getData();

        if ( *(currentItem) == BULLETUPPER) {
            auxAmount = currentItem -> getAmount();
            currentItem -> setAmount(auxAmount - 2);
            isBullet = true;
        }
    }
    items -> reset();
}

void Inventory::useItem(std::string itemName, int amountUsed) {
    bool isItem = false;
    int auxAmount;
    while ( !isItem && this -> items -> hasNext() ) {

        Element* currentItem = this -> items -> getNext() -> getData();

        if ( *(currentItem) == itemName) {
            auxAmount = currentItem -> getAmount();
            currentItem -> setAmount(auxAmount - amountUsed);
            isItem = true;
        }
    }
    items -> reset();
}

