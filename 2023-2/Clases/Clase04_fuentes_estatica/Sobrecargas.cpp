/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Persona.hpp"
#include "Estructuras.hpp"
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

bool operator >> (ifstream & input, struct StCurso & c){
    char extra;
    // INF263 Algoritmia 3.75 3506031 INGA_FLORES_PEPITO
    // INF263,Algoritmia,3.75,3506031,INGA_FLORES_PEPITO
    // Codigo Curso, Nombre Curso, Creditos, Codigo Profesor, Nombre Profesor
    if input.eof(){
     return False;   
    }
    // C es la estructura que quiero llenar
    input>>c.codigoDelCurso;
    input.getline(c.codigoDelCurso, 7, ',');
    input.getline(c.nombreDelCurso, 60, ',');
    // input.getline(creditos,3,','); GRAVE ERROR DE CONCEPTO
    //input>>c.creditos>>extra;
    input>>c.creditos;
    input>>extra;
}