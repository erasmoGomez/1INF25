/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PunterosGenericos.hpp"

void imprimirLinea(char car,int cant,ofstream &arch){
    for(int i=0;i<cant;i++){
        arch<<car;
    }
    arch<<endl;
}

char *leer_cadena(const char *descripcion){
    char * aux;
    aux = new char[strlen(descripcion)+1];
    strcpy(aux, descripcion);
    return aux;
}

void * crear_producto(int codigo,char * ptrDescripcion,double precio,int cantidad){
    void **producto;
    int *ptrCodigo, *ptrCantidad;
    double *ptrPrecio;
    ptrCodigo = new int; 
    *ptrCodigo = codigo;
    //ptrDesc -> desc
    ptrPrecio = new double;
    *ptrPrecio = precio;
    ptrCantidad = new int;
    *ptrCantidad = cantidad;
    
    //Reservar memoria para el arreglo de ptrVoid
    producto = new void*[4];
    producto[0] = ptrCodigo;
    producto[1] = ptrDescripcion;
    producto[2] = ptrPrecio;
    producto[3] = ptrCantidad;
    return producto;
}

void * crear_predido(int codigo, char *ptrDescripcion,int cantidad, int dni,int fecha,char estado){
    void **pedido;
    int *ptrCodigo, *ptrCantidad, *ptrDni, *ptrFecha;
    double *ptrPrecio;
    char *ptrEstado;
    ptrCodigo = new int; 
    *ptrCodigo = codigo;
    //ptrDesc -> desc
    ptrCantidad = new int;
    *ptrCantidad = cantidad;
    ptrFecha = new int;
    *ptrFecha = fecha;
    ptrDni = new int;
    *ptrDni = dni;
    ptrEstado = new char;
    *ptrEstado = estado;
    
    //Reservar memoria para el arreglo de ptrVoid
    pedido = new void*[6];
    pedido[0] = ptrCodigo;
    pedido[1] = ptrDescripcion;
    pedido[2] = ptrCantidad;
    pedido[3] = ptrFecha;
    pedido[4] = ptrDni;
    pedido[5] = ptrEstado;
    return pedido;
}

void cargaproductos(void *&productos){
    ifstream arch("productos2.csv", ios::in);
    if(!arch.is_open()){
        cout<<"error productos2"<<endl;
    }
    int codigo_producto, cantidad,cantidad_producto = 0;
    char coma, descripcion[200], *ptrdesc;
    double precio;
    void *producto;
    void *bufferProductos[100];
    void **bufferProductosDinamico;
    
    while(true){
        arch>>codigo_producto;
        if(arch.eof())break;
        arch>>coma;
        arch.getline(descripcion,200,',');
        arch>>precio>>coma>>cantidad;
        
        //leercadena
        ptrdesc = leer_cadena(descripcion);
        producto = crear_producto(codigo_producto,ptrdesc,precio,cantidad);
        
        //Añadir al auxilar arreglo de void
        bufferProductos[cantidad_producto] = producto;
        cantidad_producto++;
    }
    bufferProductos[cantidad_producto] = nullptr; cantidad_producto++;
    
    bufferProductosDinamico = new void*[cantidad_producto];
    
    for(int i=0; i<cantidad_producto; i++)
        bufferProductosDinamico[i] = bufferProductos[i];
    
    productos = bufferProductosDinamico;
    
}

void cargapedidos(void *&pedidos){
    ifstream arch("pedidos2.csv", ios::in);
    if(!arch.is_open()){
        cout<<"error pedidos2"<<endl;
    }
    int codigo_producto, cantidad,fecha,cantidad_pedido = 0;
    int dni, dd, mm, aa;
    char coma, descripcion[200], *ptrdesc, estado = 'N';
    void *pedido;
    void *bufferPedidos[200];
    void **bufferPedidosDinamico;
    
    while(true){
        arch>>codigo_producto;
        if(arch.eof())break;
        arch>>coma;
        arch.getline(descripcion,200,',');
        arch>>cantidad>>coma>>dni>>coma>>dd>>coma>>mm>>coma>>aa;
        fecha = aa*10000+mm*100+dd;
        //leercadena
        ptrdesc = leer_cadena(descripcion);
        pedido = crear_predido(codigo_producto,ptrdesc,cantidad, dni,fecha,estado);
        
        //Añadir al auxilar arreglo de void
        bufferPedidos[cantidad_pedido] = pedido;
        cantidad_pedido = cantidad_pedido+1;
    }
    bufferPedidos[cantidad_pedido] = nullptr; cantidad_pedido++;
    
    bufferPedidosDinamico = new void*[cantidad_pedido];
    
    for(int i=0; i<cantidad_pedido; i++)
        bufferPedidosDinamico[i] = bufferPedidos[i];
    
    pedidos = bufferPedidosDinamico;
    imprimePedidos(pedidos);
}
int verificarStock(void *&producto, int *codigo_pedido, int *cantidad_pedido){
    void **pro = (void **)producto;
    int *codigo_producto = (int*)pro[0];
    int *cantidad_producto = (int*)pro[3];
    if(*codigo_producto==*codigo_pedido){
        return *cantidad_producto;
    }
    return -1;
}

void restar_stock(void *& producto,int *cantidad_pedido){
    void ** prod = (void**) producto;
    int *cantidad = (int*)prod[3];
    *cantidad = *cantidad - *cantidad_pedido;
}

void actualizarPedido(void *& pedido, void*&productos){
    int alcanza = 0;
    void **prod = (void **)productos;
    void **ped= (void **)pedido;
    
    int *codigo_pedido = (int*)ped[0];
    int *cantidad_pedido = (int*)ped[2];
    char *estado_pedido = (char*)ped[5];
    
    int i;
    for(i=0; prod[i];i++){
        alcanza = verificarStock(prod[i],codigo_pedido,cantidad_pedido);
        if (alcanza!=-1) break;
    }
    if(alcanza>=*cantidad_pedido){
        restar_stock(prod[i],cantidad_pedido);
        *estado_pedido = 'A';
    }
}

