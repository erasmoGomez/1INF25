//
// Created by Erasmo on 5/11/25.
//

#include "Persona.hpp"

Persona::Persona() {
}

Persona::Persona(const Persona &orig) {
}

Persona::~Persona() {
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Persona::GetNombre() const {
    return nombre;
}

void Persona::leer() {
    char buffer[30];
    cin>>dni;
    if(cin.eof())return;
    cin.get();
    cin.getline(buffer, 30, ',');
    nombre = buffer; //Esta sobrecarga ya se encuentra en la clase String
    //SetNombre(buffer);
    cin>>sueldo;
}

void Persona::imprimir() const {
    cout.precision(2);
    cout << fixed;
    cout << right << setw(10) << dni << " " << left << setw(30) << nombre;
    cout << right << setw(10) << sueldo << endl;
}

void operator>>(istream &input, class Persona &p) {
    p.leer();
}

ostream &operator<<(ostream &output, const class Persona &p) {
    p.imprimir();
    return output;
}
