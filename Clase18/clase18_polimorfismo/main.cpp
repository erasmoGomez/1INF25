/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:06 PM
 */

#include "base.hpp"
#include "derivada.hpp"
#include "derivada2.hpp"
#include "functions.hpp"
/*
 * 
 */


int main(int argc, char** argv) {
    class Base base, *pt[10];
    class Derivada deriv, derivA;
    class Derivada2 deriv2, derivA2;

    base.SetB(55);
    deriv.SetB(99);
    deriv.SetD(33);
    derivA.SetB(199);
    derivA.SetD(133);

    deriv2.SetB(66);
    deriv2.SetDd(88);
    derivA2.SetB(166);
    derivA2.SetDd(188);

//    base.imprime();
//    deriv.imprime();
//    derivA.imprime();
//    deriv2.imprime();
//    derivA2.imprime();

    pt[0] = &deriv2;
    pt[1] = &base;
    pt[2] = &deriv;
    pt[3] = &derivA;
    pt[4] = &derivA2;
    
    f(pt);

    return 0;
}

