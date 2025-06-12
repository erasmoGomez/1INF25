/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 11, 2025, 4:34 PM
 */

#include "Plantilla.hpp"
#include "Persona.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    class Plantilla<int> obj_int;
//    obj_int.leer();
//    obj_int.imprimir();
//    
//    class Plantilla<double> obj_double;
//    obj_double.leer();
//    obj_double.imprimir();
//    
//    class Plantilla<string> obj_string;
//    obj_string.leer();
//    obj_string.imprimir();
    
    class Plantilla<class Persona> obj_persona;
    obj_persona.leer();
    obj_persona.imprimir();
    return 0;
}
