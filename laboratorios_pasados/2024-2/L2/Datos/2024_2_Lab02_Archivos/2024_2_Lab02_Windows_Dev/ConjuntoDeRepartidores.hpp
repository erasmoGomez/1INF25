/* 
 * Archivo: ConjuntoDeRepartidores.hpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#ifndef CONJUNTODEREPARTIDORES_HPP
#define CONJUNTODEREPARTIDORES_HPP
#include "Repartidor.hpp"

struct ConjuntoDeRepartidores{
    Repartidor *conjunto_de_datos;
    int cantidad;
};

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo);

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores);

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores);

#endif /* CONJUNTODEREPARTIDORES_HPP */

