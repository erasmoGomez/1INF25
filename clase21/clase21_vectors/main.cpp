/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 28, 2023, 4:01 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "persona.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //vector<int>vector_enteros{23,56, 12, 83, 123 ,66, 45, 19};
    //vector<int>vector_enteros(10);
    //vector<int>vector_enteros(10,33);
//    vector<int>vector_enteros;
//    vector_enteros.push_back(99);
//    vector_enteros.push_back(33);
//    vector_enteros.push_back(22);
//    vector_enteros.push_back(77);
//    vector_enteros.push_back(11);
//    vector_enteros.push_back(10);
//    vector_enteros.push_back(15);
//    vector_enteros.push_back(21);
//    vector_enteros.push_back(59);
//    
//    cout<<"Numero de elementos: "<<vector_enteros.size()<<endl;
//    cout<<"Capacidad inicial: "<<vector_enteros.capacity()<<endl;
//
//    
//    for(int i=0; i<vector_enteros.size(); i++)
//        cout<<setw(5)<<vector_enteros[i];
//    cout<<endl;
//    
//    vector_enteros.shrink_to_fit();
//    
//    cout<<"Numero de elementos: "<<vector_enteros.size()<<endl;
//    cout<<"Capacidad inicial: "<<vector_enteros.capacity()<<endl;
//
////    vector_enteros.shrink_to_fit();
////    for(int i: vector_enteros)
////        cout<<setw(5)<<i;
////    cout<<endl;
//    
//    vector_enteros.pop_back();
//    cout<<"Numero de elementos: "<<vector_enteros.size()<<endl;
//    cout<<"Capacidad inicial: "<<vector_enteros.capacity()<<endl;
//    for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//    cout<<endl;
//    int dato1, dato2;
//    dato1 = vector_enteros.front();
//    dato2 = vector_enteros.back();
//    cout<<setw(5)<<dato1<<setw(5)<<dato2<<endl;
//    for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//    cout<<endl;
////    
//    for(vector<int>::iterator it=vector_enteros.begin(); it!=vector_enteros.end(); it++)
//        cout<<setw(5)<<*it;
//    cout<<endl;
//    vector<int>::iterator it=vector_enteros.begin();
//    vector<int>::iterator it2=vector_enteros.begin();
//    it+=3;
//    it2+=6;
//    
//    cout<<setw(5)<<*it<<endl;
//    vector_enteros.erase(it);
//    //
//     for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//     cout<<endl;
//    //
//    it+=3;
//    cout<<setw(5)<<*it<<endl;
//    vector_enteros.insert(it, 77);
//    //
//     for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//     cout<<endl;
//    
//    sort(vector_enteros.begin(), vector_enteros.end());
//     for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//     cout<<endl;
//     
//    sort(vector_enteros.begin(), vector_enteros.end(), greater<int>());
//     for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//     cout<<endl;
////    vector_enteros.clear();
////    it2--;
////    vector_enteros.erase(it,it2);
//    if(vector_enteros.empty()) cout<<"está vacia"<<endl;
//     else cout<<"Tiene datos"<<endl;
//    
//     cout<<"Numero de elementos: "<<vector_enteros.size()<<endl;
//     cout<<"Capacidad inicial: "<<vector_enteros.capacity()<<endl;
//     for(int i: vector_enteros)
//        cout<<setw(5)<<i;
//     cout<<endl;
    
//    vector<string>vector_strings {"Juan Perez", "Maria","Pedro", "Jose"};
//    for(string i: vector_strings)
//        cout<<i<<endl;;
//    cout<<endl;
        vector<class Persona>vector_persona;
        ifstream arch("datos_personas.csv", ios::in);
        if (not arch.is_open()) {
            cout << "ERROR no se pudo abrir el archivo datos_personas.csv" << endl;
            exit(1);
        }
        ofstream archRep("reporte_personas.txt", ios::out);
        if (not archRep.is_open()) {
            cout << "ERROR no se pudo abrir el archivo reporte_personas.txt" << endl;
            exit(1);
        }
        class Persona per;
        while (true) {
            arch>>per;
            if (arch.eof())break;
            vector_persona.push_back(per);
        }
        for (Persona i : vector_persona)
            archRep << i;
        archRep << endl << "Datos ordenados:" << endl;
        //Se debe sobrecargar el operador <
        sort(vector_persona.begin(), vector_persona.end());
        for (Persona i : vector_persona)
            archRep << i;
    return 0;
}

