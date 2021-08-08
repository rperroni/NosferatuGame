#include "Dictionary.h"

Dictionary::Dictionary() {
    this -> root = nullptr;
}

Dictionary::~Dictionary() {
    this -> deleteAll();
}

void Dictionary::insert(Object* obj) {
    this -> root = insert(this -> root, obj);
}

bool Dictionary::search(int ID) {
    return (search(this -> root, ID) != nullptr);
}

Object* Dictionary::find(int ID) {
    return (search(this -> root, ID) -> getObject());
}

Object *Dictionary::findMin() {
    return findMin(this -> root);
}

Object *Dictionary::findMax() {
    return findMax(this -> root);
}

Object *Dictionary::successor(int ID) {

    DictNode* dataNode = this -> search(this -> root, ID);

    if(dataNode == nullptr)
        return nullptr;
    else
        return successor(dataNode);

}

Object *Dictionary::predecessor(Object *obj) {
    DictNode * dataNode = this -> search(this -> root, obj -> getId());

    if(dataNode == nullptr)
        return nullptr;

    else
        return predecessor(dataNode);

}

void Dictionary::remove(int ID) {
    this -> root = remove(this -> root, ID);
}


DictNode *Dictionary::insert(DictNode *node, Object* obj) {

    if (node == nullptr)
        node = new DictNode(obj);

    else if ( obj -> getId() > node -> getID() )
        node -> setRight( insert (node -> getRight(), obj ), node);

    else
        node -> setLeft(insert(node -> getLeft(), obj ), node);


    return node;

}

DictNode *Dictionary::search(DictNode *node, int ID) {

    if (node == nullptr || node -> getID() == ID)
        return node;

    if (ID > node -> getID())
        return search(node -> getRight(), ID);

    return search(node -> getLeft(), ID);
}

Object* Dictionary::findMin(DictNode *node) {

    if(node == nullptr)
        return nullptr;

    else if(node -> getLeft() == nullptr)
        return node -> getObject();

    else
        return findMin(node -> getLeft());

}

Object *Dictionary::findMax(DictNode *node) {

    if(node == nullptr)
        return nullptr;

    else if(node -> getRight() == nullptr)
        return node -> getObject();

    else
        return findMax(node -> getRight());

}

Object *Dictionary::successor(DictNode *node) {

    if (node -> getRight() != nullptr)
        return findMin(node -> getRight());

    DictNode* successor = nullptr;
    DictNode* ancestor = this -> root;

    while(ancestor != node) {

        if(node -> getID() < ancestor -> getID()) {
            successor = ancestor;
            ancestor = ancestor -> getLeft();
        }
        else
            ancestor = ancestor -> getRight();
    }

    return successor -> getObject();
}

Object *Dictionary::predecessor(DictNode *node) {

    if (node -> getLeft() != nullptr)
        return findMax(node -> getLeft());

    DictNode* successor = nullptr;
    DictNode* ancestor = this->root;

    while(ancestor != node) {

        if(node -> getID() > ancestor -> getID()) {
            successor = ancestor;
            ancestor = ancestor->getRight();
        }
        else
            ancestor = ancestor -> getLeft();
    }

    return successor -> getObject();
}


DictNode *Dictionary::remove(DictNode *node, int ID) {

    if (node == nullptr)
        return nullptr;

    if (node -> getID() == ID)
    {
        if (node -> isLeaf()) {
            delete node;
            node = nullptr;
        }

        else if (node -> rightChildOnly()) {
            node -> getRight() -> setParent(node -> getParent());
            DictNode* aux = node;
            node = node -> getRight();
            delete aux;
        }

        else if (node -> leftChildOnly()) {
            node -> getLeft() -> setParent(node -> getParent());
            DictNode* aux = node;
            node = node -> getLeft();
            delete aux;
        }

        else {

            Object* successor_data = this -> successor(ID);

            node -> setObject(successor_data);

            node -> setRight(remove(node -> getRight(), successor_data -> getId()));
        }
    }

    else if (node -> getID() < ID)
        node -> setRight(remove(node -> getRight(), ID));

    else
        node -> setLeft(remove(node -> getLeft(), ID));

    return node;
}

void Dictionary::deleteAll(DictNode *node) {

    if(node == nullptr)
        return;

    this -> deleteAll(node -> getLeft());
    this -> deleteAll(node -> getRight());

    delete node;

}

void Dictionary::deleteAll() {
    this -> deleteAll(this -> root);
}
