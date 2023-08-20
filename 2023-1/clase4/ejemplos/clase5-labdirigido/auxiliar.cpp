/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "auxiliar.hpp"

void imprimir_caracteres_archivo(char c, int n, ofstream & archivo_salida) {
    for (int i = 0; i < n; i++)
        archivo_salida << c;
}

void imprimir_linea_archivo(char c, int n, ofstream & archivo_salida) {
    for (int i = 0; i < n; i++)
        archivo_salida << c;
    archivo_salida << endl;
}

void imprimir_linea(char c, int n) {
    for (int i = 0; i < n; i++)
        cout << c;
    cout << endl;

}

void imprimir_encabezado_inicial(ofstream & archivo_salida) {
    archivo_salida << setw(ANCHO_REPORTE / 1.5) << "INFORMACION ACADEMICA DE LOS ESTUDIANTES" << endl;
    imprimir_linea_archivo('=', ANCHO_REPORTE, archivo_salida);
}

void imprimir_alumno(int codigo_alumno, int aaaa_ingreso, char* nombre_alumno, ofstream &archivo_salida){
    archivo_salida << setw(12) << "Alumno: " << nombre_alumno;
    archivo_salida << setw(17) << "Codigo: " << aaaa_ingreso << " - ";
    archivo_salida << setfill('0') << setw(6) << codigo_alumno << setfill(' ') << endl;
    imprimir_linea_archivo('-', ANCHO_REPORTE, archivo_salida);
    // Impresión de cabecera de cursos
    archivo_salida << setw(31)<<"CURSOS APROBADOS" << setw(41)<<"CURSOS DESAPROBADOS";
    archivo_salida << setw(23) << "OBSERVACION" << endl;
    archivo_salida <<"No." << setw(8) << "CODIGO" << setw(10) << "CREDITOS";
    archivo_salida << setw(7) << "NOTA" << setw(11) << "FECHA";
    archivo_salida << setw(12) << "CODIGO" << setw(10) << "CREDITOS";
    archivo_salida << setw(7) << "NOTA" << setw(11) << "FECHA" << endl;
    imprimir_linea_archivo('-',ANCHO_REPORTE, archivo_salida);
}

void imprimir_datos_cursos(int cantidad_curso, char* codigo_curso, double credito_curso,
        int nota_curso, int dd, int mm, int aaaa, int aaaa_ingreso, int aprobadoQ, int errorQ, 
        ofstream & archivo_salida){
    int error_espacios;
    
    archivo_salida<<setfill('0')<<setw(3)<<cantidad_curso;
    if(nota_curso < 11)
        imprimir_caracteres_archivo(' ', 40, archivo_salida);
    
    archivo_salida << setfill(' ') << setw(8) <<  codigo_curso;
    imprimir_caracteres_archivo(' ', 4, archivo_salida);
    archivo_salida.precision(2);
    archivo_salida << setw(4) << fixed << credito_curso;
    imprimir_caracteres_archivo(' ', 6, archivo_salida);
    archivo_salida << setfill('0') << setw(2) << nota_curso;
    imprimir_caracteres_archivo(' ', 5, archivo_salida);
    archivo_salida << setfill('0') << setw(2) << dd << "/";
    archivo_salida << setw(2) << mm << "/" << setw(4) << aaaa;
    if(nota_curso < 11)
        error_espacios = 13;
    else
        error_espacios = 53;
    if(aaaa_ingreso>aaaa){
        archivo_salida << setfill(' ') << setw(error_espacios) << "ERROR FECHA";
    }
    archivo_salida<<endl;
}


 void leer_curso(int aaaa_ingreso, int & cantidad_cursos, int &cantidad_cursos_matriculados, 
                       int &cantidad_cursos_aprobados, double &total_creditos, double &total_creditos_aprobados,
                       double &total_creditos_desaprobados, double &suma_notas, double &suma_notas_aprobadas,
                       int &cantidad_cursos_error, ifstream & archivo_entrada, ofstream &archivo_salida){
     char codigo_curso[8];
     double creditos_curso, nota_curso;
     char slash;
     int aaaa, mm, dd, errorQ, aprobadoQ;
     
    archivo_entrada>>codigo_curso;
    archivo_entrada>>creditos_curso;
    archivo_entrada>>nota_curso;
    archivo_entrada>>dd>>slash>>mm>>slash>>aaaa;
    
    errorQ = (aaaa_ingreso>aaaa);
    aprobadoQ = (nota_curso > 10);
    
    // TODO trabajar con los acumuladores
    cantidad_cursos++;
    if(!errorQ){
        cantidad_cursos_matriculados++;
        total_creditos += creditos_curso;
        suma_notas += nota_curso;
        if(aprobadoQ){
            cantidad_cursos_aprobados++;
            total_creditos_aprobados += creditos_curso;
            suma_notas_aprobadas += nota_curso;
        }else
            total_creditos_desaprobados += creditos_curso;
    }else
        cantidad_cursos_error++;
    // TODO imprimir el detalle curso
    
    imprimir_datos_cursos(cantidad_cursos, codigo_curso, creditos_curso, 
                            nota_curso, dd, mm, aaaa, aaaa_ingreso, aprobadoQ,
                            errorQ, archivo_salida);
    
    
}

