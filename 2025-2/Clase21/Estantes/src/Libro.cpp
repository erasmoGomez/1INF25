//
// Created by Erasmo on 22/10/25.
//

#include "Libro.hpp"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    alto = 0;
    ancho = 0;
    colocado = false;
}

Libro::Libro(const Libro &orig) {
    //cout<<"Estoy en el constructor Copia"<<endl;
    *this = orig;
}

Libro::~Libro() {
    //cout << "Me llamaron desde el destructor de Estante y estoy en Destructor de Libro" << endl;
    delete codigo;
    delete nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Libro::SetCodigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Libro::GetCodigo(char *codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Libro::leer(ifstream &input) {
    //ABC123, El libro de la Selva, 2, 5,
    char _codigo[10], _nombre[40], c;
    input.getline(_codigo, 10, ',');
    input.getline(_nombre, 40, ',');
    input >> ancho;
    input.get();
    input >> alto;
    input.get();
    SetCodigo(_codigo);
    SetNombre(_nombre);
    colocado = false;
}

void Libro::mostrar(ofstream &output) const {
    char _codigo[10], _nombre[40], c;
    GetCodigo(_codigo);
    GetNombre(_nombre);
    if (colocado)
        output << setw(10) << codigo << setw(40) << nombre << setw(8) << ancho << setw(5) << alto << endl;
    else
        output << setw(10) << codigo << setw(40) << "NO SE PUDO COLOCAR" << setw(8) << ancho << setw(5) << alto << endl;
}

void Libro::operator=(const class Libro &orig) {
    // cout<<"Estoy en la sobrecarga del ="<<endl;
    char buffer[50];
    nombre = nullptr;
    codigo = nullptr;
    orig.GetNombre(buffer);
    SetNombre(buffer);
    orig.GetCodigo(buffer);
    SetCodigo(buffer);
    SetAlto(orig.GetAlto());
    SetAncho(orig.GetAncho());
}

void operator>>(ifstream &input, Libro &l) {
    l.leer(input);
}


void operator<<(ofstream &output, const Libro &l) {
    l.mostrar(output);
}
