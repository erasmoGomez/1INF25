/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Casilla.hpp"

Casilla::Casilla(){
    elemento = '_';
}

Casilla::Casilla(int x, int y, char e){
    this->x = x;
    this->y = y;
    elemento = e;
}

void Casilla::leer(ifstream &input){
    char extra;
    input>>x>>extra;
    input>>y>>extra;
    input>>elemento;
}

void Casilla::mostrar(ostream &output){
    output<<setw(1)<<'|'<<elemento<<setw(1)<<'|';
}

void Casilla::setY(int y) {
    this->y = y;
}

int Casilla::getY() const {
    return y;
}

void Casilla::setX(int x) {
    this->x = x;
}

int Casilla::getX() const {
    return x;
}

void Casilla::setElemento(char elemento) {
    this->elemento = elemento;
}

char Casilla::getElemento() const {
    return elemento;
}

void operator>>(ifstream&input, Casilla& c){
    c.leer(input);
}

//void operator>>(ifstream&input, Casilla& c){
//    char extra, elemento;
//    int x,y;
//    input>>x>>extra;
//    input>>y>>extra;
//    input>>elemento;
//    c.setX(x);
//    c.setY(y);
//    c.setElemento(elemento);
//}

void operator<<(ostream&output, Casilla c){
    c.mostrar(output);
}