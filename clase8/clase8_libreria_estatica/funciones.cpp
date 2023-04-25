/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstring>
#include "persona.hpp"
#include "libreria_estatica_funciones.hpp"

//ifstream & operator >>(ifstream &arch, struct Persona p){
//    arch>>p.nombre;
//    arch>>p.dni;
//    arch>>p.sueldo;
//    return arch;
//}

int operator >>(istream &arch, struct Persona &p){
    char nombre[50];
    arch>>p.dni;
    //Reserva de memoria exacta para char*
    arch>>nombre;
    int n = strlen(nombre);
    p.nombre = new char[n+1];
    strcpy(p.nombre,nombre);
    arch>>p.sueldo;
    if(p.sueldo>5000)
        return 1;
    else
        return 0;
return 0;
}

int suma(int a, int b){
    return a+b;
}
