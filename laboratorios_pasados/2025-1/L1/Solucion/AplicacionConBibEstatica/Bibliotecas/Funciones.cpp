//
// Created by erasm on 1/04/2026.
//

#include "Funciones.hpp"

void leerDatos(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int &numDat,const char* nomb){
    struct CadenaDeCaracteres buff;
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO "<<nomb;
        exit(1);}

    while(true){
        !conductor[numDat];
        !placa[numDat];
        arch>>dni[numDat];
        if(arch.eof()) break;
        int i=0;
        !buff;
        while((arch>>buff)==0){
            if(i==0) conductor[numDat]<=buff;
            else {
                conductor[numDat]+="_";
                conductor[numDat]+=buff;
            }
            i++;
        }
        arch>>placa[numDat];
        numDat++;
    }
}

void imprimirRep(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int numDat,const char* nomb){
    ofstream archR(nomb,ios::out);
    archR<<setw(60)<<"REPORTE DE INFRACTORES DE TRANSITO"<<endl;
    imprimirLinea(archR,83,'=');
    archR<<"DNI       INFRACTOR"<<setw(57)<<"PLACA"<<endl;
    imprimirLinea(archR,83,'-');
    for (int i = 0; i < numDat; i++) {
        archR<<dni[i]<<"  "<<left<<setw(60);
        mayusMinus(conductor[i].cadena);
        archR<<conductor[i];
        archR<<" "<<setw(9);
        archR<<placa[i];
        archR<<endl<<right;
    }
}

void imprimirLinea(ofstream &archR,int len,char c){
    for (int i = 0; i < len; i++) archR<<c;
    archR<<endl;
}

void ordenarDatos(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int &numDat){
    for (int i = 0; i < numDat-1; i++) {
        for (int j = 0; j < numDat-i-1; j++) {
            if(conductor[j]<conductor[j+1]) conductor[j]&&conductor[j+1];
        }
    }
}

void mayusMinus(char *cad){
    for (int i = 0; cad[i]; i++) {
        if(i==0 or cad[i-1]=='_'){
            if(cad[i]>='a' and cad[i]<='z') cad[i]+='A'-'a';
        }
        else{
            if(cad[i]>='A' and cad[i]<='Z') cad[i]+='a'-'A';
        }
    }

}