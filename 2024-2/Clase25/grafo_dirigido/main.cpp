/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 12, 2024, 5:52 PM
 */

#include "persona.hpp"
#include "RedSocial.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Crear Personas
    Persona p1("erasmo", 32);
    Persona p2("rony", 52);
    Persona p3("miguel", 62);
    Persona p4("ana", 42);
    
    //Crear red social
    RedSocial redsocial;
    
    //Agregar las relaciones
    redsocial.agregar_relacion(p1, p2);
    redsocial.agregar_relacion(p1, p3);
    redsocial.agregar_relacion(p1, p4);
    
    redsocial.agregar_relacion(p2, p3);
    
    redsocial.agregar_relacion(p3, p1);
    redsocial.agregar_relacion(p3, p4);
    
    redsocial.agregar_relacion(p4, p2);
    
    redsocial.imprimir();
    return 0;
}
    
//Matrix de ADYACENCIA
//    P1   P2   P3   P4
//P1   0   1    1    1 -> P2, P3, P4
//P2   0   0    1    0 -> P3
//P3   1   0    0    1 -> P1, P4
//P4   0   1    0    0 -> P2
//KEY                     VALUE  
//P1 Erasmo
//P2 Rony
//P3 Miguel
//P4 Ana



