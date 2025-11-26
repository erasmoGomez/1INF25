//
// Created by Erasmo on 25/11/25.
//

#include "Empresa.hpp"


Empresa::Empresa() {

}

Empresa::~Empresa() {

}

void Empresa::leer(ifstream &input) {
    input >> dni;
    input.get();

    getline(input, nombre, ',');
    getline(input, distrito);
}

void Empresa::imprimir(ofstream &output) const {
    output << "DNI: " << dni << " NOMBRE: "
           << nombre << " DISTRITO: " << distrito;
}

bool Empresa::operator<(const Empresa &otro) const {
    return dni < otro.dni;
}

void Empresa::insertar_vehiculo(class Vehiculo v) {
    vehiculos[v.getPlaca()] = v;
}

void Empresa::buscar_empresa_placa_asigna(const class Multa &m) {
    if (vehiculos.find(m.getPlaca()) != vehiculos.end()) {
        multasRecibidas.push_back(m);
    }
}

void Empresa::ordenar_multas() {
    sort(multasRecibidas.begin(),
         multasRecibidas.end(),
         Multa::compara_fecha);
}

void Empresa::imprimir_vehiculos(ofstream &output) {
    for (auto &p: vehiculos)
        output << p.second << endl;
}

void Empresa::imprimir_multas(ofstream &output) {
    for (auto &m: multasRecibidas)
        output << m << endl;
}

void Empresa::eliminar_infracciones_pagadas() {
    multasRecibidas.erase(
            remove_if(multasRecibidas.begin(),
                          multasRecibidas.end(),
                          Multa::es_pagada),
                          multasRecibidas.end());
}

ifstream &operator>>(ifstream &input, Empresa &e) {
    e.leer(input);
    return input;
}

ofstream &operator<<(ofstream &output, const Empresa &e) {
    e.imprimir(output);
    return output;
}

