//
// Created by Erasmo on 29/08/25.
//

#include "MemoriaIncrementos.hpp"
void apertura_archivo_lectura(ifstream& input, const char* nombre_archivo){
    input.open(nombre_archivo, ios::in);
    if(!input.is_open()){
        cout<<"El archivo no se pudo abrir: "<<nombre_archivo<<endl;
        exit(1);
    }
}

int leer_entero(ifstream& input){
    int entero;
    input>>entero;
    return entero;
}

void incrementar_espacios(int *&codigos, int &n_datos, int &capacidad){
    int *aux;
    capacidad += INCREMENTO;

    if(codigos == nullptr)
        codigos = new int[capacidad]{}; //Importante {}
    else {
        //codigos: llega con 10 espacios
        //Aprovechamos de una reserva dinamica AUXILIAR
        aux = new int[capacidad]{};
        //aux: se reservan 15 espacios
        for(int i = 0; i<n_datos; i++)
            aux[i] = codigos[i];
        //aux: tiene los primeros 10 valores actualizados desde codigos;
        //En este punto tenemos 2 arreglos dinamicos
        //Codigos vs aux: codigos deberia escapar de la funcion
        delete codigos; //Cortar la conexion inicial
        //Inicializacion estatica de punteros
        codigos = aux;
        //delete aux; //Grave error de concepto
    }
}

void leer_datos(int* &codigos, int &n_datos){
    int codigo = 0;
    int buffer_enteros[10];
    codigos = nullptr; // Inicializar
    ifstream input;
    apertura_archivo_lectura(input, "Data/codigos.txt");
    while(true){
        codigo = leer_entero(input);
        if(input.eof())break;
        buffer_enteros[n_datos] = codigo;
        n_datos++;
    }
    codigos = new int[n_datos];
    for(int i = 0; i<n_datos; i++) {
        codigos[i] = buffer_enteros[i];
    }
}