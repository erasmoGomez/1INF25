/* 
 * Proyecto: Productos
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 25 de abril de 2022, 07:38 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Estructura_PedidoRealizado{
    char codigo[7];
    double cantidad;
    int fecha;   // Formato aaaammdd
};

struct Estructura_ClienteRegistrado{
    int dni;
    char nombre[80];
    char categoria[30];
    struct Estructura_PedidoRealizado pedidosRealizados[100];
    int numeroDePedidos;
    double montoTotalGastado;
};

struct Estructura_ProductosEnAlmacen{
    char codigo[7];
    char descripcion[80];
    double precioUnitario;
    double descuento;
};

#endif /* ESTRUCTURAS_H */

