//
// Proyecto: SolucionLab05_2025_1
// Archivo : main.cpp
// Autor   : J Miguel Guanira E
//
// Creado el viernes 06 de junio del 2025 a las 11:26
//

#include "Bibliotecas/BibliotecaGenerica.hpp"
#include "Bibliotecas/BibliotecaConductores.hpp"
#include "Bibliotecas/BibliotecaInfracciones.hpp"

int main(int argc, char **argv) {
    void *lista;
    generaLista(lista);
    creaLista(lista,leeconductores,cmpconductores,buscalistaconductores,"Data/Conductores.csv");
    cargaUnidades(lista,"Data/Unidades.csv");
    creaLista(lista,leeinfracciones,cmpinfracciones,buscalistainfraccion,"Data/Faltas.csv");
    imprimelista(lista,imprimeconductores,"Reports/RepConductores.txt");

    return 0;
}
