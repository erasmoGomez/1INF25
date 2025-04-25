/* 
 * Archivo: Repartidor.hpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:36
 */

#ifndef REPARTIDOR_HPP
#define REPARTIDOR_HPP
#include <fstream>

using namespace std;

struct Repartidor{
    char *codigo;
    char *nombre;    
    char *vehiculo;
};

bool operator>>(istream &archivo_de_repartidores, Repartidor &repartidor);

ostream & operator<<(ostream &out, const Repartidor &repartidor);

#endif /* REPARTIDOR_HPP */

