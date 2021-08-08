#ifndef UNTITLED5_OBJECT_H
#define UNTITLED5_OBJECT_H

#include <iostream>
#include <string>
#include "constantsNames.h"
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics.hpp"

class Object
{
protected:
    int id;
    std::string objectName;
    char objectCharName;
    sf::Texture texture;


public:
    //CONSTRUCTOR//
    Object();

    int getId();

    //PRE: ---
    //POST: Mostrata por pantalla las caracteristicas del objeto
    virtual void show() = 0;

    //PRE: ---
    //POST: Retornada el nombre del objeto
    std::string getObjectName();

    // PRE: --
    // POST: Muestra por pantalla el caracter que representa al objeto
    void showObjectCharacter();

    char getCharName();

    sf::Texture getTexture();

    //PRE: ---
    //POST: Retornara la cantidad del objeto
    virtual int getAmount();

    // PRE:
    // POST:
    void setId(int id);

    //DESTRUCTOR//
    virtual ~Object() = default;

};
#endif //UNTITLED5_OBJECT_H
