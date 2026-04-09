//
// Created by erasm on 9/04/2026.
//

#ifndef CREACIONLIBRERIAESTATICAUSANDOOTRA_SOBRECARGAS_HPP
#define CREACIONLIBRERIAESTATICAUSANDOOTRA_SOBRECARGAS_HPP
#include "Estructuras.hpp"

void operator++(struct Persona& p);
void operator++(struct Persona& p, int);
void operator--(struct Persona& p);
void operator--(struct Persona& p, int);

#endif //CREACIONLIBRERIAESTATICAUSANDOOTRA_SOBRECARGAS_HPP