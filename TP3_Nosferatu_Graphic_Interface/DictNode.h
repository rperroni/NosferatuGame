#ifndef DICTNODE_H
#define DICTNODE_H

#include "Object.h"


class DictNode {

private:

    int ID;
    Object* object;
    DictNode* left; //Left children
    DictNode* right; //Right children
    DictNode* parent;


public:
    // CONSTRUCTORES
    DictNode(Object* obj);

    DictNode();

    // PRE:
    // POST:
    Object* getObject();

    // PRE:
    // POST:
    int getID();

    // PRE:
    // POST:
    void setObject(Object* obj);

    // PRE:
    // POST:
    void setRight(DictNode* right, DictNode* parent);

    // PRE:
    // POST:
    void setLeft(DictNode* left, DictNode* parent);

    // PRE:
    // POST:
    void setRight(DictNode* right);

    // PRE:
    // POST:
    void setLeft(DictNode* left);

    // PRE:
    // POST:
    void setParent(DictNode* parent);

    // PRE:
    // POST:
    DictNode* getRight();

    // PRE:
    // POST:
    DictNode* getLeft();

    // PRE:
    // POST:
    DictNode* getParent();

    // PRE:
    // POST:
    bool isLeaf();

    // PRE:
    // POST:
    bool rightChildOnly();

    // PRE:
    // POST:
    bool leftChildOnly();

    // PRE:
    // POST:
    ~DictNode();
};




#endif //DICTNODE_H
