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
    std::cout << " ----- INVENTARIO ----- " << std::endl;

    int indexNumber = 1;

    while (items -> hasNext()) {
        Element* currentItem = items -> getNext() -> getData();

        std::string currentName = currentItem -> getObjectName();

        std::cout << "[" << indexNumber << "]" <<" Item: "<< currentName << std::endl;

        if (currentName ==  HOLYWATERUPPER || currentName == BULLETUPPER) {
            std::cout << "Cantidad: " << currentItem -> getAmount() << std::endl;
        }

        std::cout << std::endl;
        indexNumber++;
    }

    items -> reset();

    std::cout << " ---------------------- " << std::endl;
}

bool Inventory::isShotgunUsable() {
    return (this -> findBullets() >= 2);
}

void Inventory::removeItemAmount(Element * currentItem, std::string name, int itemCounter) {
    // Sino anda porque no teine el metodo, hay que castear a agua o bala. Lauty sabe como hacerlo.
    if (name == HOLYWATERUPPER && currentItem -> getAmount() != 1)
        currentItem -> setAmount(currentItem -> getAmount() - 1);

    // Si la bala es 1, no va a poder usar la escopeta, entonces nunca llegaria a este metodo.
    else if (name == BULLETUPPER && currentItem -> getAmount() != 2)
        currentItem -> setAmount(currentItem -> getAmount() - 2);

    else {
        delete currentItem;
        items -> erase(itemCounter);
    }
}

void Inventory::removeItem(std::string name) {

    //OJO CON EL ITEMCOUNT Y LOS PUNTEROS AAAAAAAAAAAAAA. (CHECK)?

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
    //    items->reset();
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
//    items->reset();
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
    return bulletAmount;
}

Inventory::~Inventory() {
    while (this -> itemAmount != 0 && items -> hasNext()) {
        delete (this -> items -> getNext() -> getData());
        itemAmount--;
    }

    delete items;
}

