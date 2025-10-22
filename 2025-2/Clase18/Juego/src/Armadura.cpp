//
// Created by Erasmo on 9/10/25.
//

#include "Armadura.hpp"

int Armadura::getValorIncrementar1() const {
    return valor_incrementar;
}

void Armadura::setValorIncrementar1(int valorIncrementar) {
    valor_incrementar = valorIncrementar;
}

Armadura::Armadura() {
    valor_incrementar = 0;
}
