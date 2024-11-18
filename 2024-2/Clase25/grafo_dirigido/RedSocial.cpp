/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedSocial.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on November 12, 2024, 6:05 PM
 */

#include "RedSocial.hpp"

RedSocial::RedSocial() {
}

RedSocial::RedSocial(const RedSocial& orig) {
}

RedSocial::~RedSocial() {
}

void RedSocial::agregar_relacion(const Persona& key, const Persona& elemento){
    //map<Persona,vector<Persona>> adyacencias;
    //Vector de personas
    adyacencias[key].push_back(elemento);
}

void RedSocial::imprimir(){
    for(auto& par: adyacencias){ //Recorriendo el mapa
        Persona persona = par.first; //Key -> Persona
        cout<< "Persona: ";
        persona.imprimir_persona();
        cout<<"Conectadada con: "<<endl;
        for(const Persona& vecino: par.second)//Value -> vector<Persona> //Recorriendo el vector
            vecino.imprimir_persona();
        cout<<"************"<<endl;
    }
}