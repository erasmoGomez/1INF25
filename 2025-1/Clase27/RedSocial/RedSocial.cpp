/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedSocial.cpp
 * Author: hecto
 * 
 * Created on June 18, 2025, 5:01 PM
 */

#include "RedSocial.hpp"

RedSocial::RedSocial() {
}

RedSocial::RedSocial(const RedSocial& orig) {
}

RedSocial::~RedSocial() {
}

void RedSocial::agregar_arista(const Persona& key, const Persona& elemento){
    //map<Persona, vector<Persona>> adyacencias;
    adyacencias[key].push_back(elemento);
}

void RedSocial::imprimir(){
    for(auto& par: adyacencias){
        //Obtener el Key
        Persona persona = par.first;
        cout<<"Persona: ";
        persona.imprimir();
        cout<<"Se encuentra conectada con: "<<endl;
        //Obtener mi Value
        for(const Persona& vecino:par.second) // Value -> vector<Persona> //recorrer el vector
            vecino.imprimir();
        cout<<"*****************"<<endl;
    }
}