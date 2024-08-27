/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecargas.hpp"
#include "Telefono.hpp"
//ifstream & operator >> (ifstream& input, struct Telefono& t){
//    cout<<"Estoy en la definicion de la sobrecarga de lectura"<<endl;
//    // 999999 samsung s25_ultra 345.56
//    input >> t.numero_telefonico >> t.marca >> t.modelo >> t.precio;
//    return input;
//}

bool operator >> (ifstream& input, struct Telefono& t){
    //cout<<"Estoy en sobrecarga de boolean"<<endl;
    input >> t.numero_telefonico;
    if(input.eof()) return false;
    input>> t.marca >> t.modelo >> t.precio;
    return true;
}

ofstream & operator << (ofstream& output, const struct Telefono& t){
    output<<setprecision(2);
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.numero_telefonico;
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.marca;
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.modelo;
    output<<right<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<fixed<<t.precio<<endl;
    return output;
}

ostream & operator << (ostream& output, const struct Telefono& t){
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.numero_telefonico;
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.marca;
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.modelo;
    output<<left<<setw(ANCHO_TOTAL/ANCHO_COLUMNA)<<t.precio<<endl;
    return output;
}

//telefonos[i]*=25.6

void operator *= (struct Telefono &telefono, double incremento){
    telefono.precio *= (1+incremento/100);
}