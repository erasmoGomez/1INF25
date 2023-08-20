/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 18, 2023, 7:26 AM
 */
#include <cstring>
#include "persona.hpp"
#include "funciones.hpp"
#include "funciones_sobrecargadas.hpp"
#include "plantillas.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    imprimeFecha(23,01,1991);
//    imprimeFecha(23,01);
//    imprimeFecha(23);
    // imprimeFecha();
    struct Persona persona1;
    persona1.dni = 11111111;
    strcpy(persona1.nombre,"erasmo");
    persona1.sueldo = 15000;
    
    cout<<persona1.dni<<endl;
    cout<<persona1.nombre<<endl;
    cout<<persona1.sueldo<<endl;
    
    struct Persona persona2;
    persona2.dni = 22222222;
    strcpy(persona2.nombre,"hector");
    persona2.sueldo = 12000;
    
    cout<<persona2.dni<<endl;
    cout<<persona2.nombre<<endl;
    cout<<persona2.sueldo<<endl;
    
    cout<<endl;
    cout<<"PRUEBAS"<<endl;
    
    double sueldo, sueldo2;
    sueldo = persona1.sueldo+persona2.sueldo;
    cout<<sueldo<<endl;
    
    struct Persona persona3;
    persona3 = persona1+persona2;
    cout<<persona3<<endl;
    
    struct Persona persona4;
    double porc = 50;
    persona2*porc;
    persona4 = persona1 + persona2;
    
    ofstream arch("coso.txt", ios::out);
    arch<<persona4<<endl;
    
    
    struct Persona personas[100];
    
    cout<<"LLAMADA A LEER_DATOS"<<endl;
    int n_personas = 0;
    leer_datos(personas, n_personas, "personas.txt");
    for (int i=0; i<=5; i++){
        cout<< personas[i].nombre<<endl;
    }
    
    cout<<"LLAMADA A LEER_DATOS entero"<<endl;
    int n_enteros = 0;
    int enteros[100];
    leer_datos(enteros, n_enteros, "enteros.txt");
    for (int i=0; i<=5; i++){
        cout<< enteros[i]<<endl;
    }
    return 0;
}

