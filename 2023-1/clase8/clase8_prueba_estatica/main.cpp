/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 25, 2023, 7:35 AM
 */

#include <iostream>
#include "persona.hpp"
#include "libreria_estatica_funciones.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //cout<< suma(5,6)<<endl;
    int mayorQ;
    struct Persona p;
//    p.dni = 20082060;
//    cout<< p.dni<<endl;
    cout<<"LECTURA DE DATOS"<<endl;
    mayorQ = (cin >> p);
    if (mayorQ) {
        cout<< "Sueldo mayor a lo esperado"<<endl;
    }
    else{
        cout<< "Sueldo por debajo de lo esperado"<<endl;
    }
    // 20082060 erasmo_gomez 12000
    cout<<"IMPRESION DE DATOS"<<endl;
    cout<<p.nombre<<endl;
    cout<<p.sueldo<<endl;
    cout<<p.dni<<endl;
    return 0;
}

