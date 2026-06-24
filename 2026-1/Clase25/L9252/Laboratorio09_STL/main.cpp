#include <iomanip>
using namespace std;
#include "Bibliotecas/SistemaDeGestion.hpp"

int main(int argc, char **argv) {
    class SistemaDeGestion sg;
    sg.cargarCategoria("ArchivosDeDatos/Categorias.csv");
    sg.cargarComentarios("ArchivosDeDatos/Comentarios.csv");
    sg.cargarEtiquetas("ArchivosDeDatos/Etiquetas.csv");
    sg.cargarStreamers("ArchivosDeDatos/Streamers.csv");
    sg.completarStreamers();
    sg.mostrarReporte("ArchivosDeReporte/Reporte.txt");
    return 0;
}