//
// Created by Erasmo on 22/10/25.
//

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {
    // PRIMERO se llama al constructor del PADRE automaticamente
    volumen = 0;
    peso = 0;
    // SetColocado(true); // Uso el metodo de la clase padre
}

Enciclopedia::Enciclopedia(const Enciclopedia &orig) {
    *this = orig;
}

void Enciclopedia::leer(ifstream &input) {
    //EFG123, La enciclopedia de la Vida, 2, 4, 1, 6.30
    Libro::leer(input);
    //1, 6.30
    input>>volumen;
    input.get();
    input>>peso;
    input.get();
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
