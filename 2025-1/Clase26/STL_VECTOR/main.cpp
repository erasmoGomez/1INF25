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
//    vector<int> codigos;
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//
//    codigos.push_back(20082060);
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//    codigos.push_back(20082062);
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//    codigos.push_back(20082063);
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//    codigos.push_back(20082064);
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//    codigos.push_back(20082065);
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//
//    codigos.shrink_to_fit();
//    cout << "Tamano: " << codigos.size() << endl;
//    cout << "Capaciad: " << codigos.capacity() << endl;
//
//    //Foreach
//    for (int dato : codigos)
//        cout << dato << endl;
//
//    vector<int> edades{32, 21, 19, 20, 22};
//    cout << "Tamano: " << edades.size() << endl;
//    cout << "Capaciad: " << edades.capacity() << endl;
//
//    //ForNormal
//    for (int i = 0; i < edades.size(); i++)
//        cout << edades[i] << endl;
//
//    edades[2] = 24;
//    
//    for (int i = 0; i < edades.size(); i++)
//        cout << edades[i] << endl;
//    
//    cout<<"Agregando 2 elementos como 19"<<endl;
//    edades.assign(2, 19);
//    for (int i = 0; i < edades.size(); i++)
//        cout << edades[i] << endl;
//    
//    edades.assign({32, 21, 24, 19, 20, 22});
//    for (int i = 0; i < edades.size(); i++)
//        cout << setw(3)<<edades[i];
//    cout<<endl;
//    
//    cout<<"Insertamos en 2 el numero 25"<<endl;
//    edades.insert(edades.begin()+2, 25);
//    
//    edades[0] = 40;
//    for (int i = 0; i < edades.size(); i++)
//        cout << setw(3)<<edades[i];
//    cout<<endl;
//    
//    vector<int> notas;
//    cout<<notas.empty()<<endl;
//    if(notas.empty())
//        notas.push_back(20);
//    else
//        notas.push_back(10);
//    
//    for (int i = 0; i < notas.size(); i++)
//        cout << setw(3)<<notas[i];
//    cout<<endl;
//    
//    //Forma de ordenar
//    //edades.sort(); Con esto no se puede ordenar un vector
//    sort(edades.begin(), edades.end());
//    for (int i = 0; i < edades.size(); i++)
//        cout << setw(3)<<edades[i];
//    cout<<endl;
    
    vector<class Persona> personas;
    ifstream input("personal.csv",ios::in);
    ofstream output("reporte.csv", ios::out);
    Persona persona;
    while(true){
        input>>persona;
        if(input.eof())break;
        personas.push_back(persona);
    }
    
    sort(personas.begin(), personas.end());
    
    for(Persona p: personas)
        output<<p;
    output<<endl;
    return 0;
}

