/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.hpp
 * Author: hecto
 *
 * Created on June 11, 2025, 4:51 PM
 */

#ifndef PERSONA_HPP
#define PERSONA_HPP
#include "Utils.hpp"
class Persona {
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void operator =(const class Persona&);
    bool operator <(const class Persona&);
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    
    void leer();
    void leer(ifstream&);
    void imprimir() const;
    void imprimir(ofstream&) const;
    
private:
    int dni;
    string nombre;
    double sueldo;
};
void operator>>(istream&, class Persona&);
ostream& operator<<(ostream&, const class Persona &);
void operator>>(ifstream& input, class Persona& p);
ofstream& operator<<(ofstream&, const class Persona &);

#endif /* PERSONA_HPP */

