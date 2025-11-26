//
// Created by Erasmo on 25/11/25.
//

#include "Multa.hpp"

Multa::Multa()  {
    multa = 0;
    pagada = false;
    fechaDePago = 0;
}

Multa::Multa(const Multa &o) {
    fecha = o.fecha;
    placa = o.placa;
    codMulta = o.codMulta;
    multa = o.multa;
    pagada = o.pagada;
    fechaDePago = o.fechaDePago;
}

Multa::~Multa() {

}

Multa &Multa::operator=(const Multa &o) {
    fecha = o.fecha;
    placa = o.placa;
    codMulta = o.codMulta;
    multa = o.multa;
    pagada = o.pagada;
    fechaDePago = o.fechaDePago;
    return *this;
}

bool Multa::leer(ifstream &input) {
    //1/12/2020,G760-721,G2022,N
    //23/07/2023,P474-593,G2060,P,22/08/2023
    string fechaTxt, pagoTxt;
    int aa, mm, dd;
    char c;
    input>>dd;
    if (input.eof()) return false;
    input>>c>>mm>>c>>aa;
    fecha = aa*10000+mm*100+dd;
    input.get();

    getline(input, placa, ',');
    getline(input, codMulta, ',');
    pagoTxt = input.get();
    pagada = (pagoTxt == "P");

    if (pagada){
        input.get();
        input>>dd>>c>>mm>>c>>aa;
        fechaDePago = aa*10000+mm*100+dd;
    }
    return true;
}

void Multa::imprimir(ofstream &output) const {
    output << fecha << " " << placa << " " << codMulta
       << " " << multa << " " << (pagada ? "SI" : "NO");
    if (pagada) output << " " << fechaDePago;
}

bool Multa::compara_fecha(const Multa &a, const Multa &b) {
    return a.getFecha()<b.getFecha();
}

bool Multa::es_pagada(const Multa& m) {
    return m.pagada;
}

bool operator>>(ifstream &input, Multa &m) {
    return m.leer(input);
}

ofstream &operator<<(ofstream &output, const Multa &m) {
    m.imprimir(output);
    return output;
}