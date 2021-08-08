#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "List.h"
#include "Element.h"
#include "constantsNames.h"

class Inventory {

private:

    // ATRIBUTOS
    Gotoxy gotoxy;
    List<Element*>* items;
    int itemAmount;

public:

    // METODOS

    // CONSTRUCTOR
    Inventory();

    // PRE: Ingresa un elemento
    // POST: Devuelve true en caso de tenerlo dentro del inventario
    bool isInInventory(Element* item);

    // PRE: Ingresa un nombre
    // POST: Devuelve true en caso de tenerlo dentro del inventario
    bool isInInventory(std::string itemName);

    // PRE: --
    // POST: Muestra el inventario
    void showInventory();

    // PRE: --
    // POST: Devuelve true en caso de tener escopeta y 2 balas para poder usarla
    bool isShotgunUsable();

    // PRE: --
    // POST: Devuelve la lista de items del inventario
    List<Element *> * getItems();

    // PRE: --
    // POST: Devuelve la cantidad de balas
    int findBullets();

    // PRE: --
    // POST: Usa balas del inventario
    void useBullets();

    // PRE: Ingresa el nombre y la cantidad usada
    // POST: Usa dicho item y realiza las modificaciones en el inventario
    void useItem(std::string itemName, int amountUsed);

    // PRE: Ingresa un elemento
    // POST: Agrega el elemento al inventario
    void addItem(Element * item);

    // PRE: Ingresa un nombre
    // POST: Elimina dicho elemento con ese nombre del inventario
    void removeItem(std::string name);

    // DESTRUCTOR
    ~Inventory();

private:

    // PRE: Ingresa el item, el nombre y la cantidad
    // POST: Elimina la cantidad de dicho item
    void removeItemAmount(Element * currentItem, std::string name, int itemCounter);

};


#endif //GRAFOS_INVENTORY_H
