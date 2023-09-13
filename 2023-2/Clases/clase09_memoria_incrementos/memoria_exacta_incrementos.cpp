/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"

char * leer_cadena(ifstream &input) {
    char buffer[100], *cadena;
    input.getline(buffer, 100, ',');
    cadena = new char[strlen(buffer) + 1]; //El espacio para el \0
    strcpy(cadena, buffer);
    return cadena;
}

void incrementar_memoria(int *&codigos, char **&nombres, char *&modalidades,
        int *&porcentajes, int *&escalas,
        int &n_datos, int &capacidad) {
    int *auxC, *auxP, *auxE;
    char **auxN, *auxM;
    capacidad += INCREMENTO;
    if (codigos == nullptr) {
        codigos = new int[capacidad]{};
        nombres = new char*[capacidad]{};
        modalidades = new char[capacidad]{};
        porcentajes = new int[capacidad]{};
        escalas = new int[capacidad]{};
//        codigos[0] = 0;
//        nombres[0] = nullptr;
//        modalidades[0] = '\0';
//        porcentajes[0] = 0;
//        escalas[0] = 0;
        n_datos = 1;
    } else {
        auxC = new int[capacidad]{};
        auxN = new char*[capacidad]{};
        auxM = new char[capacidad]{};
        auxP = new int[capacidad]{};
        auxE = new int[capacidad]{};
        for (int i = 0; i < n_datos; i++) {
            auxC[i] = codigos[i];
            auxN[i] = nombres[i];
            auxM[i] = modalidades[i];
            auxP[i] = porcentajes[i];
            auxE[i] = escalas[i];
        }
        delete codigos;
        delete nombres;
        delete modalidades;
        delete porcentajes;
        delete escalas;

        codigos = auxC;
        nombres = auxN;
        modalidades = auxM;
        porcentajes = auxP;
        escalas = auxE;
    }
}

void incrementar_memoria_cursos(char **&nombres_cursos, double *&creditos_cursos, int **&alumnos_cursos,
        int &n_datos, int &capacidad) {
    int **auxA;
    char **auxN;
    double *auxC;
    capacidad += INCREMENTO;
    if (nombres_cursos == nullptr) {
        nombres_cursos = new char*[capacidad]{};
        creditos_cursos = new double[capacidad]{};
        alumnos_cursos = new int*[capacidad]{};
        nombres_cursos[0] = nullptr;
        creditos_cursos[0] = 0;
        alumnos_cursos[0] = nullptr;
        n_datos = 1;
    } else {
        auxN = new char*[capacidad]{};
        auxC = new double[capacidad]{};
        auxA = new int*[capacidad]{};
        for (int i = 0; i < n_datos; i++) {
            auxN[i] = nombres_cursos[i];
            auxC[i] = creditos_cursos[i];
            auxA[i] = alumnos_cursos[i];// Adicional pueden pasar por niveles la data.
        }
        delete nombres_cursos;
        delete creditos_cursos;
        // Si es arreglo, se debe deletear desde dentro hacia afuera
        for (int i = 0; alumnos_cursos[i]; i++)
            delete alumnos_cursos[i];
        delete alumnos_cursos;

        nombres_cursos = auxN;
        creditos_cursos = auxC;
        alumnos_cursos = auxA;
    }
}

void lectura_alumnos(const char* nombre_archivo,
        int *& codigos, char **& nombres,
        char *& modalidades, int *& porcentajes,
        int *& escalas) {
    int codigo, n_datos = 0, capacidad = 0, porcentaje, escala;
    char *nombre, modalidad;
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR, no se pudo abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
    codigos = nullptr;
    nombres = nullptr;
    modalidades = nullptr;
    porcentajes = nullptr;
    escalas = nullptr;
    while (true) {
        input>>codigo;
        if (input.eof()) break;
        input.get();

        nombre = leer_cadena(input);
        input>>modalidad;
        input.get();

        input>>porcentaje;
        input.get();

        input>>escala;
        input.get();

        if (n_datos == capacidad)
            incrementar_memoria(codigos, nombres, modalidades, porcentajes,
                escalas, n_datos, capacidad);
        //Almacenamos los datos en las variables en punteros
        //codigos[n_datos] = 0;
        codigos[n_datos - 1] = codigo;
        //nombres[n_datos] = nullptr;
        nombres[n_datos - 1] = nombre;
        //modalidades[n_datos] = '\0';
        modalidades[n_datos - 1] = modalidad;
        //porcentajes[n_datos] = 0;
        porcentajes[n_datos - 1] = porcentaje;
        //escalas[n_datos] = 0;
        escalas[n_datos - 1] = escala;

        n_datos++;
    }

}

