//
// Created by Erasmo on 1/10/25.
//

#include "Cilindro.hpp"

double Cilindro::volumen() {
    //Area circulo * Altura
    return Circulo::area()*altura;
}
