//
// Created by Daniel Sanchez on 23/04/26.
//

#ifndef SOLUCION_ER_H
#define SOLUCION_ER_H


void cargarInformacion(const char *nombreDelArchivo, int *&fechas, char ****&datosDeTexto, int ***&datosEnteros,
                       float ***&datosDePuntoFlotante);

void completarInformacion(int *fechas, char ****datosDeTexto, int ***datosEnteros, float ***datosDePuntoFlotante);

void reporteDeAtenciones(const char *nombreDelArchivo, int *fechas, char ****datosDeTexto, int ***datosEnteros,
                         float ***datosDePuntoFlotante);

#endif //SOLUCION_ER_H
