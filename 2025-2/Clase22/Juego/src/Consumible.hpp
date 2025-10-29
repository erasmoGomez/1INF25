//
// Created by Erasmo on 9/10/25.
//

#ifndef JUEGO_CONSUMIBLE_HPP
#define JUEGO_CONSUMIBLE_HPP

#include "Item.hpp"

class Consumible : public Item {
private:
    int valor_incrementar;
public:
    Consumible();

    int getValorIncrementar1() const;

    void setValorIncrementar1(int valorIncrementar);

    void leer(ifstream &input);

    void mostrar(ostream &output) const;

    int get_valor();
};


#endif //JUEGO_CONSUMIBLE_HPP
