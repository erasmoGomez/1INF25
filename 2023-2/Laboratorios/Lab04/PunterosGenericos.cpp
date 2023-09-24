/* 
 * File:   PunterosGenericos.cpp
 * Author: Jorge Fatama
 *
 * Created on 23 de setiembre de 2023, 01:41
 */

#include <streambuf>

#include "PunterosGenericos.h"

void cargaproductos(void*& productos){
    ifstream archProductos("productos2.csv", ios::in);
    void *auxProductos[200];
    void **auxExacta, *registro;
    int nProductos = 0;

    if (not archProductos.is_open()) {
        cout << "No ha podido abrir el archivo de productos";
        exit(1);
    }
    
    while(true){
        registro = leeRegistroProducto(archProductos);
        if (not registro)
            break;
        auxProductos[nProductos] = registro;
        nProductos++;
    }
    
    asignacionExacta(auxProductos, auxExacta, nProductos);
    productos = auxExacta;
    
    imprimeproductos(productos);
}

void cargaclientes(void*& clientes){
    ifstream archClientes("clientes2.csv", ios::in);
    void *auxClientes[200];
    void **auxExacta, *registro;
    int nClientes = 0;

    if (not archClientes.is_open()) {
        cout << "No ha podido abrir el archivo de clientes";
        exit(1);
    }
    
    while(true){
        registro = leeRegistroCliente(archClientes);
        if (not registro)
            break;
        auxClientes[nClientes] = registro;
        nClientes++;
    }
    
    asignacionExacta(auxClientes, auxExacta, nClientes);
    clientes = auxExacta;
    
    imprimeclientes(clientes);
}

void cargapedidos(void* productos, void*& clientes){
    ifstream archPedidos("pedidos2.csv", ios::in);
    void **auxClientes;
    int *nPedidos;
    
    if (not archPedidos.is_open()) {
        cout << "No ha podido abrir el archivo de pedidos";
        exit(1);
    }
    
    nPedidos = asignarMemoriaTemporalEnPedidos(clientes);
    
    while(true){
        leePedidoEnCliente(archPedidos, productos, clientes, nPedidos);
        if (archPedidos.eof())
            break;
    }    
    
    asignarMemoriaExactaEnPedidos(clientes, nPedidos);
    
    imprimerepfinal(clientes);
}

void imprimereporte(void* clientes){
    ofstream archReporte("InformeFinal.txt", ios::out);
    void** auxClientes = (void**) clientes;
    
    if (not archReporte.is_open()) {
        cout << "No ha podido abrir el archivo de reporte";
        exit(1);
    }
    
    archReporte.precision(2);
    
    for(int i=0; auxClientes[i]; i++){
        imprimeLinea(archReporte, '=', 100);
        archReporte << left << setw(20) << "DNI" << setw(50) << "Nombre" <<
                "Crédito" << endl;
        imprimeCliente(archReporte, auxClientes[i]);
        
    }
}

void* leeRegistroProducto(ifstream& arch){
    void **registro = new void*[4];
    char *codigo, *descripcion;
    double *precio = new double;
    char *tipo = new char, aux;
    codigo = leerCadena(arch);
    if (arch.eof())
        return nullptr;
    descripcion = leerCadena(arch);
    arch >> *precio >> aux >> *tipo;
    arch.get();
    // Llenar el puntero genérico
    registro[CODIGO] = codigo;
    registro[DESCRIPCION] = descripcion;
    registro[PRECIO] = precio;
    registro[TIPO] = tipo;
    return registro;
}

void asignacionExacta(void **auxRegistros, void **&auxExacta, int nRegistros){
    auxExacta = new void*[nRegistros+1];
    for(int i=0; i<nRegistros; i++){
        auxExacta[i] = auxRegistros[i];
    }
    auxExacta[nRegistros] = nullptr;
}

