/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 30, 2025, 5:19 AM
 */

#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Mago.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Requisitos para POLIMORFISMO
    //1. Que haya Herencia.
    //2. Puntero a la clase Base.
    //3. Clases Abstractas o Metodos Virtuales.
    Personaje* p1 = new Guerrero("Aragorn", 10, 80); //Como es puntero, NECESITO reservar memoria
    Personaje* p2 = new Mago("Gandalf", 20, 100, 150);
    
//    p1->mostrar();
//    p2->mostrar();

//    cout << "\n--- Copia y asignación ---\n";
//    Personaje copia = *p1; // usa constructor copia
//    copia.mostrar();
//
//    Personaje asignado("Temp", 1);
//    asignado = *p2; // usa operador =
//    asignado.mostrar();
    
//    Personaje* p;
    ifstream input("personajes.csv", ios::in);
    char tipo[10];
    Personaje* personajes[10];
    int n_personajes = 0;
    //Mago,Gandalf,85,120
    while(true){
        input.getline(tipo, 10, ',');
        if(input.eof())break;
        Personaje *p;
        if(strcmp(tipo, "Mago")==0){
            p = new class Mago;
        }
        else 
            p = new class Guerrero;
        //Aqui ya se sabe en tiempo de ejecucion a que hace referencia P
        p->leer(input);
        //Aqui yo tengo ya sea un Mago o Guerrero completamente leido
        personajes[n_personajes] = p; //Constructor copia o al =? no llama a ninguno XD
        n_personajes++;
    }
    
    for(int i = 0; i<n_personajes; i++)
        personajes[i]->mostrar();
    return 0;
}

