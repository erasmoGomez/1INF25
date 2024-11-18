/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 17, 2024, 4:57 PM
 */

#include "Heroe.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    vector<int> edades;
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    cout << "Modificacion" << endl;
//    edades.push_back(32);
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    edades.push_back(20);
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    edades.push_back(21);
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    edades.push_back(22);
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    edades.push_back(23);
//    cout << "Cantidad de elementos: " << edades.size() << endl;
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    edades.shrink_to_fit();
//    cout << "Capacidad del vector: " << edades.capacity() << endl;
//    int n = edades.size();
//    for (int i = 0; i < n; i++)
//        cout << "El valor en : " << i << " es :" << edades[i] << endl;
//
//    //Foreach
//    for (int x : edades)
//        cout << setw(5) << x << endl;
//    cout << "NOTAS" << endl;
//    vector<int>notas{10, 8, 12, 10, 13, 6, 20};
//    for (int x : notas)
//        cout << setw(5) << x << endl;
//    vector<int>notas2(10);
//    cout << "Parentesis inicializar" << endl;
//    for (int x : notas2)
//        cout << setw(5) << x << endl;
//    cout << "Cantidad de elementos: " << notas2.size() << endl;
//    cout << "Capacidad del vector: " << notas2.capacity() << endl;
//
//    vector<int>notas3(10, 55);
//    cout << "Parentesis inicializar" << endl;
//    for (int x : notas3)
//        cout << setw(5) << x << endl;
//    cout << "Cantidad de elementos: " << notas3.size() << endl;
//    cout << "Capacidad del vector: " << notas3.capacity() << endl;
//
//    notas3.assign(5, 100);
//    cout << "luego de asignar" << endl;
//    for (int x : notas3)
//        cout << setw(5) << x << endl;
//
//    notas3.assign({20, 18, 19, 15, 12, 10});
//    for (int x : notas3)
//        cout << setw(5) << x << endl;
//    
//    cout<<"Remover elementos"<<endl;
//    notas3.pop_back();
//    for (int x : notas3)
//        cout << setw(5) << x << endl;
//    
//    int inicioA, finalA;
//    inicioA = notas3.front();
//    finalA = notas3.back();
//    cout<<"inicio: "<<inicioA<<"    final: "<<finalA<<endl;    
//    
//    //Iteradores
//    cout<<"ITERADORES"<<endl;
//    for(vector<int>::iterator it = notas3.begin();it!=notas3.end();it++)
//        cout<<setw(5)<<*it;
//    cout<<endl;
//    
//    vector<int>::iterator it2 = notas3.begin();
//    
//    notas3.erase(it2+1);
//    //notas3.erase(notas3.begin()+1);
//    
//    for(vector<int>::iterator it = notas3.begin();it!=notas3.end();it++)
//        cout<<setw(5)<<*it;
//    
//    cout<<endl;
//    cout<<"HACEMOS CLEAR"<<endl;
//    notas3.clear();
//    for(vector<int>::iterator it = notas3.begin();it!=notas3.end();it++)
//        cout<<setw(5)<<*it;
//    
//    notas3.assign({20, 6, 19, 17, 4, 10});
//    for(int x: notas3)
//        cout<<setw(5)<<x;
//    cout<<endl;
//    
//    //ordenamiento
//    cout<<"ORDENAMIENTO"<<endl;
//    sort(notas3.begin(), notas3.end());
//    for(int x: notas3)
//        cout<<setw(5)<<x;
//    cout<<endl;
//    
//    vector<class Heroe> heroes;
//    //Leer heroes
//    ifstream input("heroes.csv", ios::in);
//    if(not input.is_open()){
//        cout<<"ERROR"<<endl;
//        exit(1);
//    }
//    class Heroe h;
//    while(true){
//        input>>h;
//        if(input.eof())break;
//        //Guardar el heroe en el vector
//        heroes.push_back(h);
//    }
//    //Imprimir heroes
//    for(Heroe x: heroes)
//        cout<<x;
//    cout<<endl;
//    //ordenamiento heroes
//    sort(heroes.begin(), heroes.end());
//    //Imprimir luego de ordenar
//    cout<<"Luego de Ordenar HEROES"<<endl;
//    for(Heroe x: heroes)
//        cout<<x;
//    cout<<endl;
//    
//    list<double> promedios;
//    promedios.push_back(10.5);
//    promedios.push_back(8.5);
//    promedios.push_back(16.5);
//    promedios.push_back(12.5);
//    promedios.push_back(9.5);
//    
//    for(double x: promedios)
//        cout<<setw(5)<<x;
//    cout<<endl;
//    
//    
////    it3++;
////    promedios.erase(it3);
//    //sort(promedios.begin(), promedios.end());
//    promedios.sort();
//    for(double x: promedios)
//        cout<<setw(5)<<x;
//    cout<<endl;
//    list<double>::iterator it3;
//    it3 = promedios.begin();
//    promedios.insert(it3, 7.5);
//    
//    for(double x: promedios)
//        cout<<setw(5)<<x;
//    cout<<endl;
    // pair(KEY, VALUE) 
    map<string, int> edades_profesores;
    //insertar datos por default inserta de manera ascendente por el KEY
    edades_profesores.insert({"erasmo", 32});
    edades_profesores.insert({"rony", 52});
    edades_profesores.insert({"miguel", 62});
    
    //imprimir un solo elemento
    cout << edades_profesores["erasmo"]<<endl;
    //imprimir todo el mapa
    cout<<"Imprimiendo el mapa"<<endl;
    for(auto& elemento:edades_profesores){
        cout<<setw(20)<<elemento.first; //Devolver el KEY
        cout<<setw(5)<<elemento.second<<endl; //Devolver el VALUE
    }
    
    edades_profesores["erasmo"] = 50;
    edades_profesores["erasmos"] = 50;
    cout<<"Imprimiendo el mapa 2"<<endl;
    for(auto& elemento:edades_profesores){
        cout<<setw(20)<<elemento.first; //Devolver el KEY
        cout<<setw(5)<<elemento.second<<endl; //Devolver el VALUE
    }
    
    cout<<edades_profesores.size()<<endl;
    map<string, int>::iterator it = edades_profesores.find("rony");
    cout<<"La edad del profesor Rony es : "<< it->second <<endl;
    
    map<string, Heroe>heroes;
    Heroe h1;
    heroes.insert({"Teemo", h1});
    heroes["Teemo"] = h1;
    return 0;
}

