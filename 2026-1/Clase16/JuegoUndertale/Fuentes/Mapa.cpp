//
// Created by erasmo on 5/12/26.
//

#include "Mapa.hpp"

void Mapa::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Mapa::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete [] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Mapa::get_ancho() const {
    return ancho;
}

void Mapa::set_ancho(int ancho) {
    this->ancho = ancho;
}

int Mapa::get_alto() const {
    return alto;
}

void Mapa::set_alto(int alto) {
    this->alto = alto;
}

Mapa::Mapa() {
    ancho = 0;
    alto = 0;
    casillas = nullptr;
    nombre = nullptr;
    cantidad_personajes = 0;
}

Mapa::Mapa(int ancho, int alto, const char* nombre) {
    Mapa();
    set_nombre(nombre);
    this->ancho = ancho;
    this->alto = alto;
    if (this->casillas != nullptr) delete[] this->casillas;
    this->casillas = new Casilla[this->alto * this->ancho];
}

Mapa::Mapa(const Mapa &orig) {
    this->alto = orig.alto;
    this->ancho = orig.ancho;
    set_nombre(orig.nombre);
    for (int i = 0; i < this->ancho * this->alto; i++)
        this->casillas[i] = orig.casillas[i];
}

Mapa::~Mapa() {
    delete[] this->nombre;
    delete [] this->casillas;
}

void Mapa::cargar_mapa(ifstream &input) {
    char contenido;
    input >> ancho;
    input.get();
    input >> alto;
    //cout<<ancho<<" "<<alto<<endl;
    // RESERVAR MEMORIA CASILLAS
    this->casillas = new Casilla[this->alto * this->ancho]{};

    for (int i = 0; i < alto; i++)
        for (int j = 0; j < ancho; j++) {
            input >> contenido;
            bool transitable = contenido != '#';
            Casilla c(transitable, contenido);
            casillas[j * ancho + i] = c;
        }
}

void Mapa::mostrar_mapa() {
    cout << nombre << endl;
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++)
            cout << casillas[j * ancho + i];
        cout << endl;
    }
}

void Mapa::operator+=(class Personaje p) {
    char buffer[20];
    p.get_nombre(buffer);
    // cout<<buffer<<endl;
    Casilla c(false, buffer[0]);
    //c.imprimir(cout);
    casillas[p.get_columna() * ancho + p.get_fila()] = c;
    cantidad_personajes++;
}
