/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 8, 2025, 6:29 PM
 */

#include <valarray>

#include "funciones.hpp"

void lectura_productos(char***& productos, int *&stocks, double*&precios,
        const char* nombre_archivo) {
    char**buffer_productos[MAX_PRODUCTOS]{}, coma;
    double buffer_precios[MAX_PRODUCTOS]{};
    int buffer_stocks[MAX_PRODUCTOS]{};
    int cantidad_productos = 0;
    ifstream input(nombre_archivo, ios::in);
    if(not input.is_open()){
        cout<<"No se pudo abrir el archivo: "<<nombre_archivo<<endl;
        exit(1);
    }
    //BIT-423, Campana Extractora modelo Glass, 375.09, 10
    while (true) {
        buffer_productos[cantidad_productos] = lee_productos(input);
        if (input.eof())break;
        input >> buffer_precios[cantidad_productos] >> coma >> buffer_stocks[cantidad_productos];
        input.get();
        cantidad_productos++;
    }
    actualizar_productos(productos,stocks, precios,
                         buffer_productos, buffer_stocks, buffer_precios,
                         cantidad_productos);
}

void actualizar_productos(char***&productos, int*&stocks, double*&precios,
                         char***buffer_productos, int*buffer_stocks, double*buffer_precios,
                         int cantidad_productos){
    productos = new char**[cantidad_productos+1];
    stocks = new int[cantidad_productos];
    precios = new double[cantidad_productos];
    
    for(int i = 0; i< cantidad_productos; i++){
        productos[i] = buffer_productos[i];
        stocks[i] = buffer_stocks[i];
        precios[i] = buffer_precios[i];
    }
}

char* leer_cadena(ifstream &input, int n, char del){
    char* cadena, buffer[n];
    input.getline(buffer, n, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char** lee_productos(ifstream& input) {
    char**codigo_nombre;
    codigo_nombre = new char*[2];
    codigo_nombre[0] = leer_cadena(input, 8, ',');
    codigo_nombre[1] = leer_cadena(input, 200, ',');
    return codigo_nombre;
}

void prueba_lectura_productos(char***productos, int*stock, double*precios, const char*nombre_archivo){
    char** info_productos;
    ofstream output(nombre_archivo,ios::out);
    if( not output.is_open()){
        cout<<"Error no se pudo abrir el archivo: "<<nombre_archivo<<endl;
        exit(1);
    }
    //Agregar titulo
    //Agregar headers
    for(int i=0; productos[i];i++){
        info_productos = productos[i]; //Aterrizaje
        output<<setw(10)<<info_productos[0]; //Codigo
        output<<setw(60)<<info_productos[1]; //Descripcion
        output<<setw(10)<<precios[i]; //Precio
        output<<setw(10)<<stock[i]<<endl; //stock
        
    }
}  

int buscar_fecha(int* buffer_fechas, int fecha, int cantidad_fechas){
    for(int i=0; i< cantidad_fechas; i++)
        if(buffer_fechas[i] == fecha) return i;
    return -1;
}

void agregar_fecha(int* buffer_fechas, char*** buffer_codigos_pedidos, 
                   int***buffer_dni_cantidad_pedidos,int* cantidad_pedidos, 
                   int fecha, int& indice, int& cantidad_fechas){
    buffer_fechas[cantidad_fechas] = fecha;//Buffer a primer nivel  
    buffer_codigos_pedidos[cantidad_fechas] = new char*[200]{};
    buffer_dni_cantidad_pedidos[cantidad_fechas] = new int*[200]{};
    cantidad_pedidos[cantidad_fechas] = 0;
    indice = cantidad_fechas;
    cantidad_fechas++;
}

void agregar_pedido_fecha(int** buffer_dni_cantidad_pedidos, char**buffer_codigos_pedidos,
                             int&cantidad_pedidos, int dni, int cantidad, char* codigo){
    int *aux_dni_cantidad_pedidos;
    buffer_dni_cantidad_pedidos[cantidad_pedidos] = new int[2];
    aux_dni_cantidad_pedidos = buffer_dni_cantidad_pedidos[cantidad_pedidos];
    aux_dni_cantidad_pedidos[0] = dni; 
    aux_dni_cantidad_pedidos[1] = cantidad;
    buffer_codigos_pedidos[cantidad_pedidos] = codigo;
    cantidad_pedidos++;
}

void agregar_pedidos_dni_codigo(codigos_pedidos[i], dni_cantidad_pedidos[i],
                                   buffer_codigos_pedidos[i], buffer_dni_cantidad_pedidos[i],
                                   cantidad_pedidos[i]){
    for(int i = 0; i< cantidad_pedidos; i++){
        codigos_pedidos[i] = buffer_codigos_pedidos[i];
    }
    //Deletes esperados.
}

void recorte_pedidos(int*&fechas, char***&codigos_pedidos, int***&dni_cantidad_pedidos,
                    int* buffer_fechas, char***buffer_codigos_pedidos, int***buffer_dni_cantidad_pedidos,
                    int* cantidad_pedidos, int cantidad_fechas){
    //Reserva de memoria a primer nivel
    fechas = new int[cantidad_fechas+1]{};
    codigos_pedidos = new char**[cantidad_fechas]{};
    dni_cantidad_pedidos = new int**[cantidad_fechas]{};
    for(int i=0; i< cantidad_fechas; i++){
        fechas[i] = buffer_fechas[i];
        codigos_pedidos = buffer_codigos_pedidos[i];
        dni_cantidad_pedidos[i] = buffer_dni_cantidad_pedidos[i];
        //Proceso a segundo nivel
        agregar_pedidos_dni_codigo(codigos_pedidos[i], dni_cantidad_pedidos[i],
                                   buffer_codigos_pedidos[i], buffer_dni_cantidad_pedidos[i],
                                   cantidad_pedidos[i]);
    }
}

void lectura_pedidos(int*&fechas, char***&codigos_pedidos, 
                     int***&dni_cantidad_pedidos, const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    //JXD-139,50375303,6,24/08/2023
    char *codigo, c;
    int dni, cantidad, dd, mm, aa, fecha, indice, cantidad_fechas = 0;
    int buffer_fechas[MAX_FECHAS], **buffer_dni_cantidad_pedidos[MAX_FECHAS];
    char** buffer_codigos_pedidos[MAX_FECHAS];
    int cantidad_pedidos[MAX_FECHAS];
    while(true){
        codigo = leer_cadena(input, 8, ',');
        if(input.eof())break;
        input>>dni>>c>>cantidad>>c>>dd>>c>>mm>>c>>aa;
        input.get();
        fecha = aa*10000+mm*100+dd;
        indice = buscar_fecha(buffer_fechas, fecha, cantidad_fechas);
        if(indice == -1)
            agregar_fecha(buffer_fechas, buffer_codigos_pedidos, buffer_dni_cantidad_pedidos,
                          cantidad_pedidos, fecha, indice, cantidad_fechas); //Cuando la fecha no se encuentra
        agregar_pedido_fecha(buffer_dni_cantidad_pedidos[indice], buffer_codigos_pedidos[indice],
                             cantidad_pedidos[indice], dni, cantidad, codigo); //Cuando ya se encuentra la fecha
    }
    recorte_pedidos(fechas, codigos_pedidos, dni_cantidad_pedidos,
                    buffer_fechas, buffer_codigos_pedidos, buffer_dni_cantidad_pedidos,
                    cantidad_pedidos, cantidad_fechas);
}