/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrafoDirigido.cpp
 * Author: alulab14
 * 
 * Created on 15 de junio de 2024, 09:00 AM
 */

#include "GrafoDirigido.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

GrafoDirigido::GrafoDirigido() {
}

GrafoDirigido::GrafoDirigido(const GrafoDirigido& orig) {
}

GrafoDirigido::~GrafoDirigido() {
}

void GrafoDirigido::agregarArista(const Persona& origen, const Persona& destino) {
    //Persona new_destino("",0);
    adyacencias[origen].push_back(destino);
}

void GrafoDirigido::imprimirGrafo() const {
    for (const auto& par : adyacencias) { //For each
        Persona persona = par.first; //Key
        cout << "Persona: ";
        persona.imprimirPersona();
        cout << "Conectada con:"<<endl;
        for (const Persona& vecino : par.second) { //Recorrer los values
            vecino.imprimirPersona();
        }
        cout <<"*************"<<endl;
    }
}
