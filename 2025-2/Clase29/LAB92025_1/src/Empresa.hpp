//
// Created by Erasmo on 25/11/25.
//

#ifndef LAB92025_1_EMPRESA_HPP
#define LAB92025_1_EMPRESA_HPP

#include "Vehiculo.hpp"
#include "Multa.hpp"

class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string, Vehiculo> vehiculos;
    vector<Multa> multasRecibidas;
public:
    Empresa();

    ~Empresa();

    int getDni() const { return dni; }

    string getNombre() const { return nombre; }

    string getDistrito() const { return distrito; }

    void leer(ifstream &input);

    void imprimir(ofstream &output) const;

    bool operator<(const Empresa &otro) const;

    void insertar_vehiculo( class Vehiculo v);

    void buscar_empresa_placa_asigna(const class Multa& m);

    void ordenar_multas();

    void imprimir_vehiculos(ofstream& output);

    void imprimir_multas(ofstream& output);

    void eliminar_infracciones_pagadas();

};

ifstream &operator>>(ifstream &input, Empresa &e);

ofstream &operator<<(ofstream &output, const Empresa &e);

#endif //LAB92025_1_EMPRESA_HPP
