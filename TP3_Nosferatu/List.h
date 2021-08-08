#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
#include <iostream>

template <typename Data>

class List {

private:
    // ATRBUTOS

    // NODOS LISTA COMUN
    Node<Data>* first;
    Node<Data>* last;
    Node<Data>* current;
    Node<Data>* previous;

    int length;

public:
    // CONSTRUCTOR
    // PRE: -
    // POST: crea una lista vacia
    List();

    // PRE: -
    // POST: inserta un nuevo elemento en la lista
    void insert(Data d);

    // PRE: -
    // POST: elimina el elemento de la posicion pos de la lista
    void erase(int pos);

    // PRE: -
    // POST: devuelve true si la lista está vacia
    bool isEmpty();

    // PRE: -
    // POST: devuelve el elemento que se encuentra en la posicion pos
    Data getData(int pos);

    // PRE: -
    // POST: devuelve la cantidad de elementos de la lista
    int getLength();

    // PRE: -
    // POST: devuelve true si el puntero actual no es null
    bool hasNext();

    // PRE: -
    // POST: devuelve true si el puntero anterior no es null
    bool hasPrevious();

    // PRE: -
    // POST: apunta el puntero actual al primer elemento de la lista
    void reset();

    // PRE: -
    // POST: devuelve el nodo actual y avanza
    Node<Data>* getNext();

    // PRE: -
    // POST: devuelve el nodo actual
    Node<Data>* getCurrent();

    // PRE: -
    // POST: avanza
    void goForward();

    // PRE: -
    // POST: devuelve el nodo anterior
    Node<Data>* getPrevious();

    // DESTRUCTOR
    ~List();

private:
    Node<Data>* getNode(int pos);
};

template <typename Data>
List<Data>::List() {
    first = nullptr;
    current = nullptr;
    length = 0;
    last = nullptr;
    previous = nullptr;
}

template <typename Data>
void List<Data>::insert(Data d){

    Node<Data>* newNode = new Node<Data>(d);
    /*if(length == 0)
        first = nullptr;*/
    if(first == nullptr){
        newNode->changeNext(first);
        first = newNode;
        current = first;
        last = current;
    }
    else{
        Node<Data>* previous = last;
        newNode->changeNext(previous->getNext());
        previous->changeNext(newNode);
        newNode->changePrevious(last);
        last = newNode;
    }
    length++;
}

template <typename Data>
void List<Data>::erase(int pos) {

    Node<Data>* erased = first;

    if (pos == 1)
        first = erased->getNext();
    else {
        Node<Data>* previous = getNode(pos - 1);
        erased = previous->getNext();
        previous->changeNext(erased->getNext());
    }
    length--;

    delete erased;
}

template <typename Data>
bool List<Data>::isEmpty() {
    return (length == 0);
}

template <typename Data>
Data List<Data>::getData(int pos) {
    Node<Data>* aux = getNode(pos);
    return aux->getData();
}

template <typename Data>
int List<Data>::getLength() {
    return (length);

}

template <typename Data>
bool List<Data>::hasNext() {
    return (current != nullptr);

}

template <typename Data>
bool List<Data>::hasPrevious() {
    return (previous != nullptr);

}

template <typename Data>
void List<Data>::reset() {

    current = first;
    previous = nullptr;

}

template <typename Data>
Node<Data>* List<Data>::getNext() {

    previous = current;
    Node<Data>* aux = current;
    current = current->getNext();

    return aux;

}

template <typename Data>
Node<Data>* List<Data>::getCurrent() {

    return current;
}

template <typename Data>
void List<Data>::goForward() {

    previous = current;
    current = current->getNext();

}

template <typename Data>
Node<Data>* List<Data>::getPrevious(){

    return previous->getPrevious();

}

template <typename Data>
List<Data>::~List() {
    while (!isEmpty()) {
        erase(1);
    }
}

template <typename Data>
Node<Data>* List<Data>::getNode(int pos) {
    Node<Data>* aux = first;
    for(int i = 1; i < pos; i++)
        aux = aux->getNext();
    return aux;
}

#endif