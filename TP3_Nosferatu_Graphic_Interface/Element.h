#ifndef UNTITLED5_ELEMENT_H
#define UNTITLED5_ELEMENT_H
#include "Object.h"
#include "constantsNames.h"

class Element: public Object{
protected:
    //Atributo
    int amount;
    std::string objectType = "Consumible";

public:
    Element(int amount);

    virtual void setAmount(int amount);

    virtual void show() = 0;

    //virtual std::string getObjectName() = 0;

    void operator+=(Element * item);

    bool operator==(Element * item);

    bool operator==(std::string name);

    bool operator!=(int amount);

};



#endif //UNTITLED5_ELEMENT_H
