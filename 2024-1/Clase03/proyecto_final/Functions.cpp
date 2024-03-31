/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Sobrecargas.hpp"
#include "Functions.hpp"
#include "Persona.hpp"

int add(int a, int b){
    return  a + b;
}

void add_headers(){
    cout<<setw(ANCHO/2)<<right<<"Mi persona favorita"<<endl;
    cout<<left<<setw(ANCHO/3)<<"DNI"<<left<<setw(ANCHO/3)<<"NOMBRE";
    cout<<left<<setw(ANCHO/3)<<"PESO"<<left<<setw(ANCHO/3)<<"TALLA"<<endl;
}

void add_headers(ofstream & out){
    out<<setw(ANCHO/2)<<right<<"Reporte de Personas"<<endl;
    out<<left<<setw(ANCHO/3)<<"DNI"<<left<<setw(ANCHO/3)<<"APELLIDO Y NOMBRE";
    out<<left<<setw(ANCHO/3)<<"PESO (Kg)"<<left<<setw(ANCHO/3)<<"TALLA (m)"<<endl;
}

void read_people(ifstream &input, struct Persona *people){
    int n_people = 0;
    while(1){
        input>>people[n_people];
        if(input.eof())
            break;
        n_people++;
    }
    struct Persona p;
    p.dni = 0;
    people[n_people] = p;
}

void display_people(ofstream &output, struct Persona *people){
    add_headers(output);
    int n_people = 0;
    while(1){
        if (people[n_people].dni==0) break;
        output<<people[n_people];
        n_people++;
    }
}
