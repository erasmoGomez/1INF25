/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: hecto
 * 
 * Created on May 28, 2025, 4:18 PM
 */

#include "Libro.hpp"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char*nombre) const {
    if(this->nombre == nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void Libro::GetCodigo(char* codigo) const {
    if(this->codigo == nullptr) codigo[0]=0;
    else strcpy(codigo, this->codigo);
}

void Libro::leer(ifstream& input){
    //ABC123, El libro de la Selva, 1, 3
    char _codigo[10], _nombre[30], c;
    input.getline(_codigo, 10, ',');
    input.getline(_nombre, 30, ',');
    input>>ancho>>c>>alto;
    input.get();
    SetCodigo(_codigo);
    SetNombre(_nombre);
    colocado = false;
}

void Libro::mostrar(ofstream &output) const {
    char _codigo[10], _nombre[30], c;
    GetCodigo(_codigo);
    GetNombre(_nombre);
    if(colocado)
        output << setw(10) << codigo << setw(30) << nombre << setw(8) << ancho << setw(5) << alto << endl;
    else
        output << setw(10) << codigo << setw(30) << "NO SE PUDO COLOCAR" << setw(8) << ancho << setw(5) << alto << endl;
}

void operator>>(ifstream& input, Libro &l){
    l.leer(input);
}


void operator<<(ofstream& output, const Libro &l) {
    l.mostrar(output);
}
