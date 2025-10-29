//
// Created by Erasmo on 9/10/25.
//

#ifndef JUEGO_ARMA_HPP
#define JUEGO_ARMA_HPP
#include "Item.hpp"

class Arma: public Item {
private:
    int valor_incrementar;
public:
    Arma();

    int getValorIncrementar1() const;

    void setValorIncrementar1(int valorIncrementar);

    void leer(ifstream & input);

    void mostrar(ostream &output) const;

    int get_valor();
};


#endif //JUEGO_ARMA_HPP
