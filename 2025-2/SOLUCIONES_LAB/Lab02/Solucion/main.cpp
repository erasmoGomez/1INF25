#include "StreamingTools.h"

int main() {
    char ***categorias;
    cargarCategorias("Data/categorias.csv", categorias);

    char ***streamers;
    int **fechasPromedios;
    long long **tiempoRepSeguidores;
    cargarStreamers("Data/streamers.csv", streamers, fechasPromedios, tiempoRepSeguidores);

    char ***comentarios;
    char ***etiquetas;
    cargarComentarios("Data/comentarios.csv", comentarios, etiquetas);

    imprimirReporte("reporte.txt", categorias, streamers, fechasPromedios, tiempoRepSeguidores, comentarios, etiquetas);

    liberarCategorias(categorias);
    liberarStreamers(streamers, fechasPromedios, tiempoRepSeguidores);
    return 0;
}
