/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 9:26 PM
 */

#ifndef FARMACIA_HPP
#define FARMACIA_HPP
#include <fstream>
#include "oferta.hpp"
using namespace std;

class Farmacia {
private:
    class Oferta loferta[100];
public:
    void leer_recetas();
    void carga_recetas(ifstream&);
    void imprime_recetas();

    void imprime_reporte(ofstream&);
    void imprime_cabecera(ofstream&);
    void imprime_linea(ofstream&, int, char);
};

#endif /* FARMACIA_HPP */

