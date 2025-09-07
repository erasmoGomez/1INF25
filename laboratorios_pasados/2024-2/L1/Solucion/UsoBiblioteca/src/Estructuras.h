/* 
 * Proyecto: lab01
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 29 de agosto de 2024, 09:36 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Plato{
    char codigo[7];
    char nombre[60];
    double precio;
    int totalDePedidos;
    double totalRecaudado;
};

struct Pedido{
    int dniDelCliente;
    char codigoDelPlato[7];
    int cantidad;
    double precio;
    char codigoDelRepartidor[7];
    double distanciaARecorrer;
};

struct PlatoSolicitado{
    char codigo[7];
    int cantidad;
    double precio;
};

struct OrdenDeCompra{
    int dniDelCliente;
    double distancia;
    struct PlatoSolicitado platosSolicitados[10];
    int cantidadDePlatos;
    double montoPorCobrar;
    double pagoPorEnvio;
};

struct Repartidor{
    char codigo[7];
    char nombre[60];
    char tipoDeVehiculo[15];
    struct OrdenDeCompra ordenesDeCompra[10];
    int cantidadDeOrdenes;
    double pagoPorEntregas;
};

#endif /* ESTRUCTURAS_H */

