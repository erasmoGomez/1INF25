#include "Bibliotecas/Funciones.hpp"

int main() {
    int dni[120];
    struct CadenaDeCaracteres conductor[120],placa[120];

    int numDat=0;

    leerDatos(dni,conductor,placa,numDat,"Data/Infracciones.txt");
    ordenarDatos(dni,conductor,placa,numDat);
    imprimirRep(dni,conductor,placa,numDat,"Reports/Reporte.txt");
    return 0;
}