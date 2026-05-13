//
// Created by erasmo on 5/6/26.
//

#include "Personaje.hpp"

void Personaje::get_nombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Personaje::set_nombre(const char*nombre) {
    if (this->nombre!=nullptr) delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

int Personaje::get_vida() const {
    return vida;
}

void Personaje::set_vida(int vida) {
    this->vida = vida;
}

int Personaje::get_vida_maxima() const {
    return vida_maxima;
}

void Personaje::set_vida_maxima(int vida_maxima) {
    this->vida_maxima = vida_maxima;
}

int Personaje::get_ataque() const {
    return ataque;
}

void Personaje::set_ataque(int ataque) {
    this->ataque = ataque;
}

int Personaje::get_defensa() const {
    return defensa;
}

void Personaje::set_defensa(int defensa) {
    this->defensa = defensa;
}

int Personaje::get_fila() const {
    return fila;
}

void Personaje::set_fila(int fila) {
    this->fila = fila;
}

int Personaje::get_columna() const {
    return columna;
}

void Personaje::set_columna(int columna) {
    this->columna = columna;
}

void Personaje::operator++() {
    //W
    set_fila(fila-1);
}

void Personaje::operator++(int) {
    //S
    set_fila(fila+1);
}

void Personaje::operator--() {
    //D
    set_columna(columna+1);
}

void Personaje::operator--(int) {
    //I
    set_columna(columna-1);
}

Personaje::Personaje() {
    this->nombre = new char[20];
    strcpy(nombre, "SrCoca");
    ataque = 1000;
    defensa = 500;
    // cout<<"Estoy en el constructor de PERSONAJE"<<endl;
}

void Personaje::imprimir() {
    cout<<"Info del Personaje"<<endl;
    cout<<"NOMBRE ->"<<nombre<<endl;
    cout<<"ATAQUE ->"<<ataque<<endl;
    cout<<"DEFENSA ->"<<defensa<<endl;
}

void Personaje::imprimir(ofstream &output) {
    output<<"Info del Personaje"<<endl;
    output<<"NOMBRE ->"<<nombre<<endl;
    output<<"ATAQUE ->"<<ataque<<endl;
    output<<"DEFENSA ->"<<defensa<<endl;
}

void Personaje::leer(ifstream &input) {
    //Frisk,20,20,5,3,1,1
    char buffer[20];
    input.getline(buffer, 20, ',');
    if (input.eof()) return;
    set_nombre(buffer);
    input>>vida;
    input.get();
    input>>vida_maxima;
    input.get();
    input>>ataque;
    input.get();
    input>>defensa;
    input.get();
    input>>fila;
    input.get();
    input>>columna;
}

//Fuera de la CLASE

void operator >>(ifstream& input, class Personaje& personaje) {
    personaje.leer(input);
}

void operator <<(ofstream& output, class Personaje& personaje) {
    personaje.imprimir(output);
}