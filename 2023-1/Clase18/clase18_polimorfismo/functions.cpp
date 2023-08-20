/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"

void f(class Base **p) {
    for (int i = 0; i < 5; i++)
        p[i]->imprime();
}