//
// Created by Erasmo on 19/11/25.
//

#include "Deudor.hpp"

void Deudor::leer(ifstream &input) {
    Jugador::leer(input);
    input>>deuda;
    input.get();
}

void Deudor::imprimir(ofstream &output) {
    Jugador::imprimir(output);
    output<<setw(10)<<"DEUDOR"<<endl;
}

double Deudor::getDeuda() const {
    return deuda;
}

void Deudor::setDeuda(double deuda) {
    Deudor::deuda = deuda;
}
