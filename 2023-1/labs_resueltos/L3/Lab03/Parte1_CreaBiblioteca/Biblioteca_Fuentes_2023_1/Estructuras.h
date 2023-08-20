/* 
 * Proyecto: EstructurasLab3_2022_2
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 13 de septiembre de 2022, 09:26 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct StCurso{
    char codigoDelCurso[7];
    char nombreDelCurso[60];
    double creditos;
    int codigoDelProfesor;
    char nombreDelProfesor[60];
    int alumnos[50]; //Aquí colocará el semestre unido al código (202213456)
    int numeroDeAlumnos;
    double ingresos;
};

struct StAlumno{
    int semestre;
    int codigo;
    char nombre[60];
    char modalidad[16]; //Aquí colocará la palabra "PRESENCIAL", "VIRTUAL" o SEMIPRESENCIAL"
    int porcentaje;     // Solo si es Semi_Virtual
    int escala;
    char *cursos[7];    // Aquí colocará los códigos de los cursos
    int numeroDeCursos;
    double costoTotal;
};

struct StRegistroDeMatricula{
	char codigoDelCurso[7];
	int semestreDelAlumno;
	int codigodelAlumno;
};

#endif /* ESTRUCTURAS_H */

