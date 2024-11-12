/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrafoDirigido.h
 * Author: alulab14
 *
 * Created on 15 de junio de 2024, 09:00 AM
 */

#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H
#include <iostream>
#include <vector>
#include <map>
#include "Persona.h"
using namespace std;
class GrafoDirigido {
public:
    GrafoDirigido();
    GrafoDirigido(const GrafoDirigido& orig);
    virtual ~GrafoDirigido();
    void agregarArista(const Persona&, const Persona&);
    void imprimirGrafo() const;
private:
    map<Persona, vector<Persona>> adyacencias;
};

#endif /* GRAFODIRIGIDO_H */

