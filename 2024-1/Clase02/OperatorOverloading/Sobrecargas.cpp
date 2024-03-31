/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Sobrecargas.hpp"
using namespace std;
ostream & operator << (ostream & out, const struct Persona & p){
    
    out<<left<<setw(ANCHO/3)<<p.dni<<left<<setw(ANCHO/3)<<p.name;
    out<<left<<setw(ANCHO/3)<<p.weight<<left<<setw(ANCHO/3)<<p.height<<endl;
    return out;
}

ofstream & operator << (ofstream & out, const struct Persona & p){
    
    out<<left<<setw(ANCHO/3)<<p.dni<<left<<setw(ANCHO/3)<<p.name;
    
    out<<left<<setw(ANCHO/3)<<fixed<<setprecision(2)<<p.weight;
    out<<left<<setw(ANCHO/3)<<p.height<<endl;
    return out;
}

ifstream & operator >> (ifstream & in, struct Persona & p){
    int dni;
    char extra, name[50];
    double weight, height;
    in>>dni>>extra;
    
    in>>name>>weight>>height;
    strcpy(p.name,name);
    p.dni = dni;
    /*
     * if(extra == 'A'){
     *  weight = weight*1.1;
     * }
     */
    p.height = height;
    p.weight = weight;
    return in;
}