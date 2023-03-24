/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on March 22, 2023, 5:12 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a = 5;
    int b = 37;
    int c = 215;
    float d = 3.1415;
    float e = 31.1415;
    
//    //COUT
//    cout<<"el valor de a es = "<<a<<endl;
//    cout.width(10);
//    cout<<b<<endl;
//    cout<<c<<endl;
//    cout.width(20);
//    cout<<d<<endl;
//    
//    cout<<setw(10)<<a<<setw(20)<<b<<endl;
//    
//    cout<<fixed;
//    cout.precision(2);
//    cout<<d<<endl;
//    
//    cout.precision(3);
//    cout<<e<<endl;
//    
//    double f = 130.125;
//    cout<<fixed;
//    cout.precision(3);
//    cout<<f<<endl;
//            
//    double g = 23.456787;
//    cout<<fixed;
//    cout.precision(1);
//    cout<<setw(2)<<g<<setw(9)<<g<<endl;
//    cout.unsetf(ios::fixed);
//    
//    
//    cout<<setw(10)<<"Codigo"<<setw(6)<<"Edad"<<setw(6)<<"Talla"<<endl;
//    cout<<fixed;
//    cout.precision(1);
//    cout<<setw(10)<<20082060<<setw(6)<<32<<setw(6)<<1.67<<endl;
//    cout.precision(3);
//    cout<<setw(10)<<20172844<<setw(6)<<23<<setw(6)<<1.788888778;
//    cout.precision(2);
//    cout<<setw(6)<<1.788888778<<endl;
//    
//    cout<<endl<<endl;
//    
//    cout<<setw(10)<<a<<setw(20)<<b<<endl;
//    cout.fill('0');
//    cout<<setw(10)<<a<<setw(20)<<b<<endl;
//    cout.fill(' ');
//    cout<<setw(10)<<a<<setw(20)<<b<<endl;
//    cout.fill('X');
//    cout<<left<<setw(10)<<a<<setw(20)<<b<<endl;
    
    //CIN
    int valor;
    double valor_float;
    char dash, car;
    int dd, mm, aa;
//    cin>>valor;
//    cout<<"valor leido: "<<valor<<endl;
//    
//    cin>>valor_float;
//    cout<<"valor leido: "<<valor_float<<endl;
    
    //leer fecha
    
//    cin>>dd>>dash>>mm>>dash>>aa;
//    cout<<aa*10000+mm*100+dd<<endl;
    
//    cin>>car;
//    cout<<car<<endl;
//    
//    cin>>car;
//    cout<<car<<endl;
//    
//    cin>>car;
//    cout<<car<<endl;
    
    car = cin.get();
    cout<<int(car)<<endl;
    return 0;
}

