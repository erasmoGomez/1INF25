//
// Created by Erasmo on 1/10/25.
//

#ifndef HERENCIA_CIRCULO_HPP
#define HERENCIA_CIRCULO_HPP

#include <iostream>
#include <iomanip>

class Circulo {
private:
    int radio;
    char *nombre;
public:
    Circulo();

    double area();

    double perimetro();

    void mostrarResultados();
};


#endif //HERENCIA_CIRCULO_HPP
