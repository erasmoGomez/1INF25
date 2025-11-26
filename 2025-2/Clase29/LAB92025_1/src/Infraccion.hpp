//
// Created by Erasmo on 25/11/25.
//

#ifndef LAB92025_1_INFRACCION_HPP
#define LAB92025_1_INFRACCION_HPP

#include "Utils.hpp"

using namespace std;

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
public:
    Infraccion();

    Infraccion(const Infraccion &o);

    ~Infraccion();

    Infraccion &operator=(const Infraccion &o);

    string getCodigo() const { return codigo; }

    double getMulta() const { return multa; }

    string getGravedad() const { return gravedad; }

    string getDescripcion() const { return descripcion; }

    void leer(ifstream &input);

    void imprimir(ofstream &output) const;

    bool operator<(const Infraccion& otro) const;
};

ifstream &operator>>(ifstream &is, Infraccion &inf);

ostream &operator<<(ofstream &os, const Infraccion &inf);

#endif //LAB92025_1_INFRACCION_HPP
