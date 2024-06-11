//
// Created by Erasmo on 3/06/24.
//

#include "Arma.hpp"

Arma::Arma() {
}

Arma::Arma(const Arma& orig) {
}

Arma::~Arma() {
}

void Arma::SetModificador_att(int modificador_att) {
    this->modificador_att = modificador_att;
}

int Arma::GetModificador_att() const {
    return modificador_att;
}

void Arma::leer(ifstream &input){
    //Lectura de la clase padre
    Item::leer(input);  //Aplica herencia
    //Lectura de la clase derivada
    int valor;
    input>>valor;
    input.get();
    modificador_att = valor;
}

void Arma::mostrar(ofstream&output){
    //Mostrar de la clase padre
    Item::mostrar(output);
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        output<<"El modificador de ATT es: "<<modificador_att<<endl;
    else
        output<<"El item se encuentra equipado"<<endl;
}

int Arma::get_modificador() {
    return modificador_att;
}

void Arma::mostrar(){
    //Mostrar de la clase padre
    Item::mostrar();
    //Mostrar de la clase derivada
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        cout<<"El modificador de ATT es: "<<modificador_att<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
}