//
// Created by erasmo on 5/5/26.
//

#ifndef L5_20252_BIBLIOTECAGENERICA_HPP
#define L5_20252_BIBLIOTECAGENERICA_HPP
#include "Utils.hpp"

void crealista(void *&lista, void *(*leenumeros)(ifstream &), const char *nomArch);

void cargalista(void *&lista, bool (*compruebanumero)(void *, void *), void *(*leeregnumeros)(ifstream &),
                const char *nomArch);

void muestralista(void *lista, void (*imprimenumeros)(ofstream &, void *, void *), const char *nomArch);

void construir(void *&list);

void creaDupla(void *&dup, void *dato);

bool eslitavacia(void *list);

void insertafinal(void *&list, void *dato);
#endif //L5_20252_BIBLIOTECAGENERICA_HPP
