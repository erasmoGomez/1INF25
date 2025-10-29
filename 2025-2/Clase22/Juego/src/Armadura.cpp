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

void Armadura::leer(ifstream &input) {
    int dato;
    //Lectura del Padre
    Item::leer(input);
    //Lectura de la Hija
    input>>valor_incrementar;
}

void Armadura::mostrar(ostream&output) const{
    Item::mostrar(output);
    output<<setw(5)<<left<<valor_incrementar<<setw(10)<<(Item::getEquipado() ? "EQUIPADO" : "NO EQUIPADO")<<endl;
}

int Armadura::get_valor() {
    return valor_incrementar;
}