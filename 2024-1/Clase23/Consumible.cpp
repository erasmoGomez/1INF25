//
// Created by Erasmo on 3/06/24.
//

#include "Consumible.hpp"

Consumible::Consumible() {
    modificador_hp = 0;
}

Consumible::Consumible(const Consumible& orig) {
}

Consumible::~Consumible() {
}

void Consumible::SetModificador_hp(int modificador_hp) {
    this->modificador_hp = modificador_hp;
}

int Consumible::GetModificador_hp() const {
    return modificador_hp;
}

void Consumible::leer(ifstream &input){
    //Lectura de la clase padre
    Item::leer(input);
    //Lectura de la clase derivada
    int valor;
    input>>valor;
    input.get();
    modificador_hp = valor;
}

void Consumible::mostrar(ofstream&output){
    //Mostrar de la clase padre
    Item::mostrar(output);
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        output<<"El modificador de HP es: "<<modificador_hp<<endl;
    else
        output<<"El item se encuentra equipado"<<endl;
}

int Consumible::get_modificador(){
    return modificador_hp;
}

void Consumible::mostrar(){
    //Mostrar de la clase padre
    Item::mostrar(); //Herencia
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        cout<<"El modificador de HP es: "<<modificador_hp<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
}