//
// Created by Erasmo on 25/11/25.
//

#include "Infraccion.hpp"
Infraccion::Infraccion() {

}

Infraccion::Infraccion(const Infraccion &o) {
    codigo = o.codigo;
    multa = o.multa;
    gravedad = o.gravedad;
    descripcion = o.descripcion;
}

Infraccion::~Infraccion() {

}

Infraccion &Infraccion::operator=(const Infraccion &o) {
    if (this != &o) {
        codigo = o.codigo;
        multa = o.multa;
        gravedad = o.gravedad;
        descripcion = o.descripcion;
    }
    return *this;
}

void Infraccion::leer(ifstream &input) {
    getline(input, codigo, ',');
    if(input.eof())return;
    input >> multa;
    input.get(); // coma
    getline(input, gravedad, ',');
    getline(input, descripcion);
}

void Infraccion::imprimir(ofstream &output) const{
    output << codigo << " " << multa << " "
       << gravedad << " " << descripcion;
}

bool Infraccion::operator<(const Infraccion &otro) const {
    return codigo<otro.codigo;
}

ifstream &operator>>(ifstream &input, Infraccion &inf){
    inf.leer(input);
    return input;
}

ostream &operator<<(ofstream &output, const Infraccion &inf) {
    inf.imprimir(output);
    return output;
}