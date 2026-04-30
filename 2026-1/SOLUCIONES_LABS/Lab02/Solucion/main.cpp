#include "src/ER.h"

#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const char *archivoDeLectura = "data/ER_Final_Dataset_For_Students_Programacion_2.csv";
    const char *archivoDeEscritura = "reports/Reporte.txt";
    int *fechas;
    char ****datosDeTexto;
    int ***datosEnteros;
    float ***datosDePuntoFlotante;

    cargarInformacion(archivoDeLectura, fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    completarInformacion(fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    reporteDeAtenciones(archivoDeEscritura, fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    return 0;
}