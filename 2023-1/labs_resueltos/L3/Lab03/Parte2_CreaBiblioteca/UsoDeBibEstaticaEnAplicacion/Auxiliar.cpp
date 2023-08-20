
/* 
 * File:   Auxiliar.cpp
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 28 de abril de 2023, 10:20
 */

#include "Auxiliar.h"

void leerCursos(ifstream& arch, struct StCurso* cursos){
    struct StCurso curso;
     /* Artificio: Se agrega al inicio un curso de código "XXXXXX" para no tener
     *  problemas con la búsqueda del último elemento del arreglo.
     */
    strcpy(cursos[0].codigoDelCurso, "XXXXXX");
    while(1){
        /* El operador sobrecargado >> detecta el fin de archivo, por lo que
         * confiamos en el resultado del operador (si retorna false, sabremos
         * que llegamos al fin de archivo y, por ende, debemos parar la lectura.
         */
        if(arch >> curso)
            cursos += curso;
        else
            break;
    }
}

void leerAlumnos(ifstream& arch, struct StAlumno* alumnos){
    struct StAlumno alumno;
    alumnos[0].semestre = 0;
    while(1){
        if(arch >> alumno)
            alumnos += alumno;
        else
            break;
    }
}

void leerMatriculas(ifstream& arch, struct StCurso* cursos,
        struct StAlumno* alumnos){
    struct StRegistroDeMatricula matricula;
    while(1){
        if(arch >> matricula){
            /* Luego de procesar una matrícula, la agregamos a los arreglos de
             * cursos y alumnos.
             */
            cursos *= matricula;
            alumnos *= matricula;
        }
        else
            break;
    }
}

void calcularCostos(struct StCurso* cursos, struct StAlumno* alumnos){    
    // Lectura de las escalas.
    double* costosXEscala = leerEscalas();
    
    // Procesamiento de costos en cursos.
    procesarPagosEnCursos(cursos, alumnos, costosXEscala);
    
    // Procesamiento de costos en alumnos.
    procesarPagosEnAlumnos(alumnos, cursos, costosXEscala);
}

void imprimirReporte(ofstream& reporte, struct StCurso* cursos,
        struct StAlumno* alumnos){
    reporte << right << setw(71) << "REPORTE GENERAL DE CURSOS Y ALUMNOS" <<
            left << endl << endl;
    reporte << right << setw(61) << "REPORTE DE CURSOS" << left << endl << endl;
    for(int i=0; strcmp(cursos[i].codigoDelCurso, "XXXXXX") != 0; i++)
        reporte << cursos[i] << endl;
    reporte << right << setw(62) << "REPORTE DE ALUMNOS" << left << endl << endl;
    for(int i=0; alumnos[i].semestre != 0; i++)
        reporte << alumnos[i] << endl;
}

double* leerEscalas(){
    // Declaración de variables.
    ifstream archEscalas;
    double* costosXEscala = new double[5];
    char aux;
    int escala;
    double costo;
    // Procesamiento de archivo de escalas.
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas, "Escalas.txt");
    while(1){
        archEscalas >> aux;
        if(archEscalas.eof())
            break;
        archEscalas >> escala >> costo;
        /* El archivo está desordenado; por ende, insertaremos el valor de la
         * escala en base a su número y posición en el arreglo
         */
        costosXEscala[escala-1] = costo;
    }
    return costosXEscala;
}

void procesarPagosEnCursos(struct StCurso* cursos, struct StAlumno* alumnos,
        double* costosXEscala){
    int semestreAlumno, codAlumno, escalaAlumno, porcentajePago;
    // Como no sabemos cuándo termina el arreglo, buscaremos su elemento "nulo"
    for(int i=0; strcmp(cursos[i].codigoDelCurso, "XXXXXX") != 0; i++){
        for(int j=0; j<cursos[i].numeroDeAlumnos; j++){
            // Extracción de semestre y código de alumno
            semestreAlumno = (cursos[i].alumnos[j] / 10000);
            codAlumno = cursos[i].alumnos[j] % 10000;
            /* Búsqueda de la escala y porcentaje del alumno matriculado en el
             * arreglo de alumnos.
             */
            obtenerDatosAlumno(alumnos, semestreAlumno, codAlumno, escalaAlumno, 
                    porcentajePago);
            // Cálculo acumulativo del ingreso por alumno.
            cursos[i].ingresos += costosXEscala[escalaAlumno-1] *
                    cursos[i].creditos * porcentajePago / 100;
        }
    }
}

void procesarPagosEnAlumnos(struct StAlumno* alumnos, struct StCurso* cursos,
        double* costosXEscala){
    double creditaje;
    // Como no sabemos cuándo termina el arreglo, buscaremos su elemento "nulo"
    for(int i=0; alumnos[i].semestre != 0; i++){
        for(int j=0; j<alumnos[i].numeroDeCursos; j++){
            /* Búsqueda del creditaje del curso matriculado en el
             * arreglo de cursos.
             */
            creditaje = obtenerCreditosCurso(cursos, alumnos[i].cursos[j]);
            // Cálculo acumulativo del costo por curso.
            alumnos[i].costoTotal += costosXEscala[alumnos[i].escala-1] * 
                    creditaje * calcularPorcentaje(alumnos[i])/100;
        }
    }
}

void obtenerDatosAlumno(struct StAlumno* alumnos, int semestre, int codigo, 
        int& escala, int& porcentaje){
    for(int i=0; alumnos[i].semestre != 0; i++){
        // OJO: Búsqueda por semestre y código (no sólo por código)
        if(alumnos[i].semestre == semestre && alumnos[i].codigo == codigo){
            escala = alumnos[i].escala;
            porcentaje = calcularPorcentaje(alumnos[i]);
            break;
        }
    }
}

double obtenerCreditosCurso(struct StCurso* cursos, const char* codigo){
    for(int i=0; strcmp(cursos[i].codigoDelCurso, "XXXXXX") != 0; i++){
        if(strcmp(cursos[i].codigoDelCurso, codigo) == 0){
            return cursos[i].creditos;
        }
    }
}

int calcularPorcentaje(const struct StAlumno alumno){
    /* Uso del operador trinario para determinar el porcentaje del pago en base
     * a su modalidad. El porcentaje de virtualidad se extrajo del Laboratorio
     * 1.
     */
    return (strcmp(alumno.modalidad, "PRESENCIAL") ? 100 :
                (strcmp(alumno.modalidad, "VIRTUAL") ? 45 : alumno.porcentaje));
}