/* 
 * Archivo: ConjuntoDePlatos.hpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:49
 */

#ifndef CONJUNTODEPLATOS_HPP
#define CONJUNTODEPLATOS_HPP
#include "Plato.hpp"
#define PLATO_NO_ENCONTRADO -1

struct ConjuntoDePlatos{
    Plato *conjunto_de_datos;
    int cantidad;
};

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo);

void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos);

void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos);

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo);

void operator~(ConjuntoDePlatos &conjuntoDePlatos);

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo);

#endif /* CONJUNTODEPLATOS_HPP */

