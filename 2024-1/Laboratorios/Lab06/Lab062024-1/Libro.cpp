/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 23, 2024, 10:21 PM
 */

#include "Libro.hpp"

Libro::Libro() {
    colocado = false;
    codigo = nullptr;
    nombre = nullptr;
}

void Libro::getCodigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Libro::setCodigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Libro::getNombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Libro::setNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Libro::getAlto() const {
    return alto;
}

void Libro::setAlto(int alto) {
    Libro::alto = alto;
}

int Libro::getAncho() const {
    return ancho;
}

void Libro::setAncho(int ancho) {
    Libro::ancho = ancho;
}

bool Libro::getColocado() const {
    return colocado;
}

void Libro::setColocado(bool colocado) {
    Libro::colocado = colocado;
}

void Libro::lee(ifstream &input) {
    char codigo[10], nombre[30], c;
    input.getline(codigo, 10, ',');
    input.getline(nombre, 30, ',');
    input >> ancho >> c>>alto;
    setCodigo(codigo);
    setNombre(nombre);
    input.get();
}

void Libro::muestra(ofstream &output) {
    char codigo[10], nombre[30], c;
    getCodigo(codigo);
    getNombre(nombre);
    if(colocado)
        output << setw(10) << codigo << setw(30) << nombre << setw(8) << ancho << setw(5) << alto << endl;
    else
        output << setw(10) << codigo << setw(30) << "NO SE PUDO COLOCAR" << setw(8) << ancho << setw(5) << alto << endl;
}

void operator>>(ifstream& input, Libro& l) {
    l.lee(input);
}

void operator<<(ofstream& output, Libro l) {
    l.muestra(output);
}

