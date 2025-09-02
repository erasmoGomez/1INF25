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
    int capacidad = 0;
    int codigo;
    codigos = nullptr;
    ifstream input;
    apertura_archivo_lectura(input, "Data/codigos.txt");
    while(true){
        codigo = leer_entero(input);
        //2 validaciones
        if(input.eof())break;
        if(n_datos == capacidad) incrementar_espacios(codigos, n_datos, capacidad);
        //A partir de aqui, codigos tienes memoria suficiente para recibien un nuevo codigo
        codigos[n_datos] = codigo;
        n_datos++;
        //En este punto hay 2 opciones
        //1era: Asumir q van a quedar espacios sobrantes.
        //2da : Realizar un proceso de RECORTE
    }
}

CHAR -> CARACTER E R A S M O
CHAR* -> CADENA O ARREGLO DE CARACTERES ERASMO\0
CHAR** -> ARREGLO DE CADENAS
            ERASMO\0
            BINNY\0
            PIERO\0
CHAR*** -> ARREGLO DE ARREGLOS DE CADENAS
            [0] //0581
                JUAN\0
                ANA\0
                LUCAS\0
            [1] //0582
                MAX\0
                JULIO\0
                PIERO2\0
            [0] //0583
                ERASMO\0
                BINNY\0
                PIERO\0
CHAR*** NOMBRES_PROGRA2_HORARIO

INT CODIGO 20082060
INT* ARREGLO CODIGOS
            20082060
            20082062
            20082131
INT** ARREGLO DE ARREGLO DE CODIGOS
            [0] //0581
            20082160
            20082031
            20082162
            [2] //0583
            20082060
            20082131
            20082062

VOID APUNTAR A CUALQUIER TIPO DE DATO