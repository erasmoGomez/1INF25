/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tablero.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 7:12 AM
 */

#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <iomanip>
#include <fstream>
using namespace std;
#include "ficha.hpp"

class Tablero{
private:
    int numFichas;
    Ficha *ficha[100];
public:
    Tablero();
    virtual ~Tablero();
    void SetNumFichas(int numFichas);
    int GetNumFichas() const;
    void leer_fichas(ifstream &);
    void set_ficha(char *, char, int, int);
    void leer_movimiento(ifstream &);
    void mover_ficha(char*, char, int);
    void imprime_datos(ofstream &);
            
};

#endif /* TABLERO_HPP */

