//
// Created by erasmo on 5/6/26.
//

#include "Heroe.hpp"

Heroe::Heroe() {
    this->nombre = new char[20];
    strcpy(nombre, "Erasmo");
    ataque = 1000;
    defensa = 500;
    cout<<"Estoy en el constructor de HEROE"<<endl;
}

void Heroe::imprimir() {
    cout<<"Info del Heroe"<<endl;
    cout<<"NOMBRE ->"<<nombre<<endl;
    cout<<"ATAQUE ->"<<ataque<<endl;
    cout<<"DEFENSA ->"<<defensa<<endl;
}
