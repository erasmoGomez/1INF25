//
// Created by Erasmo on 25/11/25.
//

#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {

}

Vehiculo::Vehiculo(const Vehiculo &o) {
    placa = o.placa;
    marca = o.marca;
    modelo = o.modelo;
}

Vehiculo::~Vehiculo() {

}

void Vehiculo::operator=(const Vehiculo &o) {
    placa = o.placa;
    marca = o.marca;
    modelo = o.modelo;
}

void Vehiculo::leer(ifstream &input) {
    //M982-853,Honda,Civic
    char buffer[30];
    input.getline(buffer, 30, ',');
    placa = buffer;
    input.getline(buffer, 30, ',');
    marca = buffer;
    input.getline(buffer, 30, '\n');
    modelo = buffer;
}

void Vehiculo::imprimir(ofstream &output) const {
    output << placa << " " << marca << " " << modelo;

}

istream &operator>>(ifstream &input, Vehiculo &v) {
    v.leer(input);
    return input;
}

ostream &operator<<(ofstream &output, const Vehiculo &v) {
    v.imprimir(output);
    return output;
}