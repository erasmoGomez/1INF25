/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 4, 2023, 7:05 AM
 */


#include "auxiliar.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archivo_entrada("Alumnos-Cursos.txt",ios::in); 
    ofstream archivo_salida("reporte_salida.txt",ios::out);
    if(!archivo_entrada){
        cout<<"Error: El archivo de entrada no se puede abrir";
        exit(1);
    }
    if(!archivo_salida){
        cout<<"Error: El archivo de salida no se puede abrir";
        exit(1);
    }
    //TODO impresion del encabezado
    imprimir_encabezado_inicial(archivo_salida);
//    //TODO lectura e impresion de datos por linea
    imprimir_datos_alumnos(archivo_entrada, archivo_salida);
    //TODO impresion del resumen final
    
    archivo_entrada.close();
    archivo_salida.close();
    return 0;
}

