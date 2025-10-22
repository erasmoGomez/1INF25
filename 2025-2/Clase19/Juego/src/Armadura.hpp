//
// Created by Erasmo on 9/10/25.
//

#ifndef JUEGO_ARMADURA_HPP
#define JUEGO_ARMADURA_HPP
#include "Item.hpp"

class Armadura: public Item {
private:
    int valor_incrementar;
public:
    Armadura();

    int getValorIncrementar1() const;

    void setValorIncrementar1(int valorIncrementar);

    void leer(ifstream& input);

    void mostrar(ostream &output) const;
};


#endif //JUEGO_ARMADURA_HPP
