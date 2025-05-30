/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 22, 2024, 6:12 PM
 */

#include "Armadura.hpp"

Armadura::Armadura() {
    modificador_defensa = 0;
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::SetModificador_defensa(int modificador_defensa) {
    this->modificador_defensa = modificador_defensa;
}

int Armadura::GetModificador_defensa() const {
    return modificador_defensa;
}

void Armadura::leer(ifstream&input){
    //LLamar a la clase padre y su metodo de lectura
    //Sword,A sharp and sturdy sword.,
    //Item - Consumible/Armadura/Arma
    Item::leer(input); // nombre y descripcion llenos para consumible
    //Se usa el proceso de lectura de la clase hija
    //147
    //Consumible/Armadura/Arma
    input>>modificador_defensa;
    input.get();
    Item::SetEquipadoQ(false);
}

void Armadura::mostrar(){
    cout<<"Item de tipo Armadura"<<endl;
    Item::mostrar();
    if(not IsEquipadoQ())
        cout<<"El modificador de Defensa es "<<modificador_defensa<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
                
}

int Armadura::get_valor(){
    return GetModificador_defensa();
}