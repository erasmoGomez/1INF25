/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "mapa.hpp"
Mapa::Mapa(){
    filas = 20;
    columnas = 20;
    casillas = new Casilla[filas * columnas]{}; 
}

void Mapa::leer(ifstream&input){
    Casilla c;
    while(true){
        input>>c;
        if(input.eof())break;
        casillas[c.getX()*columnas + c.getY()] = c;  //2D a 1D
    }
}

void Mapa::mostrar(){
    for(int i=1; i<=filas*columnas;i++){
        cout<<casillas[i-1];
        if(i%columnas == 0) cout<<endl;
    }
}

void Mapa::operator+=(Heroe h){
    // x, y, e = Erasmo
    char buffer[20];
    h.getNombre(buffer);
    Casilla c(h.getPosx(), h.getPosy(), buffer[0]);
    casillas[(h.getPosx()-1)*columnas + h.getPosy()-1] = c;
}