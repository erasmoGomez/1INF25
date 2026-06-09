//
// Created by erasmo on 5/27/26.
//

#ifndef JUEGOUNDERTALE_CONSUMIBLE_HPP
#define JUEGOUNDERTALE_CONSUMIBLE_HPP

#include "Item.hpp"
class Consumible:public Item {
private:
    int modificador_vida;
public:
    void leer(ifstream&);
    int get_modificador();
};


#endif //JUEGOUNDERTALE_CONSUMIBLE_HPP