/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 24, 2023, 9:21 AM
 */

#include <cstdlib>
#include "Base.hpp"
#include "Derivada2.hpp"
#include "Derivada.hpp"

using namespace std;

/*
 * 
 */

void f(class Base **p){
    for(int i=0; i<6; i++)
        p[i]->mostrar();
}

int main(int argc, char** argv) {
    class Base base;
    class Derivada derivada;
    class Derivada2 derivada2;
    class Base *pt, *pt1;
//    pt = &base;
//    pt->SetB(5);
//    pt->mostrar();
//    
//    derivada.SetB(5);
//    derivada.SetD(10);
//    pt = &derivada;
//    pt->mostrar();
    
    class Base *arr[10];
    class Derivada da, db, dc;
    class Derivada2 d2a, d2b, d2c;
    da.SetB(2);
    da.SetD(22);
    db.SetB(3);
    db.SetD(33);
    dc.SetB(4);
    dc.SetD(44);
    
    d2a.SetB(202);
    d2a.SetD2(2022);
    d2b.SetB(303);
    d2b.SetD2(3033);
    d2c.SetB(404);
    d2c.SetD2(4044);
    
    arr[0] = &dc;
    arr[1] = &d2a;
    arr[2] = &d2c;
    arr[3] = &db;
    arr[4] = &dc;
    arr[5] = &d2b;
    f(arr);        
    return 0;
}

