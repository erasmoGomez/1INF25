/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <sstream>

#include "Sobrecargas.hpp"
#include "Persona.hpp"
using namespace std;

//ifstream & operator >> (ifstream & in, struct Persona & p){
//    char buffer[30];
//    in>>p.dni;
//    in.get();
//    in.getline(buffer, 30, ',');
//    in>>p.weight;
//    in.get();
//    in>>p.height;
//    
//    strcpy(p.name,buffer);
//    return in;
//}

ostream & operator << (ostream & out, const struct Persona & p){
    
    out<<left<<setw(ANCHO/3)<<p.dni<<left<<setw(ANCHO/3)<<p.name;
    out<<left<<setw(ANCHO/3)<<p.weight<<left<<setw(ANCHO/3)<<p.height<<endl;
    return out;
}

bool operator >> (ifstream & in, struct Persona & p){
    char buffer[30];
    int dni;
    in>>dni; // Levanta la bandera fail()
    //Aqui reviso si hubo una lectura correcta al incio de la linea
    if(in.eof()) {
        //si quisiera agregar un tope podria hacerlo aqui o saliendo del while
        return false;
    }
    p.dni = dni;
    in.get();
    in.getline(buffer, 30, ',');
    in>>p.height;
    in.get();
    in>>p.weight;
    
    strcpy(p.name,buffer);
    return true;
}