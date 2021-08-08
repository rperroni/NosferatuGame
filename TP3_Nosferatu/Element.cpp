#include "Element.h"

Element::Element(int amount) {
    this -> amount = amount;
}

void Element::setAmount(int amount) {
    this -> amount = amount;
}

void Element::operator+=(Element *item) {
    (this -> amount) += item -> getAmount();
}

bool Element::operator==(Element *item) {
    return (this -> getObjectName() == item -> getObjectName());
}

bool Element::operator==(std::string name) {
    return (this -> getObjectName() == name);
}

bool Element::operator!=(int amount) {
    return(this -> amount != amount);
}


