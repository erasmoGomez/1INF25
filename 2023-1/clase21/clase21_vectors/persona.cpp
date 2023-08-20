#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;
#include <cstring> 
#include "persona.hpp"

Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
    nombre = nullptr;
    *this = orig;
}

Persona::~Persona() {
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* nomb) {
    if (nombre) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Persona::GetNombre(char*nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator=(const class Persona&per) {
    char nomb[100];
    dni = per.dni;
    per.GetNombre(nomb);
    SetNombre(nomb);
    sueldo = per.sueldo;
}

bool Persona::operator>(const class Persona&per) {
    return strcmp(nombre,per.nombre)>0;
}

bool Persona::operator<(const class Persona&per) const{
    return strcmp(nombre,per.nombre)<0;
}

bool Persona::operator==(int dni) {
    return this->dni == dni;
}

ifstream & operator>>(ifstream &arch, class Persona&per) {
    int dni;
    char nombre[100];
    double sueldo;
    arch>>dni;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetNombre(nombre);
    per.SetSueldo(sueldo);
    return arch;
}

ostream & operator<<(ostream &arch, const class Persona&per) {
    char nombre[100];
    arch.precision(2);
    arch << fixed;
    per.GetNombre(nombre);
    arch << left << setw(10) << per.GetDni() << setw(40) << nombre
            << right << setw(10) << per.GetSueldo() << endl;
    return arch;
}