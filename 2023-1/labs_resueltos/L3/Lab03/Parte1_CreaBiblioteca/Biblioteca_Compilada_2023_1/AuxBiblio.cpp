/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 28 de abril de 2023, 08:41 AM
 */

#include "AuxBiblio.h"

// Lectura
bool operator>>(ifstream& arch,  struct StCurso& curso){
    // Leyendo el curso
    arch >> curso.codigoDelCurso;
    if(arch.eof())
        return false;
    arch >> ws >> curso.nombreDelCurso >> ws;
    arch >> curso.creditos >> curso.codigoDelProfesor >> ws;
    arch >> curso.nombreDelProfesor;
    curso.numeroDeAlumnos = 0;
    curso.ingresos = 0;
    return true;
}

bool operator>>(ifstream& arch, struct StAlumno& alumno){
    char aux, carModalidad;
    // Leyendo el alumno
    arch >> alumno.semestre;
    if(arch.eof())
        return false;
    arch >> aux >> alumno.codigo >> ws >> alumno.nombre >> ws >> carModalidad;
    strcpy(alumno.modalidad, devolverCadenaModalidad(carModalidad));
    if(carModalidad == 'S')
        arch >> alumno.porcentaje;
    if(carModalidad != 'G')
        arch >> aux;
    arch >> alumno.escala;
    alumno.numeroDeCursos = 0;
    alumno.costoTotal = 0;
    return true;
}

bool operator>>(ifstream& arch,  struct StRegistroDeMatricula& matricula){
    char aux;
    // Leyendo el registro
    arch >> matricula.codigoDelCurso;
    if(arch.eof())
        return false;
    arch >> matricula.semestreDelAlumno >> aux >> matricula.codigodelAlumno;
    return true;
}

// Agregación
void operator+=(struct StCurso* cursos, const struct StCurso curso){
    /* Se actualiza el buscador hasta encontrar el curso nulo ("XXXXXX") */
    int buscador;
    for(buscador=0; strcmp(cursos[buscador].codigoDelCurso, "XXXXXX") != 0;
            buscador++);
    // Agregar curso
    strcpy(cursos[buscador].codigoDelCurso, curso.codigoDelCurso);
    strcpy(cursos[buscador].nombreDelCurso, curso.nombreDelCurso);
    strcpy(cursos[buscador].nombreDelProfesor, curso.nombreDelProfesor);
    for(int i=0; i<curso.numeroDeAlumnos; i++)
        cursos[buscador].alumnos[i] = curso.alumnos[i];
    cursos[buscador].codigoDelProfesor = curso.codigoDelProfesor;
    cursos[buscador].creditos = curso.creditos;
    cursos[buscador].ingresos = curso.ingresos;
    cursos[buscador].numeroDeAlumnos = curso.numeroDeAlumnos;
    // Establecer el curso siguiente como nulo.
    strcpy(cursos[buscador+1].codigoDelCurso, "XXXXXX");
}

void operator+=(struct StAlumno* alumnos, const struct StAlumno alumno){
    int buscador;
    // Se actualiza el buscador hasta encontrar el alumno nulo (0)
    for(buscador=0; alumnos[buscador].codigo != 0; buscador++);
    // Agregar curso
    strcpy(alumnos[buscador].nombre, alumno.nombre);
    strcpy(alumnos[buscador].modalidad, alumno.modalidad);
    for(int i=0; i<alumno.numeroDeCursos; i++)
        strcpy(alumnos[buscador].cursos[i], alumno.cursos[i]);
    alumnos[buscador].codigo = alumno.codigo;
    alumnos[buscador].costoTotal = alumno.costoTotal;
    alumnos[buscador].escala = alumno.escala;
    alumnos[buscador].numeroDeCursos = alumno.numeroDeCursos;
    alumnos[buscador].porcentaje = alumno.porcentaje;
    alumnos[buscador].semestre = alumno.semestre;
    // Establecer el curso siguiente como nulo.
    alumnos[buscador+1].semestre = 0;
}

