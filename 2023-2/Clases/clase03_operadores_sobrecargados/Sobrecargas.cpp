/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Persona.hpp"
#include "Sobrecargas.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
void operator *= (struct Persona &p, double aumento){
    p.sueldo *= aumento;
}

struct Persona operator + (const struct Persona &p1, const struct Persona& p2){
    struct Persona nuevo{};
    nuevo.dni = 159852;
    nuevo.sueldo = p1.sueldo + p2.sueldo;
    char nuevo_nombre[150];
    strcpy(nuevo_nombre, p1.nombre);
    strcat(nuevo_nombre, p2.nombre);
    strcpy(nuevo.nombre, nuevo_nombre);
    return nuevo;
}

ostream & operator << (ostream & out, const struct Persona & p){
    out<<right<<setw(10)<<p.dni<<" "<<left<<setw(40)<<p.nombre;
    out<<right<<setw(10)<<p.sueldo<<endl;
    return out;
}


