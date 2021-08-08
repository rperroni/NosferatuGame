#include "Being.h"

Being::Being() {
    this -> setRandomStats();
    this -> inventory = new Inventory();
}

int Being::getEnergy() {
    return this -> energy;
}

int Being::getArmor() {
    return this -> armor;
}

int Being::getHealth() {
    return this -> health;
}

int Being::getStrength(){
    return this -> strength;
}

void Being::addEnergy(int energy) {
    this -> energy += energy;
}

bool Being::isAlive(){
    return (this -> health > 0);
}

int Being::getCostType() {
    return this -> costType;
}

void Being::setRandomStats() {
    health = rand() % 81 + 20;
    energy = rand() % 21;
    strength = rand() % 31 + 10;
    armor = rand() % 3;
}

void Being::receiveDamage(int damage) {
    if(armor > 2)
        damage *= 0.2;

    else
        damage *= (1 - ((float)armor / 10));

    health -= damage;
}

void Being::killBeing() {
    health = 0;
}

Inventory* Being::getInventory() {
    return inventory;
}

bool Being::hasCross() {
    return inventory -> isInInventory(CROSSUPPER);
}


void Being::addStrength(int strength) {
    this -> strength += strength;
}

void Being::addArmor(int armor) {
    this -> armor += armor;
}

void Being::addHealth(int health) {
    this -> health += health;
}

Being::~Being() {
    delete inventory;
}

int Being::getTeam() {
    return team;
}
