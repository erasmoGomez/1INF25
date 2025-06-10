/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 5:39 PM
 */

#include "Arma.hpp"

Arma::Arma() {
}

Arma::Arma(const Arma& orig) {
}

Arma::~Arma() {
}

void Arma::setModificador_poder(int modificador_poder) {
    this->modificador_poder = modificador_poder;
}

int Arma::getModificador_poder() const {
    return modificador_poder;
}

void Arma::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    //cout<<"Me llamaron de cargar_items y soy Arma"<<endl;
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_poder;
    input.get();
}

void Arma::mostrar(ostream&output) const{
    Item::mostrar(output);
    output<<setw(5)<<left<<modificador_poder<<setw(10)<<(IsEquipado() ? "EQUIPADO" : "NO EQUIPADO")<<endl;
}

int Arma::get_valor(){
    return modificador_poder;
}