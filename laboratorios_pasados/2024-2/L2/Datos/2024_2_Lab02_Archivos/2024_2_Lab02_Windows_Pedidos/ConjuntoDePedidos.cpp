/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad]; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    // ++p
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    // p++
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos){
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}