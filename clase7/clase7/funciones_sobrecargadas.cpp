/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones_sobrecargadas.hpp"
#include "persona.hpp"

struct Persona& operator +(const struct Persona &p1,const struct Persona &p2){
    struct Persona * persona_salida = new Persona;
    char nombre[150] = {};
    //dni
    persona_salida->dni = p1.dni + p2.dni;
    //nombre
    strcpy(persona_salida->nombre,strcat(strcat(nombre,p1.nombre),p2.nombre));
    //sueldo
    persona_salida->sueldo = p1.sueldo + p2.sueldo;

    return *persona_salida;
}

void operator *(struct Persona &p, double porc){
    p.sueldo = p.sueldo + p.sueldo * porc/100.0;
}

ostream & operator <<(ostream &salida , const struct Persona &p){
    salida<<"DNI   "<<p.dni<<endl;
    salida<<"NOMBRE   "<<p.nombre<<endl;
    salida<<"SUELDO   "<<p.sueldo<<endl;
    return salida;
}

ifstream & operator >> (ifstream & entrada, struct Persona &p){
    entrada>>p.dni>>p.nombre>>p.sueldo;
    return entrada;
}
