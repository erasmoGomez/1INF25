/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hecto
 *
 * Created on March 25, 2025, 4:37 PM
 */

#include "persona.hpp"
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    
//    persona.nombre = "Juan Perez";
//    cout<<persona.nombre<<endl;
    //Persona 1
    struct Persona persona;
    persona.dni = 123456;
    //cout<<persona.dni<<endl;
    strcpy(persona.nombre, "Juan Perez");
    //cout<<persona.nombre<<endl;
    persona.sueldo = 3500.0;
    //cout<<persona.sueldo<<endl;
    //Persona 2
    struct Persona persona2;
    persona2.dni = 123456;
    //cout<<persona2.dni<<endl;
    strcpy(persona2.nombre, "Ana Roncal");
    //cout<<persona2.nombre<<endl;
    persona2.sueldo = 5300.0;
    //cout<<persona2.sueldo<<endl;
    
    cout<<persona;
    
    return 0;
}

