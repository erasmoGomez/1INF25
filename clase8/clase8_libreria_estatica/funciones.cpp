/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "libreria_estatica_funciones.hpp"

ifstream & operator >>(ifstream &arch, struct Persona p){
    arch>>p.nombre;
    arch>>p.dni;
    arch>>p.sueldo;
    return arch;
}

int operator >>(ifstream &arch, struct Persona p){
    arch>>p.nombre;
    arch>>p.dni;
    arch>>p.sueldo;
    if(p.sueldo>500000)
        return 1;
    else
        return 0;
}

int operator 



int suma(int a, int b){
    return a+b;
}
