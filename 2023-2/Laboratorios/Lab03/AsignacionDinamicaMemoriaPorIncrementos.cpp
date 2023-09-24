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
    char codigoProducto[50], aux;
    int dniSolicitante, cantidadPedido, ddPedido, mmPedido, aaPedido, fechaPedido;
    int *nPedidosFecha, *capacidadFecha, nPedidos = 0, capacidad = 0;
    ifstream archLectura(nombArchLectura, ios::in);
    if(not archLectura.is_open()){
        cout << "No se pudo abrir archivo de pedidos" << endl;
        exit(1);
    }
    fechaPedidos = nullptr;
    codigoPedidos = nullptr;
    dniCantPedidos = nullptr;
    while(true){
        archLectura.getline(codigoProducto, 50, ',');
        if(archLectura.eof())
            break;
        archLectura >> dniSolicitante >> aux >> cantidadPedido >> aux;
        archLectura >> ddPedido >> aux >> mmPedido >> aux >> aaPedido;
        fechaPedido = determinarFecha(ddPedido, mmPedido, aaPedido);
        archLectura.get(); // '\n'
        insertarEnMemoriaPedidos(fechaPedidos, codigoPedidos, dniCantPedidos, codigoProducto, dniSolicitante, cantidadPedido, fechaPedido, nPedidos, capacidad, nPedidosFecha, capacidadFecha);
    }
}

