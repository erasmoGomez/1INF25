/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estructuras.hpp
 * Author: hecto
 *
 * Created on March 26, 2025, 5:15 PM
 */

#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP
struct Papeleta{
    char* codigo;
    int fecha;
    double monto;
    char* gravedad;
    char* descripcion;
};
    
struct Conductor{
    int dni;
    char* nombre;
    Papeleta papeletas[30];
};

#endif /* ESTRUCTURAS_HPP */

