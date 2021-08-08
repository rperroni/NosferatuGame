#ifndef GRAFOS_GOTOXY_H
#define GRAFOS_GOTOXY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class Gotoxy{

public:

    Gotoxy(){}

    template <typename T>

    inline std::string ToString(const T& t) {

        std::stringstream ss;
        ss << t;

        return ss.str();
    }

    inline std::string pos(const int& y,const int& x) {

        return "\33[" + ToString(y) + ";" + ToString(x) + "H";
    }


};



#endif //GRAFOS_GOTOXY_H
