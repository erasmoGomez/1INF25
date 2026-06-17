//
// Created by erasmo on 5/6/26.
//

#include "Personaje.hpp"

void Personaje::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Personaje::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete [] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
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

bool Personaje::mover(char mov, class Mapa &mapa) {
    int nuevo_posX = fila;
    int nuevo_posY = columna;
    if (mov == 'W') nuevo_posX -= 1;
    if (mov == 'S') nuevo_posX += 1;
    if (mov == 'D') nuevo_posY += 1;
    if (mov == 'A') nuevo_posY -= 1;
    //Verificar si me encuentro dentro del mapa
    //Verificar si es transitable o no
    if (mapa.estoy_dentro(nuevo_posX, nuevo_posY) and mapa.es_transitable(nuevo_posX, nuevo_posY))
        return true;
    return false;
}

void Personaje::atacar() {
    cout << "El persona esta atacando!" << endl;
}

void Personaje::leer_item(char *tipo, ifstream &input) {
    mochila.leer_item(tipo, input);
}

void Personaje::equipar(int tipo, const char *nombre_item) {
    int modificador = 0;
    switch (tipo) {
        case 0: modificador = mochila.equipar_arma(nombre_item);
            ataque += modificador;
            break;
        case 1: modificador = mochila.equipar_armadura(nombre_item);
            defensa += modificador;
            break;
        case 2: modificador = mochila.equipar_consumible(nombre_item);
            vida += modificador;
            break;
        default: break;
    }
}

void Personaje::operator++() {
    //W
    set_fila(fila - 1);
}

void Personaje::operator++(int) {
    //S
    set_fila(fila + 1);
}

void Personaje::operator--() {
    //D
    set_columna(columna + 1);
}

void Personaje::operator--(int) {
    //I
    set_columna(columna - 1);
}

Personaje::Personaje() {
    this->nombre = new char[20];
    strcpy(nombre, "SrCoca");
    ataque = 1000;
    defensa = 500;
    // cout<<"Estoy en el constructor de PERSONAJE"<<endl;
}

Personaje::Personaje(const char *nombre) {
    set_nombre(nombre);
}

void Personaje::imprimir(ostream &output) {
    output << nombre << endl;
}

void Personaje::imprimir(ofstream &output) {
    output << "NOMBRE ->" << nombre << endl;
}

void Personaje::leer(ifstream &input) {
    //Frisk,20,20,5,3,1,1
    char buffer[20];
    input.getline(buffer, 20, ',');
    if (input.eof()) return;
    set_nombre(buffer);
    input >> vida;
    input.get();
    input >> vida_maxima;
    input.get();
    input >> ataque;
    input.get();
    input >> defensa;
    input.get();
    input >> fila;
    input.get();
    input >> columna;
    input.get();
}

void Personaje::operator=(const Personaje &p) {
    //Priorizar los char*
    char _nombre[60];
    vida = p.get_vida();
    ataque = p.get_ataque();
    defensa = p.get_defensa();
    p.get_nombre(_nombre);
    set_nombre(_nombre);
    fila = p.get_fila();
    columna = p.get_columna();
}

bool Personaje::operator>(const class Personaje &h) {
    char _nombre[60];
    h.get_nombre(_nombre);
    return strcmp(this->nombre, _nombre)>0;
}

bool Personaje::operator==(const Personaje &otro) const {
    return strcmp(nombre, otro.nombre) == 0;
}


Personaje::Personaje(const Personaje &orig) {
    nombre = nullptr;
    *this = orig;
}

//Fuera de la CLASE

void operator >>(ifstream &input, class Personaje &personaje) {
    personaje.leer(input);
}

void operator <<(ofstream &output, class Personaje &personaje) {
    personaje.imprimir(output);
}

void operator <<(ostream &output, class Personaje &personaje) {
    personaje.imprimir(cout);
}