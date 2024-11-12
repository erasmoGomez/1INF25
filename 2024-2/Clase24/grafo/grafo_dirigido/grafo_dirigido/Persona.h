/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: alulab14
 *
 * Created on 15 de junio de 2024, 08:54 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Clase para representar a una Persona
class Persona {
private:
    string nombre;
    int edad;
public:
    // Constructor copia
    Persona(const Persona&);
    
    // Constructor con parametros
    Persona(string, int);

    // Método para imprimir los detalles de la persona
    void imprimirPersona() const;
    
    // Sobrecarga del operador de comparación ==
    bool operator==(const Persona& otra) const;

    // Sobrecarga del operador de comparación <
    bool operator<(const Persona& otra) const;
};


#endif /* PERSONA_H */

