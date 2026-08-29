//
// Created by erasm on 9/04/2026.
//

#include "Sobrecargas.hpp"


void operator++(struct Persona &p) {
    p.edad++;
}

void operator++(struct Persona &p, int) {
    p.salario += 500.5;
}

void operator--(struct Persona &p) {
    p.edad--;
}

void operator--(struct Persona &p, int) {
    p.salario -= 205.5;
}
