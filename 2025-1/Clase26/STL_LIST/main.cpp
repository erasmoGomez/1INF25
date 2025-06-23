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
//    list<int> codigos{20082060, 20082062, 20082131, 20082101, 20089266};
//    list<string> nombres{"Erasmo", "Marcia", "Cyndi", "Xtian", "David"};
//    cout<<"Lista de Codigos"<<endl;
//    //foreach
//    for(int codigo: codigos)
//        cout<<setw(10)<<codigo;
//    cout<<endl<<endl;
//    cout<<"Lista de Nombres"<<endl;
//    //foreach
//    for(string nombre: nombres)
//        cout<<setw(15)<<nombre;
//    cout<<endl<<endl;
//    
//    cout<<"Lista de Nombres Auto"<<endl;
//    //foreach
//    for(auto nombre_auto: nombres)
//        cout<<setw(15)<<nombre_auto;
//    cout<<endl<<endl;
//    
//    list<class Persona> personas;
//    Persona p1,p2,p3;
//    p1.SetNombre("Erasmo");
//    p1.SetDni(1234567);
//    p1.SetSueldo(123.123);
//    p2.SetNombre("Cueva");
//    p2.SetDni(22123);
//    p2.SetSueldo(123.124);
//    p3.SetNombre("Miguel");
//    p3.SetDni(111111);
//    p3.SetSueldo(234.432);
//    
//    cout<<p1;
//    cout<<p2;
//    cout<<p3;
//    //Inserta al Final
//    personas.push_back(p1); //Llama la sobrecarga del operador = y al constructor copia.
//    //Inserta al Inicio
//    personas.push_front(p2);
//    personas.push_front(p3);
//    
//    cout<<"Lista de Personas"<<endl;
//    //foreach
//    for(auto persona: personas)
//        cout<<persona;
//    cout<<endl<<endl;
//    
//    personas.sort(); //Necesitamos la sobrecarga del operador <
//    
//    cout<<"Lista de Personas Ordenado"<<endl;
//    //foreach
//    for(auto persona: personas)
//        cout<<persona;
//    cout<<endl<<endl;
//    
//    
//    //Iterador
//    list<int>::iterator it_int = codigos.end();
//    list<class Persona>::iterator it = personas.begin();
//    // iterator it = personas.begin(); //falta la especificacion del iterador.
//    //it+1; //Aritmetica de punteros.
//    it++;
//    it++;
//    cout<<"Iterador ++"<<endl;
//    cout<<*it<<endl;
//    Persona p4;
//    p4.SetNombre("Andres");
//    p4.SetDni(333333);
//    p4.SetSueldo(555.432);
//    //Insertar en una posicion.
//    personas.insert(it, p4);
//    
//    cout<<"Lista de Personas Insert It"<<endl;
//    //foreach
//    for(auto persona: personas)
//        cout<<persona;
//    cout<<endl<<endl;
//    //For con iterator
//    for(list<class Persona>::iterator it = personas.begin(); it!=personas.end();it++)
//        cout<<*it;
//    cout<<endl;
//    
//    list<class Persona>::iterator it2 = personas.end();
//    while(true){
//        it2--;
//        cout<<*it2;
//        if(it2==personas.begin())break;
//    }
    
    list<class Persona> personas;
    ifstream input("personal.csv",ios::in);
    ofstream output("reporte.csv", ios::out);
    
    while(true){
        Persona persona;
        input>>persona;
        if(input.eof())break;
        personas.push_back(persona);
    }
    
    personas.sort();
    
    for(auto persona: personas)
        output<<persona;
    output<<endl;
    
    //Exploren el metodo merge -> Merge Sort
    //Primer Paso Una lista ordenada.
    //Segundo Paso otra lista ordenada.
    //Tercer Pasos en una tercera lista la funcion merge.
    return 0;
}

