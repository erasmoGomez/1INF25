/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "functions.hpp"
using namespace std;
void f(struct Tweet &t){
    t.created_at = 240331;
    cout<<"Fecha de cracion YYMMDD: "<<t.created_at<<endl;
}

//void f1(const struct Tweet &t){
//    g(t);
//}

void f2(const struct Tweet &t){
    g1(t);
}

void g(struct Tweet &t){
    t.created_at = 240401;
    cout<<"Fecha de cracion YYMMDD: "<<t.created_at<<endl;
}

void g1(const struct Tweet &t){
    cout<<"Fecha de cracion YYMMDD: "<<t.created_at<<endl;
}

void h(int *p){
    p[1] = 55;
    cout<<p[1]<<endl;
}

void h1(const int *p){
    //p[1] = 55;
    p = new int;
    cout<<p[1]<<endl;
}

void h2(int *const p){
    p[1] = 33;
    cout<<p[1]<<endl;
}

void h3(const int *const p){
    //p[1] = 44;
    //*p = 44; 
    //p = new int;
    cout<<*p<<endl;
}