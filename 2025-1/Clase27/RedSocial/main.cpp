/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 18, 2025, 5:01 PM
 */

#include "Persona.hpp"
#include "RedSocial.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Creacion Persona
    Persona p1("erasmo", 888888888);
    Persona p2("rony", 9999999);
    Persona p3("miguel", 77777777);
    Persona p4("andres", 66666666);
    
    //Crear Red Social
    RedSocial redsocial;
    
    //Agregar las relaciones - Construir las aristas
    redsocial.agregar_arista(p1, p2);
    redsocial.agregar_arista(p1, p3);
    redsocial.agregar_arista(p1, p4);
    
    redsocial.agregar_arista(p2, p3);
    
    redsocial.agregar_arista(p3, p1);
    redsocial.agregar_arista(p3, p4);
    
    redsocial.agregar_arista(p4, p2);
    
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
//P4 Andres
    
    redsocial.imprimir();
    return 0;
}

