//
// Created by Erasmo on 11/11/25.
//

#ifndef GRAFOS_PERSONA_HPP
#define GRAFOS_PERSONA_HPP
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
#endif //GRAFOS_PERSONA_HPP
