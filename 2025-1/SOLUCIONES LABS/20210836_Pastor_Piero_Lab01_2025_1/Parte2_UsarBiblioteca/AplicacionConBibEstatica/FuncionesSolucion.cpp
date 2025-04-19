/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesSolucion.cpp
 * Author: piero
 * 
 * Created on 15 de abril de 2025, 07:58 AM
 */

#include "FuncionesSolucion.h"

void LeerDatos(const char *archname, int *&dni, CadenaDeCaracteres *&conductor, 
               CadenaDeCaracteres *&placa){
    int dni_i, i=0;
    CadenaDeCaracteres cadena; !cadena;
    ifstream arch(archname, ios::in);
    if(not arch.is_open()){cout << "No se pudo abrir el archivo " << archname; exit(1);}
    dni = new int[201]; conductor = new CadenaDeCaracteres[201]; placa = new CadenaDeCaracteres[201];
    while(true){
        arch >> dni_i;
        if(arch.eof()) {dni[i] = -1; break;} //Se pone un 1 al final para luego poder contar cuantos hay
        dni[i] = dni_i;
        !conductor[i];
        !placa[i];
        arch >> ws;
        arch >> conductor[i];
        //conductor[i] <= cadena;
        while(true){
            arch >> ws;
            if(arch >> cadena == -1) break;
            conductor[i] += "_";
            conductor[i] += cadena;
        }
        arch >> ws;
        arch >> placa[i];
        i++;
    }
}

void OrdenarDatos(int *dni, CadenaDeCaracteres *conductor, CadenaDeCaracteres *placa){
    int n=0;
    for(n=0;dni[n]!=-1;n++);
    srand(time(nullptr)); //Semilla para aleatoriedad
    QSort(dni, conductor, placa, 0, n);
}

void QSort(int *dni, CadenaDeCaracteres *conductor, CadenaDeCaracteres *placa, int beg, int end){
    if(beg >= end - 1) return;
    int pivot = beg + rand() % (end - beg); //Pivot aleatorio para evitar n^2
    int less = beg - 1; //Lo inicializa al comienzo del arreglo -1
    // Mover el pivote al final para evitar que lo toque cualquier swap
    SwitchDatos(dni, conductor, placa, pivot, end - 1);
    pivot = end - 1;
    for (int i = beg; i < end - 1; ++i) { // end-1 porque el pivote está al final
        if (conductor[i] < conductor[pivot]) { //Si es menor al pivote se va al primer lado
            ++less; //Avanza el tope del primer lado
            SwitchDatos(dni, conductor, placa, less, i);
        }
    }
    // Colocamos el pivote en su lugar final (entre ambos lados)
    SwitchDatos(dni, conductor, placa, less + 1, pivot);
    QSort(dni, conductor, placa, beg, less + 1); //Manda la mitad menor
    QSort(dni, conductor, placa, less + 2, end); //Manda la mitad mayor
}

void SwitchDatos(int *dni, CadenaDeCaracteres *conductor, CadenaDeCaracteres *placa,
                 int i, int j){
    int aux;
    CadenaDeCaracteres aux2, aux3; !aux2; !aux3;
    aux = dni[i];
    aux2 <= conductor[i];
    aux3 <= placa[i];
    dni[i] = dni[j];
    dni[j] = aux;
    conductor[i] <= conductor[j];
    conductor[j] <= aux2;
    placa[i] <= placa[j];
    placa[j] <= aux3;
}

void ImprimirReporte(const char *archname, int *dni, CadenaDeCaracteres *conductor, 
               CadenaDeCaracteres *placa){
    ofstream arch(archname, ios::out);
    if(not arch.is_open()){cout << "No se pudo abrir el archivo " << archname; exit(1);}
    ImprimirEncabezado(arch);
    for(int i=0; dni[i] != -1; i++){
        arch << setfill('0') << setw(8) << dni[i] << setfill(' ') << setw(5) << " ";
        arch << conductor[i] << setw(MAX_TAM-conductor[i].longitud) << " ";
        arch << placa[i];
        arch << endl;
    }
}

void ImprimirEncabezado(ofstream &arch){
    arch << setw(12) << " " << "REPORTE INFRACTORES DE TRANSITO" << endl;
    for(int i=0; i < 58; i++) arch << "=";
    arch << "\nDNI" << setw(10) << " " << "INFRACTOR" << setw(27) << " " << "PLACA" << endl;
    for(int i=0; i < 58; i++) arch << "-";
    arch << endl;
} 
        