void actualizarPedidos(void *&pedidos, void *&productos){
    void **pedido = (void **)pedidos;
    for(int i=0; pedido[i];i++)
        actualizarPedido(pedido[i],productos);
    
}

void * asignaPtr(int *fecha,int *codigo,char *descripcion,int *cantidad){
    void **ptr;
    ptr = new void*[4];
    ptr[0] = fecha;
    ptr[1] = codigo;
    ptr[2] = descripcion;
    ptr[3] = cantidad;
    return ptr;
}

void asignaPedidosAt(int dni,void *&pedidos, void *&ptrR){
    void **ped = (void**)pedidos;
    int cantPedAt=0;
    void *ptrAsignar;
    void *buffPedAt[100];
    void **ptrRetorno;
    for(int i=0;ped[i];i++){
        void *ptr = ped[i];
        void **pedido = (void **)ptr;
        int *codigo = (int *)pedido[0];
        char *descripcion = (char *)pedido[1];
        int *cantidad = (int *)pedido[2];
        int *dniL = (int *)pedido[3];
        int *fecha = (int *)pedido[4];
        char *estado = (char *)pedido[5];
        if(*dniL == dni and estado[0]=='A'){
            ptrAsignar = asignaPtr(fecha,codigo,descripcion,cantidad);
            buffPedAt[cantPedAt] = ptrAsignar;
            cantPedAt++;
        }
    }
    buffPedAt[cantPedAt] = nullptr; cantPedAt++;
    ptrRetorno = new void*[cantPedAt];
    for(int i=0;i<cantPedAt;i++) ptrRetorno[i]=buffPedAt[i];
    ptrR = ptrRetorno;
}

void * asignaCliente(int dni,char *ptrNombre,void *&pedidos){
    void **cliente;
    void *pedidosAtentidos;
    int *ptrDni;
    ptrDni = new int; *ptrDni = dni;
    cliente = new void*[3];
    cliente[0] = ptrDni;
    cliente[1] = ptrNombre;
    asignaPedidosAt(dni,pedidos, pedidosAtentidos);
    cliente[2] = pedidosAtentidos;
    return cliente;
}

void procesaclientes(void *&productos, void *&pedidos, void *&clientes){
    ifstream arch("clientes2.csv",ios::in);
    int dni, cantidadClientes=0;
    char car;
    void *cliente, *buffClientes[50], **cli;
    char nombre[200], *ptrNombre;
    
    actualizarPedidos(pedidos, productos);
    
    while(1){
        arch>>dni;
        if(arch.eof()) break;
        arch>>car;
        arch.getline(nombre,200);
        ptrNombre = new char[strlen(nombre)+1];
        strcpy(ptrNombre, nombre);
        cliente = asignaCliente(dni,ptrNombre,pedidos);
        buffClientes[cantidadClientes] = cliente;
        cantidadClientes++;
    }
    buffClientes[cantidadClientes] = nullptr; cantidadClientes++;
    cli = new void*[cantidadClientes];
    for(int i=0;i<cantidadClientes;i++) cli[i]=buffClientes[i];
    clientes = cli;
}

void imprimepedreg(void *&registro){
    void **laux = (void**)registro;
    char *nombre,*estado;
    int *codigo,*dni,*fecha,*cantidad;
    
   
    codigo = (int*)laux[0];
    nombre = (char*)laux[1];
    cantidad = (int*)laux[2];
    dni = (int*)laux[3];
    fecha = (int*)laux[4];;
    estado = (char*)laux[5];
    cout <<left<<setw(20)<< *codigo << setw(50)<< nombre << 
        setw(10)<< *cantidad <<   setw(10)<< *fecha<<
        setw(10)<< *estado << endl;
    
}

void imprimePedido(void *pedido){
    int i=0;
    void **laux = (void**)pedido;
    while(1){
        if(laux[i]==NULL) break; 
        imprimepedreg(laux[i]);
        i++;
    }
}

void imprimePedidos(void *&pedidos){
    
    void **pedido = (void **)pedidos;
    cout<<pedido[1]<<endl; 
    for(int i=0;pedido[i];i++)
        imprimePedido(pedido[i]);
}

void imprimeCliente(void *&cliente,ofstream &arch){
    void **cli = (void **)cliente;
    
    int *dni = (int *)cli[0];
    char *nombre = (char *)cli[1];
    arch<<left<<setw(20)<<"DNI"<<setw(70)<<"NOMBRE"<<endl;
    arch<<setw(20)<<*dni<<setw(70)<<nombre<<endl;
    imprimirLinea('-',150,arch);
    arch<<"Pedidos atendidos:"<<endl;
    imprimirLinea('-',150,arch);
    arch<<setw(20)<<"FECHA"<<setw(20)<<"CODIGO"<<setw(70)<<"DESCRIPCION"<<setw(20)<<"CANTIDAD"<<endl;
    imprimirLinea('-',150,arch);
    imprimePedidos(cli[2]);
    imprimirLinea('=',150,arch);
}

void imprimereporte(void *&clientes){
    ofstream arch("ReporteDePedidos.txt", ios::out);
    imprimirLinea('=',150,arch);
    arch<<"PEDIDOS ATENDIDOS POR CLIENTE:"<<endl;
    imprimirLinea('=',150,arch);
    void **cliente = (void **)clientes;
    for(int i=0;cliente[i];i++)
        imprimeCliente(cliente[i],arch);
}