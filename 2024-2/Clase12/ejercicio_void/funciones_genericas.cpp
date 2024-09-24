/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funcines_genericas.hpp"

void incrementar_memoria(void **&alumnos, int &nd, int &cap) {
    void ** aux;
    cap += INCREMENTO;
    if (alumnos == nullptr) {
        alumnos = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = alumnos[i];
        delete alumnos;
        alumnos = aux;
    }
}

char *leer_cadena(ifstream &arch, char car) {
    char cadena[60], *cad;
    arch.getline(cadena, 60, car);
    cad = new char [strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
}

void* leer_registro(ifstream& input) {
    //20196975,Hijar Pairazaman Jenny Delicia
    void**reg;
    int *codigo, cod;
    char* nombre;
    input>>cod;
    if (input.eof())return nullptr;
    codigo = new int;
    *codigo = cod;
    input.get();
    nombre = leer_cadena(input);

    reg = new void*[4] {
    };
    reg[CODIGO] = codigo;
    reg[NOMBRE] = nombre;
    reg[CURSOS] = nullptr;
    reg[PROMEDIO] = nullptr;
    return reg;
}

void cargar_alumnos(void *&alumnos, const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    int cantidad = 0, capacidad = 0;
    void** alumnos_arr, *registro;
    alumnos_arr = nullptr;
    while (true) {
        registro = leer_registro(input);
        if (input.eof())break;
        if (cantidad == capacidad) incrementar_memoria(alumnos_arr, cantidad, capacidad);
        alumnos_arr[cantidad - 1] = registro;
        cantidad++;
    }
    alumnos = alumnos_arr;
}

void probar_carga(void *alumnos, const char* archivo_nombre) {
    ofstream output(archivo_nombre, ios::out);
    void **alumnos_recorrido = (void**) alumnos;
    for (int i = 0; alumnos_recorrido[i]; i++)
        imprimir_alumno(alumnos_recorrido[i], output);
}

void imprimir_alumno(void *alumno, ofstream& output) {
    void **registro = (void**) alumno;
    int*ptr_codigo;
    char*ptr_nombre;
    ptr_codigo = (int*) registro[CODIGO];
    ptr_nombre = (char*) registro[NOMBRE];

    output << left << setw(10) << *ptr_codigo;
    output << left << setw(50) << ptr_nombre << endl;
}

void ordenar(void* alumnos) {
    void **alumnos_recorrido = (void**) alumnos;
    int cantidad = 0;
    for (cantidad = 0; alumnos_recorrido[cantidad]; cantidad++);
    //cout<<cantidad<<endl;
    quick_sort(alumnos_recorrido, 0, cantidad - 1);
}

void cambiar(void*&alumno1, void*&alumno2) {
    void*aux;
    aux = alumno1;
    alumno1 = alumno2;
    alumno2 = aux;
}

void quick_sort(void**alumnos, int izq, int der) {
    int limite;
    int pivote = (izq + der) / 2;
    if (izq >= der)return; //Condicion de parada
    cambiar(alumnos[izq], alumnos[pivote]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (comparar_orden(alumnos[i], alumnos[izq]))
            cambiar(alumnos[++limite], alumnos[i]);
    cambiar(alumnos[izq], alumnos[limite]);
    quick_sort(alumnos, izq, limite - 1);
    quick_sort(alumnos, limite + 1, der);
}

bool comparar_orden(void*al1, void*al2) {
    void**registro1 = (void**) al1;
    void**registro2 = (void**) al2;
    char *nombre_al1, *nombre_al2;
    int *codigo_al1, *codigo_al2;
    nombre_al1 = (char*) registro1[NOMBRE];
    nombre_al2 = (char*) registro2[NOMBRE];
    //    
    //    codigo_al1 = (int*)registro1[CODIGO];
    //    codigo_al2 = (int*)registro2[CODIGO];
    //    
    //    bool resultado;
    //    if(strcmp(nombre_al1, nombre_al2)<0) or  
    //            strcmp(nombre_al1, nombre_al2 == 0 
    //            and *codigo_al1<*codigo_al1:
    //        resultado == true;
    return strcmp(nombre_al1, nombre_al2) < 0;
}

bool son_iguales(int codigo, void *alumnos) {
    void **registro = (void**) alumnos;
    int* codigo_ptr = (int*) registro[CODIGO];
    return codigo == *codigo_ptr;
}

int buscar_alumno(int codigo, void**alumnos) {
    for (int i = 0; alumnos[i]; i++)
        if (son_iguales(codigo, alumnos[i])) return i;
    return -1;
}

void* leer_curso(ifstream& input) {
    char* codigo;
    int* nota = new int;
    void**registro = new void*[2];
    codigo = leer_cadena(input, ',');
    input >> *nota;
    registro[CODIGOCURSO] = codigo;
    registro[NOTA] = nota;
    return registro;
}

void agregar_curso(void* curso, void *cursos, int nd) {
    void**arr_cursos = (void**) cursos;
    arr_cursos[nd] = curso;
}

void aumentar_memoria(void* &cursos, int &nd, int &cap) {
    void **aux, **cursos_arreglo = (void**) cursos;
    cap += INCREMENTO;
    if (cursos_arreglo == nullptr) {
        cursos_arreglo = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = cursos_arreglo[i];
        delete cursos_arreglo;
        cursos_arreglo = aux;
    }
    cursos = cursos_arreglo;
}

void colocar_curso(ifstream& input, void* alumno, int &nd, int &cap) {
    void **registro = (void**) alumno;
    void* curso;
    curso = leer_curso(input);
    if (nd == cap)
        aumentar_memoria(registro[CURSOS], nd, cap);
    agregar_curso(curso, registro[CURSOS], nd - 1);
    nd++;
}

void cargarNotas(void* alumnos, const char * nombre_archivo) {
    void**arr_alumnos = (void**) alumnos;
    int codigo, nd[50]{}, cap[50]{}, indice;
    ifstream input(nombre_archivo, ios::in);
    //20171444,MEC270,13
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.get();
        indice = buscar_alumno(codigo, arr_alumnos);
        if (indice != -1) {
            colocar_curso(input, arr_alumnos[indice], nd[indice], cap[indice]);
        } else
            while (input.get() != '\n');
    }
}

//void* promedio(void*cursos){
//    void**cursos_arreglo = (void**)cursos;
//    int suma = 0;
//    void**datos_cursos;
//    int*nota, i=0;
//    double *promedio = new double;
//    for(i=0; cursos_arreglo[i];i++){
//        datos_cursos = (void**)cursos_arreglo[i];
//        nota = (int*)datos_cursos[NOTA]; 
//        suma += *nota;
//    }
//    *promedio = (double)suma/i;
//    return promedio;
//}

int obtener_nota(void* curso) {
    void**registro = (void**) curso;
    int*nota = (int*) registro[NOTA];
    return *nota;
}

void* promedio(void*cursos) {
    void**cursos_arreglo = (void**) cursos;
    int suma = 0, cantidad_datos = 0;
    double *promedio = new double;
    for (int i = 0; cursos_arreglo[i]; i++) {
        suma += obtener_nota(cursos_arreglo[i]);
        cantidad_datos++;
    }
    *promedio = (double) suma / cantidad_datos;
    return promedio;
}

void obtener_promedio(void* alumno) {
    void**registro = (void**) alumno;
    registro[PROMEDIO] = promedio(registro[CURSOS]);
}

void calcular_promedios(void *alumnos) {
    void**arreglo_alumnos = (void**) alumnos;
    for (int i = 0; arreglo_alumnos[i]; i++)
        obtener_promedio(arreglo_alumnos[i]);
}

int obtener_cantidad(const void* alumnos) {
    void**arreglo = (void**) alumnos;
    int cantidad = 0;
    while (arreglo[cantidad])cantidad++;
    return cantidad;
}

int compara_cadenas(const void* al1, const void*al2) {
    //Primer Salto
    void**a1 = (void**) al1;
    void**a2 = (void**) al2;
    //Segundo Salto
    void**registro_a = (void**) a1[0];
    void**registro_b = (void**) a2[0];

    char *nombre_al1, *nombre_al2;
    nombre_al1 = (char*) registro_a[NOMBRE];
    nombre_al2 = (char*) registro_b[NOMBRE];
    //cout<<"xxx"<<endl;
    //cout<<nombre_al1<<"    -   "<<nombre_al2<<endl;

    return strcmp(nombre_al2, nombre_al1);
}

int comparar_orden_generico(const void*al1, const void*al2) {
    void**registro1 = (void**) al1;
    void**registro2 = (void**) al2;
    char *nombre_al1, *nombre_al2;
    int *codigo_al1, *codigo_al2;
    nombre_al1 = (char*) registro1[NOMBRE];
    nombre_al2 = (char*) registro2[NOMBRE];
    return strcmp(nombre_al1, nombre_al2);
}

void quick_sort_generico(void* alumnos, int izq, int der, int (*cmp)(const void*, const void*)) {
    void **arreglo = (void**) alumnos;
    int limite;
    int pivote = (izq + der) / 2;
    if (izq >= der)return; //Condicion de parada
    cambiar(arreglo[izq], arreglo[pivote]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (cmp(arreglo[i], arreglo[izq])<0)
            cambiar(arreglo[++limite], arreglo[i]);
    cambiar(arreglo[izq], arreglo[limite]);
    quick_sort_generico(arreglo, izq, limite - 1, cmp);
    quick_sort_generico(arreglo, limite + 1, der, cmp);
} 