void prueba_lectura_alumnos(const char* nombre_archivo,
        int *codigos, char **nombres,
        char *modalidades, int *porcentajes,
        int *escalas) {
    ofstream output(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: No se pudo abrir :(";
        exit(1);
    }

    output.precision(2);
    output << fixed;

    for (int i = 0; codigos[i]; i++) {
        output << left << setw(10) << codigos[i] << setw(60) << nombres[i];
        output << setw(5) << modalidades[i];
        output << setw(10) << porcentajes[i];
        output << setw(10) << escalas[i] << endl;
    }

}

int obtener_pos(char *nombre_curso, char** nombres_cursos, int n_datos) {
    for (int i = 0; i < n_datos; i++)
        if (!strcmp(nombres_cursos[i], nombre_curso)) {
            return i;
        }
    return -1;
}

int encontrar_indice_alumno(int codigo_alumno, int *codigos){
    int i=0;
    while(true){
        if(codigos[i] == codigo_alumno)
            return i;
        i++;
    }
    return -1;
}

void agregar_alumnos(int *codigos, int *escalas, int **&alumnos_cursos, 
                     int indice_cursos, int codigo_alumno) {
    int *cada_alumno, pos_alumno;
    int n_datos_alumnos = 0;
    int *auxA;
    cada_alumno = alumnos_cursos[indice_cursos];
    pos_alumno = encontrar_indice_alumno(codigo_alumno, codigos);
    
    if (cada_alumno == nullptr) {
        cada_alumno = new int[3]{};
        cada_alumno[0] = codigos[pos_alumno];
        cada_alumno[1] = escalas[pos_alumno];
        cada_alumno[2] = -1;
        
    } else {
        for(n_datos_alumnos = 0; cada_alumno[n_datos_alumnos]!=-1;n_datos_alumnos++);
        auxA = new int[n_datos_alumnos+++1]{};
            
        for (int i = 0; i < n_datos_alumnos; i++) {
            auxA[i] = cada_alumno[i];
        }
        auxA[n_datos_alumnos] = codigos[pos_alumno];
        auxA[n_datos_alumnos+1] = escalas[pos_alumno];
        auxA[n_datos_alumnos+2] = -1;
        delete alumnos_cursos[indice_cursos];
        cada_alumno = auxA;
    }
    alumnos_cursos[indice_cursos] = cada_alumno;
}

void lectura_cursos(const char* nombre_archivo, int* codigos, int* escalas,
        char**& nombres_cursos, double *& creditos_cursos,
        int **& alumnos_cursos) {
    int codigo_alumno, n_datos = 0, capacidad = 0, *alumno, pos_alumno, indice_curso;
    double credito_curso;
    char *nombre_curso;
    int n_datos_alumnos = 0;
    int capacidad_alumnos = 0;
    int pos;
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR, no se pudo abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
    nombres_cursos = nullptr;
    alumnos_cursos = nullptr;
    while (true) {
        input>>codigo_alumno;
        if (input.eof())break;
        input.get();
        nombre_curso = leer_cadena(input);
        input>>credito_curso;
        input.get();

        indice_curso = obtener_pos(nombre_curso, nombres_cursos, n_datos-1); //Sin repeticion
//        cout<<pos<<endl;
        if (indice_curso == -1) {
            if (n_datos == capacidad)
                incrementar_memoria_cursos(nombres_cursos, creditos_cursos,
                                           alumnos_cursos, n_datos, capacidad);
            //Insertarlo
            indice_curso = n_datos-1;
            //nombres_cursos[n_datos] = nullptr;
            nombres_cursos[indice_curso] = nombre_curso;
            //creditos_cursos[n_datos] = 0;
            creditos_cursos[indice_curso] = credito_curso;
            //alumnos_cursos[n_datos] = nullptr;
            
            n_datos++;
        }
        agregar_alumnos(codigos, escalas, alumnos_cursos, indice_curso, codigo_alumno);
    }
}

void prueba_lectura_cursos(const char* nombre_archivo, char ** nombres_cursos,
                           double *creditos_cursos, int**alumnos_cursos){
    ofstream output(nombre_archivo, ios::out);
    int *cada_curso;
    for (int i = 0; nombres_cursos[i]; i++) {
        output<<left<<setw(75)<<nombres_cursos[i]<<right<<setw(15);
        output<<fixed<<setprecision(2)<<creditos_cursos[i]<<endl;
        cada_curso = alumnos_cursos[i];
        
        for(int j =0; cada_curso[j]!=-1; j+=2){
            output<<left<<setw(15)<<cada_curso[j]<<setw(15)<<cada_curso[j+1]<<endl;
        }
    }

}