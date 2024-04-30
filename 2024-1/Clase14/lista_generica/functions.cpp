/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.hpp"

void* leer_enteros(ifstream& input) {
    //Codigo 123456
    int codigo, *registro;
    input>>codigo;
    if (input.eof())return nullptr;
    registro = new int;
    *registro = codigo;
    return registro;
}

void* leer_registro(ifstream& input) {
    int *codigo, cod;
    char *nombre, buffer[60];
    double *sueldo;
    //Codigo 123456, nombre Erasmo Montoya, sueldo 2.5
    void**registro;
    input>>cod;
    if (input.eof())return nullptr;
    input.get();
    codigo = new int;
    *codigo = cod;
    input.getline(buffer, 60, ',');
    nombre = new char[strlen(buffer) + 1];
    strcpy(nombre, buffer);
    sueldo = new double;
    input>>*sueldo;

    registro = new void*[3];
    registro[COD] = codigo;
    registro[NOM] = nombre;
    registro[SUE] = sueldo;
    return registro;

}

int cmp_registro_str_qsort(const void*a, const void*b) {

}


int cmp_registro_str(const void*a, const void*b) {
    void **regI = (void**) a, **regK = (void**) b; //apuntamos al registro
    char*nombreI = (char*) regI[NOM];
    char*nombreK = (char*) regK[NOM];
    return strcmp(nombreI, nombreK);
}

int cmp_enteros(const void*, const void*) {

}

void insertar(void *dato, void*&lista, int(*cmp)(const void*, const void*)) {
    //Incializar
    void **rec = (void**) lista, **ant = nullptr;
    void **nuevo;
    nuevo = new void*[2]{};
    nuevo[DATO] = dato;
    //Insertar ordenado
    while (rec) {
        if (cmp(rec[DATO], dato) > 0)break;
        ant = rec;
        rec = (void**)(rec[SIG]);
    }
    //Hacer conexiones
    nuevo[SIG] = rec;
    if (ant == nullptr)
        lista = nuevo;
    else
        ant[SIG] = nuevo;
}

void crear_lista(const char* filename, void*&lista, void*(*lee)(ifstream&), int(*cmp)(const void*, const void*)) {
    ifstream input(filename,ios::in);    
    lista = nullptr;
    void* dato;
    while (true) {
        dato = lee(input);
        if (input.eof())break;
        insertar(dato, lista, cmp);//La funcion insertar construye el Nodo con el dato.
    }
}

void imprime_lista(const char *filename,void *lst, void (*imprime)(ofstream&, void*)) {
    ofstream output(filename, ios::out);
    void **rec = (void **) lst;
    while (rec) {
        imprime(output, rec[DATO]);
        rec = (void **) (rec[SIG]);
    }
    output << endl;
}

void imprime_registro(ofstream &output,void*a) {
    void **reg = (void**) a; //apuntamos al registro 
    int* codigo = (int*) reg[COD];
    char*nombre = (char*) reg[NOM];
    double*sueldo = (double*) reg[SUE];
    output.precision(2);
    output << fixed;
    output << setw(10) << *codigo << "  " << left << setw(50) << nombre 
            << right << setw(10) << *sueldo << endl;
}

void eliminar_lista(void*l, void(*elimina)(void*)){
    void ** rec = (void **)l, **nodo_sale;
    while(rec){
        nodo_sale = rec;
        elimina(rec[DATO]);
        rec = (void**)(rec[SIG]);
        delete nodo_sale;
    }
}

//void eliminar_lista_codigo(void*l, void(*elimina)(void*), int codigo_eliminar){
//    void ** rec = (void **)l, **nodo_sale = nullptr;
//    while(rec){
//        if(comparar_para_eliminar(rec[DATO], codigo_eliminar) break;
//        rec = (void**)(rec[SIG]);
//    }
//    nodo_sale = rec;
//    nodo_sale[SIG] = rec[SIG];
//    if(rec[DATO])
//        elimina(rec[DATO]);
//}

void elimina_registro(void*l){
    void **reg = (void**)l;
    int* codigo = (int*) reg[COD];
    char*nombre = (char*) reg[NOM];
    double*sueldo = (double*) reg[SUE];
    delete codigo;
    delete nombre;
    delete sueldo;
    delete reg;
}
