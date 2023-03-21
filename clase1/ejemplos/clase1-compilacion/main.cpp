/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on March 21, 2023, 3:11 AM
 */

#include <iostream>
using namespace std;
#include "FuncionesMatematicas.hpp"
#include "FuncionesFinancieras.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int f;
    double imp;
    f = get_factorial(5);
    imp = get_igv(3567.45);
    cout<<"Factorial de 5 = "<<f<<endl;
    cout<<"Impuesto a pagar = "<<imp<<endl;
    return 0;
}

