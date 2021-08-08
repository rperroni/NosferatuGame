#ifndef GRAFOS_INVENTORY_H
#define GRAFOS_INVENTORY_H
#include "List.h"
#include "Element.h"
#include "constantsNames.h"

class Inventory {
private:

    List<Element*>* items;
    int itemAmount;

public:

    Inventory();

    // Pasar a being.
    // void isGrabbable();

    bool isInInventory(Element* item);

    bool isInInventory(std::string itemName);

    void showInventory();

    bool isShotgunUsable();

    List<Element *> * getItems();

    int findBullets();

    void addItem(Element * item);

    void removeItem(std::string name);

    ~Inventory();

private:

    void removeItemAmount(Element * currentItem, std::string name, int itemCounter);

};


#endif //GRAFOS_INVENTORY_H
