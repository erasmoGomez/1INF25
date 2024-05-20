/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mapa.hpp
 * Author: ASUS
 *
 * Created on May 7, 2024, 9:30 AM
 */

#ifndef MAPA_HPP
#define MAPA_HPP
#include "Utils.hpp"
#include "Casilla.hpp"
#include "Heroe.hpp"
using namespace std;

class Mapa{
private:
    int filas;
    int columnas;
    Casilla *casillas; //Arreglo unidimensional para representar el mapa
public:
    Mapa();
    void leer(ifstream &);
    void mostrar();
    void operator+=(Heroe);
};



#endif /* MAPA_HPP */

