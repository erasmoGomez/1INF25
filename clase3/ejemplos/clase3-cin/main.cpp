/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on March 28, 2023, 6:21 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    int codigo, edad;
//    char nombre[15];
//    double talla;
//    
//    cin>>codigo>>edad;
//    cin>>nombre;
//    cin>>talla;
//    
//    cout<<codigo<<endl;
//    cout<<edad<<endl;
//    cout<<nombre<<endl;
//    cout<<talla<<endl;
    
//    int entero, b;
//    double a;
//    char c;
//    
//    cin>>entero>>a;
//    if(cin.fail()){
//        cout<< "ERROR!"<<endl;
//        cin.clear();
//        cin>>c;
//        cin>>c;
//        cin>>b;
//        
//    }
//    cout<<entero<<"   "<<b<<endl;  
    
    int codigo, edad;
    char nombre[20];
    double talla;
    
    //Imprimir cabecera
//    cout<<setw(10)<<"codigo"<<setw(10)<<"nombre";
//    cout<<setw(6)<<"edad"<<setw(8)<<"talla"<<endl;
//    cout.fill('=');
//    cout<<setw(35)<<" "<<endl;
//    cout.fill(' ');
//    
//    while(true){
//        cin>>codigo;
//        if(cin.eof()) break;
//        cin>>edad;
//        cin>>nombre;
//        cin>>talla;
//        cout<<setw(10)<<codigo<<setw(10)<<nombre;
//        cout<<setw(6)<<edad;
//        cout.precision(3);
//        //cout.fill('0');
//        cout<<fixed<<setw(8)<<talla<<endl;
//        //cout.fill(' ');
//        
//    }
    
    cout<<setw(10)<<"codigo"<<setw(10)<<"edad"<<endl;
    
    while(true){
        cin>>codigo;
        if(cin.eof()) break;
        cin>>edad;
        cin.ignore(100,'\n');
        cout<<setw(10)<<codigo<<setw(10)<<edad<<endl;
        
    }
    return 0;
}

