#include "Monster.h"

bool Monster::isZombieTransformed(){
    return this -> transformedHuman;
}


void Monster::setTransformation(){
    transformedHuman = true;
}

bool Monster::isBitten(){
    return false;
}

bool Monster::isVampireTransformed() {
    return this -> tranformedVampire;
}

void Monster::vampireTransform() {
    tranformedVampire = true;
}

Monster::Monster() {
    this -> tranformedVampire = false;
    this -> transformedHuman = false;
}
