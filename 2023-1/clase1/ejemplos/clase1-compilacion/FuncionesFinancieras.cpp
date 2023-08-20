/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FuncionesFinancieras.hpp"

double get_igv(double price){
    double igv;
    igv=price*18/100;
    return igv;
}