/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Consumible.hpp"

Consumible::Consumible(){
}

void Consumible::SetValor(int valor) {
    this->valor = valor;
}

int Consumible::GetValor() const {
    return valor;
}

void Consumible::mostrar(){
    Item::mostrar();
    cout<<"Clase Hija 2"<<endl;
    cout<<setw(5)<<valor<<endl;
}