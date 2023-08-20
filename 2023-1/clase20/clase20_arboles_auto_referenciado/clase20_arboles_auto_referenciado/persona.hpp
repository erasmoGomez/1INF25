
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   persona.hpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 6:18 AM
 */

#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Persona {
private:
    int dni;
    char * nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator=(const class Persona&);
    bool operator==(int);
    bool operator>(const class Persona&);
};

ifstream & operator>>(ifstream &, class Persona&);

ostream &operator<<(ostream &, const class Persona&);
#endif /* PERSONA_HPP */

