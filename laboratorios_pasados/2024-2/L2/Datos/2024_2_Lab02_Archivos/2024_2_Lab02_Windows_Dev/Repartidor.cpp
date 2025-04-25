/* 
 * Archivo: Repartidor.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:36
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Repartidor.hpp"
#include "Comunes.hpp"

using namespace std;


bool operator>>(istream &archivo_de_repartidores, Repartidor &repartidor){
    char buffer_codigo[7];
    char buffer_nombre[100];    
    char buffer_vehiculo[50];

    archivo_de_repartidores.getline(buffer_codigo, 7, ',');
    if (archivo_de_repartidores.eof())
        return false;
    archivo_de_repartidores.getline(buffer_nombre, 100, ',');    
    archivo_de_repartidores.getline(buffer_vehiculo, 50);
        
    repartidor.codigo = mi_strdup(buffer_codigo);
    repartidor.nombre = mi_strdup(buffer_nombre);    
    repartidor.vehiculo = mi_strdup(buffer_vehiculo);
    return true;
    
}

ostream & operator<<(ostream &out, const Repartidor &repartidor){
    out<<setw(10)<<repartidor.codigo;
    out<<setw(20)<<repartidor.nombre;    
    out<<setw(15)<<repartidor.vehiculo;
    return out;
}