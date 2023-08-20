/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MovimientosTablero.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 8:47 AM
 */

#ifndef MOVIMIENTOSTABLERO_HPP
#define MOVIMIENTOSTABLERO_HPP
#include "tablero.hpp"
class MovimientosTablero{
private:
    Tablero tablero;
public:
    void cargar_mover_fichas(const char*, const char* , const char* );
};


#endif /* MOVIMIENTOSTABLERO_HPP */

