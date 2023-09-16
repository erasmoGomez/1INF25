#include "AsignacionDinamicaMemoriaPorIncrementos.h"

void lecturaDeProductos (const char* nombArchLectura, char***& productos,
        int*& stock, double*& precios){
    char codigo[50], descripcion[200], aux;
    int nEjemplares, nProductos = 0, capacidad = 0;
    double precio;
    ifstream archLectura(nombArchLectura, ios::in);
    if(not archLectura.is_open()){
        cout << "No se pudo abrir archivo de productos" << endl;
        exit(1);
    }
    productos = nullptr;
    stock = nullptr;
    precios = nullptr;
    while(true){
        archLectura.getline(codigo, 50, ',');
        if(archLectura.eof())
            break;
        archLectura.getline(descripcion, 200, ',');
        archLectura >> precio >> aux >> nEjemplares;
        archLectura.get(); // '\n'
        if(nProductos == capacidad)
            incrementarMemoriaProductos(productos, stock, precios, nProductos, capacidad);
        insertarEnMemoriaProductos(productos, stock, precios, codigo, descripcion, nEjemplares, precio, nProductos);
        nProductos++;
    }
}

void pruebaDeLecturaDeProductos (const char* nombArchReporte, char *** productos,
        int* stock, double *precios){
    ofstream archReporte(nombArchReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "No se pudo abrir archivo de productos" << endl;
        exit(1);
    }
    archReporte << "REPORTE DE PRODUCTOS" << endl << endl;
    archReporte << left << setw(11) << "CÓDIGO" << setw(70) << "DESCRIPCIÓN" << right << setw(9) << "STOCK" << setw(15) << "PRECIO" << endl;
    imprimirLinea(archReporte, '-', 103);
    archReporte.precision(2);
    for(int i=0; productos[i]; i++){
        char **auxProducto = productos[i];
        archReporte << left << setw(10) << auxProducto[0] << setw(70) <<
                auxProducto[1] << right << setw(6) << " " << setfill('0') <<
                setw(2) << stock[i] << setfill(' ') << setw(15) << fixed <<
                precios[i] << endl;
    }
}

void lecturaDePedidos (const char* nombArchLectura, int*& fechaPedidos,
        char***& codigoPedidos, int***& dniCantPedidos){
    
}

void pruebaDeLecturaDePedidos (const char* nombArchLectura, int* fechaPedidos,
        char*** codigoPedidos, int*** dniCantPedidos){
    
}

void reporteDeEnvioDePedidos (const char* nombArchLectura, char***& productos,
        int*& stock, double*& precios, int*& fechaPedidos,
        char***& codigoPedidos, int***& dniCantPedidos){
    
}

void incrementarMemoriaProductos(char***& productos, int*& stock,
        double*& precios, int& cantidad, int& capacidad){
    capacidad += INCREMENTO;
    if(productos == nullptr){
        productos = new char**[capacidad];
        stock = new int[capacidad];
        precios = new double[capacidad];
    }else{
        char*** auxProductos = new char**[capacidad];
        int *auxStock = new int[capacidad];
        double* auxPrecios = new double[capacidad];
        for(int i=0; i<cantidad; i++){
            auxProductos[i] = productos[i];
            auxStock[i] = stock[i];
            auxPrecios[i] = precios[i];
        }
        delete productos;
        delete stock;
        delete precios;
        productos = auxProductos;
        stock = auxStock;
        precios = auxPrecios;
    }
}

void insertarEnMemoriaProductos(char***& productos, int*& stock,
        double*& precios, const char* codigo, const char* descripcion, int nEjemplares,
        double precio, int nProductos){
    char **auxProducto = new char*[2];
    almacenarCadenaDinamica(codigo, auxProducto[0]);
    almacenarCadenaDinamica(descripcion, auxProducto[1]);
    productos[nProductos] = auxProducto;
    productos[nProductos+1] = nullptr;
    stock[nProductos] = nEjemplares;
    precios[nProductos] = precio;
}

void almacenarCadenaDinamica(const char* original, char*& copia){
    copia = new char[strlen(original)+1];
    strcpy(copia, original);
}

void imprimirLinea(ofstream& arch, char caracter, int repeticiones){
    for(int i=0; i<repeticiones; i++)
        arch << caracter;
    arch << endl;
}