/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecargas.hpp"
#include "estructuras.hpp"

ostream& operator << (ostream& out, const struct Papeleta& p){
    out<<"Datos de la Papeleta"<<endl;
    out<<"Codigo: "<<p.codigo<<"Fecha: "<<p.fecha<<endl;
    out<<"Monto: "<<p.monto<<"Gravedad: "<<p.gravedad<<endl;
    out<<"Descripcion: "<<p.descripcion<<endl;
}