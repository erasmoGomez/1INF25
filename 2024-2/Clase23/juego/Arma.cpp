/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 22, 2024, 6:12 PM
 */

#include "Arma.hpp"

Arma::Arma() {
    modificador_ataque = 0;
}

Arma::Arma(const Arma& orig) {
}

Arma::~Arma() {
}

void Arma::SetModificador_ataque(int modificador_ataque) {
    this->modificador_ataque = modificador_ataque;
}

int Arma::GetModificador_ataque() const {
    return modificador_ataque;
}

void Arma::leer(ifstream&input){
    //LLamar a la clase padre y su metodo de lectura
    //Sword,A sharp and sturdy sword.,
    //Item - Consumible/Armadura/Arma
    Item::leer(input); // nombre y descripcion llenos para consumible
    //Se usa el proceso de lectura de la clase hija
    //147
    //Consumible/Armadura/Arma
    input>>modificador_ataque;
    input.get();
    Item::SetEquipadoQ(false);
}

void Arma::mostrar(){
    cout<<"Item de tipo Arma"<<endl;
    Item::mostrar();
    bool is_equipado = IsEquipadoQ();
    if(not IsEquipadoQ())
        cout<<"El modificador de Ataque es "<<modificador_ataque<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
                
}

int Arma::get_valor(){
    return GetModificador_ataque();
}