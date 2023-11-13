/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 8, 2023, 7:04 AM
 */

#include "utils.hpp"
#include "Hero.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    vector<int> vector_int{10,11,25,8,3};
//    vector<int> vector_int(10);
//    vector<int> vector_int(10,30);
    vector<int> vector_int_2;
    vector_int_2.push_back(54);
    vector_int_2.push_back(14);
    vector_int_2.push_back(24);
    vector_int_2.push_back(34);
    cout<<"Numero de elementos:  "<<vector_int_2.size()<<endl;
    cout<<"Capacidad del vector:  "<<vector_int_2.capacity()<<endl;
    vector_int_2.shrink_to_fit();
    cout<<"Numero de elementos:  "<<vector_int_2.size()<<endl;
    cout<<"Capacidad del vector:  "<<vector_int_2.capacity()<<endl;
    
//    for(int i=0; i<vector_int_2.size(); i++)
//        cout<<vector_int_2[i]<<endl;
    
    for(int i: vector_int_2)
        cout<<i<<endl;
    
    vector_int_2.pop_back();
    cout<<"Numero de elementos:  "<<vector_int_2.size()<<endl;
    cout<<"Capacidad del vector:  "<<vector_int_2.capacity()<<endl;
    for(int i: vector_int_2)
        cout<<i<<endl;
    int dato1, dato2;
    dato1 = vector_int_2.front();
    cout<<"Front: "<<dato1<<endl;
    dato2 = vector_int_2.back();
    cout<<"Back: "<<dato2<<endl;
    
    for(vector<int>::iterator it = vector_int_2.begin(); it!=vector_int_2.end(); it++)
        cout<<*it<<endl;
    
    vector<int>::iterator it1 = vector_int_2.begin();
    vector<int>::iterator it2 = vector_int_2.end();
    
    cout<<"Ultima impresion"<<endl;
    it1+=1;
    vector_int_2.erase(it1);
    for(int i: vector_int_2)
        cout<<i<<endl;
    vector_int_2.clear();
    if(vector_int_2.empty())
        cout<<"vacio"<<endl;
    else
        cout<<"no vacio"<<endl;
    cout<<*(vector_int_2.begin())<<endl;
    
    vector<int> vector_int{10,11,25,8,3};
    sort(vector_int.begin(), vector_int.end());
    for(int i: vector_int)
        cout<<i<<endl;
    cout<<"insert"<<endl;
    vector<int>::iterator it3 = vector_int.begin();
    it3+=2;
    vector_int.insert(it3, 10000);
    for(int i: vector_int)
        cout<<i<<endl;
    
    return 0;
}

