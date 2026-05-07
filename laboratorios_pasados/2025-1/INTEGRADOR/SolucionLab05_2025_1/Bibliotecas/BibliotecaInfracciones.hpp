//
// Created by erasmo on 5/6/26.
//

#ifndef SOLUCIONLAB05_2025_1_BIBLIOTECAINFRACCIONES_HPP
#define SOLUCIONLAB05_2025_1_BIBLIOTECAINFRACCIONES_HPP
#include "BibliotecaGenerica.hpp"

void *buscalistainfraccion(void *lista, void *dato);

void *leeinfracciones(ifstream &arch);

int cmpplacas(void *a, void *b);

int cmpinfracciones(void *a, void *b);

void imprimeinfracciones(ofstream &arch, void *dato);

#endif //SOLUCIONLAB05_2025_1_BIBLIOTECAINFRACCIONES_HPP
