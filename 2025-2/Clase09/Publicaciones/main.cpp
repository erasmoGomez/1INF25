#include "src/Publicaciones.hpp"

int main() {
    char ***usuarios;
    int **fechas_edades;
    carga_usuarios("Data/usuarios.csv", usuarios, fechas_edades);

    imprimir_reporte("Reports/reporte_usuarios.txt", usuarios, fechas_edades);

    int **idsFechas;
    char ***publicaciones;
    char ***menciones;

    cargar_publicaciones("Data/publicaciones.csv", idsFechas, publicaciones, menciones);

    imprimir_reporte("Reports/reporte_completo.txt",
                     usuarios,
                     fechas_edades,
                     idsFechas,
                     publicaciones,
                     menciones);
    return 0;
}
