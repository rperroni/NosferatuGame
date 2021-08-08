#ifndef _DICTNODE_H_
#define _DICTNODE_H_

#include "Object.h"

class DictNode {

private:

    // ATRIBUTOS

    int ID;
    Object* object;
    DictNode* left;
    DictNode* right;
    DictNode* parent;


public:

    // METODOS

    // CONSTRUCTOR CON PARAMETOS
    DictNode(Object* obj);

    // CONSTRUCTOR SIN PARAMETROS
    DictNode();

    // PRE: --
    // POST: Devuelve el dato
    Object* getObject();

    // PRE: --
    // POST: Devuelve el ID
    int getID();

    // PRE: Ingresa el objeto
    // POST: Setea el objeto en el nodo
    void setObject(Object* obj);

    // PRE: Ingresa el nodo y su antecesor
    // POST: Setea el nodo a la derecha y su antecesor
    void setRight(DictNode* right, DictNode* parent);

    // PRE: Ingresa el nodo y su antecesor
    // POST: Setea el nodo a la izquierda y su antecesor
    void setLeft(DictNode* left, DictNode* parent);

    // PRE: Ingresa un nodo
    // POST: Setea es nodo a la derecha
    void setRight(DictNode* right);

    // PRE: Ingresa un nodo
    // POST: Setea el nodo a la izquierda
    void setLeft(DictNode* left);

    // PRE: Ingresa un nodo
    // POST: Setea el nodo como su antecesor
    void setParent(DictNode* parent);

    // PRE: --
    // POST: Devuelve el nodo derecho
    DictNode* getRight();

    // PRE: --
    // POST: Devuelve el nodo izquierdo
    DictNode* getLeft();

    // PRE: --
    // POST: Devuelve el antecesor
    DictNode* getParent();

    // PRE: --
    // POST: Devuelve true en caso de no tener nodos hijos
    bool isLeaf();

    // PRE: --
    // POST: Devuelve true en caso de tener solo hijo derecho
    bool rightChildOnly();

    // PRE: --
    // POST: Devuelve true en caso de tener solo hijo izquierdo
    bool leftChildOnly();

    // DESTRUCTOR
    ~DictNode();
};




#endif //_DICTNODE_H