void leer_alumno(int codigo_alumno, int& aaaa_ingreso, ifstream &archivo_entrada, ofstream &archivo_salida) {
    char char_aux, nombre_alumno[50];
    archivo_entrada >> char_aux >> aaaa_ingreso>>nombre_alumno;
    imprimir_alumno(codigo_alumno, aaaa_ingreso, nombre_alumno, archivo_salida);

}

void imprimir_estadisticas_alumno(int cantidad_cursos_matriculados,
                                         int cantidad_cursos_aprobados,
                                         double total_creditos,
                                         double total_creditos_aprobados,
                                         double total_creditos_desaprobados,
                                         double suma_notas, 
                                         double suma_notas_aprobadas, 
                                         int cantidad_cursos_error,
                                         ofstream &archivo_salida){
    //Declarar variables auxiliares
    double porcentaje_creditos_aprobados = total_creditos_aprobados/total_creditos*100;
    double promedio_general = suma_notas/(double)cantidad_cursos_matriculados;
    double promedio_aprobados = suma_notas_aprobadas/(double)cantidad_cursos_aprobados;
    
    imprimir_linea_archivo('=',ANCHO_REPORTE, archivo_salida);
    archivo_salida.fill(' ');
    
    archivo_salida<<setw(12) << "RESUMEN:" << endl;
    //Imprimir cursos matriculados
    archivo_salida<<setw(26)<< "Cursos Matriculados: ";
    archivo_salida<<setfill('0')<<setw(2)<<cantidad_cursos_matriculados;
    archivo_salida.precision(2);
    //Impresion de total de creiditos
    archivo_salida<<setfill(' ')<<setw(43)<<"Total de creditos: ";
    archivo_salida<<setw(5)<<setfill('0')<<fixed<<total_creditos<<endl;
    archivo_salida << setfill(' ') << setw(26) << "Creditos aprobados:   ";
    archivo_salida << setw(5) << setfill('0') << fixed << total_creditos_aprobados;
    archivo_salida << setfill(' ') << setw(40) << "Creditos desaprobados:  ";
    archivo_salida << setw(5) << setfill('0') << fixed << total_creditos_desaprobados << endl;
    archivo_salida << setfill(' ') << setw(38) << "Creditos aprobados/matriculados:  ";
    archivo_salida << setw(5) << setfill('0') << fixed << porcentaje_creditos_aprobados << "%" <<endl;
    imprimir_linea_archivo('-', ANCHO_REPORTE,archivo_salida);
    archivo_salida << setw(21) << setfill(' ') <<"Promedio General:";
    imprimir_caracteres_archivo(' ', 17,archivo_salida);
    archivo_salida << setw(5) << setfill('0') << fixed << promedio_general << endl;
    archivo_salida << setw(38) << setfill(' ') << "Promedio General de aprobados:    ";
    archivo_salida << setw(5) << setfill('0') << fixed << promedio_aprobados << endl;
    imprimir_linea_archivo('-', ANCHO_REPORTE,archivo_salida);
    archivo_salida << setw(38) << setfill(' ') <<"Curso con error no considerados:  ";
    archivo_salida << setfill('0') << setw(2) << cantidad_cursos_error << setfill(' ') << endl;
    imprimir_linea_archivo('=', ANCHO_REPORTE, archivo_salida);
    imprimir_linea_archivo('=', ANCHO_REPORTE, archivo_salida);
    
    
}

