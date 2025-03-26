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