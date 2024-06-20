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

#include "utils.hpp"
#include "Heroe.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    vector<int> vi;
//    vector<Heroe> vii;
//    vi.push_back(2);
//    vi.push_back(4);
//    vi.push_back(1);
//    vi.push_back(24);
//    vi.push_back(333);
//    cout<<"size: "<<vi.size()<<endl;
//    cout<<"capacity: "<<vi.capacity()<<endl;
//    vi.shrink_to_fit();
//    cout<<"size: "<<vi.size()<<endl;
//    cout<<"capacity: "<<vi.capacity()<<endl;
//    
////    for(int i=0; i<vi.size();i++)
////        cout<<vi[i]<<" ";
//    //For each
//    for(int entero: vi)
//        cout<<entero<< " ";
////    for(Heroe h: vii)
////        h.mostrar();
////    vector<Item*>mochila;
////    for(auto valor: contenedor)
////        valor.mostrar();
//    vi.pop_back();
//    cout<<endl;
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
//    int a = vi.back();
//    int b = vi.front();
//    cout<<a<<"   "<<b<<endl;
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
//    
//    vector<int>::iterator it1;
//    vector<int>::iterator it2;
//    it1 = vi.begin();
//    
//    vi.erase(it1);
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
//    it1 += 2;
//    vi.erase(it1);
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
//    it2 = vi.end();
//    vi.insert(it2, 3333);
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
//    
//    it2 -= 1;
//    vi.insert(it2, 4444);
//    for(int entero: vi)
//        cout<<entero<< " ";
//    cout<<endl;
    list<class Heroe>heroes;
    ifstream input("heroes.csv", ios::in);
    class Heroe new_heroe;
    while(true){
        input>>new_heroe;
        if(input.eof())break;
        heroes.push_back(new_heroe);
    }
    
    for(Heroe h: heroes)
        h.mostrar(cout);
    cout<<endl;
    
    heroes.sort();
    for(Heroe h: heroes)
        h.mostrar(cout);
    cout<<endl;
    return 0;
}

