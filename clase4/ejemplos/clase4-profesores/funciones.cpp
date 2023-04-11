/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void imprime_linea(char c, int n){
    for(int i = 0; i< n; i++) cout<<c;
    cout<<endl;
}

void imprimir_cabecera(){
    cout<<"Registro de Ventas"<< endl;
    imprime_linea('=', 60);
}

void imprimir_fecha(int dd, int mm, int aaaa){
    cout<<setfill('0')<<setw(2)<<left<<dd<<'-'<<setfill('0')<<setw(2)<<mm<<'-';
    cout.fill(' ');
    cout<<setw(6)<<left<<aaaa;
}

void imprimir_option(char option){
    if (option=='T'){
        cout<<setw(12)<<left<< "PROFESSOR";
    }
    else{
        cout<<setw(12)<<left<<"STUDENT";
    }
}

void leer_imprimir_datos(){
    int codigo, age, dd, mm, aaaa;
    char option, slash;
    double ammount, total_debt = 0, total_charge = 0;
    //Imprimir cabecera juego de datos
    cout<<setw(10)<<left<<"CODE";
    cout<<setw(12)<<left<<"DOB";
    cout<<setw(6)<<left<<"AGE";
    cout<<setw(12)<<left<<"TYPE";
    cout<<setw(8)<<left<<"DEBT";
    cout<<setw(8)<<left<<"CHARGE"<<endl;
    
    while(1){
        cin>>codigo;
        if(cin.eof()) break;
        cin>>age;
        //Leer fecha
        cin>>dd>>slash>>mm>>slash>>aaaa;
        //leer character
        cin>>option>>ammount;
        
        cout<<setw(10)<<left<<codigo;
        imprimir_fecha(dd,mm,aaaa);
        cout<<setw(6)<<left<<age;
        imprimir_option(option);
        if (option == 'T'){
            cout<<setw(8)<<left<<ammount;
            cout<<setw(8)<<left<<"--"<<endl;
            total_debt = total_debt + ammount;
        }
        else{
            cout<<setw(8)<<left<<"--";
            cout<<setw(8)<<left<<ammount<<endl;
            total_charge = total_charge + ammount;
        }       
    }
    imprime_linea('=',60);
    cout<<setw(40)<<left<<"Totales";
    cout<<left<<setw(8)<<total_debt<<left<<setw(8)<<total_charge<<endl;
    
    cout<<setw(30)<<right<<"Saldo Final";
    cout<<setw(8)<<total_debt+total_charge<<endl;
    cout<<setw(19)<<right<<"Saldo Final";
    cout<<setw(8)<<total_debt+total_charge<<endl;
    cout<<setw(25)<<right<<"Saldo Final";
    cout<<setw(8)<<total_debt+total_charge<<endl;
    cout<<setw(33)<<left<<"Saldo Final";
    cout<<setw(8)<<total_debt+total_charge<<endl;
    
}