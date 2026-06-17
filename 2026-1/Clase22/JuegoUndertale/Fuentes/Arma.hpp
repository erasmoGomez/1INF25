//
// Created by erasmo on 5/26/26.
//

#ifndef JUEGOUNDERTALE_ARMA_HPP
#define JUEGOUNDERTALE_ARMA_HPP

#include "Item.hpp"
class Arma:public Item {
private:
    int modificador_ataque;
public:
    void leer(ifstream&);
    int get_modificador();
};


#endif //JUEGOUNDERTALE_ARMA_HPP