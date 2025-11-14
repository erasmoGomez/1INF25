//
// Created by Daniel Sanchez on 17/09/25.
//

#ifndef SOLUCION_STREAMINGTOOLS_H
#define SOLUCION_STREAMINGTOOLS_H

constexpr int MEM_INC = 5;

enum {
    CAT_CODIGO = 0,
    CAT_NOMBRE,
    CAT_DESCRIPCION,
    CAT_N,
};

enum {
    STREAMER_CUENTA = 0,
    STREAMER_CATEGORIA,
    STREAMER_N,
};

enum {
    FECHA_CREACION = 0,
    FECHA_ULTIMA_TRANSMISION,
    PROMEDIO_ESPECTADORES,
    FECHA_N,
};

enum {
    TIEMPO_TOTAL = 0,
    CANTIDAD_SEGUIDORES,
    STATS_N,
};

void cargarCategorias(const char *arch_nom, char ***&categorias);

void liberarCategorias(char ***&categorias);

void cargarStreamers(const char *arch_nom, char ***&streamers, int **&fechasPromedios,
                     long long **&tiempoRepSeguidores);

void liberarStreamers(char ***&streamers, int **&fechasPromedios, long long **&tiemposRepSeguidores);

void cargarComentarios(const char *arch_nom, char ***&comentarios, char ***&etiquetas);

void imprimirReporte(const char *arch_nom, char ***categorias, char ***streamers, int **fechasPromedios,
                     long long **tiempoRepSeguidores, char ***comentarios, char ***etiquetas);

#endif //SOLUCION_STREAMINGTOOLS_H
