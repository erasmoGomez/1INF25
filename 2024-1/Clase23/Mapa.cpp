//
// Created by Erasmo on 8/05/24.
//
#include "Mapa.hpp"
using namespace std;
Mapa::Mapa() {
    filas = 20;
    columnas = 20;
    this->casillas = new Casilla[filas*columnas];
}

Mapa::~Mapa() {
    cout<<"destructor"<<endl;
}

void Mapa::leer(ifstream &input) {
    Casilla c;
    //19,6,#
    while(true){
        input>>c;
        if (input.eof()) break;
        casillas[c.getX()*columnas+c.getY()] = c;
    }
}

void Mapa::mostrar() {
    for (int i=1;i<=filas*columnas;i++){
        cout<<casillas[i-1];
        if(i%(columnas)==0) cout<<endl;
    }

}

void Mapa::inicializar() {
    Casilla c;
    for (int i=1;i<=filas*columnas;i++){
        casillas[i-1] = c;
    }
}

void Mapa::operator+=(Heroe &h) {
    char buffer[20];
    h.getNombre(buffer);
    Casilla c(h.getPosx(), h.getPosy(), buffer[0]);
    casillas[(h.getPosx()-1)*columnas+h.getPosy()-1] = c;
}