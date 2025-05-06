/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 1, 2024, 4:55 PM
 */

#ifndef BIBLIOTECAGENERICA_HPP
#define BIBLIOTECAGENERICA_HPP
#include "utils.hpp"
void crealista(void *&pedidos,void *(*lee)(ifstream &),const char *nom);
void generalista(void *&pedidos);
void insertar(void *pedidos, void *dato);
void *quitalista(void *pedidos);
bool listavacia(void *pedidos);
void imprimelista(void *pedidos,void (*imprime)(ofstream &, void *),const char *nom);
void combinalista(void *pedidos1,void *pedidos2,void *&listafinal,int (*cmp)(void *, void *));

#endif /* BIBLIOTECAGENERICA_HPP */

