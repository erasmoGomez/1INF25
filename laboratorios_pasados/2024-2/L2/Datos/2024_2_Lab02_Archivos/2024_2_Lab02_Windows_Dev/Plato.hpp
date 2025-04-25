/* 
 * Archivo: Plato.hpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:41
 */

#ifndef PLATO_HPP
#define PLATO_HPP
#include <fstream>

using namespace std;

struct Plato{
    char *codigo;
    char *nombre;
    double precio;
    char *tipo;
};

bool operator>>(istream &archivo_de_platos, Plato &plato);

ostream & operator<<(ostream &out, const Plato &plato);

bool operator>(const Plato &platoI, const Plato &platoJ);

#endif /* PLATO_HPP */

