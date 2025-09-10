//
// Created by Erasmo on 9/09/25.
//

#ifndef PUBLICACIONES_PUBLICACIONES_HPP
#define PUBLICACIONES_PUBLICACIONES_HPP

#include "FuncionesAuxiliares.hpp"

void carga_usuarios(const char *, char ***&, int **&);

void incrementar_usuarios(char ***&, int, int);

void incrementar_fechas_edades(int **&, int, int);

void insertar_ordenado(char ***&usuarios, int **&fechasEdades, char **usuario,
                       int *fechaEdad, int num);

void imprimir_reporte(const char *nombreArchivo, char ***usuarios, int **fechasEdades);

void cargar_publicaciones(const char *, int **&, char ***&, char ***&);

void cargarMenciones(ifstream &, char **&);

void incrementarIdsFechas(int **&, int, int);

void incrementarMenciones(char ***&, int, int);

void incrementarPublicaciones(char ***&, int, int);

void imprimir_reporte(const char *nombreArchivo, char ***usuarios,
                      int **fechasEdades,
                      int **idsFechas, char ***publicaciones,
                      char ***menciones);

#endif //PUBLICACIONES_PUBLICACIONES_HPP
