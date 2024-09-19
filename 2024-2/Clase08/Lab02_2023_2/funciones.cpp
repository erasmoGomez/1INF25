/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

char* leer_cadena(ifstream &input, int n, char delimitador) {
    char* cadena, buffer[n];
    input.getline(buffer, n, delimitador);
    //if(input.eof()) return nullptr;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void lectura_productos(char***& productos, int*& stocks, double*& precios,
        const char*nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    char** buffer_productos[200]{}, coma;
    int buffer_stocks[200]{}, cantidad = 0;
    double buffer_precios[200]{};
    //QHC-492,Terma Solucion,1907.23,17
    while (true) {
        buffer_productos[cantidad] = lee_productos(input);
        if (input.eof()) break;
        input >> buffer_precios[cantidad] >> coma >> buffer_stocks[cantidad];
        input.get();
        cantidad++;
    }
    actualizar_productos(productos, stocks, precios, buffer_productos,
            buffer_stocks, buffer_precios, cantidad);
}

void actualizar_productos(char***&productos, int*& stocks, double*&precios,
        char*** buffer_productos, int* buffer_stocks, double* buffer_precios,
        int cantidad) {
    productos = new char**[cantidad + 1] {
    };
    stocks = new int[cantidad];
    precios = new double[cantidad];
    for (int i = 0; i < cantidad; i++) {
        productos[i] = buffer_productos[i];
        stocks[i] = buffer_stocks[i];
        precios[i] = buffer_precios[i];
    }
}

char** lee_productos(ifstream &input) {
    char**codigo_nombre;
    codigo_nombre = new char*[2];
    codigo_nombre[0] = leer_cadena(input, 8, ',');
    codigo_nombre[1] = leer_cadena(input, 200, ',');
    return codigo_nombre;
}

void prueba_lectura_productos(char*** productos, int* stock,
        double* precios, const char*nombre_archivo) {
    char **aux_productos;
    ofstream output(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error no se abrio el" << nombre_archivo << endl;
        exit(1);
    }
    //Agregar headers
    for (int i = 0; productos[i]; i++) {
        aux_productos = productos[i]; // Aterrizaje        
        output << setw(10) << aux_productos[0]; //Codigo
        output << setw(60) << aux_productos[1]; //Descripcion
        output << setw(10) << precios[i]; //Precio
        output << setw(10) << stock[i] << endl; //Stock
    }
}

int buscar_fecha(int *buffer_fechas, int fecha, int cantidad_pedidos) {
    for (int i = 0; i < cantidad_pedidos; i++)
        if (buffer_fechas[i] == fecha) return i;
    return -1;
}

void lectura_pedidos(int *&fechas, char***&codigos_pedidos,
        int***&dni_cantidad_pedidos, const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    //JXD-139,50375303,6,24/08/2023
    int buffer_fechas[600], **buffer_dni_cantidad_pedidos[600];
    char **buffer_codigos_pedidos[600];
    int dia, mes, anio, dni, cantidad, fecha, indice;
    char *codigo, c;
    int cantidad_fechas = 0, cantidad_pedidos[600];
    while (true) {
        codigo = leer_cadena(input, 8, ',');
        if (input.eof())break;
        input >> dni >> c >> cantidad >> c >> dia >> c >> mes >> c>>anio;
        input.get();
        fecha = anio * 10000 + mes * 100 + dia;
        indice = buscar_fecha(buffer_fechas, fecha, cantidad_fechas);
        if (indice == -1) agregar_fecha(buffer_fechas, buffer_codigos_pedidos,
                buffer_dni_cantidad_pedidos, cantidad_pedidos,
                fecha, indice, cantidad_fechas); //La fecha es nueva
        agregar_pedido_fecha(buffer_dni_cantidad_pedidos[indice],
                buffer_codigos_pedidos[indice], cantidad_pedidos[indice],
                dni, cantidad, codigo); //Cuando ya se encuentra la fecha
    }
    recorte_pedidos(fechas, codigos_pedidos, dni_cantidad_pedidos,
            buffer_fechas, buffer_codigos_pedidos, buffer_dni_cantidad_pedidos,
            cantidad_pedidos, cantidad_fechas);
}

