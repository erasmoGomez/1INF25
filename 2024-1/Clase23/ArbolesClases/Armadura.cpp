//
// Created by Erasmo on 3/06/24.
//

#include "Armadura.hpp"

Armadura::Armadura() {
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::SetModificador_def(int modificador_def) {
    this->modificador_def = modificador_def;
}

int Armadura::GetModificador_def() const {
    return modificador_def;
}

void Armadura::leer(ifstream &input){
    //Lectura de la clase padre
    Item::leer(input); //HERENCIA
    //Lectura de la clase derivada
    int valor;
    input>>valor;
    input.get();
    modificador_def = valor;
}

void Armadura::mostrar(ofstream&output){
    //Mostrar de la clase padre
    Item::mostrar(output);
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        output<<"El modificador de DEF es: "<<modificador_def<<endl;
    else
        output<<"El item se encuentra equipado"<<endl;
}

int Armadura::get_modificador() {
    return modificador_def;
}

void Armadura::mostrar(){
    //Mostrar de la clase padre
    Item::mostrar();
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        cout<<"El modificador de DEF es: "<<modificador_def<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
}
