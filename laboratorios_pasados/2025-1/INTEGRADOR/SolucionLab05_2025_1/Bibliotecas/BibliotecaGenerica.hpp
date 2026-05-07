//
// Proyecto: SolucionLab05_2025_1
// Archivo : BibliotecaGenerica.hpp.h.cpp
// Autor   : J Miguel Guanira E
//
// Creado el viernes 06 de junio del 2025 a las 11:30
//
#ifndef SOLUCIONLAB05_2025_1_BIBLIOTECAGENERICA_HPP_H
#define SOLUCIONLAB05_2025_1_BIBLIOTECAGENERICA_HPP_H
#include "Utils.hpp"

void insertalista(void *&lista, void *dato, int (*cmp)(void *, void *));

void creaLista(void *&lista, void *(*lee)(ifstream &), int (*cmp)(void *, void *),
               void *(*busca)(void *, void *), const char *nombre);

void imprimelista(void *lista, void (*imprime)(ofstream &, void *), const char *nombre);

void generaLista(void *&lista);

#endif //SOLUCIONLAB05_2025_1_BIBLIOTECAGENERICA_HPP_H
