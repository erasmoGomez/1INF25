/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"
#include "sobrecargas.hpp"

void leer_conductores(ifstream& input, struct Conductor* conductores, int& n){
    while(true){ // Leo todos los conductores
        //struct Conductor c;
        input>>conductores[n]; //Leo un conductor
        if(input.eof())break;
        n++;
    }
}

void imprimir_conductores(ofstream& output, struct Conductor* conductores, int n){
    for(int i=0; i<n;i++)
        output<<conductores[i];
}

int buscar_indice_conductor(struct Conductor* conductores, int id, int n){
    int i=0;
    for(i=0; i<n;i++)
        if(conductores[i].dni==id)return i;
    return -1;
}

void leer_y_llenar_papeletas(ifstream &input, struct Conductor* conductores, int n){
    //12345678,F001,2024-03-01,350.5257,Grave,Paso de luz roja
    int id, indice, n_papeleta;
    struct Papeleta p;
    while(true){
        input>>id;
        if(input.eof())break;
        input.get();
        input>>p;
        indice = buscar_indice_conductor(conductores, id, n);
        conductores[indice]+=p;
    }
}