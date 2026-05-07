//
// Created by erasmo on 5/6/26.
//

#ifndef SOLUCIONLAB05_2025_1_BIBLIOTECACONDUCTORES_HPP
#define SOLUCIONLAB05_2025_1_BIBLIOTECACONDUCTORES_HPP
#include "BibliotecaGenerica.hpp"
#include "BibliotecaInfracciones.hpp"

void *leeconductores(ifstream & arch);

void imprimeconductores(ofstream &arch, void *dato);

int cmpconductores(void *a, void *b);

void *buscaconductor(void *lista, int licencia);

void cargaUnidades(void *&lista, const char *nombre);

int compara(const void *a, const void *b);

void cargaplaca(void *&placas, char *placa);

void ordenacorta(void *&);

void imprimelistaint(void *lista, void (*imprime)(ofstream &, void *),
                     ofstream &arch);

void *buscalistaconductores(void *lista, void *dato);

#endif //SOLUCIONLAB05_2025_1_BIBLIOTECACONDUCTORES_HPP
