/* 
 * File:   PunterosGenericos.h
 * Author: Jorge Fatama
 *
 * Created on 23 de setiembre de 2023, 01:41
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MuestraPunteros.h"
#define NO_ENCONTRADO -1
using namespace std;

enum RegProducto {CODIGO, DESCRIPCION, PRECIO, TIPO};
enum RegCliente {DNI, NOMBRE, PEDIDOS, LINEACREDITO};
enum RegPedido {CODIGOPRODUCTO, CANTIDADPRODUCTO, TOTALPEDIDO};

void cargaproductos(void*& productos);
void cargaclientes(void*& clientes);
void cargapedidos(void* productos, void*& clientes);
void imprimereporte(void* clientes);

void* leeRegistroProducto(ifstream&);
void asignacionExacta(void **, void **&, int);
void* leeRegistroCliente(ifstream&);
int* asignarMemoriaTemporalEnPedidos(void *&);
void leePedidoEnCliente(ifstream&, void*, void*&, int*);
void asignarMemoriaExactaEnPedidos(void *&, int*);

char* leerCadena(ifstream&);
int buscarProducto(void*, const char*);
int buscarCliente(void*, int);
void insertarPedidoEnCliente(void*&, int, bool, char*, int, double, int*);
void validarInsercion(void*, int, void*, int, int, bool&, bool&, double&);

void imprimeLinea(ofstream&, char, int);
void imprimeCliente(ofstream&, void*);

#endif /* PUNTEROSGENERICOS_H */

