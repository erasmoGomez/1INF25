//
// Created by Erasmo on 11/11/25.
//

#ifndef GRAFOS_REDSOCIAL_HPP
#define GRAFOS_REDSOCIAL_HPP
#include <iostream>
#include <vector>
#include <map>
#include "Persona.hpp"
using namespace std;
class RedSocial {
public:
    RedSocial();
    RedSocial(const RedSocial& orig);
    virtual ~RedSocial();
    void agregar_relacion(const Persona&, const Persona&);
    void imprimir();
private:
    map<Persona,vector<Persona>> adyacencias;
};
//Matrix de ADYACENCIA
//    P1   P2   P3   P4
//P1   0   1    1    1 -> P2, P3, P4
//P2   0   0    1    0 -> P3
//P3   1   0    0    1 -> P1, P4
//P4   0   1    0    0 -> P2
//KEY                     VALUE
#endif //GRAFOS_REDSOCIAL_HPP
