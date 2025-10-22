//
// Created by Erasmo on 9/10/25.
//

#include "Arma.hpp"

int Arma::getValorIncrementar1() const {
    return valor_incrementar;
}

void Arma::setValorIncrementar1(int valorIncrementar) {
    valor_incrementar = valorIncrementar;
}

Arma::Arma() {
    valor_incrementar = 0;

}

void Arma::leer(ifstream &input) {
    int dato;
    //1,Sword,A sharp and sturdy sword.,147,3
    Item::leer(input); // Lee solo lo del padre
    input>>valor_incrementar; //Lee solo lo de la hija
    input.get();
    input>>dato;
}
