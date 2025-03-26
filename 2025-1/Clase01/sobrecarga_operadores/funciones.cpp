/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

ostream & operator <<(ostream & out, const struct Persona& p){
    out<<"tengo hambre"<<endl;
    out<<p.dni<<endl;
    out<<p.nombre<<endl;
    out<<p.sueldo<<endl;
}
istream & operator >> (istream & in, struct Persona& p){
    cout<<"Ingrese Datos"<<endl;
    in>>p.dni;
    in>>p.nombre;
    in>>p.sueldo;
}

void operator += (struct Persona& p, double porcentaje){
    p.sueldo += (1+p.sueldo/porcentaje);
}