void agregar_fecha(int *buffer_fechas, char ***buffer_codigos_pedidos,
        int ***buffer_dni_cantidad_pedidos, int *cantidad_pedidos,
        int fecha, int &indice, int &cantidad_fechas) {
    buffer_fechas[cantidad_fechas] = fecha; //Buffer a primer nivel
    buffer_codigos_pedidos[cantidad_fechas] = new char*[200]{}; // Buffer a segundo nivel
    buffer_dni_cantidad_pedidos[cantidad_fechas] = new int*[200]{}; // Buffer a segundo nivel
    cantidad_pedidos[cantidad_fechas] = 0;
    indice = cantidad_fechas;
    cantidad_fechas++;
}

void agregar_pedido_fecha(int **buffer_dni_cantidad_pedidos,
        char**buffer_codigos_pedidos, int &cantidad_pedidos,
        int dni, int cantidad, char*codigo) {
    int *aux_dni_cantidad_pedidos;
    buffer_dni_cantidad_pedidos[cantidad_pedidos] = new int[2];
    aux_dni_cantidad_pedidos = buffer_dni_cantidad_pedidos[cantidad_pedidos];
    //    buffer_dni_cantidad_pedidos[cantidad_pedidos][0] = dni; ESTO NO SE PUEDE HACER
    //    buffer_dni_cantidad_pedidos[cantidad_pedidos][1] = cantidad; GRAVE ERROR DE CONCEPTO
    aux_dni_cantidad_pedidos[0] = dni;
    aux_dni_cantidad_pedidos[1] = cantidad;
    buffer_codigos_pedidos[cantidad_pedidos] = codigo;
    cantidad_pedidos++;
}

void recorte_pedidos(int*&fechas, char***&codigos_pedidos, int ***&dni_cantidad_pedidos,
        int *buffer_fechas, char ***buffer_codigos_pedidos,
        int ***buffer_dni_cantidad_pedidos,
        int *cantidad_pedidos, int cantidad_fechas) {
    //Reserva de memoria a primer nivel
    fechas = new int[cantidad_fechas + 1] {};
    codigos_pedidos = new char**[cantidad_fechas] {};
    dni_cantidad_pedidos = new int **[cantidad_fechas] {};
    for (int i = 0; i < cantidad_fechas; i++) {
        fechas[i] = buffer_fechas[i];
        codigos_pedidos[i] = buffer_codigos_pedidos[i];
        dni_cantidad_pedidos[i] = buffer_dni_cantidad_pedidos[i];
        //Proceso a segundo nivel
        agregar_pedidos_dni_codigo(codigos_pedidos[i], dni_cantidad_pedidos[i],
                buffer_codigos_pedidos[i], buffer_dni_cantidad_pedidos[i],
                cantidad_pedidos[i]);
    }
}

void agregar_pedidos_dni_codigo(char **codigos_pedidos, int **dni_cantidad_pedidos,
        char **buffer_codigos_pedidos, int**buffer_dni_cantidad_pedidos,
        int cantidad_pedidos) {
    for (int i = 0; i < cantidad_pedidos; i++) {
        codigos_pedidos[i] = buffer_codigos_pedidos[i];
        dni_cantidad_pedidos[i] = buffer_dni_cantidad_pedidos[i];
    }
    //Aqui podrian deletear el arreglo estatico pero a segundo nivel
}

void prueba_lectura_pedidos(int *fechas, char ***codigos_pedidos, 
                            int ***dni_cantidad_pedidos, const char* nombre_archivo){
    char **aux_codigos;
    int **aux_dnis, *aux_dnis_cantidades;
    ofstream output(nombre_archivo, ios::out);
    for(int i=0; fechas[i];i++){
        output<<setw(10)<<fechas[i]<<endl;
        aux_codigos = codigos_pedidos[i];//Aterrizaje
        aux_dnis = dni_cantidad_pedidos[i]; //Aterrizaje
        for(int j=0;aux_codigos[j];j++){
            aux_dnis_cantidades = aux_dnis[j];
            output<<setw(10)<<aux_codigos[j];
            output<<setw(10)<<aux_dnis_cantidades[0];
            output<<setw(10)<<aux_dnis_cantidades[1]<<endl;
        }
        output<<endl;
    }
}