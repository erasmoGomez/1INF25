/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Pokeball.hpp"
Pokeball::Pokeball(){
}

void Pokeball::SetValor(int valor) {
    this->valor = valor;
}

int Pokeball::GetValor() const {
    return valor;
}

//void Pokeball::mostrar(){
//    char nombre[20], descripcion[50];
//    GetNombre(nombre);
//    GetDescripcion(descripcion);
//    cout<<"Clase Hija"<<endl;
//    cout<<setw(20)<<nombre;
//    cout<<setw(50)<<descripcion<<endl;
//    cout<<setw(5)<<valor;
//}

void Pokeball::mostrar(){
    Item::mostrar();
    cout<<"Clase Hija"<<endl;
    cout<<setw(5)<<valor<<endl;
}
