//
// Created by Erasmo on 30/09/25.
//

#include "Mapa.hpp"

Mapa::Mapa() {
    ancho = 0;
    alto = 0;
    casillas = nullptr;
}

Mapa::Mapa(int ancho, int alto) {
    this->ancho = ancho;
    this->alto = alto;
    if(this->casillas!= nullptr) delete[] this->casillas;
    this->casillas = new Casilla[this->alto*this->ancho];
}

Mapa::Mapa(const Mapa &orig) {
    this->alto = orig.alto;
    this->ancho = orig.ancho;
    for(int i = 0; i< this->ancho*this->alto; i++)
        this->casillas[i] = orig.casillas[i];
}

Mapa::~Mapa() {
    delete [] this->casillas;
}

void Mapa::cargar_mapa(ifstream & input) {
    int contenido;
    input>>ancho;
    input.get();
    input>>alto;
    this->casillas = new Casilla[this->alto*this->ancho]{};
    for(int i=0; i<alto; i++)
        for(int j = 0; j<ancho; j++){
            input>>contenido;
            bool transitable = contenido == 1;
            Casilla c(transitable);
            casillas[j*ancho + i] = c;
            input.get();
        }
}

void Mapa::mostrar_mapa() {
    for(int i = 0; i<alto;i++){
        for(int j=0; j<ancho; j++)
            cout<<casillas[j*ancho+i];
        cout<<endl;
    }
}

void Mapa::operator+=(class Heroe h) {
    char buffer[20];
    h.getNombre(buffer);
    Casilla c;
    c.setSprite(buffer[0]);
    casillas[h.getPosy()*ancho + h.getPosx()] = c;
}
