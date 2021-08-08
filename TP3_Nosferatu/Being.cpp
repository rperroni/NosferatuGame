#include "Being.h"

Being::Being() {
    this -> setRandomStats();
    this -> inventory = new Inventory();
    this -> defenseDuration = -1;
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
    if(this -> energy > 20)
        this -> energy = 20;
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

void Being::receiveDamage(float damage) {
    if(armor > 2)
        damage = damage * (float)0.2;
    else
        damage =  ((float) damage * (1 - ((float) armor / 10)));

    health -= (int) damage;
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
    if(this -> health > 100)
        this -> health = 100;
}

Being::~Being() {
    delete inventory;
}

int Being::getTeam() {
    return team;
}

bool Being::hasShotgun() {
    return inventory -> isInInventory(SHOTGUN_CAPITALIZED);
}

bool Being::hasBullets() {
    return inventory -> isInInventory(BULLET_CAPITALIZED);
}

bool Being::hasStake() {
    return inventory -> isInInventory(STAKE_CAPITALIZED);
}

bool Being::hasHolyWater() {
    return inventory -> isInInventory(HOLYWATER_CAPITALIZED);
}

void Being::setEnergy(int energy) {
    this -> energy = energy;
}

void Being::setArmor(int armor) {
    this -> armor = armor;
}

void Being::setHealth(int health) {
    this -> health = health;
}

void Being::setStrength(int strength) {
    this -> strength = strength;
}

void Being::defenseCountdown() {
    this -> defenseDuration--;
}

int Being::getDefenseDuration() {
    return defenseDuration;
}

void Being::startDefense(int turns) {
    defenseDuration = turns;
}