void operator*=(struct StCurso* cursos, 
        const struct StRegistroDeMatricula matricula){
    int buscadorCurso;
    // Obtener la ubicación del curso
    for(buscadorCurso=0; 
            strcmp(cursos[buscadorCurso].codigoDelCurso, matricula.codigoDelCurso) != 0 ;
            buscadorCurso++);
    // Agregar código de alumno a curso
    cursos[buscadorCurso].alumnos[cursos[buscadorCurso].numeroDeAlumnos] = 
            matricula.semestreDelAlumno*10000 + matricula.codigodelAlumno;
    cursos[buscadorCurso].numeroDeAlumnos++;
}

void operator*=(struct StAlumno* alumnos, 
        const struct StRegistroDeMatricula matricula){
    int buscadorAlumno;
    // Obtener la ubicación del alumno
    for(buscadorAlumno=0; alumnos[buscadorAlumno].semestre != 0 &&
            !(alumnos[buscadorAlumno].semestre == matricula.semestreDelAlumno &&
            alumnos[buscadorAlumno].codigo == matricula.codigodelAlumno);
            buscadorAlumno++);
    // Agregar código de alumno a curso
    alumnos[buscadorAlumno].cursos[alumnos[buscadorAlumno].numeroDeCursos] = 
            new char[7];
    strcpy(alumnos[buscadorAlumno].cursos[alumnos[buscadorAlumno].numeroDeCursos],
            matricula.codigoDelCurso);
    alumnos[buscadorAlumno].numeroDeCursos++;
}

// Impresión
ofstream& operator<<(ofstream& arch, const struct StCurso& curso){
    arch << left << setw(16) << "CÓDIGO" << setw(48) << "NOMBRE";
    arch << "CRÉDITOS" << endl;
    arch << setw(15) << curso.codigoDelCurso << setw(50);
    arch << curso.nombreDelCurso << setw(20) << curso.creditos << endl;
    arch << "PROFESOR: ";
    imprimirNombreDocente(arch, curso.nombreDelProfesor);
    arch << " [" << curso.codigoDelProfesor << "]" << endl;
    arch << "Alumnos matriculados:" << endl;
    arch << "  " << setw(14) << "Semestre" << "Código" << endl;
    if(curso.numeroDeAlumnos == 0){
        arch << "  El curso no presenta alumnos matriculados." << endl;
    } else {
        for(int i=0; i<curso.numeroDeAlumnos; i++){
            arch << setw(15) << curso.alumnos[i]/10000;
            arch << curso.alumnos[i]%10000 << endl;
        }
    }
    arch << "Número de alumnos: " << curso.numeroDeAlumnos << endl;
    arch.precision(2);
    arch << "Total ingresado: " << fixed << curso.ingresos << endl;
    return arch;
}

ofstream& operator<<(ofstream& arch, const struct StAlumno& alumno){
    arch << left << setw(10) << "SEMESTRE" << setw(10) << "CODIGO";
    arch << setw(50) << "NOMBRE" << setw(30) << "MODALIDAD" << "ESCALA";
    arch << endl;
    arch << setw(10) << alumno.semestre << setw(10);
    arch << alumno.codigo << setw(50) << alumno.nombre;
    if(strcmp(alumno.modalidad, "SEMIPRESENCIAL") == 0)
        arch << "SEMIPRESENCIAL CON " << setfill('0') << setw(2) << right << 
                alumno.porcentaje << left << setw(9) << setfill(' ') << "%";
    else
        arch << setw(30) << alumno.modalidad;
    arch << alumno.escala <<endl;
    arch << "Códigos de cursos matriculados:" << endl;
    if(alumno.numeroDeCursos == 0){
        arch << setw(10) << "" 
                << "El alumno no se ha matriculado en ningún curso." << endl;
    } else {
        for(int i=0; i<alumno.numeroDeCursos; i++){
            arch << setw(10) << "" << alumno.cursos[i] << endl;
        }
    }
    arch << "Número de cursos: " << alumno.numeroDeCursos << endl;
    arch.precision(2);
    arch << "Costo total: " << fixed << alumno.costoTotal << endl;
    return arch;
}

const char* devolverCadenaModalidad(char modalidad){
    if(modalidad == 'G')
        return "PRESENCIAL";
    if(modalidad == 'S')
        return "SEMIPRESENCIAL";
    return "VIRTUAL";
}

void imprimirNombreDocente(ofstream& arch, const char* nombreOriginal){
    for(int i=0; i<strlen(nombreOriginal); i++){
        if((nombreOriginal[i] == '_'))
            arch << " ";
        else
            arch << nombreOriginal[i];
    }
}