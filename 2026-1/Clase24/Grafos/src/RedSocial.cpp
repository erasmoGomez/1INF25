//
// Created by Erasmo on 11/11/25.
//

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
