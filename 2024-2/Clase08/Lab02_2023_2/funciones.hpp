/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 10, 2024, 6:18 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
void lectura_productos(char***&, int*&, double*&, const char*);
void prueba_lectura_productos(char***, int*, double*, const char*);
void actualizar_productos(char***&, int*&, double*&, char***, int*, double*, int);
char** lee_productos(ifstream &);
void lectura_pedidos(int *&, char***&, int***&, const char*);
int buscar_fecha(int *, int , int );
void agregar_fecha(int *, char ***,int ***, int *,int , int & , int &);
void agregar_pedido_fecha(int **,char**, int &, int , int, char*);
void recorte_pedidos(int*&, char***&, int ***&, int *, char ***,int ***,int *,int );
void agregar_pedidos_dni_codigo(char **, int **,char **, int**,int );
void prueba_lectura_pedidos(int *, char ***,int ***, const char*);
#endif /* FUNCIONES_HPP */

