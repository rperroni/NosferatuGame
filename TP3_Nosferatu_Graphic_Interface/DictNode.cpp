#include "DictNode.h"

DictNode::DictNode(Object *obj) {

    this -> object = obj;
    this -> ID = obj->getId();
    this -> left = nullptr;
    this -> right = nullptr;
    this -> parent = nullptr;
}

Object *DictNode::getObject() {

    return ( this -> object);

}

int DictNode::getID() {

    return ( this -> ID );

}

void DictNode::setObject(Object *obj) {

    this -> object = obj;

}

void DictNode::setRight(DictNode *right, DictNode *parent) {

    this -> right = right;
    this -> parent = parent;

}

void DictNode::setLeft(DictNode *left, DictNode *parent) {

    this -> left = left;
    this -> parent = parent;

}

void DictNode::setLeft(DictNode *left) {
    this -> left = left;
}

void DictNode::setRight(DictNode *right) {
    this -> right = right;
}

void DictNode::setParent(DictNode *parent) {
    this -> parent = parent;
}

DictNode *DictNode::getRight() {
    return ( this -> right );
}

DictNode *DictNode::getLeft() {
    return ( this -> left );
}

DictNode *DictNode::getParent() {
    return ( this -> parent );
}

bool DictNode::isLeaf() {

    return ( this->getLeft() == nullptr && this->getRight() == nullptr );

}

bool DictNode::rightChildOnly() {

    return ( this->getLeft() == nullptr && this->getRight() != nullptr );

}

bool DictNode::leftChildOnly() {

    return ( this->getLeft() != nullptr && this->getRight() == nullptr );

}

DictNode::~DictNode() {}
