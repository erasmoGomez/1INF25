//
// Created by Erasmo on 19/11/25.
//

#include "Pagador.hpp"

void Pagador::leer(ifstream &input) {
    Jugador::leer(input);
    input>>saldo;
    input.get();
}

void Pagador::imprimir(ofstream &output) {
    Jugador::imprimir(output);
    output<<setw(10)<<"PAGADOR"<<endl;
}

double Pagador::getSaldo() const {
    return saldo;
}

void Pagador::setSaldo(double saldo) {
    Pagador::saldo = saldo;
}

bool Pagador::eligeDerecha() const {
    return true;
}
