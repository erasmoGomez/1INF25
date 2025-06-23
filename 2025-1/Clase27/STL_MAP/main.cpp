/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 11, 2025, 5:31 PM
 */

#include "Utils.hpp"
#include "Persona.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    //Key-> Codigo Value -> Promedio
//    map<int, double> mapa_promedios;
//    map<int, double>::iterator it;
//    
//    mapa_promedios[20082060] = 18.75;
//    mapa_promedios[20082052] = 16.25;
//    mapa_promedios[20081980] = 19.45;
//    mapa_promedios[20082080] = 12.50;
//
//    cout<<fixed;
//    cout<<setprecision(2);
//    
//    //Foreach
//    for(auto promedio: mapa_promedios)
//        cout<<setw(10)<<promedio.first<<setw(10)<<promedio.second<<endl;
//    
//    cout<<mapa_promedios[20082060]<<endl; //Dado el Key obtengo el value
//    //Acceder directo a un Key
//    cout<<"Acceder directo a un Key"<<endl;
//    it = mapa_promedios.find(20082031);
//    if (it != mapa_promedios.end())
//        cout<<it->first<<"    "<<it->second<<endl;
//    else cout<<"No se encontro el Key!"<<endl;
//    
//    string nombre;
//    map<string, int> edades;
//    nombre = "Erasmo";
//    edades[nombre] = 32;
//    nombre = "Rony";
//    edades[nombre] = 52;
//    nombre = "Miguel";
//    edades[nombre] = 64;
//    cout<<"Mapa de Edades string,int"<<endl;
//    for(auto p: edades)
//        cout<<setw(15)<<p.first<<setw(10)<<p.second<<endl;
//    
//    map<string, int>::iterator it2;
//    nombre = "Erasmo";
//    it2 = edades.find(nombre);
//    if (it2 != edades.end())
//        cout<<it2->first<<"    "<<it2->second<<endl;
//    else cout<<"No se encontro el Key!"<<endl;
    
    map<string, class Persona>personas;
    //map<string, vector<class Persona>> mapa_personas;
    ifstream input("personal.csv", ios::in);
    class Persona persona;
    while(true){
        input>>persona;
        if(input.eof())break;
        //Aca se coloca la construccion del mapa
        personas[persona.GetNombre()] = persona;
    }
    
    for(auto p: personas)
        cout<<p.second;
    return 0;
}

