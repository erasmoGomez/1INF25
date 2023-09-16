/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"
#define INCREMENTO 5
enum Registro {CODIGO, NOMBRE, NOTA, PROMEDIO};
enum RegistroCurso {CODIGOCURSO, NOTACURSO};

char * leer_cadena(ifstream &input, char delimitador){
    char buffer[100], *cadena;
    input.getline(buffer, 100, delimitador);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void *leer_registro(ifstream &input){
    void **registro;
    int *codigo, cod;
    char *nombre;
    input>>cod;
    if(input.eof()) return nullptr;
    input.get();
    nombre = leer_cadena(input);
    codigo = new int;
    *codigo = cod;
    
    //Asignacion al registro
    registro = new void*[4];
    registro[CODIGO] = codigo;
    registro[NOMBRE] = nombre;
    registro[NOTA] = nullptr;
    registro[PROMEDIO] = nullptr;
    return registro;
}

void incrementar_memoria(void **&alumnos, int &n_datos, int &capacidad){
    void **aux;
    capacidad += INCREMENTO;
    if(alumnos == nullptr){
        alumnos = new void*[capacidad]{};
        n_datos = 1;
    }
    else{
        aux = new void*[capacidad]{};
        for(int i= 0; i<n_datos; i++)
            aux[i] = alumnos[i];
        delete alumnos;
        alumnos = aux;
    }
}

void cargar_alumnos(void*& alumnos){
    void *registro, **todos_alumnos;
    int n_datos = 0, capacidad = 0;
    ifstream input("Alumnos.csv");
    alumnos = nullptr;
    while(true){
        registro = leer_registro(input);
        if(input.eof()) break;
        // Consultar si hay o no memoria suficiente en mi arreglo todos_alumnos
        if(n_datos == capacidad) incrementar_memoria(todos_alumnos, n_datos, capacidad);
        todos_alumnos[n_datos-1] = registro;
        n_datos++;
    }
    alumnos = todos_alumnos;
}

void mostrar_alumno(void *alumno){
    void **registro_alumno = (void**)alumno;
    int*codigo;
    char * nombre;
    codigo = (int*)registro_alumno[CODIGO];
    nombre = (char*)registro_alumno[NOMBRE];
    cout<<right<<setw(10)<<*codigo<<" - "<<left<<nombre<<endl;
}

void probar_alumnos(void*alumnos){
    void **todos_alumnos = (void**)alumnos;
    for(int i=0; todos_alumnos[i];i++)
        mostrar_alumno(todos_alumnos[i]);
}

bool son_iguales(int codigo_buscar, void*alumno){
    void **registro = (void**)alumno;
    int *codigo_alumno = (int*)registro[CODIGO];
    return codigo_buscar == *codigo_alumno;
    
}

int buscar_alumno(int codigo,void **todos_alumnos){
    for(int i=0;todos_alumnos[i];i++)
        if(son_iguales(codigo, todos_alumnos[i]))return i;
    return -1;
}

void *leer_curso(ifstream &input){
    char *codigo_curso;
    int *nota = new int;
    void **registro = new void*[2];
    codigo_curso = leer_cadena(input, ',');
    input>>*nota;
    registro[CODIGOCURSO] = codigo_curso;
    registro[NOTACURSO] = nota;
    return registro;
}

void incrementar_espacios(void *&alumnos,int &n_datos, int& capacidad){
    void **aux;
    void **alumnos_cursos = (void**)alumnos;
    capacidad +=INCREMENTO;
    if(alumnos_cursos == nullptr){
        alumnos_cursos = new void*[capacidad]{};
        n_datos = 1;
    }
    else{
        aux = new void*[capacidad]{};
        for(int i=0; i<n_datos;i++)
            aux[i] = alumnos_cursos[i];
        delete alumnos_cursos;
        alumnos_cursos = aux;
    }
    alumnos = alumnos_cursos;
}

void agregar_curso(void *curso, void *&alumno_nota, int n_datos){
    void **alumno = (void**)alumno_nota;
    alumno[n_datos-1] = curso;
}

void colocar_curso(ifstream &input, void *&alumno, int &n_datos, int &capacidad){
    void **registro = (void**)alumno;
    void *curso;
    curso = leer_curso(input);

    if(n_datos == capacidad) incrementar_espacios(registro[NOTA],n_datos,capacidad);
    agregar_curso(curso, registro[NOTA],n_datos);
    n_datos++;
    
}

void cargar_notas(void *&alumnos){
    int codigo, pos = 0;
    void **todos_alumnos;
    todos_alumnos = (void**)alumnos;
    ifstream input("CursosNotas.csv");
    int n_datos[50]{}, capacidad[50]{};
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input.get();
        pos = buscar_alumno(codigo,todos_alumnos);
        if(pos!=-1){
            colocar_curso(input, todos_alumnos[pos],n_datos[pos], capacidad[pos]);
        }
        else
            while(input.get()!='\n');  
    }
}
