#ifndef _OBJECT_H
#define _OBJECT_H

#include <iostream>
#include <string>
#include "constantsNames.h"
#include "Gotoxy.h"

class Object
{
protected:

    Gotoxy gotoxy;
    int id;
    std::string objectName;
    char objectCharName;
    int currentRow;
    int currentCol;

public:

    //CONSTRUCTOR//
    Object();

    // PRE:
    // POST:
    int getId();

    //PRE: ---
    //POST: MUESTRA POR PANTALLA LAS CARACTERISTICAS DEL OBJETO
    virtual void show() = 0;

    //PRE: ---
    //POST: Retornada el nombre del objeto
    std::string getObjectName();

    // PRE: --
    // POST: Muestra por pantalla el caracter que representa al objeto
    void showObjectCharacter();

    // PRE: --
    // POST: Devuelve la letra que corresponde a dicho objeto
    char getCharName();

    //PRE: ---
    //POST: Retornara la cantidad del objeto
    virtual int getAmount();

    // PRE: Ingresa la fila
    // POST: Setea la fila al personaje
    void setRow(int row);

    // PRE: Ingresa la columna
    // POST: Setea la columna al personaje
    void setColumn(int col);

    // PRE: --
    // POST: Devuelve la fila
    int getRow();

    // PRE: --
    // POST: Devuelve la columna
    int getCol();

    // PRE: --
    // POST: Devuelve true en caso de estar transformado en zombie
    virtual bool isZombieTransformed() = 0;

    // PRE: --
    // POST: Devuelve true en caso de estar transformado en vampiro
    virtual bool isVampireTransformed() = 0;

    // PRE: Ingresa el id
    // POST: Setea el id al objeto
    void setId(int id);

    //DESTRUCTOR//
    virtual ~Object() = default;

};
#endif //UNTITLED5_OBJECT_H
