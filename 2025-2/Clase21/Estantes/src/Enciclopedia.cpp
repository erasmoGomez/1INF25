//
// Created by Erasmo on 22/10/25.
//

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {
    volumen = 0;
    peso = 0;
}

Enciclopedia::Enciclopedia(const Enciclopedia &orig) {
    *this = orig;
}

int Enciclopedia::getVolumen() const {
    return volumen;
}

void Enciclopedia::setVolumen(int volumen) {
    Enciclopedia::volumen = volumen;
}

double Enciclopedia::getPeso() const {
    return peso;
}

void Enciclopedia::setPeso(double peso) {
    Enciclopedia::peso = peso;
}

void Enciclopedia::leer(ifstream &input) {
    //1, 6.30
    Libro::leer(input);
    input >> volumen;
    input.get();
    input >> peso;
}

void Enciclopedia::mostrar(ofstream &output) const {
    char _codigo[10], _nombre[40];
    GetCodigo(_codigo);
    GetNombre(_nombre);
    if (IsColocado())
        output << setw(10) << _codigo << setw(30) << _nombre << setw(8) << GetAncho() << setw(5) << GetAlto() << endl;
    else
        output << setw(10) << _codigo << setw(30) << "NO SE PUDO COLOCAR" << setw(8) << GetAncho() << setw(5)
               << GetAlto() << endl;
}

void Enciclopedia::operator=(const Enciclopedia &orig) {
    char _nombre[40], _codigo[10];
    orig.GetCodigo(_codigo);
    orig.GetNombre(_nombre);
    SetCodigo(_codigo);
    SetNombre(_nombre);
    SetColocado(orig.IsColocado());
    SetAlto(orig.GetAlto());
    SetAncho(orig.GetAncho());
    setVolumen(orig.volumen);
    setPeso(orig.peso);
}

void operator>>(ifstream &input, Enciclopedia &e) {
    e.leer(input);
}

void operator<<(ofstream &output, const Enciclopedia &e) {
    e.mostrar(output);
}