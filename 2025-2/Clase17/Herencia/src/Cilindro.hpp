//
// Created by Erasmo on 1/10/25.
//

#ifndef HERENCIA_CILINDRO_HPP
#define HERENCIA_CILINDRO_HPP

#include "Circulo.hpp"
class Cilindro: public Circulo{
private:
    int altura;
public:
    double volumen();
};


#endif //HERENCIA_CILINDRO_HPP
