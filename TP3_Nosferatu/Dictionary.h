#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include "DictNode.h"
#include "Object.h"

class Dictionary {
private:

    // ATRIBUTOS

    DictNode* root;

public:

    // METODOS

    // CONSTRUCTOR
    Dictionary();

    // DESTRUCTOR
    ~Dictionary();

    // PRE:
    // POST: Inserta un objeto en el diccionario
    void insert(Object* obj);

    // PRE: recibe un id entre 0 y 999
    // POST: devuelve true si el ID se encuentra en el diccionario
    bool search(int ID);

    // PRE: recibe un id entre 0 y 999
    // POST: devuelve el objeto que tiene el ID si lo tiene, si no devuelve null
    Object* find(int ID);

    // PRE:
    // POST: Encuentra el minimo del diccionario
    Object* findMin();

    // PRE:
    // POST: Encuentra el maximo del diccionario
    Object* findMax();

    // PRE: Recibe un ID entre 0 y 999
    // POST: Encuentra el sucesor del dato asociado al ID
    Object* successor(int ID);

    // PRE: Recibe un objeto
    // POST: Encuentra el predecesor del objeto en el diccionario
    Object* predecessor(Object* obj);

    // PRE:
    // POST: Libera la memoria de todos los nodos
    void deleteAll();

    // PRE: Recibe un ID entre 0 y 999
    // POST: Remueve el dato asociado al ID
    void remove(int ID);

private:

    // METODOS PRIVADOS
    // PRE: Ingresa un nodo y el objeto
    // POST: Ingresa el nodo en su posicion correspondiente
    DictNode* insert(DictNode* node, Object* obj);

    // PRE: Ingresa un nodo y su respectivo ID
    // POST: Devuelve el nodo siguiente en caso de no llegar al Id deseado
    DictNode* search(DictNode* node, int ID);


    Object* findMin(DictNode* node);

    // PRE: Ingresa un nodo
    // POST: Devuelve el siguiente para seguir buscando el de mayor valor
    Object* findMax(DictNode* node);
    Object* successor(DictNode* node);

    // PRE: Ingresa un nodo
    // POST: Devuelve su predecesor
    Object* predecessor(DictNode* node);
    DictNode* remove(DictNode* node, int ID);

    // PRE: Ingresa el nodo
    // POST: Borra sus conexiones
    void deleteAll(DictNode* node);

};


#endif //_DICTIONARY_H
