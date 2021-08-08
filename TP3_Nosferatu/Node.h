#ifndef _NODE_H_
#define _NODE_H_

template <typename Data>

class Node {

private:
    // ATRIBUTOS
    Data data;
    Node<Data>* next;
    Node<Data>* previous;

public:
    // METODOS

    // CONSTRUCTOR
    Node(Data d);

    // PRE: -
    // POST: cambia el nodo siguiente por ps
    void changeNext(Node* ps);

    // PRE: -
    // POST: cambia el nodo anterior por ps
    void changePrevious(Node* ps);

    // PRE: -
    // POST: devuelve el nodo anterior
    Node* getPrevious();

    // PRE: -
    // POST: devuelve el nodo siguiente
    Node* getNext();

    // PRE: -
    // POST: devuelve el dato que contiene el nodo
    Data getData();

};

template <typename Data>
Node<Data>::Node(Data d) {
    data = d;
    next = 0;
    previous = 0;
}

template <typename Data>
void Node<Data>::changeNext(Node* ps) {
    next = ps;
}

template <typename Data>
void Node<Data>::changePrevious(Node* ps) {
    previous = ps;
}

template <typename Data>
Node<Data>* Node<Data>::getPrevious() {
    return previous;
}

template <typename Data>
Node<Data>* Node<Data>::getNext() {
    return next;
}

template <typename Data>
Data Node<Data>::getData() {
    return data;
}

#endif /* _NODE_H_ */
