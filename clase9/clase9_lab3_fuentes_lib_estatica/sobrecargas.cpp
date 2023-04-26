/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecargas.hpp"


ifstream & operator >>(ifstream & input, struct Estructura_ClienteRegistrado & cr){
    int dni, telefono, tamano;
    char nombre[80];
    char categoria;
    
    input>>dni;
    if(input.eof()) return input;
    input>>nombre;
    input>>telefono;
    
    tamano = strlen(nombre);
    if (nombre[tamano-2] == '-'){
        categoria = nombre[tamano-1];
        nombre[tamano-2] = '\0';
    }
    else
        categoria = 'D';
    
    //Guardar los valores cheveres
    
    cr.dni = dni;
    
    strcpy(cr.nombre, nombre);
    
    if(categoria == 'A') strcpy(cr.categoria, "Cliente muy frecuente");
    if(categoria == 'B') strcpy(cr.categoria, "Cliente frecuente");
    if(categoria == 'C') strcpy(cr.categoria, "Cliente ocasional");
    if(categoria == 'D') strcpy(cr.categoria, "Cliente nuevo");
    
    cr.numeroDePedidos = 0;
    cr.montoTotalGastado = 0.0;
    //Como pedidosRealizados es estatico no me preocupo por inicializarlo.
    return input;
}

void operator +=(struct Estructura_ClienteRegistrado * a, const struct Estructura_ClienteRegistrado &c){
    int indice;
    for(indice = 0; a[indice].dni!=0;indice++);
    a[indice].dni = c.dni;
    a[indice].montoTotalGastado = c .montoTotalGastado;
    a[indice].numeroDePedidos = c.numeroDePedidos;
    strcpy(a[indice].categoria,c.categoria);
    strcpy(a[indice].nombre, c.nombre);
    
    a[indice+1].dni = 0;
}

void operator +=(struct Estructura_ClienteRegistrado & c, const struct Estructura_PedidoRealizado p){
    c.pedidosRealizados[c.numeroDePedidos].cantidad = p.cantidad;
    c.pedidosRealizados[c.numeroDePedidos].fecha = p.fecha;
    strcpy(c.pedidosRealizados[c.numeroDePedidos].codigo,p.codigo);
    c.numeroDePedidos++;
}

void operator +=(struct Estructura_ProductosEnAlmacen *a, const struct Estructura_ProductosEnAlmacen &p){
    int indice, encontrado =0;
    for(indice = 0; strcmp(a[indice].codigo,"X")!=0;indice++){
        if(strcmp(a[indice].codigo,p.codigo)==0) encontrado = 1;
    }
    if(!encontrado){
        strcpy(a[indice].codigo,p.codigo);
        strcpy(a[indice].descripcion, p.descripcion);
        a[indice].descuento = p.descuento;
        a[indice].precioUnitario = p.precioUnitario;
        strcpy(a[indice+1].codigo, "X");
    }
}
