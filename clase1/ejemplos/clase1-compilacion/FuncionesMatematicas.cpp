/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FuncionesMatematicas.hpp"

int get_factorial(int n){
    int factorial = 1; 
    if (n < 0)
        return n;
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        return factorial; 
    }
}