/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   persona.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 12, 2024, 5:53 PM
 */

#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Persona {
public:
    Persona();
    Persona(string, int);
    Persona(const Persona& orig);
    virtual ~Persona();
    //Sobrecarga de comparacion
    bool operator<(const Persona&)const;
    void imprimir_persona()const;
private:
    string nombre;
    int edad;
};

#endif /* PERSONA_HPP */

