//
// Created by Erasmo on 22/10/25.
//

#include "Novela.hpp"

Novela::Novela() {
    tipo = nullptr;
    peso = 0;
}

Novela::Novela(const Novela &orig) {
    *this = orig;
}

double Novela::getPeso() const {
    return peso;
}

void Novela::setPeso(double peso) {
    Novela::peso = peso;
}

void Novela::SetTipo(const char *tipo) {
    if (this->tipo != nullptr) delete this->tipo;
    this->tipo = new char[strlen(tipo) + 1];
    strcpy(this->tipo, tipo);
}

void Novela::GetTipo(char *tipo) const {
    if (this->tipo == nullptr) tipo[0] = 0;
    else strcpy(tipo, this->tipo);
}

void Novela::operator=(const Novela &orig) {
    char _nombre[40], _codigo[10], _tipo[20];
    orig.GetCodigo(_codigo);
    orig.GetNombre(_nombre);
    orig.GetTipo(_tipo);
    SetCodigo(_codigo);
    SetNombre(_nombre);
    SetColocado(orig.IsColocado());
    SetAlto(orig.GetAlto());
    SetAncho(orig.GetAncho());
    tipo = nullptr;
    SetTipo(_tipo);
    setPeso(orig.peso);
}

Novela::~Novela() {
    delete tipo;
}

void Novela::leer(ifstream &input) {
    // Aventura, 0.75
    Libro::leer(input);
    char _tipo[20];
    input.getline(_tipo, 20, ',');
    input >> peso;
    SetTipo(_tipo);
}

void Novela::mostrar(ofstream &output) const{
    char _codigo[10], _nombre[40];
    GetCodigo(_codigo);
    GetNombre(_nombre);
    if (IsColocado())
        output << setw(10) << _codigo << setw(30) << _nombre << setw(8) << GetAncho() << setw(5) << GetAlto() << endl;
    else
        output << setw(10) << _codigo << setw(30) << "NO SE PUDO COLOCAR" << setw(8) << GetAncho() << setw(5)
               << GetAlto() << endl;
}

void operator<<(ofstream& output, const Novela &n){
    n.mostrar(output);
}