//
// Created by erasm on 1/04/2026.
//

#include "Sobrecargas.hpp"

void operator ! (struct CadenaDeCaracteres &cadena){
    cadena.cadena=nullptr;
    cadena.longitud=0;
    cadena.capacidad=0;
}

// cadena <= palabra
// cadena = 10 espacios reservados CAPACIDAD
// cadena <= "hola\0", si funciona sin problemas
// cadena <= "programacion\0", no funciona, debemos incrementar capacidad

// cadena -> "hola"
// Asignacion: Chancando la variable
// cadena <= "mundo"
void operator <= (struct CadenaDeCaracteres &cadena,const char* cad){
    if(cadena.capacidad<strlen(cad)+1 or cadena.cadena==nullptr){
        //Reservar memoria a la CadenaDeCaracteres
        cadena.capacidad=strlen(cad)+1;
        if(cadena.cadena!=nullptr) delete cadena.cadena;
        cadena.cadena=new char[cadena.capacidad]{};
    }
    cadena.longitud=strlen(cad); // igualamos longitudes
    // La asignacion per se
    strcpy(cadena.cadena,cad);
}

void operator <= (struct CadenaDeCaracteres &cadena, int espacio){
    delete cadena.cadena;
    cadena.capacidad=espacio;
    cadena.longitud=0;
    cadena.cadena=new char[espacio]{};

    // Cadena vacia, pero con "espacio" de memoria reservado
}

void operator <= (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    // struct CadenaDeCaracteres & <= char*
    // void operator <= (struct CadenaDeCaracteres &cadena,const char* cad){
    cad1<=cad2.cadena;
}

bool operator += (struct CadenaDeCaracteres &cadena,const char* cad){
    char* nuevaCad;
    if(cadena.cadena==nullptr or cadena.longitud==0) return false;
    //Validar si la nueva palabra que se va a concatenar es soportada por la capacidad de cadena
    if(cadena.capacidad<(cadena.longitud+strlen(cad)+1)){
        //Si la supera
        //cadena -> Hola, cad -> Mundo
        //cadena -> HolaMundo
        cadena.capacidad=cadena.longitud+strlen(cad)+1;
        nuevaCad=new char[cadena.capacidad]{}; //Gestado de NUEVA memoria
        // Concatenacion
        strcpy(nuevaCad,cadena.cadena); // Lo que habia en cadena
        strcat(nuevaCad,cad); // Lo nuevo que se concatena
        //nuevaCad -> "HolaMundo\0"
        delete [] cadena.cadena; // Borramos lo que habia antes en la cadena
        cadena.cadena=nuevaCad; // Hacemos escapar la nuevaCad en cadena.cadena creando una nueva conexion.
    }
    else{
        strcat(cadena.cadena,cad);
    }
    cadena.longitud+=strlen(cad);
    return true;
}

bool operator += (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2){
    return cad1+=cad2.cadena;
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


