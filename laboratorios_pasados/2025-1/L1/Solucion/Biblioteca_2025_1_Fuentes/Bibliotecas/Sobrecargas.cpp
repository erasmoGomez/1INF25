//
// Created by erasm on 1/04/2026.
//

#include "Sobrecargas.hpp"

void operator ! (struct CadenaDeCaracteres &cadena){
    cadena.cadena=nullptr;
    cadena.longitud=0;
    cadena.capacidad=0;
}

void operator <= (struct CadenaDeCaracteres &cadena,const char* cad){
    if(cadena.capacidad<strlen(cad)+1 or cadena.cadena==nullptr){
        cadena.capacidad=strlen(cad)+1;
        if(cadena.cadena!=nullptr) delete cadena.cadena;
        cadena.cadena=new char[cadena.capacidad]{};
    }
    cadena.longitud=strlen(cad);
    strcpy(cadena.cadena,cad);
}

void operator <= (struct CadenaDeCaracteres &cadena, int espacio){
    delete cadena.cadena;
    cadena.capacidad=espacio;
    cadena.longitud=0;
    cadena.cadena=new char[espacio]{};
}

void operator <= (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres cad2){
    cad1<=cad2.cadena;
//    if(cad1.capacidad<cad2.capacidad or cad1.cadena==nullptr){
//        cad1.capacidad=cad2.capacidad;
//        if(cad1.cadena!=nullptr) delete cad1.cadena;
//        cad1.cadena=new char[cad1.capacidad]{};
//    }
//    cad1.longitud=cad2.longitud;
//    strcpy(cad1.cadena,cad2.cadena);
}

bool operator += (struct CadenaDeCaracteres &cadena,const char* cad){
    char* nuevaCad;
    if(cadena.cadena==nullptr or cadena.longitud==0) return false;
    if(cadena.capacidad<(cadena.longitud+strlen(cad)+1)){
        cadena.capacidad=cadena.longitud+strlen(cad)+1;
        nuevaCad=new char[cadena.capacidad]{};
        strcpy(nuevaCad,cadena.cadena);
        strcat(nuevaCad,cad);
        delete cadena.cadena;
        cadena.cadena=nuevaCad;
    }
    else{
        strcat(cadena.cadena,cad);
    }
    cadena.longitud+=strlen(cad);
    return true;
}

bool operator += (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres cad2){
    return cad1+=cad2.cadena;
//    char* nuevaCad;
//    if(cad1.cadena==nullptr or cad1.longitud=0) return false;
//    if(cad1.capacidad<(cad1.longitud+cad2.longitud+1)){
//        cad1.capacidad=cad1.longitud+cad2.longitud+1;
//        nuevaCad=new char[cad1.capacidad]{};
//        strcpy(nuevaCad,cad1.cadena);
//        strcat(nuevaCad,cad2.cadena);
//        delete cad1.cadena;
//        cad1.cadena=nuevaCad;
//    }
//    else{
//        strcat(cad1.cadena,cad2.cadena);
//    }
//    cad1.longitud+=cad2.longitud;

}

int compare (struct CadenaDeCaracteres &cadena,const char* cad){
    char buff1[cadena.capacidad],buff2[strlen(cad)+1];
    strcpy(buff1,cadena.cadena);
    strcpy(buff2,cad);
    for (int i = 0; buff1[i]; i++)
        if(buff1[i]>='A' and buff1[i]<='Z') buff1[i]+='a'-'A';
    for (int i = 0; buff2[i]; i++)
        if(buff2[i]>='A' and buff2[i]<='Z') buff2[i]+='a'-'A';

    return strcmp(buff1,buff2);
}

bool operator == (struct CadenaDeCaracteres &cadena,const char* cad){
    return (compare(cadena,cad)==0);
}

bool operator > (struct CadenaDeCaracteres &cadena,const char* cad){
    return (compare(cadena,cad)>0);
}

bool operator < (struct CadenaDeCaracteres &cadena,const char* cad){
    return (compare(cadena,cad)<0);
}

int compare (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    return compare(cad1,cad2.cadena);
//    char buff1[cad1.capacidad],buff2[cad2.capacidad];
//    strcpy(buff1,cad1.cadena);
//    strcpy(buff2,cad2.cadena);
//    for (int i = 0; buff1[i]; i++)
//        if(buff1[i]>='A' and buff1[i]<='Z') buff1+='a'-'A';
//    for (int i = 0; buff2[i]; i++)
//        if(buff2[i]>='A' and buff2[i]<='Z') buff2+='a'-'A';
//
//    return strcmp(buff1,buff2);
}

bool operator == (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    return (compare(cad1,cad2)==0);
}

bool operator > (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    return (compare(cad1,cad2)>0);
}

bool operator < (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    return (compare(cad1,cad2)<0);
}

int operator >> (ifstream &arch,struct CadenaDeCaracteres &cadena){
    char buff[100];
    arch>>buff;
    if(arch.eof()) return 1;
    if(not ((buff[0]>='a' and buff[0]<='z') or
            (buff[0]>='A' and buff[0]<='Z'))) return -1;
    cadena<=buff;
    return 0;
}

void operator && (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    struct CadenaDeCaracteres aux;
    aux=cad1;
    cad1=cad2;
    cad2=aux;
}

ofstream& operator << (ofstream &arch,struct CadenaDeCaracteres cadena){
    arch<<cadena.cadena;
    return arch;
}


