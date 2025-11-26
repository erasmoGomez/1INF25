//
// Created by Erasmo on 25/11/25.
//

#ifndef LAB92025_1_MULTA_HPP
#define LAB92025_1_MULTA_HPP

#include "Utils.hpp"

class Multa {
private:
    int fecha;              // ddmmaaaa como entero
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
public:
    Multa();

    Multa(const Multa &o);

    ~Multa();

    Multa &operator=(const Multa &o);

    int getFecha() const { return fecha; }

    string getPlaca() const { return placa; }

    string getCodigo() const { return codMulta; }

    double getMulta() const { return multa; }

    bool isPagada() const { return pagada; }

    int getFechaPago() const { return fechaDePago; }

    void setMulta(double m) { multa = m; }

    bool leer(ifstream &input);

    void imprimir(ofstream &output) const;

    //Metodo estático usado como comparador
    static bool compara_fecha(const Multa &a, const Multa &b);

    static bool es_pagada(const Multa &a);
};

bool operator>>(ifstream &input, Multa &m);

ofstream &operator<<(ofstream &output, const Multa &m);

#endif //LAB92025_1_MULTA_HPP
