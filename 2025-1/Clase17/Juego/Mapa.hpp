/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.hpp
 * Author: hecto
 *
 * Created on May 7, 2025, 5:20 PM
 */

#ifndef MAPA_HPP
#define MAPA_HPP
#include "Casilla.hpp"
class Mapa {
public:
    Mapa();
    Mapa(int, int);
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void cargar_mapa(ifstream&);
    void mostrar_mapa();
    bool dentro(int, int) const;
    bool es_transitable(int , int );
    void operator+=(class Heroe);
private:
    int ancho;
    int alto;
    Casilla *casillas;
};

#endif /* MAPA_HPP */

