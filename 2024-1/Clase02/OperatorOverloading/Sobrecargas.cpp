/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Sobrecargas.hpp"
using namespace std;
ostream & operator << (ostream & out, const struct Persona & p){
    
    cout<<left<<setw(ANCHO/3)<<p.dni<<left<<setw(ANCHO/3)<<p.nombre;
    cout<<left<<setw(ANCHO/3)<<p.talla<<endl;
    return out;
}