#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "DictNode.h"
#include "Object.h"


class Dictionary {
private:

    DictNode* root;

public:
    // CONSTRUCTOR
    Dictionary();

    // DESTRUCTOR
    ~Dictionary();

    // PRE:
    // POST:
    void insert(Object* obj);

    // PRE: recibe un id entre 0 y 999
    // POST: devuelve true si el ID se encuentra en el diccionario
    bool search(int ID);

    // PRE: recibe un id entre 0 y 999
    // POST: devuelve el objeto que tiene el ID si lo tiene, si no devuelve null
    Object* find(int ID);

    // Finds the minimum value that exist in the BST.
    // PRE:
    // POST:
    Object* findMin();

    // Finds the maximum value that exist in the BST.
    // PRE:
    // POST:
    Object* findMax();

    // Finds the successor of a given data value.
    // PRE:
    // POST:
    Object* successor(int ID);

    // Finds the predecessor of a given data value.
    // PRE:
    // POST:
    Object* predecessor(Object* obj);

    // PRE:
    // POST:
    void deleteAll();

    // PRE:
    // POST:
    void remove(int ID);

private:

    DictNode* insert(DictNode* node, Object* obj);
    DictNode* search(DictNode* node, int ID);
    Object* findMin(DictNode* node);
    Object* findMax(DictNode* node);
    Object* successor(DictNode* node);
    Object* predecessor(DictNode* node);
    DictNode* remove(DictNode* node, int ID);
    void deleteAll(DictNode* node);
};


#endif //DICTIONARY_H