void* leeRegistroCliente(ifstream& arch){
    void **registro = new void*[4];
    char *nombre, aux;
    int *dni = new int, telefono;
    double *lineaCredito = new double;
    
    arch >> *dni >> aux;
    if (arch.eof())
        return nullptr;
    nombre = leerCadena(arch);
    arch >> telefono >> aux >> *lineaCredito;
    arch.get();
    // Llenar el puntero genérico
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[PEDIDOS] = nullptr;
    registro[LINEACREDITO] = lineaCredito;
    return registro;
}

int* asignarMemoriaTemporalEnPedidos(void *& clientes){
    int nClientes = 0, *nPedidosXCliente;
    void **auxClientes = (void **)clientes, **auxCliente;
    for(nClientes; auxClientes [nClientes]; nClientes++){
        // Se asigna un puntero temporal de 50 registros.
        auxCliente = (void**) auxClientes[nClientes];
        auxCliente[PEDIDOS] = new void*[50];
        auxClientes[nClientes] = auxCliente;
    }
    clientes = auxClientes;
    nPedidosXCliente = new int[nClientes]{0};
    return nPedidosXCliente;
}

void leePedidoEnCliente(ifstream& arch, void* productos, void*& clientes,
        int* nPedidos){
    char *codProducto, aux;
    int dniCliente, cantidad, indiceProducto, indiceCliente;
    bool debeInsertar, debeDescontar;
    double montoADescontar;
    
    // Lectura de línea de archivo
    codProducto = leerCadena(arch);
    if(arch.eof())
        return;
    arch >> dniCliente >> aux >> cantidad;
    arch.get();
    // Búsqueda
    indiceProducto = buscarProducto(productos, codProducto);
    if(indiceProducto > NO_ENCONTRADO){
        indiceCliente = buscarCliente(clientes, dniCliente);
        if(indiceCliente > NO_ENCONTRADO){
            // Ahora sí, procesar;
            validarInsercion(productos, indiceProducto, clientes, indiceCliente,
                    cantidad, debeInsertar, debeDescontar, montoADescontar);
            if(debeInsertar){
                insertarPedidoEnCliente(clientes, indiceCliente, debeDescontar,
                        codProducto, cantidad, montoADescontar, nPedidos);
            }
        }
    }
}

void asignarMemoriaExactaEnPedidos(void *& clientes, int* nPedidos){
    int nClientes = 0, i;
    void **auxPedidos, **auxCliente, **auxNuevo;
    void **auxClientes = (void **)clientes;
    for(nClientes; auxClientes[nClientes]; nClientes++){
        auxCliente = (void**) auxClientes[nClientes];
        if(nPedidos[nClientes] > 0){    
            auxPedidos = (void**) auxCliente[PEDIDOS];
            auxNuevo = new void*[nPedidos[nClientes]+1];
            for(i=0; i<nPedidos[nClientes]; i++)
                auxNuevo[i] = auxPedidos[i];
            auxNuevo[i] = nullptr;
            auxPedidos = auxNuevo;
        } else {
            auxPedidos = nullptr;
        }
        auxCliente[PEDIDOS] = auxPedidos;
        auxClientes[nClientes] = auxCliente;
    }
    clientes = auxClientes;
}

char* leerCadena(ifstream& arch) {
    char auxCadena[100], *cadenaDinamica;
    arch.getline(auxCadena, 100, ',');
    cadenaDinamica = new char [strlen(auxCadena) + 1];
    strcpy(cadenaDinamica, auxCadena);
    return cadenaDinamica;
}

int buscarProducto(void* productos, const char* codProducto){
    void **auxProductos = (void**)productos, **auxProducto;
    for(int i=0; auxProductos[i]; i++){
        auxProducto = (void**)auxProductos[i];
        if(strcmp(codProducto, (char*)auxProducto[CODIGO]) == 0)
            return i;
    }
    return NO_ENCONTRADO;
}

