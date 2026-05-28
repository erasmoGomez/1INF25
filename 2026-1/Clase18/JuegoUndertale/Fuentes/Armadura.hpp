//
// Created by erasmo on 5/27/26.
//

#ifndef JUEGOUNDERTALE_ARMADURA_HPP
#define JUEGOUNDERTALE_ARMADURA_HPP

#include "Item.hpp"
class Armadura:public Item {
private:
    int modificador_defensa;
public:
    void leer(ifstream&);
};


#endif //JUEGOUNDERTALE_ARMADURA_HPP