void pruebaDeLecturaDePedidos (const char* nombArchReporte, int* fechaPedidos,
        char*** codigoPedidos, int*** dniCantPedidos){
    ofstream archReporte(nombArchReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "No se pudo abrir archivo de pedidos" << endl;
        exit(1);
    }
    archReporte << "REPORTE DE PRODUCTOS" << endl << endl;
    archReporte << left << setw(12) << "FECHA" << setw(8) << "PRODUCTO" << right << setw(15) << "DNI CLIENTE" << setw(10) << "CANTIDAD" << endl;
    imprimirLinea(archReporte, '-', 103);
    archReporte.precision(2);
    for(int i=0; codigoPedidos[i]; i++){
        archReporte << left << setw(15) << fechaPedidos[i] << endl;
        char **auxCodigo = codigoPedidos[i];
        int j;
        for(j=0; auxCodigo[j]; j++);
        archReporte << "N°: " << j << endl;
        /*char **auxCodigo = codigoPedidos[i];
        int **auxDNICant = dniCantPedidos[i];
        for(int j=0; auxCodigo[j]; j++){
            archReporte << right << setw(20) << auxCodigo[j];
            int *detallePedido = auxDNICant[j];
            archReporte << setw(15) << detallePedido[0] << setw(8) << " " <<
                    setfill('0') << setw(2) << detallePedido[1] <<
                    setfill(' ') << endl; 
        }*/
    }
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

int determinarFecha(int ddPedido, int mmPedido, int aaPedido){
    return ddPedido + 100 * mmPedido + 10000 * aaPedido;
}

void incrementarMemoriaPedidos(int*& fechaPedidos, char***& codigoPedidos,
        int***& dniCantPedidos, int& cantidad, int& capacidad,
        int*& nPedidosFecha, int*& capacidadFecha){
    capacidad += INCREMENTO;
    if(codigoPedidos == nullptr){
        fechaPedidos = new int[capacidad];
        codigoPedidos = new char**[capacidad];
        dniCantPedidos = new int**[capacidad];
        nPedidosFecha = new int[capacidad];
        capacidadFecha = new int[capacidad];
    }else{
        int* auxFecha = new int[capacidad];
        char*** auxCodigo = new char**[capacidad];
        int*** auxDNI = new int**[capacidad];
        int* auxNPedidos = new int[capacidad];
        int* auxCapacidadPedidos = new int[capacidad];
        for(int i=0; i<cantidad; i++){
            auxFecha[i] = fechaPedidos[i];
            auxCodigo[i] = codigoPedidos[i];
            auxDNI[i] = dniCantPedidos[i];
            auxNPedidos[i] = nPedidosFecha[i];
            auxCapacidadPedidos[i] = capacidadFecha[i];
        }
        /*delete fechaPedidos;
        delete codigoPedidos;
        delete dniCantPedidos;
        delete nPedidosFecha;
        delete capacidadFecha;*/
        fechaPedidos = auxFecha;
        codigoPedidos = auxCodigo;
        dniCantPedidos = auxDNI;
        nPedidosFecha = auxNPedidos;
        capacidadFecha = auxCapacidadPedidos;
    }
}

void insertarEnMemoriaPedidos(int*& fechaPedidos, char***& codigoPedidos,
        int***& dniCantPedidos, const char* codigoProducto, int dniSolicitante,
        int cantidadPedido, int fechaPedido, int& nPedidos, int& capacidad, int*& nPedidosFecha,
        int*& capacidadFecha){
    //char **auxProducto = new char*[2];
    int indiceABuscar = buscarFecha(fechaPedidos, fechaPedido, nPedidos);
    // Caso: la fecha no se encuentra.
    if(indiceABuscar == -1){
        // Buscar el índice donde se puede insertar
        for(indiceABuscar=0; indiceABuscar<nPedidos; indiceABuscar++)
            if(fechaPedido < fechaPedidos[indiceABuscar])
                break;
        if(nPedidos == capacidad)
            incrementarMemoriaPedidos(fechaPedidos, codigoPedidos, dniCantPedidos, nPedidos, capacidad, nPedidosFecha, capacidadFecha);
        // Insertar en la posición
        insertarNuevaFecha(fechaPedidos, codigoPedidos, dniCantPedidos, fechaPedido, nPedidosFecha, capacidadFecha, indiceABuscar, nPedidos);
        nPedidos++;
    }
    // Caso: la fecha se encontró
    // Se sabe que se insertará en el índice "indiceABuscar"
    insertarEnPunteros(codigoPedidos, dniCantPedidos, indiceABuscar, codigoProducto, dniSolicitante, cantidadPedido, nPedidosFecha, capacidadFecha);
}

int buscarFecha(int* fechaPedidos, int fechaABuscar, int nPedidos){
    for(int i = 0; i<nPedidos; i++){
        if(fechaPedidos[i] == fechaABuscar)
            return i;
    }
    return -1;
}

void insertarNuevaFecha(int*& fechaPedidos, char***& codigoPedidos,
        int***& dniCantPedidos, int fechaPedido, int*& nPedidosFecha,
        int*& capacidadFecha, int indiceABuscar, int nPedidos){
    // Reacomodar las fechas más recientes
    for(int i=nPedidos-1; i>=indiceABuscar; i--){
        fechaPedidos[i+1] = fechaPedidos[i];
        codigoPedidos[i+1] = codigoPedidos[i];
        dniCantPedidos[i+1] = dniCantPedidos[i];
        nPedidosFecha[i+1] = nPedidosFecha[i];
        capacidadFecha[i+1] = capacidadFecha[i];
    }
    // Insertar nuevos registros de capacidad en los punteros.
    fechaPedidos[indiceABuscar] = fechaPedido;
    codigoPedidos[indiceABuscar] = nullptr;
    codigoPedidos[nPedidos+1] = nullptr;
    dniCantPedidos[indiceABuscar] = nullptr;
    nPedidosFecha[indiceABuscar] = 0;
    capacidadFecha[indiceABuscar] = 0;
}

void insertarEnPunteros(char***& codigoPedidos, int***& dniCantPedidos,
        int indiceABuscar, const char* codigoProducto, int dniSolicitante,
        int cantidadPedido, int* nPedidosFecha, int* capacidadFecha){
    // Ver si se incrementa la memoria
    if(nPedidosFecha[indiceABuscar] == capacidadFecha[indiceABuscar])
        incrementarMemoriaPedidosEnFecha(codigoPedidos, dniCantPedidos, indiceABuscar, nPedidosFecha[indiceABuscar], capacidadFecha);
    // Insertar al fin
    // Insertar en codigoPedidos
    char **auxCodigo = codigoPedidos[indiceABuscar];
    almacenarCadenaDinamica(codigoProducto, auxCodigo[nPedidosFecha[indiceABuscar]]);
    auxCodigo[nPedidosFecha[indiceABuscar]+1] = nullptr;
    codigoPedidos[indiceABuscar] = auxCodigo;
    
    // Insertar en dniCantPedidos
    int **auxDNICant = dniCantPedidos[indiceABuscar];
    int *auxPedidoIndividual = new int[2];
    auxPedidoIndividual[0] = dniSolicitante;
    auxPedidoIndividual[1] = cantidadPedido;
    auxDNICant[nPedidosFecha[indiceABuscar]] = auxPedidoIndividual;
    dniCantPedidos[indiceABuscar] = auxDNICant;
    // Incrementar en nPedidosFecha
    nPedidosFecha[indiceABuscar]++;
}

void incrementarMemoriaPedidosEnFecha(char***& codigoPedidos,
        int***& dniCantPedidos, int indiceABuscar, int nPedidos,
        int* capacidadFecha){
    capacidadFecha[indiceABuscar] += INCREMENTO;
    if(codigoPedidos[indiceABuscar] == nullptr){
        codigoPedidos[indiceABuscar] = new char*[capacidadFecha[indiceABuscar]];
        dniCantPedidos[indiceABuscar] = new int*[capacidadFecha[indiceABuscar]];
    } else{
        char **auxTotalPedidos = codigoPedidos[indiceABuscar];
        int** auxTotalDNI =  dniCantPedidos[indiceABuscar];
        char** auxCodigo = new char*[capacidadFecha[indiceABuscar]];
        int** auxDNI = new int*[capacidadFecha[indiceABuscar]];
        for(int i=0; i<nPedidos; i++){
            almacenarCadenaDinamica(auxTotalPedidos[i], auxCodigo[i]);
            auxCodigo[i] = auxTotalPedidos[i];
            auxDNI[i] = auxTotalDNI[i];
        }
        //delete codigoPedidos[indiceABuscar];
        //delete dniCantPedidos[indiceABuscar];
        codigoPedidos[indiceABuscar] = auxTotalPedidos;
        dniCantPedidos[indiceABuscar] = auxTotalDNI;
    }
}