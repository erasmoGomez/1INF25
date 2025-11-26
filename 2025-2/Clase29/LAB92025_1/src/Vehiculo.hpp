//
// Created by Erasmo on 25/11/25.
//

#ifndef LAB92025_1_VEHICULO_HPP
#define LAB92025_1_VEHICULO_HPP

#include "Utils.hpp"

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
public:
    Vehiculo();

    Vehiculo(const Vehiculo &o);

    ~Vehiculo();

    void operator=(const Vehiculo &o);

    string getPlaca() const { return placa; }

    string getMarca() const { return marca; }

    string getModelo() const { return modelo; }

    void leer(ifstream &input);

    void imprimir(ofstream &output) const;
};

istream &operator>>(ifstream &input, Vehiculo &v);
ostream &operator<<(ofstream &output, const Vehiculo &v);

#endif //LAB92025_1_VEHICULO_HPP
