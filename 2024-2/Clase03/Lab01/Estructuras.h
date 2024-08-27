/* 
 * Proyecto: Laboratorio01
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 31 de marzo de 2024, 18:59
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct LibroSolicitado{
    int numeroDePedido;
    char codigoDelLibro[8];
	double precio;
    bool atendido; // true ==> Pedido atendido
                   // false ==> Pedido no atendido
};

struct Cliente{
    int dni;
    char nombre[60];
    struct LibroSolicitado librosSolicitados[30];
    int cantDeLibros;
    double pagoTotal;
};

struct Libro{
    char codigo[8];
    char tiltulo[80];
    char autor[60];
    int stock;
    double precio;
};
#endif /* ESTRUCTURAS_H */

