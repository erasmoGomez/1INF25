#include "src/MinisterioTransporte.hpp"

int main() {
    MinisterioDeTransporte mt;

    mt.cargaDeInfracciones("Data/TablaDeInfracciones.csv");
    mt.cargaEmpresas("Data/EmpresasRegistradas.csv");
    mt.cargaVehiculos("Data/VehiculosRegistrados.csv");
    mt.cargaInfraccionesCometidas("Data/InfraccionesCometidas.csv");

    mt.reporteDeEmpresasConInfracciones("Reports/ReporteCompleto.txt");
    mt.eliminaInfraccionesPagadas();

    mt.reporteDeEmpresasConInfracciones("Reports/ReporteDeuda.txt");
    return 0;
}
