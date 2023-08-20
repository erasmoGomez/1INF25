/* 
 * File:   PruebaBiblio.h
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 29 de abril de 2023, 03:44
 */

#include "PruebaBiblio.h"

void probarCurso(ifstream& archEntrada, ofstream& archSalida, 
        struct StCurso* cursos, struct StCurso curso){
    archSalida << "Prueba #1: Lectura de curso" << endl << endl;
    // Lectura de curso
    archEntrada >> curso;
    archSalida << curso;
    /* Agregación de curso en arreglo de cursos
     * Artificio: Se agrega al inicio un curso de código "XXXXXX" para no tener
     * problemas con la búsqueda del último elemento del arreglo.
     */
    strcpy(cursos[0].codigoDelCurso, "XXXXXX");
    cursos += curso;
    archSalida << endl << "Prueba #2: Agregación de curso a arreglo" << endl << endl;
    archSalida << cursos[0];
}

void probarAlumno(ifstream& archEntrada, ofstream& archSalida, 
        struct StAlumno* alumnos, struct StAlumno alumno){
    archSalida << endl << "Prueba #3: Lectura de alumno" << endl << endl;
    archEntrada >> alumno;
    archSalida << alumno;
    // Agregación de curso en arreglo de cursos
    alumnos += alumno;
    archSalida << endl << "Prueba #4: Agregación de alumno a arreglo" << endl << endl;
    archSalida << alumnos[0];
}

void probarMatricula(ifstream& archEntrada, ofstream& archSalida, 
        struct StCurso* cursos, struct StAlumno* alumnos, struct StCurso curso,
        struct StAlumno alumno){
    archSalida << endl << "Prueba #5: Lectura de matrícula" << endl << endl;
    struct StRegistroDeMatricula matricula;
    archEntrada >> matricula;
    archSalida << matricula.semestreDelAlumno << "-";
    archSalida << matricula.codigodelAlumno << " matriculado en ";
    archSalida << matricula.codigoDelCurso << endl;
    // Para poder realizar la demostración, se modificará el código del alumno
    matricula.semestreDelAlumno = 20211;
    matricula.codigodelAlumno = 1260;
    
    cursos *= matricula;
    alumnos *= matricula;
    
    archSalida << endl << "Prueba #6: Agregación de alumno a curso" << endl << endl;
    archSalida << cursos[0];    
    archSalida << endl << "Prueba #7: Agregación de curso a alumno" << endl << endl;
    archSalida << alumnos[0];
}