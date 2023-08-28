/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Persona.hpp"
#include "Estructuras.hpp"
#include "Sobrecargas.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
void operator *= (struct Persona &p, double aumento){
    p.sueldo *= aumento;
}

struct Persona operator + (const struct Persona &p1, const struct Persona& p2){
    struct Persona nuevo{};
    nuevo.dni = 159852;
    nuevo.sueldo = p1.sueldo + p2.sueldo;
    char nuevo_nombre[150];
    strcpy(nuevo_nombre, p1.nombre);
    strcat(nuevo_nombre, p2.nombre);
    strcpy(nuevo.nombre, nuevo_nombre);
    return nuevo;
}

ostream & operator << (ostream & out, const struct Persona & p){
    out<<right<<setw(10)<<p.dni<<" "<<left<<setw(40)<<p.nombre;
    out<<right<<setw(10)<<p.sueldo<<endl;
    return out;
}

bool operator >> (ifstream & input, struct StCurso & c){
    char extra;
    // INF263 Algoritmia 3.75 3506031 INGA_FLORES_PEPITO TXT
    // INF263,Algoritmia,3.75,3506031,INGA_FLORES_PEPITO CSV
    // Codigo Curso, Nombre Curso, Creditos, Codigo Profesor, Nombre Profesor
    // C es la estructura que quiero llenar
    input.getline(c.codigoDelCurso, 7, ',');
 
    if(input.eof()){
        return false;   
    }
    
    input.getline(c.nombreDelCurso, 60, ',');
    // input.getline(creditos,3,','); GRAVE ERROR DE CONCEPTO
    //input>>c.creditos>>extra;
    input>>c.creditos;
    input>>extra;
    input.getline(c.nombreDelProfesor, 60, ',');
    input>>c.codigoDelProfesor;
    input>>extra; //Para el fin de linea
    return true;
}

void get_info(char *buffer,struct StAlumno & alumno_info){
    //este es un proceso generico si se requiere separar dos partes de una cadena
    //teniendo en medio informacion irrelevante
    //En el caso del texto del 2023-1 son enteros los numeros a los extremos
    //De ser ese el caso se debe leer como enteros, pero para este ejercicio lo vamos
    ///a generalizar
    //cout<<buffer<<endl;
    int pos1, pos2, pos3,f=0, s=0, last;
    char first_part[8], second_part[8];
    for(pos1=0;pos1<strlen(buffer);pos1++){
        if ( buffer[pos1] == '-') break;
        first_part[f] = buffer[pos1];
        f++;
    }
    first_part[f] = 0;
    for(pos2=pos1+1;pos2<strlen(buffer);pos2++){
        if ( buffer[pos2] == '-') last = pos2; 
    }
    for(pos3=last+1;pos3<strlen(buffer);pos3++){
        second_part[s] = buffer[pos3];
        s++;
    }
    second_part[s] = 0;
    //Repito aqui se va a hacer una transformacion de los str a int
    alumno_info.codigo = atoi(first_part);
    alumno_info.semestre = atoi(second_part);
}

bool operator >> (ifstream & input, struct StAlumno & alumno_info){
    // 20211-A-1260,GORDILLO/CASTRO/RONAL,O,100,G2
    // Semestre de ingreso - Codigo alumno, Nombre Alumno, Modalidad, 
    // Porcentaje , Escala
    // alumno_info es la estructura que quiero llenar
    char buffer[60];
    char modalidad, escala[2],extra;
    
    input.getline(buffer, 60, ',');
    if(input.eof()){
        return false;   
    }
    
    get_info(buffer, alumno_info);
    
    input.getline(alumno_info.nombre,60, ',');
    input>>modalidad>>extra;
    if (modalidad == 'O'){
       strcpy(alumno_info.modalidad,"Presencial");
    }
    if (modalidad == 'V'){
       strcpy(alumno_info.modalidad ,"Virtual");
    }
    if (modalidad == 'S'){
       strcpy(alumno_info.modalidad ,"Semi-Presencial");
    }
    
    input>>alumno_info.porcentaje>>extra;
    //Obligo a leer un patron de caracteres fijo
    //OJO: Solo funciona si leo una misma cantidad de caracteres. 
    //El buffer en este caso escala se define con 3 espacion escala[2] 0 1 2
    //El get recibe para este caso el buffer y un espacio adicional
    //From docs 
    //A null character ('\0') is automatically appended to the written sequence
    input.get(escala,3);
    //Esto para convertir un digito de caracter a int
    alumno_info.escala = escala[1] - '0'; 
    
    input.get(); //Para el fin de linea
    return true;
}

bool operator >> (ifstream & input, struct StRegistroDeMatricula & reg_mat_info){
    //INF263,20222,4569
    //CODIGO DEL CURSO, SEMESTRE, CODIGO ALUMNO
    input.getline(reg_mat_info.codigoDelCurso, 7, ',');
    if(input.eof()){
        return false;   
    }
    input>>reg_mat_info.semestreDelAlumno;
    input.get();
    input>>reg_mat_info.codigodelAlumno;
    input.get();
    return true;
}