int buscarCliente(void* clientes, int dniCliente){
    void **auxClientes = (void**)clientes, **auxCliente;
    int *auxDNI;
    
    for(int i=0; auxClientes[i]; i++){
        auxCliente = (void**)auxClientes[i];
        auxDNI = (int*) auxCliente[DNI];
        if(*auxDNI == dniCliente)
            return i;
    }
    return NO_ENCONTRADO;
}

void insertarPedidoEnCliente(void*& clientes, int indiceCliente, bool debeDescontar,
            char *codProducto, int cantidad, double montoPedido, int* nPedidos){
    void **auxClientes = (void**)clientes;
    void **auxCliente  = (void**)auxClientes[indiceCliente];
    void **auxPedidos = (void**)auxCliente[PEDIDOS];
    void **registro = new void*[3];
    int *auxCantidad = new int;
    *auxCantidad = cantidad;
    double *auxMonto = new double, *auxLinea;
    *auxMonto = montoPedido;
    registro[CODIGOPRODUCTO] = codProducto;
    registro[CANTIDADPRODUCTO] = auxCantidad;
    registro[TOTALPEDIDO] = auxMonto;
    
    // Insertar en puntero de pedidos
    int indiceInsertado = nPedidos[indiceCliente];
    auxPedidos[indiceInsertado] = registro;
    auxCliente[PEDIDOS] = auxPedidos;
    
    // Descontar de la línea en caso corresponda.
    if(debeDescontar){
        auxLinea = (double*) auxCliente[LINEACREDITO];
        *auxLinea -= montoPedido;
        auxCliente[LINEACREDITO] = auxLinea; 
    }
    
    auxClientes[indiceCliente] = auxCliente;
    clientes = auxClientes;
    nPedidos[indiceCliente]++;
}

void validarInsercion(void* productos, int indiceProducto, void* clientes,
        int indiceCliente, int cantidad, bool& debeInsertar,
        bool& debeDescontar, double& montoPedido){
    char tipo;
    double lineaCredito;
    // Ver si el producto consume línea de crédito
    void **auxProductos = (void**) productos;
    void **auxProducto = (void**) auxProductos[indiceProducto];
    void **auxClientes = (void**) clientes;
    void **auxCliente = (void**) auxClientes[indiceCliente];
    tipo = *((char*) auxProducto[TIPO]);
    montoPedido = *((double*) auxProducto[PRECIO]) * cantidad;
    if(tipo == 'N'){
        debeInsertar = true;
        debeDescontar = false;
    } else{
        lineaCredito = *((double*) auxCliente[LINEACREDITO]);
        if(lineaCredito >= montoPedido){
            debeInsertar = true;
            debeDescontar = true;
        } else
            debeInsertar = false;
    }
}

void imprimeLinea(ofstream& arch, char caracter, int repeticiones){
    for(int i=0; i<repeticiones; i++)
        arch << caracter;
    arch << endl;
}

void imprimeCliente(ofstream& archReporte, void* cliente){
    void** auxCliente, **auxRegistro, **auxPedidos, **auxPedido;
    auxCliente = (void**) cliente;
    auxRegistro = (void**) auxCliente;
    archReporte << left << setw(20) << *((int*) auxRegistro[DNI]) << 
            setw(50) << (char*) auxRegistro[NOMBRE] << fixed <<
            *((double*) auxRegistro[LINEACREDITO]) << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << "Pedidos atendidos:" << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << left << setw(10) << "Código" << setw(10) << "Cantidad" <<
            "Total" << endl;
    auxPedidos = (void**) auxRegistro[PEDIDOS];
    if(auxPedidos != nullptr)
        for(int i=0; auxPedidos[i]; i++){
            auxPedido = (void**) auxPedidos[i];
            archReporte << left << setw(10) << ((char*) auxPedido[CODIGOPRODUCTO]) <<
                    setw(10) << *((int*) auxPedido[CANTIDADPRODUCTO]) <<
                    *((double*) auxPedido[TOTALPEDIDO]) << endl;
        }
    archReporte << endl;
}