//
// Created by Erasmo on 22/10/25.
//

#include "Libro.hpp"

string Libro::get_codigo() const {
    return codigo;
}

void Libro::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Libro::get_nombre() const {
    return nombre;
}

void Libro::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

Libro::Libro() {
    alto = 0;
    ancho = 0;
    colocado = false;
}

Libro::Libro(const Libro& orig) {
    // cout<<"Estoy en el constructor Copia"<<endl;
    *this = orig;
}

Libro::~Libro() {
    //cout<<"Me llamaron x ahi Soy El Destructor"<<endl;
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


void Libro::leer(ifstream& input){
    //ABC123, El libro de la Selva, 2, 5,
    //EFG123, La enciclopedia de la Vida, 2, 4,

    // PRIMERA FORMA DE LECTURA CON STRING
    char buffer[50];
    input.getline(buffer, 50, ',');
    codigo = buffer; // ESTO ASIGNA EL buffer al string

    // SEGUNDA FORMA DE LECTURA CON STRING
    getline(input, nombre, ',');

    input>>ancho;
    input.get();
    input>>alto;
    input.get();
}

void Libro::mostrar(ofstream &output) const {
    if(colocado)
        output << setw(10) << codigo << setw(30) << nombre << setw(8) << ancho << setw(5) << alto << endl;
    else
        output << setw(10) << codigo << setw(30) << "NO SE PUDO COLOCAR" << setw(8) << ancho << setw(5) << alto << endl;
}

void Libro::operator = (const class Libro& orig){
    //cout<<"Estoy en la sobrecarga del ="<<endl;
    nombre = orig.nombre; // Esto es string: Ya existe una sobrecarga de asignacion (=) hecha para string
    codigo = orig.codigo;
    SetAlto(orig.GetAlto());
    SetAncho(orig.GetAncho());
    SetColocado(orig.IsColocado());
}

void operator>>(ifstream& input, Libro &l){
    l.leer(input);
}


void operator<<(ofstream& output, const Libro &l) {
    l.mostrar(output);
}
