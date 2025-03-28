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

ifstream& operator >> (ifstream& in, struct Papeleta& p){
    //DNI,CodigoFalta,Fecha,Monto,Gravedad,Descripción
    //12345678,F001,2024-03-01,350,Grave,Paso de luz roja
    int id;
    char extra, buffer[5];
    in>>id;
    in>>extra; //Leer la coma
    in.getline(buffer, 5, ',');
    p.codigo = new char[strlen(buffer)+1];
    strcpy(p.codigo, buffer);
    leer_fecha(in, p);
    in>>p.monto;
    in>>extra;
    p.gravedad = leer_cadena(in);
    p.descripcion = leer_cadena(in);
    return in;
}