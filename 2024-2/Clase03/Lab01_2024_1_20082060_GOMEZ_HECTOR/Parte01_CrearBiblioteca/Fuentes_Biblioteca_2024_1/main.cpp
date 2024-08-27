/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 26, 2024, 5:47 PM
 */

#include "Estructuras.hpp"
#include "AperturaDeArchivos.h"
#include "Fuentes_Biblioteca_2024_1.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input_clientes, input_pedidos, input_libros;
    ofstream output;
    int n_libros = 0;
    AperturaDeUnArchivoDeTextosParaLeer(input_clientes, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(input_pedidos, "Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(input_libros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(output, "reporter_chevere.txt");
    
//    while(input_libros>>arrLib[n_libros])n_libros++;
//    strcpy(arrLib[n_libros].codigo,"FIN");
    
    int i=0, j=0;
    struct Libro arrLib[20]{}, lib;
    while(i<10){
        if( ! (input_libros >> lib)) break;
        arrLib[i]=lib;
        i++;
    }
    strcpy(arrLib[i].codigo,"FIN");
    
    struct Cliente arrCli[20]{}, cli;
    while(j<10){
        if( ! (input_clientes >> cli)) break;
        arrCli[j]=cli;
        j++;
    }
    arrCli[j].dni=0;
    
    struct LibroSolicitado libro_solicitado;
    int DNI;
    //000001,34460612,  CRY6839    VYG3594
    input_pedidos>>libro_solicitado.numeroDePedido;
    input_pedidos.get(); // Lee la coma
    input_pedidos>>DNI;
    input_pedidos.get();
    input_pedidos>>ws;
    input_pedidos.getline(libro_solicitado.codigoDelLibro, 8, ' ');
    //input_pedidos>>libro_solicitado.codigoDelLibro;
    libro_solicitado >> arrLib; //Prueba de la sobrecarga
    
    
    
    arrCli[0] << libro_solicitado; //Prueba Sobrecarga
    
    ++arrCli[0]; //Prueba Sobrecarga
    
    output<<fixed;
    output<<arrCli[0];
    output<<endl;
    output<<arrLib[0];
    return 0;
}

