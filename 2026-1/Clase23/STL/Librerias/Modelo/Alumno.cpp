//
// Created by erasmo on 6/16/26.
//
#include "Alumno.hpp"

int Alumno::get_codigo() const {
    return codigo;
}

void Alumno::set_codigo(int codigo) {
    this->codigo = codigo;
}

string Alumno::get_nombre() const {
    return nombre;
}

void Alumno::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

bool Alumno::is_aprobado() const {
    return aprobado;
}

void Alumno::set_aprobado(bool aprobado) {
    this->aprobado = aprobado;
}

void Alumno::leer(ifstream &input) {
    char buffer_nombre[20];
    input>>this->codigo;
    input.ignore();
    input.getline(buffer_nombre,20, '\n');
    this->nombre = buffer_nombre;
}

void Alumno::imprimir(ostream& out) {
    out << "Datos del Alumno: "<<this->codigo<<endl;
    out << left << setw(30) << this->nombre;
    out << setw(5) << boolalpha << this->aprobado << endl;
}

bool Alumno::operator<(const Alumno &otro) const {
    return codigo < otro.codigo;
    //return nombre < otro.nombre;
}

Alumno::Alumno() {
    this->codigo = 0;
    this->nombre = "";
    this->aprobado = false;
}

Alumno::~Alumno() {
}

void operator<<(ostream &out, Alumno& alumno) {
    alumno.imprimir(out);
}

void operator>>(ifstream &input,Alumno& alumno) {
    alumno.leer(input);
}