void imprimir_resumen_final(int cantidad_alumnos, ofstream &archivo_salida){
    imprimir_linea_archivo('-', ANCHO_REPORTE, archivo_salida);
    archivo_salida << "TOTAL DE ALUMNOS REGISTRADOS: " << cantidad_alumnos<<endl;
}

void imprimir_datos_alumnos(ifstream &archivo_entrada, ofstream &archivo_salida) {
    //TODO imprimir encabezado con datos
    //TODO leer e imprimir datos de alumnos
    //TODO imprimir resumen parcial
    int cantidad_cursos = 0;
    int cantidad_cursos_matriculados = 0;
    int cantidad_cursos_aprobados = 0;
    double total_creditos = 0;
    double total_creditos_aprobados = 0;
    double total_creditos_desaprobados = 0;
    double suma_notas = 0;
    double suma_notas_aprobadas = 0;
    int cantidad_cursos_error = 0;
    int codigo_alumno;
    int cantidad_alumnos = 0;
    int aaaa_ingreso = 0;
    
    archivo_entrada >> codigo_alumno;
    leer_alumno(codigo_alumno, aaaa_ingreso, archivo_entrada, archivo_salida);
    while (1) {
        archivo_entrada>>codigo_alumno;
        // Cuando se detecta fin de linea, queda pendiente procesar el ultimo estudiante
        if (archivo_entrada.eof()) {
            imprimir_estadisticas_alumno(cantidad_cursos_matriculados,
                                         cantidad_cursos_aprobados,
                                         total_creditos,
                                         total_creditos_aprobados,
                                         total_creditos_desaprobados,
                                         suma_notas, 
                                         suma_notas_aprobadas, 
                                         cantidad_cursos_error,
                                         archivo_salida);
            cantidad_alumnos++;
            imprimir_resumen_final(cantidad_alumnos, archivo_salida);
            break;
        }
        // Cuando se activa la bandera fail, se ha intentado leer una cadena 
        // (codigo del curso) en lugar de un entero para codigo_alumno
        if (archivo_entrada.fail()) {
            archivo_entrada.clear();
            leer_curso(aaaa_ingreso, cantidad_cursos, cantidad_cursos_matriculados, 
                       cantidad_cursos_aprobados, total_creditos, total_creditos_aprobados,
                       total_creditos_desaprobados, suma_notas, suma_notas_aprobadas,
                       cantidad_cursos_error, archivo_entrada, archivo_salida);
        } else {
            // Cuando estamos leyendo los datos del curso normalmente
            imprimir_estadisticas_alumno(cantidad_cursos_matriculados, 
                                          cantidad_cursos_aprobados,
                                          total_creditos, 
                                          total_creditos_aprobados, 
                                          total_creditos_desaprobados,
                                          suma_notas, 
                                          suma_notas_aprobadas, 
                                          cantidad_cursos_error,
                                          archivo_salida);
            cantidad_cursos = 0;
            cantidad_cursos_matriculados = 0;
            cantidad_cursos_aprobados = 0;
            total_creditos = 0;
            total_creditos_aprobados = 0;
            total_creditos_desaprobados = 0;
            suma_notas = 0;
            suma_notas_aprobadas = 0;
            cantidad_cursos_error = 0;
            cantidad_alumnos++;
            leer_alumno(codigo_alumno, aaaa_ingreso, archivo_entrada, archivo_salida);
        }
    }
}