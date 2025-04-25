/* 
 * Archivo: Plato.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:42
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Plato.hpp"
#include "Comunes.hpp"

using namespace std;

bool operator>>(istream &archivo_de_platos, Plato &plato) {
    char buffer_codigo[7];
    char buffer_nombre[100];
    double buffer_precio;
    char buffer_tipo[50];

    archivo_de_platos.getline(buffer_codigo, 7, ',');
    if (archivo_de_platos.eof())
        return false;
    archivo_de_platos.getline(buffer_nombre, 100, ',');
    archivo_de_platos>>buffer_precio;
    archivo_de_platos.get(); //sacamos la coma    
    archivo_de_platos.getline(buffer_tipo, 50);

    plato.codigo = mi_strdup(buffer_codigo);
    plato.nombre = mi_strdup(buffer_nombre);
    plato.precio = buffer_precio;
    plato.tipo = mi_strdup(buffer_tipo);
    return true;
}

ostream & operator<<(ostream &out, const Plato &plato) {
    out << setw(10) << plato.codigo;
    out << setw(20) << plato.nombre;
    out << setw(6) << plato.precio;
    out << setw(15) << plato.tipo;
    return out;
}

bool operator>(const Plato &platoI, const Plato &platoJ) {
    return strcmp(platoI.codigo, platoJ.codigo) > 0;
}