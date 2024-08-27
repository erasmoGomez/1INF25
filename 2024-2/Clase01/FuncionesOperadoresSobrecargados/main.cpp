/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 19, 2024, 6:49 PM
 */

#include "Utils.hpp"
#include "Telefono.hpp"
#include "sobrecargas.hpp"
#include "funciones.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    int *p; //Declaracion de varible
//    p = new int[5];//Reserva de Memoria
//    *p = 10;  //   p[0] // Asignacion de valores
//    cout<<*p<<endl;
//    Telefono t;
//    Telefono t2;
//    t.numero_telfonico = 98387473;
//    strcpy(t.marca,"samsung");
//    strcpy(t.modelo, "galaxys");
//    t.precio = 1500.99;
    
    ifstream input("telefonos.txt", ios::in);
    ofstream output("reporte.txt", ios::out);
    
//    int p;
//    input>>p;

//    input>>t; // Por linea solo una linea
//    bool lectura = input>>t2;
//    cout<<t.numero_telefonico<<endl;
//    cout<<t.marca<<endl;
//    cout<<t.modelo<<endl;
//    cout<<t.precio<<endl;
//    cout<<t2.numero_telefonico<<endl;
//    cout<<t2.marca<<endl;
//    cout<<t2.modelo<<endl;
//    cout<<t2.precio<<endl;
//    cout<<lectura<<endl;
    
    //input>>t;
    //output<<t;
    //cout<<t;
    
    struct Telefono telefonos[6];
    leer_telefonos(input, telefonos);
    imprimir_telefonos(output, telefonos);
    incrementar_precios(telefonos);
    output<<"NUEVOS VALORES"<<endl;
    imprimir_telefonos(output, telefonos);
    //cout<<sizeof(struct Telefono)<<endl;
    
//    while(true){
//        input>>telefonos[cantidad_telefonos_leidos];
//        if(input.eof())break;
//        cantidad_telefonos_leidos++;
//    }
    
    
    return 0;
}

